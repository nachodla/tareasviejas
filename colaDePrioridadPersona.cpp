#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"

/*struct nodo{
	TPersona *array;
    nat cantidad;
    nat cantidadMaxima;
};*/

struct rep_colaDePrioridadPersona {
	TPersona* array;
	TPersona* ids;
	nat cantidad;   
	nat cantidadMaxima;
	bool invert;
};

TColaDePrioridadPersona crearCP(nat N) {
  rep_colaDePrioridadPersona *tablaPersonas=new rep_colaDePrioridadPersona;
  tablaPersonas->array=new TPersona[N+1];
  for(nat i=0;i<=N;i++){
		tablaPersonas->array[i]=NULL;
    }
  tablaPersonas->cantidad=0;
  tablaPersonas->cantidadMaxima=N;
  tablaPersonas->invert=false;
  tablaPersonas->ids=new TPersona[N+1];
  for(nat i=0;i<=N;i++){
		tablaPersonas->ids[i]=NULL;
    }
  return tablaPersonas;
} 

TFecha obtenerFechaPrioridad(TPersona persona){
		return fechaTEvento(primerEventoDeTPersona(persona));
	}

bool compararFechasPrioridad(TPersona per1, TPersona per2){ 
		return compararTFechas(obtenerFechaPrioridad(per1),obtenerFechaPrioridad(per2))==-1;
}

void fa(TColaDePrioridadPersona &cp, nat pos){
	if (!cp->invert){
		if (pos>1 && compararFechasPrioridad(cp->array[pos],cp->array[pos/2])) {
			TPersona swap=cp->array[pos];
			cp->array[pos]=cp->array[pos/2];
			cp->array[pos/2]=swap;
			pos=pos/2;
			fa(cp,pos);
		}
	} else {
		if (pos>1 && ((compararTFechas(obtenerFechaPrioridad(cp->array[pos]),obtenerFechaPrioridad(cp->array[pos/2]))==1)/*||compararTFechas(obtenerFechaPrioridad(cp->array[pos]),obtenerFechaPrioridad(cp->array[pos/2]))!=0)*/)) {
			TPersona swap=cp->array[pos];
			cp->array[pos]=cp->array[pos/2];
			cp->array[pos/2]=swap;
			pos=pos/2;
			fa(cp,pos);
		}
		}
		
}

void fd(TColaDePrioridadPersona &cp, nat pos){	
	nat indMax=pos;
	
	if(!cp->invert){
		
		if(2*pos<=cp->cantidad && compararFechasPrioridad(cp->array[2*pos],cp->array[pos])){
			indMax=2*pos;
		}
		
		if(2*pos+1<=cp->cantidad && compararFechasPrioridad(cp->array[2*pos+1],cp->array[indMax])){
			indMax=2*pos+1;
		}
		
		if(indMax!=pos){
			TPersona swap=cp->array[pos];
			cp->array[pos]=cp->array[indMax];
			cp->array[indMax]=swap;
			fd(cp,indMax);
		}
	} else { 
		
		if(2*pos<=cp->cantidad && compararTFechas(obtenerFechaPrioridad(cp->array[2*pos]),obtenerFechaPrioridad(cp->array[pos]))==1){
			indMax=2*pos;
		}
		
		if(1+2*pos<=cp->cantidad && compararTFechas(obtenerFechaPrioridad(cp->array[2*pos+1]),obtenerFechaPrioridad(cp->array[indMax]))==1){
			indMax=1+2*pos;
		}
		
		if(indMax!=pos){
			TPersona swap=cp->array[pos];
			cp->array[pos]=cp->array[indMax];
			cp->array[indMax]=swap;
			fd(cp,indMax);
		}
	}
}	
	
	/*while(pos<cp->cantidad){
		if (2*pos<=cp->cantidad){
			nat hijo=2*pos;
			if (hijo+1<=cp->cantidad && compararFechasPrioridad(cp->array[hijo+1],cp->array[hijo])) {
				hijo++;
				}
			if (compararFechasPrioridad(cp->array[hijo],cp->array[pos])){
				    TPersona swap=cp->array[hijo];
				    cp->array[hijo]=cp->array[pos];
				    cp->array[pos]=swap;
				    pos=hijo;
				}else {break;}	
			} 
		} 
}

	
	*/
	
	/*if (!cp->invert) {
		if(2*pos <= cp->cantidad){
				nat hijo=2*pos;
				if (hijo+1<=cp->cantidad && compararFechasPrioridad(cp->array[hijo+1],cp->array[hijo])){
					hijo=hijo+1;}
					TPersona swap=cp->array[pos];
				    cp->array[pos]=cp->array[hijo];
				    cp->array[hijo]=swap;
				    pos=hijo;
					fd(cp,pos);
			}	
	} else {
		if(2*pos <= cp->cantidad){
				nat hijo=2*pos;
				if ((hijo+1<=cp->cantidad) && compararTFechas(obtenerFechaPrioridad(cp->array[hijo+1]),obtenerFechaPrioridad(cp->array[hijo]))==1) {
					hijo=hijo+1;}
					TPersona swap=cp->array[pos];
				    cp->array[pos]=cp->array[hijo];
				    cp->array[hijo]=swap;
				    pos=hijo;
					fd(cp,pos); 
			}
		}
}
	
void filtradoInverso(TColaDePrioridadPersona &cp, nat pos) {
		if (pos>1 && ((compararTFechas(obtenerFechaPrioridad(cp->array[pos]),obtenerFechaPrioridad(cp->array[pos/2]))!=1)||compararTFechas(obtenerFechaPrioridad(cp->array[pos]),obtenerFechaPrioridad(cp->array[pos/2]))!=0))) {
			TPersona swap=cp->array[pos];
			cp->array[pos]=cp->array[pos/2];
			cp->array[pos/2]=swap;
			pos=pos/2;
			filtradoInverso(cp,pos);
		}
	}*/

