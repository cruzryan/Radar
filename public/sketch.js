var socket;

function setup(){
    createCanvas(200,200);
    background(51);

    socket = io.connect('http://localhost:3000');
   
}

function drawIt(data){
    console.log(data);
}

function draw(){
   /*
       */

    socket.on('arduinoData', drawIt);  
    ellipse(mouseX, mouseY, 60, 60);

}