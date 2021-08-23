#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <stdbool.h>

typedef struct _dnodo DNODO;
typedef int INFO;

struct _dnodo{
    INFO info;
    DNODO *sig;
    DNODO *ant;
};

DNODO *crear_nodo(INFO info);
void eliminar_nodo(DNODO *n);

typedef struct _dlista DLISTA;

struct _dlista{
    DNODO *head;
    DNODO *tail;
    int num;
};

DLISTA *crear_lista();
void eliminar_lista(DLISTA *l);
bool es_vacia(DLISTA *l);
void vaciar_lista(DLISTA *l);
bool insertar_inicio(DLISTA *l, INFO info);
bool insertar_fin(DLISTA *l, INFO info);
bool insertar_pos(DLISTA *l, INFO info, int pos);
void eliminar_inicio(DLISTA *l);
void eliminar_final(DLISTA *l);
void eliminar_pos(DLISTA *l);
void imprimir_lista(DLISTA *l);
INFO* buscar(DLISTA *l, int pos);
int localizar(DLISTA *l, INFO info);
bool comparar(DLISTA *l, INFO info1);

#endif
