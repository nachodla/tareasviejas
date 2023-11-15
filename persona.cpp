#include "../include/persona.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_persona {
	int id;
	nat edad;
	char nombre[MAX_DESCRIPCION];
	TAgendaLS agenda;

};

TPersona crearTPersona(nat id, nat edad, const char nombre[100], TAgendaLS agenda) {
    rep_persona *persona=NULL;
    persona=new rep_persona;
    persona->id=id;
    persona->edad=edad;
    strcpy(persona->nombre, nombre);
    persona->agenda=agenda;
    return persona;
}

void liberarTPersona(TPersona &persona) {
	liberarAgendaLS(persona->agenda);
	delete persona;
	persona=NULL;

}

//Imprime a la persona utilizando printf e imprimeAgendaLS
void imprimirTPersona(TPersona persona) {
printf("Persona %d: %s, %d años\n", persona->id, persona->nombre, persona->edad);
imprimirAgendaLS(persona->agenda);
}

nat idTPersona(TPersona persona) {
    
    return persona->id;
}

nat edadTPersona(TPersona persona) {
    return persona->edad;
}

char* nombreTPersona(TPersona persona) {
    return persona->nombre;
}

TAgendaLS agendaTPersona(TPersona persona) {
    return persona->agenda;
}

void agregarEventoATPersona(TPersona &persona, TEvento evento) {
agregarEnAgendaLS(persona->agenda,evento);
}

void posponerEventoEnTPersona(TPersona &persona, int id, nat n) {
posponerEnAgendaLS(persona->agenda,id,n);
}

void removerEventoDeTPersona(TPersona &persona, int id) {
removerDeAgendaLS(persona->agenda,id);
}

bool estaEnAgendaDeTPersona(TPersona persona, int id) {
    return estaEnAgendaLS(persona->agenda,id);
}

TEvento obtenerDeAgendaDeTPersona(TPersona persona, int id) {
    return obtenerDeAgendaLS(persona->agenda,id);
}

TPersona copiarTPersona(TPersona persona) {
    rep_persona *copiarTPersona=NULL;
    if (persona!=NULL) {
    copiarTPersona= new rep_persona;
    copiarTPersona->id=persona->id;
    copiarTPersona->edad=persona->edad;
    strcpy(copiarTPersona->nombre,persona->nombre);
    copiarTPersona->agenda=copiarAgendaLS(persona->agenda);
    
    }
    return copiarTPersona;
}
///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoDeTPersona(TPersona persona){
    return primerEventoAgendaLS(persona->agenda);
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
