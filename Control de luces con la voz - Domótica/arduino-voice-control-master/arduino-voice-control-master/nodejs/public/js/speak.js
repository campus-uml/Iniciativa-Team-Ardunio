var palabras = ['Con mucho gusto','ok','Claro','A la orden','En seguida','Por supuesto','Listo!','Usted manda'];
var ne = new SpeechSynthesisUtterance('¿puede repetirlo, por favor?')
var speechSynthesisUtterance = [];
for (var i in palabras) {
	speechSynthesisUtterance.push({s:new SpeechSynthesisUtterance(palabras[i])});
}
function habla(code){
	if(code != 7){
		window.speechSynthesis.speak(speechSynthesisUtterance[Math.floor((Math.random() * 8))].s);
	}
	else{
		window.speechSynthesis.speak(ne);
	}
}