var socket = io.connect('http://localhost:8080', { 'forceNew': true });
annyang.setLanguage('es-NI');
var vc = new command();

annyang.addCallback('result', function(txt) {
  var r = vc.analize(txt[0]);
  asignarColor(r);
  socket.emit('led',r);
});
annyang.addCallback('errorNetwork', function() {
  alert('error');
});


annyang.start({ autoRestart: true, continuous: true });