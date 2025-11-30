#include <iostream>
#include <string>
#include <format>
#include <filesystem>
#include "crow_all.h"
int main() {
  auto app = crow::SimpleApp();
  CROW_ROUTE(app, "/")([] {
    crow::response r;
    r.set_header("Content-Type", "text/html");
    r.write(std::format(R"(
    <html>
      <head>
        <style>
          * {
            background-color: black;
            color: white;
            font-family: sans-serif;
          }
          body {
            margin: auto;
          }
          a {
            color: cyan;
          }
        </style>
      </head>
      <body>
        <h1>C++ Website</h1>
        <a href="https://github.com/lt25106/api">https://github.com/lt25106/api</a>

      </body>
    </html>
    )"));
    return r;
  });
  app.bindaddr("0.0.0.0").port(8000).multithreaded().run();
}
