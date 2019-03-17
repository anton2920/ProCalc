# Autoconf requirements

# Initialize, but use more options. Note parameters brackts and whitespace.
AC_INIT([ProCalc], [1.0], [anton2920@gmail.com])

# Safety check - list a source file that wouldn't be in other directories:
AC_CONFIG_SRCDIR([src/main.cpp])

# Put configuration results here, so we can easily #include them:
AC_CONFIG_HEADERS([src/headers/config.h])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir:
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Enable «automake» to simplify creating makefiles:
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile man/Makefile examples/Makefile])

# Look for a C (CXX) compiler:
AC_LANG([C++])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX

# Check for: (more) programs, libraries, header files, types,
# structures, compiler characteristics, library functions, system services.
LT_INIT

AC_ENABLE_SHARED
AC_PROG_LIBTOOL

# Check for SDL2
AC_SEARCH_LIBS([SDL_Init], [SDL SDL2], [], [
AC_MSG_WARN([without SDL ProCalc is not able to plot a graph])
	])
 
AC_SEARCH_LIBS([sin], [m], [], [
	AC_MSG_ERROR([unable to find math lib])
	])

AC_CHECK_HEADERS([cmath iostream string], [], [
	AC_MSG_ERROR([unable to find necessary headers])
	])

AC_CHECK_HEADERS([SDL2/SDL.h], [], [],
[#ifdef HAVE_SDL2_SDL_H
#include <SDL2/SDL.h>
endif
])

AC_CHECK_HEADERS([SDL/SDL.h], [], [],
[#ifdef HAVE_SDL_SDL_H
#include <SDL/SDL.h>
endif
])

AC_CHECK_HEADERS([SDL.h], [], [],
[#ifdef HAVE_SDL_H
#include <SDL.h>
#endif
])

 # Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Do final output.
AC_OUTPUT
