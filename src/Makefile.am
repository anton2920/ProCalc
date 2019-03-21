AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = ProCalc

ProCalc_SOURCES = main.cpp
ProCalc_CPPFLAGS = $(CPPFLAGS) -Wall -Wextra -std=c++11
ProCalc_LDADD = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la libfraction.la libmatrix.la libfuncs.la
ProCalc_LDFLAGS =

include_HEADERS = headers/header.h headers/config.h headers/fraction.h headers/Combinatorics.h headers/polynom.h headers/TeoriaVer.h headers/bigint.h headers/matrix.h headers/derivative.h headers/func_menu.h headers/graph.h headers/input.h headers/integral.h headers/root.h

lib_LTLIBRARIES = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la libfraction.la libmatrix.la libfuncs.la

# libmainmenu.la
libmainmenu_la_LDFLAGS = -version-info 0:0:0
libmainmenu_la_SOURCES = libs/main_menu.cpp
libmainmenu_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libpolynom.la
libpolynom_la_LDFLAGS = -version-info 0:0:0
libpolynom_la_SOURCES = libs/polynom.lib.cpp libs/polynom.main.cpp
libpolynom_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libcombinatorics.la
libcombinatorics_la_LDFLAGS = -version-info 0:0:0
libcombinatorics_la_SOURCES = libs/Combinatorics.cpp libs/Combinatorics_menu.cpp
libcombinatorics_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libbigint.la
libbigint_la_LDFLAGS = -version-info 0:0:0
libbigint_la_SOURCES = libs/bigint.cpp 
libbigint_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libterver.la
libterver_la_LDFLAGS = -version-info 0:0:0
libterver_la_SOURCES = libs/func.ter.ver.cpp libs/ter.ver.menu.cpp
libterver_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libfraction.la
libfraction_la_LDFLAGS = -version-info 0:0:0
libfraction_la_SOURCES = libs/fraction.cpp libs/fraction_menu.cpp
libfraction_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libmatrix.la
libmatrix_la_LDFLAGS = -version-info 0:0:0
libmatrix_la_SOURCES = libs/matrix.cpp libs/matrix_main.cpp
libmatrix_la_CPPFLAGS = $(ProCalc_CPPFLAGS)

# libfuncs.la
libfuncs_la_LDFLAGS = -version-info 0:0:0
libfuncs_la_SOURCES = libs/func_menu.cpp libs/graph.cpp libs/input.cpp libs/integral.cpp libs/root.cpp
libfuncs_la_CPPFLAGS = $(ProCalc_CPPFLAGS)