#!/bin/bash

rm -rf build
mkdir build
cp -rv src/gui/ico build

cd build
cmake ..
