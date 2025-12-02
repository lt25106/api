import express from 'express'
import fs from 'fs'
const app = express()
let template = fs.readFileSync('../template.html', 'utf-8')
const code = await fetch("https://cdn.jsdelivr.net")
template = template.replaceAll("__CODE__", code)
template = template.replaceAll("__LANGNAME__", "JavaScript")
template = template.replaceAll("__CLASSNAME__", "js")
app.get("/", (req, res) => {
  res.send(template)
})
app.listen(3000, () => {})