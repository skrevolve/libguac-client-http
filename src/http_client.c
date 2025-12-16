#include <guacamole/client.h>
#include <guacamole/protocol.h>
#include <guacamole/socket.h>
#include <guacamole/user.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

const char* HTTP_ARGS[] = {
    "hostname",
    "port",
    "path",
    "ssl-enabled",
    "method",
    NULL
};

int http_join_handler(guac_user* user, int argc, char** argv);

int guac_client_init(guac_client* client) {
    client->args = HTTP_ARGS;
    client->join_handler = http_join_handler;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    // memory init
    return 0;
}

int http_join_handler(guac_user* user, int argc, char** argv) {
    guac_socket* socket = user->socket;

    guac_protocol_send_size(socket, GUAC_DEFAULT_LAYER, 1024, 768);
    guac_protocol_send_rect(socket, GUAC_DEFAULT_LAYER, 0, 0, 1024, 768);
    guac_protocol_send_cfill(socket, GUAC_COMP_OVER, GUAC_DEFAULT_LAYER, 0x80, 0x80, 0x80, 0xFF);
    guac_protocol_send_sync(socket, user->client->last_sent_timestamp, user->client->last_sent_timestamp);
    guac_socket_flush(socket);

    return 0;
}