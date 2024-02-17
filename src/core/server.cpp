//
// Created by Tevz on 9. 02. 24.
//

#include <SPIFFS.h>
#include "core/server.hpp"
#include "core/util.hpp"
#include "core/image_loader.hpp"

WebServer server(80);

void deliver_file(const char* file_path, const char* mime_type);
void file_handler();
void handle_default();
void handle_not_found();

void init_server() {
    // actions
    GET_PATH_WITH_ACTION("/", handle_default());
    GET_PATH_WITH_ACTION("/pfp", load_image("/pfp.img"); handle_default());
    GET_PATH_WITH_ACTION("/desk", load_image("/desk.img"); handle_default());

    // public files
    PUBLIC_FILE("/index.html");
    PUBLIC_FILE("/main.css");

    // 404
    server.onNotFound(handle_not_found);
    server.begin();
}

void deliver_file(const char* file_path, const char* mime_type) {
    File file = SPIFFS.open(file_path, "r");

    if (!file) {
        server.send(404, "text/plain", "404: Not Found");
        return;
    }

    server.streamFile(file, mime_type);
}

void file_handler() {
    String path = server.uri();

    if (path.endsWith(".css"))
        deliver_file(path.c_str(), "text/css");
    else if (path.endsWith(".html"))
        deliver_file(path.c_str(), "text/html");
    else if (path.endsWith(".js"))
        deliver_file(path.c_str(), "application/javascript");
    else if (path.endsWith(".png"))
        deliver_file(path.c_str(), "image/png");
    else if (path.endsWith(".jpg"))
        deliver_file(path.c_str(), "image/jpeg");
    else
        server.send(404, "text/plain", "404: Not Found");
}

void handle_default()
{
    String page = "";
    File index = SPIFFS.open("/index.html");

    if(!index)
    {
        server.send(500, "text/plain", "Woops theng not worki");
        return;
    }

    while(index.available()){
        page += (char)index.read();
    }

    server.send(200, "text/html", page.c_str());
}



void handle_not_found() {
    server.send(404, "text/plain", "Not found bruh");
}