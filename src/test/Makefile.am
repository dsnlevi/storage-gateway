noinst_PROGRAMS=test
AM_CPPFLAGS=-I$(top_srcdir)/src/dr_server -I$(top_srcdir)/src/rpc -std=c++11
test_LDFLAGS=-D_GNU_SOURCE
test_SOURCES=control_client.cpp 
test_LDADD=$(top_srcdir)/src/rpc/librpc.la
DEFS+=-D_GNU_SOURCE
LIBS=-lpthread -lprotobuf -lpthread -ldl -lgrpc -lgrpc++ -lboost_unit_test_framework
SUBDIRS=../dr_server
