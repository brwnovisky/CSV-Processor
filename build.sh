#!/bin/sh

#Info: Bash Script to build a C++ shared library (.so) on a Alpine docker container

# Update container environment
apk update
apk upgrade --no-cache

# Install compiler dependencies from C++ to C interface
apk add --no-cache git
apk add --no-cache make
apk add --no-cache cmake
apk add --no-cache g++ gcc
apk add --no-cache libc-dev libstdc++ libgcc

# Install GoogleTest
git clone https://github.com/google/googletest.git -b v1.14.0
cd googletest
mkdir build
cd build
cmake ..
make
make install
cd ../..
rm -rf googletest/

# Build the shared library in a clean way using a Makefile
make re

# Stop docker build if the shared library building fail
if [ ! -f /app/libcsv.so ]; then
	echo "Error: Could not find libcsv.so. Build failed."
	exit 1
fi

# Run tests
make test

# Get exit code from Make test process
EXIT_CODE=$?

# Stop docker building if the tests fail
if [[ $EXIT_CODE -ne 0 ]]; then
	echo "Error: FAILED TESTS on Gtest."
	exit $EXIT_CODE
fi