/*void fdi(TColaDePrioridadPersona &cp, nat pos){	
		if(2*pos <= cp->cantidad){
				
				nat hijo=2*pos;
				if ((hijo+1<=cp->cantidad) && compararTFechas(obtenerFechaPrioridad(cp->array[hijo+1]),obtenerFechaPrioridad(cp->array[hijo]))!=-1) {
					hijo=hijo+1;}
					TPersona swap=cp->array[pos];
				    cp->array[pos]=cp->array[hijo];
				    cp->array[hijo]=swap;
				    pos=hijo;
					fdi(cp,pos); 
				
			}
		}*/

void invertirPrioridad(TColaDePrioridadPersona &cp) {
	for(nat i=1;i<cp->cantidad/2;i++){
		TPersona aux=cp->array[i];
		cp->array[i]=cp->array[cp->cantidad+1-i];
		cp->array[cp->cantidad+1-i]=aux;		
    }
    cp->invert=!cp->invert;
   // fa(cp,cp->cantidadMaxima/2);
   for (nat i=1;i<=cp->cantidad/2;i++){
	   fd(cp,i);}
   fa(cp,cp->cantidad/2);
  // if (cp->invert){
	//   fa(cp,cp->cantidad);}
	   
}

void liberarCP(TColaDePrioridadPersona &cp) {
    if (cp!=NULL){
		for(nat i=1;i<=cp->cantidad;i++){
			liberarTPersona(cp->array[i]);
		}
	}
    delete [] cp->ids;
    delete [] cp->array;
	delete cp;
	cp=NULL;
}

void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp) {
	
    if (cp->cantidad<cp->cantidadMaxima){
	  //if (!cp->invert){
		cp->array[cp->cantidad+1]=persona;
		cp->ids[idTPersona(persona)]=persona;
		fa(cp,cp->cantidad+1);
	    cp->cantidad++;
	  } /*else { 
		  cp->array[cp->cantidad+1]=persona;
		  cp->ids[idTPersona(persona)]=persona;
		  filtradoInverso(cp,cp->cantidad+1);
	      cp->cantidad++;
	   
	   }*/
	
     //} 
}
 


bool estaVaciaCP(TColaDePrioridadPersona cp) { 
  return cp->cantidad==0;
}

TPersona prioritaria(TColaDePrioridadPersona cp) {
  return cp->array[1];
} 

void eliminarPrioritaria(TColaDePrioridadPersona &cp) {
  if(!estaVaciaCP(cp)){ 
		//if (!cp->invert){
			cp->ids[idTPersona(cp->array[1])]=NULL;
			liberarTPersona(cp->array[1]);
			cp->array[1]=cp->array[cp->cantidad];
			cp->array[cp->cantidad]=NULL;
			cp->cantidad--;
			fd(cp,1);
		} /*else {
			cp->ids[idTPersona(cp->array[1])]=NULL;
			liberarTPersona(cp->array[1]);
			cp->array[1]=cp->array[cp->cantidad];
			cp->array[cp->cantidad]=NULL;
			cp->cantidad--;
			fdi(cp,1);
			}*/
		
  
}
  


bool estaEnCP(nat id, TColaDePrioridadPersona cp) {
  if (1<=id && id<=cp->cantidadMaxima){
	  return cp->ids[id]!=NULL;
  } else return false;
  
   
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp){
	/*int i=1;
	while (id!=idTPersona(cp->array[i])){
		i++;
		}*/
  return fechaTEvento(primerEventoDeTPersona(cp->ids[id]));
}
