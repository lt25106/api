#include <iostream>
#include "crow_all.h"
int main() {
  auto app = crow::SimpleApp();
  CROW_ROUTE(app, "/")([] {
    return "<h1>What</h1>";
  });
  app.port(6767).multithreaded().run();
}
