#include <iostream>
#include "crow_all.h"
int main() {
  auto app = crow::SimpleApp();
  CROW_ROUTE(app, "/")([] {
    return "<h1>What</h1>";
  });
  app.bindaddr("0.0.0.0").port(8000).multithreaded().run();
}
