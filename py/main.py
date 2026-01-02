import requests
response = requests.get("https://cdn.jsdelivr.net/gh/lt25106/api@main/py/main.py")

with open("../template.html", "r") as file:
  template = file.read()
template = template.replace("__CODE__", response.text)
template = template.replace("__LANGNAME__", "Python")
template = template.replace("__CLASSNAME__", "py")

from fastapi import FastAPI
from fastapi.responses import HTMLResponse
app = FastAPI()
@app.get("/", response_class=HTMLResponse)
def root():
  return template