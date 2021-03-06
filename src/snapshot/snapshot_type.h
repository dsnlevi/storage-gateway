#ifndef _SNAP_TYPE_H
#define _SNAP_TYPE_H
#include <string>
#include <set>
#include "../rpc/snapshot.pb.h"

using namespace std;

/*snapshot id*/
typedef uint64_t snapid_t;
/*block no*/
typedef uint64_t block_t;

/*cow data object name*/
typedef string cow_object_t;
/*cow data object snapshot reference list*/
typedef set<snapid_t> cow_object_ref_t;

/*snapshot internal status*/
enum snapshot_status {
    SNAPSHOT_CREATING  = 0,
    SNAPSHOT_CREATED   = 1,
    SNAPSHOT_DELETING  = 2,
    SNAPSHOT_DELETED   = 3, 
    SNAPSHOT_ROLLBACKING = 4,
    SNAPSHOT_ROLLBACKED  = 5,
    SNAPSHOT_INVALID     = 10, 
};
typedef enum snapshot_status snapshot_status_t;

/*status code*/
enum snapshot_error_code {
    SNAPSHOT_OK  = 0,
    SNAPSHOT_ERR = 1,
    SNAPSHOT_EXIST   = 10,
    SNAPSHOT_NOEXIST = 11
};
typedef snapshot_error_code snapshot_error_code_t;

/*cow block splited by COW_BLOCK_SIZE*/
struct cow_block
{
    off_t   off;
    size_t  len;
    block_t blk_no;
};
typedef struct cow_block cow_block_t;

/*block operation way*/
enum cow_op {
    COW_YES = 0, /*need cow */
    COW_NO  = 1, /*noneed cow, direct overlap*/
};
typedef enum cow_op cow_op_t;

/*mininum cow block size*/
#define COW_BLOCK_SIZE (4096UL)

/*io alignment*/
#define ALIGN_UP(v,align) (((v)+(align)-1) & ~((align)-1))

/*index db store path*/
#define DB_DIR  "/var/tmp/"

/*use spawn cow object name*/
#define FS  "@"
#define OBJ_SUFFIX ".obj"

/*snapshot indexstore key prefix*/
#define SNAPSHOT_ID_PREFIX           "snapshot_latestid"
#define SNAPSHOT_NAME_PREFIX         "snapshot_latestname"
#define SNAPSHOT_MAP_PREFIX           "snapshot_table_prefix"
#define SNAPSHOT_STATUS_PREFIX        "snapshot_status_prefix"
#define SNAPSHOT_COWBLOCK_PREFIX      "snapshot_cowblock_prefix"
#define SNAPSHOT_COWOBJECT_PREFIX     "snapshot_cowobject_prefix"

#endif
