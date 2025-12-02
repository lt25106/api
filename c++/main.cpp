#include <iostream>
#include <fstream>
#include <string>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "crow_all.h"
int main() {
  auto app = crow::SimpleApp();
  httplib::SSLClient cli("cdn.jsdelivr.net");
  auto res = cli.Get("/gh/lt25106/api@main/c%2B%2B/main.cpp");
  std::string code = (res && res->status == 200) ? res->body : "Failed to fetch source code.";
  code = std::regex_replace(code, std::regex("<"), "&lt;");
  code = std::regex_replace(code, std::regex(">"), "&gt;");
  std::ifstream f("/app/template.html");
  std::stringstream ss;
  ss << f.rdbuf();
  std::string resp = ss.str();
  std::cout << resp << '\n';
  resp = std::regex_replace(resp, std::regex("__LANGNAME__"), "C++");
  resp = std::regex_replace(resp, std::regex("__CLASSNAME__"), "cpp");
  resp = std::regex_replace(resp, std::regex("__CODE__"), code);
  CROW_ROUTE(app, "/")([&resp] {
    crow::response r;
    r.set_header("Content-Type", "text/html");
    r.write(resp);
    return r;
  });
  app.bindaddr("0.0.0.0").port(8000).multithreaded().run();
}
