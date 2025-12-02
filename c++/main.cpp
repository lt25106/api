#include <iostream>
#include <fstream>
#include <string>
#include <format>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "crow_all.h"
int main() {
  auto app = crow::SimpleApp();
  CROW_ROUTE(app, "/")([] {
    httplib::SSLClient cli("cdn.jsdelivr.net");
    auto res = cli.Get("/gh/lt25106/api@main/c%2B%2B/main.cpp");
    std::string code = (res && res->status == 200) ? res->body : "Failed to fetch source code.";
    code = std::regex_replace(code, std::regex("<"), "&lt;");
    code = std::regex_replace(code, std::regex(">"), "&gt;");
    std::ifstream f("template.html");
    std::stringstream ss;
    ss << f.rdbuf();
    std::string resp = ss.str();
    std::cout << resp << '\n';
    resp.replace(resp.find("__CODE__"), sizeof("__CODE__") - 1, code);
    resp.replace(resp.find("__LANGNAME__"), sizeof("__LANGNAME__") - 1, "C++");
    resp.replace(resp.find("__CLASSNAME__"), sizeof("__CLASSNAME__") - 1, "cpp");
    crow::response r;
    r.set_header("Content-Type", "text/html");
    r.write(resp);
    return r;
  });
  app.bindaddr("0.0.0.0").port(8000).multithreaded().run();
}
