// WORK IN PROGRESS

#[macro_use] extern crate rocket;
use rocket::respose::content::RawHtml;

#[get("/")]
fn index() -> RawHtml<&'static str> {
  RawHtml(r#"
    <!DOCTYPE html>
    <html>
    <head><title>Hello</title></head>
    <body>
      <h1>Hello, world!</h1>
    </body>
    </html>
  "#)
}

#[launch]
fn rocket() -> _ {
  rocket::build()
  .mount("/", routes![index])
}