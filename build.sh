#!/bin/bash

# Check if building for Raspberry Pi
if [ -f /etc/rpi-issue ]
then
  installArgs="-DRPI_BUILD=true"
else
  installArgs=""
fi

# Compile/install libraries first
# AASDK
pushd ./libs/aasdk > /dev/null
mkdir -p build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
sudo make install
popd > /dev/null

# OpenAuto
pushd ./libs/openauto > /dev/null
mkdir -p build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Release ${installArgs} -DGST_BUILD=true ..
make -j$(nproc)
sudo make install
popd > /dev/null

# QtApng
pushd ./libs/QtApng > /dev/null
git apply ../QtApng.patch
qmake
make sub-src-all -j$(nproc)
sudo make install
popd > /dev/null

# Build module
mkdir -p build
cd build
cmake ..
make -j$(nproc)