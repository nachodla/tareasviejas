#include "../include/tablaPersonas.h"


struct rep_tablaPersonas {
	TPersonasLDE* personas;
	int cantidad;
	int cota;
};

nat funcionDeDispersion(const char nombre[100]){
    nat res = 0;
    int i = 0;
    while(i< 100 && nombre[i] != '\0'){
        res += int(nombre[i]);
        i++;
    }
    return res;
}

TTablaPersonas crearTTablaPersonas(int max){
    rep_tablaPersonas *tablaPersonas=new rep_tablaPersonas;
    tablaPersonas->personas=new TPersonasLDE[max];
    for(int i=0;i<max;i++){
		tablaPersonas->personas[i]=crearTPersonasLDE();
    }
    tablaPersonas->cantidad=0;
    tablaPersonas->cota=max;
    return tablaPersonas;
}

void insertarPersonaEnTabla(TTablaPersonas &tabla, TPersona persona){
	int i=funcionDeDispersion(nombreTPersona(persona))%(tabla->cota);
	insertarInicioDeTPersonasLDE(tabla->personas[i], persona);
	tabla->cantidad++;
}


void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100]){
	int i=funcionDeDispersion(nombre)%(tabla->cota);
	eliminarPersonaConNombreTPersonasLDE(tabla->personas[i],nombre);
	tabla->cantidad--;
}

bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    int i=funcionDeDispersion(nombre)%(tabla->cota);
    return estaPersonaConNombreEnTPersonasLDE(tabla->personas[i],nombre);
}

TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    int i=funcionDeDispersion(nombre)%(tabla->cota);
    return obtenerPersonaConNombreTPersonasLDE(tabla->personas[i],nombre);
}


void liberarTTablaPersonas(TTablaPersonas &tabla){
	for(int i=0;i<tabla->cota;i++){
		liberarTPersonasLDE(tabla->personas[i]);
	}
	delete [] tabla->personas;
	delete tabla;
	tabla=NULL;
}


void imprimirTTablaPersonas(TTablaPersonas tabla){
	for(int i=0;i<tabla->cota;i++){
		if (tabla->personas!=NULL) {
			imprimirTPersonasLDE(tabla->personas[i]);
			}
    }
}

int cantidad(TTablaPersonas tabla){
	return tabla->cota;
	}
