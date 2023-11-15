#include "../include/agendaLS.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_agendaLS {
    TEvento evento;
    rep_agendaLS * sig=NULL;
};

typedef struct rep_agendaLS * TAgendaLS ;


TAgendaLS crearAgendaLS() {
    rep_agendaLS *agenda = NULL;
    return agenda;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento) {
    
    if (agenda==NULL) {
		agenda=new rep_agendaLS; 
		agenda->evento=evento;
		agenda->sig=NULL;		
	}
	else {
		rep_agendaLS *aux=NULL;
		aux=new rep_agendaLS;
		aux->evento=evento;
		rep_agendaLS *m=agenda;
		if (compararTFechas(fechaTEvento(evento),fechaTEvento(m->evento))==1){
		   while((m->sig!=NULL) && (compararTFechas(fechaTEvento(evento),fechaTEvento(m->sig->evento))==1)  ) {
			  m=m->sig; }
		   if (m->sig != NULL) {
                 aux->sig=m->sig;
                 m->sig=aux;
            } 
            else {
                aux->sig=NULL;
                m->sig=aux;
		      }
		   }
		 else {
			 aux->sig=agenda;
			 agenda=aux;
		   }     
       }
     }

		
		
		




void imprimirAgendaLS(TAgendaLS agenda) {
    
       while (agenda!=NULL)  {
		   imprimirTEvento(agenda->evento);
		   agenda=agenda->sig;
         }     
   
}

void liberarAgendaLS(TAgendaLS &agenda) {
	rep_agendaLS *aux=agenda;
	
	if (agenda!=NULL) {
	while (agenda->sig!=NULL) {
		aux=agenda->sig;
		liberarTEvento(agenda->evento);
		agenda->sig=NULL;
		delete agenda;
		agenda=aux;
	}
	
	aux=NULL;
	liberarTEvento(agenda->evento);
	delete agenda;
	agenda=NULL;
   
}
}

bool esVaciaAgendaLS(TAgendaLS agenda){
  return agenda==NULL;
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda){
	
	rep_agendaLS *copiaAgenda=NULL;	
    rep_agendaLS *aux=NULL;
        if (agenda!=NULL) {
			copiaAgenda=new rep_agendaLS;
		  aux=copiaAgenda;
		  aux->evento=copiarTEvento(agenda->evento);
	      aux->sig=NULL;
	      while (agenda->sig!=NULL) {
			  agenda=agenda->sig;
			  aux->sig=new rep_agendaLS;
			  aux->sig->evento=copiarTEvento(agenda->evento);
			  aux=aux->sig;
			  
	    }
	    aux->sig=NULL;
	   } 
	   
	
    return copiaAgenda;
}


bool estaEnAgendaLS(TAgendaLS agenda, int id) {
    if (agenda!=NULL) {
		while (agenda!=NULL && idTEvento(agenda->evento)!=id){
			agenda=agenda->sig; }
	}	
    return agenda!=NULL;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id) {
    while ((idTEvento(agenda->evento))!=id) {
		agenda=agenda->sig; }
    return agenda->evento;
}
    
	
void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n) {

TEvento auxEvento;
auxEvento=copiarTEvento(obtenerDeAgendaLS(agenda,id));
posponerTEvento(auxEvento,n);
TAgendaLS pos=agenda;
if (idTEvento(pos->evento)==id) {
	agenda=agenda->sig;
	liberarTEvento(pos->evento);
	delete pos;
}
else{

		while (idTEvento(pos->sig->evento)!=id) {
			pos=pos->sig;}
			TAgendaLS borrar=pos->sig;
		    pos->sig=pos->sig->sig;
		    liberarTEvento(borrar->evento);
		    delete borrar;
		    		
	}
		
	agregarEnAgendaLS(agenda,auxEvento);
	//liberarTEvento(auxEvento);
}


void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
    while (agenda!=NULL) {
		if (compararTFechas(fechaTEvento(agenda->evento),fecha)==0) {
			imprimirTEvento(agenda->evento);
		}
		agenda=agenda->sig;
	}
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
    while (agenda!=NULL &&  (compararTFechas(fechaTEvento(agenda->evento),fecha)!=0)) {
		agenda=agenda->sig;
	}
    return agenda!=NULL;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id) {
TAgendaLS pos=agenda;
if (idTEvento(pos->evento)==id) {
	agenda=agenda->sig;
	liberarTEvento(pos->evento);
	delete pos;
}
else{

		while (idTEvento(pos->sig->evento)!=id) {
			pos=pos->sig;}
			TAgendaLS borrar=pos->sig;
		    pos->sig=pos->sig->sig;
		    liberarTEvento(borrar->evento);
		    delete borrar;
    
}
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoAgendaLS(TAgendaLS agenda){
    return agenda->evento;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
