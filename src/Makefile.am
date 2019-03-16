AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = ProCalc

ProCalc_SOURCES = main.cpp
ProCalc_LDADD = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la
ProCalc_LDFLAGS = -lm -lSDL2

include_HEADERS = headers/*

lib_LTLIBRARIES = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la

# libmainmenu.la
libmainmenu_la_LDFLAGS = -version-info 0:0:0
libmainmenu_la_SOURCES = libs/main_menu.cpp

# libpolynom.la
libpolynom_la_LDFLAGS = -version-info 0:0:0
libpolynom_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp

# libcombinatorics.la
libcombinatorics_la_LDFLAGS = -version-info 0:0:0
libcombinatorics_la_SOURCES = libs/Combinatorics.cpp libs/Combinatorics_menu.cpp

# libbigint.la
libbigint_la_LDFLAGS = -version-info 0:0:0
libbigint_la_SOURCES = libs/bigint.cpp 

# libterver.la
libterver_la_LDFLAGS = -version-info 0:0:0
libterver_la_SOURCES = libs/func.ter.ver.cpp libs/ter.ver.menu.cpp


libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h


libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h


libHelloWorld_la_LDFLAGS = -version-info 0:0:0
libHelloWorld_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp headers/polynom.h
