# libguac-client-http

```commandline
/guac-client-http
├── configure.ac  # build configure
├── Makefile.am   # compile configure
└── src
    └── http_client.c  # HTTP Protocol
```

### install
```shell
sudo apt update
sudo apt install build-essential libtool automake autoconf pkg-config libcurl4-openssl-dev
```

### build
```shell
autoreconf -fi
./configure
make
sudo make install
sudo ldconfig
```