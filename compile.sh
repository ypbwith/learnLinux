#!/bin/sh

cd build 

#rm -rf ./*
#make clean

#cmake -DCMAKE_TOOLCHAIN_FILE=~./cross.cmake ..
cmake ..

make -j4

make install

cp -r  ./install/bin/learnLinux  ../bin
cp -r  ../log/log.conf  ../bin

#nm -D ./install/lib/*.so >> So.txt

cd -




