#include "../include/aplicaciones.h"
#include "../include/colaDePrioridadPersona.h"
void listarEnOrden(TTablaPersonas t, char** nombres, nat n){
	
	TColaDePrioridadPersona cola=crearCP(MAX_ID);
	for(nat j=0;j<n;j++){
		if (perteneceATTablaPersonas(t,nombres[j])){
			TPersona aInsertar=obtenerPersonaDeTTablaPersonas(t,nombres[j]);
			//nat id=idTPersona(aInsertar);
			//if((1<=id && id<=n) && !estaEnCP(id,cola)){
				insertarEnCP(copiarTPersona(aInsertar),cola);
				}
			//}
		}
	
	
	while (!estaVaciaCP(cola)){
		TPersona aux=prioritaria(cola);
		imprimirTPersona(aux);
		eliminarPrioritaria(cola);
		}
	liberarCP(cola);		
}
