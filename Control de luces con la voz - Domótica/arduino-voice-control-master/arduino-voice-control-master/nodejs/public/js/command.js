var cmd = [{keys:['encenderledrojo','encenderrojo','activarrojo','rojo'],value:1},
{keys:['apagarledrojo','apagarrojo','desactivarrojo'],value:2},
{keys:['encenderledverde','encenderverde','activarverde','verde'],value:3},
{keys:['apagarledverde','apagarverde','desactivarverde'],value:4},
{keys:['encendertodo','encendertodoslosleds','activarleds','activartodos'],value:5},
{keys:['apagartodo','apagartodoslosleds','desactivarleds','desactivartodos'],value:6}];
function command(){
	function deleteSpace(txt){
		var t = '';
		for (var i in txt){
			if(txt[i] != ' '){
				t = t+txt[i];
			}
		}
		return(t);
	}
	return{
		analize:function(txt){
			var def = 7;
			var ntxt = deleteSpace(txt);
			ntxt = ntxt.toLowerCase();
			console.log(ntxt);
				for(var i in cmd){
				    for(var x in cmd[i].keys){
				      if(ntxt == cmd[i].keys[x]){
				      	console.log('ok');
				        return(cmd[i].value);
				      }
				    }
			  }
		  	return(def);
			}
	}
}