noinst_PROGRAMS=journal_server
AM_CPPFLAGS=-I$(top_srcdir)/src -I$(top_srcdir)/src/include -std=c++11
ACLOCAL_AMFLAGS=-I m4
journal_server_SOURCES=connection.cpp  io_service_pool.cpp  journal_writer.cpp  main.cpp  pre_processor.cpp  request_handler.cpp  server.cpp  volume_manager.cpp \
                    $(top_srcdir)/src/common/crc32.c $(top_srcdir)/src/common/xxhash.c $(top_srcdir)/src/common/utils.cpp
journal_server_LDADD=${top_srcdir}/src/rpc/librpc.la ${top_srcdir}/src/log/liblog.la
journal_server_LDFLAGS=-D_GNU_SOURCE
DEFS+=-D_GNU_SOURCE -DBOOST_ALL_DYN_LINK -DNDEBUG
LDFLAGS="-L$(top_srcdir)/lib"
LIBS=-lpthread -lprotobuf -lgrpc -lgrpc++ -ls3 -lboost_system -lboost_log_setup -lboost_log -lboost_date_time -lboost_thread -lboost_filesystem
SUBDIRS=../rpc