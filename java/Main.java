import com.sun.net.httpserver.HttpServer;
// import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.net.URI;

public class Main {
  public static void main(String[] args) throws IOException, Exception {
    HttpClient client = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
      .uri(URI.create("https://cdn.jsdelivr.net/gh/lt25106/api@main/java/Main.java"))
      .GET()
      .build();
    HttpResponse<String> response = client.send(
      request,
      HttpResponse.BodyHandlers.ofString()
    );

    Path templatepath = Paths.get("../template.html");
    String template = Files.readString(templatepath)
      .replace("__CODE__", response.body())
      .replace("__LANGNAME__", "Java")
      .replace("__CLASSNAME__", "java");

    HttpServer server = HttpServer.create(
      new InetSocketAddress(8080),
      0
    );

    server.createContext("/", exchange -> {
      exchange.sendResponseHeaders(200, template.getBytes().length);

      try (OutputStream os = exchange.getResponseBody()) {
        os.write(template.getBytes());
      };
    });

    server.start();

    System.out.println("http://localhost:8080");
  }
}
