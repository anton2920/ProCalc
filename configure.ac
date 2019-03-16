# Autoconf requirements

# Initialize, but use more options. Note parameters brackts and whitespace.
AC_INIT([ProCalc], [1.0], [anton2920@gmail.com])

# Safety check - list a source file that wouldn't be in other directories:
AC_CONFIG_SRCDIR([src/main.cpp])

# Put configuration results here, so we can easily #include them:
AC_CONFIG_HEADERS([config.h])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir:
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Enable «automake» to simplify creating makefiles:
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])

# Look for a C compiler:
AC_LANG([C++])
AC_PROG_CXX

# Perhaps check for: (more) programs, libraries, header files, types,
# structures, compiler characteristics, library functions, system services.
LT_INIT
AC_ENABLE_SHARED
AC_PROG_LIBTOOL(libtool)

AC_SEARCH_LIBS([SDL_Init], [SDL SDL2], [], [
  AC_MSG_ERROR([unable to find SDL lib])
  ])

AC_SEARCH_LIBS([sin], [m], [], [
  AC_MSG_ERROR([unable to find math lib])
  ])

 AC_CHECK_HEADERS([cmath iostream SDL2/SDL.h string], [], [
  AC_MSG_ERROR([unable to find necessary headers])
  ])

 # Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Do final output.
AC_OUTPUT
