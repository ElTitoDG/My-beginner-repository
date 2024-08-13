const http = require('node:http')
const { findAvaliblePort } = require('./10.free-port.js')

const targetPort = process.env.PORT ?? 3000

const server = http.createServer((req, res) => {
  console.log('request recived')
  res.end('Hola Mundo')
})

findAvaliblePort(targetPort).then(port => {
  server.listen(port, () => {
    console.log(`server listening on port http://localhost:${port}`)
  })
})
