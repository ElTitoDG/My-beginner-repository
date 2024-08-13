const http = require('node:http')

const targetPort = process.env.PORT ?? 1234

const processReq = (req, res) => {
  if (req.url === '/') {
    res.statusCode = 200
    res.setHeader('Content-type', 'text/plain')
    res.end('Hola Mundo')
  }
}

const server = http.createServer(processReq)

server.listen(targetPort, () => {
  console.log(`server listening on port http://localhost:${targetPort}`)
})
