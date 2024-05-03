# BerkeleyDBtest
Self contained test to demonstrate BerkeleyDB bug on FreeBSD arm64

Build on a system that has BerkelyDB  libraries installed.

## Building
The distribution tarball contains the file `configure` already
built. When building from the git source, you have to run the
following command first to build configure and all of its supporting
files. This requires that you have Gnu autotools installed on your
system.

```
autoreconf --install
```

Once configure exists, the steps to build the program and run the test
are

```
./configure
make
make check
```

`configure` will search for the latest version of BerkeleyDB installed on the
system, allowing for mutliple versions having been installed. You can
specify the version to use, which will be much faster. For example if
you know that you want to use version 18.1, when you call configure use
the command

```
./configure --with-dbm=db181
```

The `make check` command runs the bdbtest executable twice. The first
time creates BerkeleyDB  shared memory region files for an
environment. Running it the second  time should open those files for
reuse. Instead on FreeBSD arm64 it gets an error trying to lock a
pthread mutex.
