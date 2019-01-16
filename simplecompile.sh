#!/bin/bash

# To more easily compile and run this program on CSS Linux Lab
# Lines starting with '$' indicate what is typed on command line

# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1


date

echo "*** Compiling"
g++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram.exe

echo "*** cpplint"
cpplint *.cpp *.h

echo "*** cppcheck"
# CSS Linux lab has cppcheck version 1.72 which only has c++11, removing --std=c++14
cppcheck --enable=all --force --inconclusive --language=c++ --suppress=missingIncludeSystem *.cpp *.h

echo "*** running"
./myprogram.exe

echo "*** running with valgrind"
valgrind ./myprogram.exe

echo "*** cleaning up"
rm myprogram.exe

date

