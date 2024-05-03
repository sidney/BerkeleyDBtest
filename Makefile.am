AM_CPPFLAGS = \
    -I$(top_srcdir) \
    -I$(top_srcdir)/src

bin_PROGRAMS = bdbtest
CLEANFILES = __db.001 __db.002 __db.003 __db.004 __db.005 __db.006 bdbtest-1.0.tar.gz test-suite.log tests/test1.sh.log tests/tests1.sh.trs
BUILT_SOURCES =

bin_PROGRAMS += bdbtest

bdbtest_SOURCES = $(top_srcdir)/src/bdbtest.c

check_SCRIPTS=tests/test1.sh
TESTS=tests/test1.sh

EXTRA_DIST = \
    README.md \
    LICENSE \
    $(check_SCRIPTS)
