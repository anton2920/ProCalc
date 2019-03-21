AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = ProCalc

ProCalc_SOURCES = main.cpp
ProCalc_LDADD = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la libfraction.la libmatrix.la
ProCalc_LDFLAGS =

include_HEADERS = headers/header.h

lib_LTLIBRARIES = libmainmenu.la libpolynom.la libcombinatorics.la libbigint.la libterver.la libfraction.la libmatrix.la

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

# libfraction.la
libfraction_la_LDFLAGS = -version-info 0:0:0
libfraction_la_SOURCES = libs/fraction.cpp libs/fraction_menu.cpp

# libmatrix.la
libmatrix_la_LDFLAGS = -version-info 0:0:0
libmatrix_la_SOURCES = libs/matrix.cpp libs/matrix_main.cpp