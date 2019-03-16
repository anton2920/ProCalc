AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = ProCalc

ProCalc_SOURCES = main.cpp
ProCalc_LDADD = libpolynom.la libcombinatorics.la libbigint.la libterver.la
ProCalc_LDFLAGS = -lm -lSDL2

include_HEADERS = headers/*

lib_LTLIBRARIES = libpolynom.la
libpolynom_la_LDFLAGS = -version-info 0:0:0
libpolynom_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp

lib_LTLIBRARIES = libcombinatorics.la
libcombinatorics_la_LDFLAGS = -version-info 0:0:0
libcombinatorics_la_SOURCES = libs/Combinatorics.cpp

lib_LTLIBRARIES = libbigint.la
libbigint_la_LDFLAGS = -version-info 0:0:0
libbigint_la_SOURCES = libs/bigint.cpp 

lib_LTLIBRARIES = libterver.la
libterver_la_LDFLAGS = -version-info 0:0:0
libterver_la_SOURCES = libs/func.ter.ver.cpp

lib_LTLIBRARIES = libpolynom.la
libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h

lib_LTLIBRARIES = libpolynom.la
libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h

lib_LTLIBRARIES = libpolynom.la
libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h
