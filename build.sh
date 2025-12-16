#!/bin bash

sudo apt update
sudo apt install build-essential libtool automake autoconf pkg-config libcurl4-openssl-dev

autoreconf -fi
./configure

make

sudo make install
sudo ldconfig