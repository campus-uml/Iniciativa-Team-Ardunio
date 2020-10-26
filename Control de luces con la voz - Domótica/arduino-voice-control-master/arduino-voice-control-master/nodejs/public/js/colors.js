var rojo = document.getElementById('rojo');
var verde = document.getElementById('verde');
function asignarColor(code){
	habla(code);
	if(code == 1){
		rojo.style.backgroundColor = '#CC3333';
	}
	else if(code == 2){
		rojo.style.backgroundColor = '#666666';
	}
	else if(code == 3){
		verde.style.backgroundColor = '#33CC66';
	}
	else if(code == 4){
		verde.style.backgroundColor = '#666666';
	}
	else if(code == 5){
		rojo.style.backgroundColor = '#CC3333';
		verde.style.backgroundColor = '#33CC66';
	}
	else if(code == 6){
		rojo.style.backgroundColor = '#666666';
		verde.style.backgroundColor = '#666666';
	}
}