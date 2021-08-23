#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

DNODO *crear_nodo(INFO info){
    DNODO *nodo = (DNODO*)malloc(sizeof(DNODO));
    nodo->sig = nodo->ant = NULL;
    nodo->info = info;
    return nodo;
}

void eliminar_nodo(DNODO *n){
    if(n->sig == NULL && n->ant == NULL){
        free(n);
        n = NULL;
    }
}

DLISTA *crear_lista(){
    DLISTA *dlista = (DLISTA*)malloc(sizeof(DLISTA));
    dlista->head = dlista->tail = NULL;
    dlista->num = 0;
    return dlista;
}

bool insertar_inicio(DLISTA *l, INFO info){
    DNODO *nuevo = crear_nodo(info);
        nuevo->sig = l->head;
        l->head->ant = nuevo;
        l->head = nuevo;
        l->num++;
    return true;
}

bool insertar_fin(DLISTA *l, INFO info){
    DNODO *nuevo = crear_nodo(info);
    if(comparar(l, info)){
        if(l->head == NULL && l->tail == NULL){
            l->head = l->tail = nuevo;
            l->num++;
        }else{
            l->tail->sig = nuevo;
            nuevo->ant = l->tail;
            l->tail = nuevo;
            l->num++;
            return true;
        }
    }
}

bool insertar_pos(DLISTA *l, INFO info, int pos){
    if(pos > l->num || pos < 0) return false;

    else if(pos == 0) return insertar_inicio(l, info);

    if(comparar(l, info)){
        if(pos == l->num) return insertar_fin(l, info);
        else{
            DNODO* nuevo = crear_nodo(info);
            DNODO* temporal = l->head;
            for(int i = 0; i < pos-1; i++) 
                temporal = temporal->sig;
            nuevo->ant = temporal->ant;  
            nuevo->sig = temporal;              
            temporal->ant->sig = nuevo;
            temporal->ant = nuevo;
            l->num++;
            return true;
        }
    }
    return false;
}

bool es_vacia(DLISTA *l){
    if(l->head == NULL && l->tail ==NULL) return true;
    return false;
}

bool vaciar(DLISTA *l){
    if(es_vacia(l)) return false;
    DNODO* temporal = l->head;
    while(temporal !=NULL){
        l->head = temporal->sig;
        temporal->sig = NULL;
        l->head->ant = NULL;
        free(temporal);
        temporal = l->head;
    }
    l->head = l->tail = NULL;
    l->num = 0;
    return true;
}

void imprimir_lista(DLISTA *l){
    for(DNODO* t = l->head; t != NULL; t = t->sig){
        printf("%d ->", t->info);
    }
    printf("\n");
}

void eliminar_inicio(DLISTA *l){
    if(es_vacia(l)) return;
    DNODO *temporal = l->head;
    l->head = l->head->sig;
    temporal->sig = NULL;
    l->head->ant = NULL;
    eliminar_nodo(temporal);
    l->num--;    
}

void eliminar_fin(DLISTA *l){
    if(es_vacia(l)) return;
    DNODO *temporal = l->tail;
    l->tail = l->tail->ant;
    l->tail->sig = NULL;
    temporal->ant = NULL;
    eliminar_nodo(l->tail);
    l->num--;
}

void eliminar(DLISTA *l, int pos){
    if(pos ==0) eliminar_inicio(l);
    else if(pos==l->num-1) eliminar_fin(l);
    else if(pos>0 && pos <(l->num-1)){
        DNODO *temporal = l->head;
        for(int i=0; i < pos; i++ )
            temporal->ant->sig = temporal->sig;
        temporal->sig->ant = temporal->ant; 
        temporal->sig = temporal->ant = NULL;
        eliminar_nodo(temporal);
        l->num--;        
    }
}

INFO* buscar(DLISTA* l, int pos){
    if(es_vacia(l)) return NULL;
    if(pos ==0) return &l->head->info;
    if(pos==l->num-1) return &l->tail->info;
    if(pos>0 && pos <(l->num-1)){
        DNODO *temporal=l->head;
        for(int i=0; i < pos; i++ )
            temporal = temporal->sig;
        return &temporal->info;
    }
}

int localizar(DLISTA *l, INFO info){
    if(es_vacia(l)) return -1;
    DNODO *temporal = l->head;
    int pos = 0;
    while(temporal != NULL){
        if(comparar(l, temporal->info)) return pos;
        pos++;
        temporal = temporal->sig;
    }
    return -1;
}

bool comparar(DLISTA *l, INFO info){
    DNODO *temporal = l->head;
    for (int i = 0; i < l->num; i++){
        if(temporal->info == info) return false;
        temporal = temporal->sig;
    }
    return true;
}

void eliminar_lista(DLISTA *l){
    if(l == NULL) return;
    vaciar(l);
    free(l);
    l = NULL;
}
