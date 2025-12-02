import express from 'express'
import fs from 'fs'
const app = express()
let template = fs.readFileSync('../template.html', 'utf-8')
const code = await fetch("https://cdn.jsdelivr.net/gh/lt25106/api@main/js/index.js")
template = template.replaceAll("__CODE__", await code.text())
template = template.replaceAll("__LANGNAME__", "JavaScript")
template = template.replaceAll("__CLASSNAME__", "js")
app.get("/", (req, res) => {
  res.send(template)
})
app.listen(3000, () => {
  console.log("http://localhost:3000")
})