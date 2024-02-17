//
// Created by Tevz on 9. 02. 24.
//

#ifndef BORED_PROGRAMING_SERVER_HPP
#define BORED_PROGRAMING_SERVER_HPP

#include <WebServer.h>

// TODO: spawn thread for action and just call the handler
#define GET_PATH_WITH_ACTION(_path, _action) LOG(_path) server.on(_path, HTTP_GET, []() { _action; });
#define POST_PATH_WITH_ACTION(_path, _action) LOG(_path) server.on(_path, HTTP_POST, []() { _action; });
#define PUBLIC_FILE(_path_to_file) LOG(_path_to_file) server.on(_path_to_file, HTTP_GET, file_handler);

extern WebServer server;

void init_server();

#endif //BORED_PROGRAMING_SERVER_HPP
