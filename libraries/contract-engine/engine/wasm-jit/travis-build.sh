#!/bin/sh

set -e -v

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
export LLVM_DIR=~/llvm/llvm-compiler/llvm/build/lib/cmake

# Build and test a debug build of WAVM.

if [ ! -d "debug" ]; then
mkdir debug
fi

cd debug
cmake .. -DCMAKE_BUILD_TYPE=DEBUG -DLLVM_DIR=${LLVM_DIR}
make
ASAN_OPTIONS=detect_leaks=0 ctest -V
cd ..
