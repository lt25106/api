using System.Net.Http;
using System.IO;
var client = new HttpClient();
string code = await client.GetStringAsync(
  "https://cdn.jsdelivr.net/gh/lt25106/api@main/c#/Main.cs"
);
string template = await File.ReadAllTextAsync("../template.html");
Console.WriteLine(template);
var app = WebApplication.Create(args);
app.MapGet("/", () => {
  return "Hello C#";
});

app.Run();