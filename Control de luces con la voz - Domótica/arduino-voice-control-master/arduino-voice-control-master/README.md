# arduino-voice-control

<h2>Archivos a modificar</h2>
<ul>
  <li>nodejs/index.js</li>
</ul>
<p>
  Cambiar el valor de la variable port por el numero de puerto que desea que inicie la app (por defecto este valor es 8080).<br>
  <code>var port = process.env.PORT || 8080;</code>
  <br>
  Cambiar el puerto serial de la computadora al que esta conectado tu arduino (puerto por defecto "COM5"), en caso de no saber a que puerto esta conectado puedes verificaren el arduino IDE en la pestaña: herramintas > puerto.
  <br>
  <code>
    var usb_port = new SerialPort('COM5', {
      baudRate: 9600
    });
  </code>
  <br>
  Solo configurando esos 2 parametros (port es opcional) ya se puede encender o apagar leds.
  
  <h2>Agregando nuevos comandos</h2>
  encender y apagar leds mediante comandos de voz esta bien pero... 
  <br>
  ¿que tal si queremos hacer mas?
  <br>
  puedes modificar el archivo: nodejs/public/js/command.js
  <br>
  existe un array llamado cmd, que contiene diferentes objetos json cada uno con la siguiente estructura:
  <br>
  <code>
  {keys:['comando'],value:0}
  </code>
  <br>
  <b>keys</b> contiene un array con las palabras o frases que se usan como comandos (sin espacios y en minuscula ejemplo: "holamundo").
  <br>
  <b>value</b>contiene un numero que sera el que interprete arduino.
  <br>
  <code>
  var cmd = [{keys:['encenderledrojo','encenderrojo','activarrojo','rojo'],value:1},
{keys:['apagarledrojo','apagarrojo','desactivarrojo'],value:2},
{keys:['encenderledverde','encenderverde','activarverde','verde'],value:3},
{keys:['apagarledverde','apagarverde','desactivarverde'],value:4},
{keys:['encendertodo','encendertodoslosleds','activarleds','activartodos'],value:5},
{keys:['apagartodo','apagartodoslosleds','desactivarleds','desactivartodos'],value:6}];
  </code>
  <br>
  si agregas un nuevo comando con <code>value:7</code> por ejemplo, entonces solo necesitaras agregar un nuevo if en el codigo de arduino.
  <br>
  <code>
  else if(data == 7 || data == '7'){
      // mi codigo
    }
  </code>
</p>
