var express = require('express');
var app = express();

var server = app.listen(3000);

app.use(express.static('public'));

console.log("Socket server...")

var socket = require('socket.io');

var io = socket(server);

io.sockets.on('connection', newConnection);

var data = {
    yeah: "alright"
}

function newConnection(socket){
    //console.log(socket);
    socket.emit('arduinoData', data);
}
var SerialPort = require('serialport');
/*var port = new SerialPort('\\\\.\\COM3', {baudRate: 9600}, true, function(err){
    if (err) {
        return console.log('Error: ', err.message);
      }
});*/
var port = new SerialPort('COM3',  {baudRate: 9600}, function (err) {
  if (err) {
    return console.log('Error: ', err.message);
  }
});



    port.on('data', function (AD) {
        console.log('Data:', AD);
      });
    
