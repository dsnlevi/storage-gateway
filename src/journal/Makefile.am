noinst_PROGRAMS=sg_client
AM_CPPFLAGS=-I$(top_srcdir)/src -I$(top_srcdir)/src/include -std=c++11
ACLOCAL_AMFLAGS=-I m4
sg_client_SOURCES=$(top_srcdir)/src/common/crc32.c \
                       $(top_srcdir)/src/common/xxhash.c \
                       $(top_srcdir)/src/common/utils.cpp \
                       $(top_srcdir)/src/dr_server/ceph_s3_lease.cc \
                       $(top_srcdir)/src/dr_server/ceph_s3_api.cc   \
                       control_service.cpp  \
                       connection.cpp       \
                       io_service_pool.cpp  \
                       seq_generator.cpp    \
                       journal_entry.cpp    \
                       journal_writer.cpp   \
                       journal_replayer.cpp \
                       journal_reader.cpp   \ 
                       pre_processor.cpp    \
                       volume_manager.cpp   \
                       server.cpp           \
                       main.cpp  
  
sg_client_LDADD=${top_srcdir}/src/rpc/librpc.la \
                     ${top_srcdir}/src/log/liblog.la \
                     $(top_srcdir)/src/journal/cache/libcache.la \
                     $(top_srcdir)/src/snapshot/libsnapshot.la

sg_client_LDFLAGS=-D_GNU_SOURCE
DEFS+=-D_GNU_SOURCE -DBOOST_ALL_DYN_LINK -DNDEBUG
LDFLAGS="-L$(top_srcdir)/lib"
LIBS=-lpthread -lprotobuf -lgrpc -lgrpc++ -ls3 \
     -lboost_system -lboost_log_setup -lboost_log \ 
     -lboost_date_time -lboost_thread -lboost_filesystem

SUBDIRS=../rpc
SUBDIRS=cache

