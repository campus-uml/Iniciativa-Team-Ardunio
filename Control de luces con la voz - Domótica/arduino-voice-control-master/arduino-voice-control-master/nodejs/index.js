var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var SerialPort = require('serialport');
var io = require('socket.io')(server);
var port = process.env.PORT || 8080;
var usb_port = new SerialPort('COM5', {
  baudRate: 9600
});
app.use(express.static('public'));
var control = 0;
var tiempo;

app.get('/home', function(req, res) {
  res.sendFile('public/index.html' , { root : __dirname});
});



io.on('connection', function(socket) {
  console.log('Alguien se ha conectado con Sockets');

  // obtener todos los registros
  socket.on('led', function(data) {
  	console.log(data);
    usb_port.write(''+data, errorPort);
  });
});


function errorPort(err){
	if (err) {
	    return console.log('Error on write: ', err.message);
	  }
}
server.listen(port, function() {
	console.log('Servidor corriendo en http://localhost:8080');
});
