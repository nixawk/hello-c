#!/bin/sh

# autoscan
autoreconf --install
mkdir build && cd build
../configure
make

# https://stackoverflow.com/questions/2531827/what-are-makefile-am-and-makefile-in