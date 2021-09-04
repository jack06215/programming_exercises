#include <iostream>
#include "../http.hpp"

void Root(Request* req) {
    req->Respond(200, "<b style=\"font-size: 50px\">Hello World!</b>");
}

void Post(Request* req) {
    std::cout << req->Body << "\n";

    req->Respond(200, "Something");
}

int main() {
  Server server = Server();

  server.Get("/", Root);

  server.Post("/post", Post);

  server.Start(4001);

  // If the main function returns the entire program exits.
  while (server.Running);
}
