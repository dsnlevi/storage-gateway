noinst_PROGRAMS=dr_server
AM_CPPFLAGS=-I$(top_srcdir)/src -I$(top_srcdir)/src/include -std=c++11
ACLOCAL_AMFLAGS=-I m4
dr_server_SOURCES=dr_server.cc \
				  consumer_service.cc \
				  writer_service.cc \
				  ceph_s3_meta.cc \
				  ceph_s3_api.cc \
                  gc_task.cc \
				  ceph_s3_lease.cc \
				  replicate/replicate.cc \
				  replicate/rep_receiver.cc \
                  replicate/rep_client.cc

dr_server_LDADD=${top_srcdir}/src/rpc/librpc.la \
                 ${top_srcdir}/src/log/liblog.la \
                 ${top_srcdir}/src/snapshot/libsnapshot.la
dr_server_LDFLAGS=-D_GNU_SOURCE
DEFS+=-D_GNU_SOURCE -DBOOST_ALL_DYN_LINK
LDFLAGS="-L$(top_srcdir)/lib" "-L/usr/lib/x86_64-linux-gnu/"
LIBS=-lpthread -lprotobuf -lpthread -ldl -lgrpc -lgrpc++ -ls3 -lboost_system \
     -lboost_log_setup -lboost_log -lboost_date_time -lboost_thread \
     -lboost_filesystem
SUBDIRS=../rpc 
