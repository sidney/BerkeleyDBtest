# BerkeleyDBtest
Self contained test to demonstrate BerkeleyDB bug on FreeBSD arm64

Build on a system that has BerkelyDB 18 libraries installed.

## Building
```text
autoreconf --install
./configure
make
```

Running the bdbtest executable the first time creates BerkeleyDB
shared memory region files for an environment. Running it a second
time should open those files for reuse. Instead on FreeBSD arm64 it
gets an error trying to lock a pthread mutex.
