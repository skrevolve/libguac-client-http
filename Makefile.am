AUTOMAKE_OPTIONS = foreign
# ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -Werror -Wall -pedantic

# libguac-client-http.la (plugin for guacd)
lib_LTLIBRARIES = libguac-client-http.la

libguac_client_http_la_SOURCES = src/http_client.c

libguac_client_http_la_LDFLAGS = \
    -version-info 0:0:0 \
    -lguac \
    -lcurl # add libcurl link
