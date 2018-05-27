#!/bin/sh

set -e -v


export LLVM_DIR=~/llvm/llvm-compiler/llvm/build/lib/cmake

# Build and test a debug build of WAVM.
mkdir debug
cd debug
cmake .. -DCMAKE_BUILD_TYPE=DEBUG -DLLVM_DIR=${LLVM_DIR}
make
ASAN_OPTIONS=detect_leaks=0 ctest -V
cd ..
