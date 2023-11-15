#include "../include/personasLDE.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct nodo_doble {
TPersona elem;
nodo_doble *sig;
nodo_doble *ant;
};
struct rep_personasLDE{
	nodo_doble *ppio;
	nodo_doble *fin;
	nat cantidad;
};

TPersonasLDE crearTPersonasLDE(){
    TPersonasLDE personas=new rep_personasLDE;
    personas->fin=NULL;
    personas->ppio=NULL;
    personas->cantidad=0;
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos){
if (personas->ppio==NULL) {
    personas->ppio = new nodo_doble;
    personas->ppio->elem=persona;
    personas->ppio->sig=NULL;
    personas->ppio->ant=NULL;
    personas->fin=personas->ppio;
    }
    else { if (pos>personas->cantidad) {
		   nodo_doble *aux= new nodo_doble;
		   aux->elem=persona;
		   aux->ant=personas->fin;
		   aux->sig=NULL;
		   personas->fin->sig=aux;
		   personas->fin=aux;
		   aux=NULL;
	       }
	       else { if (pos==1) {
			      nodo_doble *aux= new nodo_doble;
			      aux->elem=persona;
			      aux->sig=personas->ppio;
			      aux->ant=NULL;
			      personas->ppio->ant=aux;
			      personas->ppio=aux;
			      aux=NULL;
			      }
			      

			      else {
					  nodo_doble *aux= new nodo_doble;
					  aux->elem=persona;
					  nodo_doble *insertar=personas->ppio;
					  nat i=1;
					  while (i<pos) {
						  insertar=insertar->sig;
						  i++; }
					  aux->sig=insertar;
					  aux->ant=insertar->ant;
					  insertar->ant->sig=aux;
					  insertar->ant=aux;
					  
					  
					//insertar=NULL;
					  aux=NULL;
				  }
			  }
		  }
personas->cantidad++;
}		  
			      
		   


void liberarTPersonasLDE(TPersonasLDE &personasLDE){
nodo_doble *aux=NULL;
if (personasLDE->ppio!=NULL) {
while (personasLDE->ppio!=NULL) {
	aux=personasLDE->ppio;
	personasLDE->ppio=personasLDE->ppio->sig;
	liberarTPersona(aux->elem);
	aux->sig=NULL;
	delete aux;
	}	
}
aux=NULL;
delete personasLDE;
personasLDE=NULL;
}	

void imprimirTPersonasLDE(TPersonasLDE personas){
    nodo_doble *aux=personas->ppio;   
    while(aux!=NULL) {
		imprimirTPersona(aux->elem);
	    aux=aux->sig;
	}
	
}

