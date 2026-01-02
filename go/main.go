package main

import (
	"io"
	"net/http"
	"os"
	"strings"
)

func main() {
	resp, _ := http.Get("https://cdn.jsdelivr.net/gh/lt25106/api@main/go/main.go")
	code, _ := io.ReadAll(resp.Body)
	template, _ := os.ReadFile("../template.html")
	templates := string(template)
	templates = strings.ReplaceAll(templates, "__CODE__", string(code))
	templates = strings.ReplaceAll(templates, "__LANGNAME__", "Go")
	templates = strings.ReplaceAll(templates, "__CLASSNAME__", "go")
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		w.Write([]byte(templates))
	})
	http.ListenAndServe(":3000", nil)
}
