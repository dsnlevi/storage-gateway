#ifndef _PROXY_H
#define _PROXY_H

#include <unistd.h>
#include <string>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include "common.h"
#include "jcache.h"
#include "bcache.h"
#include "../nedmalloc.h"
#include "../seq_generator.hpp"
#include "../../log/log.h"
using namespace std;

class CacheProxy
{
    const static size_t MAX_CACHE_LIMIT  = (10 * 1024 * 1024);
    const static size_t CACHE_EVICT_SIZE = (2 * 1024 * 1024);
public:
    CacheProxy() = default;
    explicit CacheProxy(string blk_dev, shared_ptr<IDGenerator> id_maker);

    /*each volume own a cproxy, disable copy constructor and operator=*/
    CacheProxy(const CacheProxy& other) = delete;
    CacheProxy(CacheProxy&& other) = delete;
    CacheProxy& operator=(const CacheProxy& other) = delete;
    CacheProxy& operator=(CacheProxy&& other) = delete;

    ~CacheProxy();
  
    /*journal writer or cache recover add cache*/
    void write(string journal_file, off_t  journal_off,
               shared_ptr<JournalEntry> journal_entry);

    /*io hook read*/
    int  read(off_t  off, size_t len, char*  buf); 
    
    /*journal replayer call*/
    shared_ptr<CEntry> pop();                                     

    /*journal replayer reclaim CEntry from jcache and bcache */
    bool reclaim(shared_ptr<CEntry> entry);         
    
    /*check whether cache is full*/
    bool isfull(size_t cur_io_size);

    /*backgroud cache evict */
    void start_cache_evict_thr();
    void trigger_cache_evict();
    void cache_evict_work();
    void stop_cache_evict_thr();

    /*debug*/
    void trace();

private:
    /*block device*/
    string   blkdev;
    /*io seq generator*/
    shared_ptr<IDGenerator> idproc;

    /*current cache memory size*/
    atomic<size_t>  total_mem_size; 
    
    /*backgroud cache evict*/
    bool               evict_run;
    thread*            evict_thread;
    mutex              evict_lock;
    condition_variable evict_cond;

    /*accelerate journal replay*/
    Jcache*  jcache;
    /*accelerate read cache*/
    Bcache*  bcache;
};

#endif