nat cantidadTPersonasLDE(TPersonasLDE personas){
	
	return personas->cantidad;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas){
if ((personas->ppio!=NULL) && (personas->ppio->sig!=NULL)) {
	nodo_doble *aux=personas->ppio;
	personas->ppio=personas->ppio->sig;
	personas->ppio->ant=NULL;
	liberarTPersona(aux->elem);
	aux->sig=NULL;
	delete aux;
	aux=NULL;
	personas->cantidad--;
}
else { if (personas->ppio!=NULL) {
	      liberarTPersona(personas->ppio->elem);
	      delete personas->ppio;
	      personas->ppio=NULL;
	      personas->fin=NULL;
	      	personas->cantidad--;

	  }
  }
	
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas){
if ((personas->fin!=NULL) && (personas->fin->ant!=NULL)) {
	nodo_doble *aux=personas->fin;
	personas->fin=personas->fin->ant;
	personas->fin->sig=NULL;
	liberarTPersona(aux->elem);
	aux->ant=NULL;
	delete aux;
	aux=NULL;
	personas->cantidad--;
}
else { if (personas->fin!=NULL) {
	      liberarTPersona(personas->fin->elem);
	      delete personas->fin;
	      personas->fin=NULL;
	      personas->ppio=NULL;
	      	personas->cantidad--;
	  }
  }
  
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id){
    nodo_doble *aux=personas->ppio;
    while (aux !=NULL && idTPersona(aux->elem)!=id) {
		aux=aux->sig; }
    return aux!=NULL;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id){
    nodo_doble *aux=personas->ppio;
    while (idTPersona(aux->elem)!=id){
		aux=aux->sig; }
    
    return aux->elem;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2){
    TPersonasLDE concaPersonas=new rep_personasLDE;
    if (personas1->ppio!=NULL && personas2->ppio!=NULL) {
		concaPersonas->ppio=personas1->ppio;
		personas1->fin->sig=personas2->ppio;
		concaPersonas->fin=personas2->fin;
		concaPersonas->cantidad=(personas1->cantidad)+(personas2->cantidad);
	}
	else { if (personas1->ppio!=NULL) {
		   concaPersonas->ppio=personas1->ppio;
		   concaPersonas->fin=personas1->fin;
		   concaPersonas->cantidad=personas1->cantidad;
	       }
	       else { if (personas2->ppio!=NULL) {
		   concaPersonas->ppio=personas2->ppio;
		   concaPersonas->fin=personas2->fin;
		   concaPersonas->cantidad=personas2->cantidad;
	       }
	         else { delete concaPersonas;
				    concaPersonas=NULL;}
			}
		}
		
    personas1->ppio=NULL;
    personas1->fin=NULL;
    personas2->ppio=NULL;
    personas2->fin=NULL;
    delete personas1;
    delete personas2;
    personas1=NULL;
    personas2=NULL;
		      
    
    return concaPersonas;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void insertarInicioDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    nodo_doble *aux=new nodo_doble;
    aux->elem=persona;
    aux->ant=NULL;
    if (personas->ppio!=NULL){
		aux->sig=personas->ppio;
		personas->ppio->ant=aux;
		personas->ppio=aux;
	} else {
	    aux->sig=NULL;
	    personas->ppio=aux;
	    personas->fin=aux;
	}
	personas->cantidad++;
}

void insertarFinalDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){    
   nodo_doble *aux=new nodo_doble;
    aux->elem=persona;
    aux->sig=NULL;
    if (personas->ppio!=NULL){
		aux->ant=personas->fin;
		personas->fin->sig=aux;
		personas->fin=aux;
	} else {
	    aux->ant=NULL;
	    personas->ppio=aux;
	    personas->fin=aux;
	}
	personas->cantidad++;
}

TPersona obtenerInicioDeTPersonasLDE(TPersonasLDE personas){
    if (personas->ppio!=NULL) {
    return personas->ppio->elem;}
    else return NULL;
}

TPersona obtenerFinalDeTPersonasLDE(TPersonasLDE personas){
    if (personas->fin!=NULL) {
    return personas->fin->elem;}
    else return NULL;
}



///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void eliminarPersonaConNombreTPersonasLDE(TPersonasLDE &personas, const char nombre[100]){
    nodo_doble *aux=personas->ppio;
    while (strcmp(nombreTPersona(aux->elem),nombre)!=0) {
		aux=aux->sig;
	}
	if (aux->ant==NULL && aux->sig==NULL) {
			liberarTPersona(aux->elem);
			personas->ppio=NULL;
			personas->fin=NULL;
			delete aux;
			aux=NULL;
			personas->cantidad--;
	} else if (aux->ant==NULL && aux->sig!=NULL){
			eliminarInicioTPersonasLDE(personas);
		} else if (aux->ant!=NULL && aux->sig==NULL) { 
			eliminarFinalTPersonasLDE(personas); 
			} else { aux->ant->sig=aux->sig;
					 aux->sig->ant=aux->ant;
					 liberarTPersona(aux->elem);
			         delete aux;
			         aux=NULL;
			         personas->cantidad--;
				 }
	
					 
}

bool estaPersonaConNombreEnTPersonasLDE(TPersonasLDE personas, const char nombre[100]){
    bool aux=false;
    nodo_doble *aux2=personas->ppio;
    while (aux2!=NULL && (strcmp(nombreTPersona(aux2->elem),nombre)!=0)) {
			aux2=aux2->sig; 
	}
	if (aux2!=NULL) {
		aux=true; 
	}
	return aux;
}

TPersona obtenerPersonaConNombreTPersonasLDE(TPersonasLDE personas, const char nombre[100]){
    nodo_doble *aux=personas->ppio;
    while ((strcmp(nombreTPersona(aux->elem),nombre)!=0)) {
			aux=aux->sig; 
	}
    return aux->elem;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

