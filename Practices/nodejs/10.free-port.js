const net = require('node:net')

function findAvaliblePort (targetPort) {
  return new Promise((resolve, reject) => {
    const server = net.createServer()

    server.listen(targetPort, () => {
      const { port } = server.address()
      server.close(() => {
        resolve(port)
      })
    })

    server.on('error', (err) => {
      if (err.code === 'EADDRIUSE') {
        findAvaliblePort(0).then(port => resolve(port))
      } else
        reject(err)
    })
  })
}

module.exports = { findAvaliblePort }
