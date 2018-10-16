#!/bin/bash
cd ../moduleA
make
cd ../moduleB
make
cd ..
make
export LD_LIBRARY_PATH=/home/xhp/xhp/myproject1/release
./main
