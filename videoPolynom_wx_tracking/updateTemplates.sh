#!/bin/bash

rm -rf src/camModule
rm -rf src/classifiers
rm -rf src/imageView

cp -rv ../../templates/camModule src/
cp -rv ../../templates/classifiers src/
cp -rv ../../templates/imageView src/
