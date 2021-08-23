#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    DLISTA *conjunto = crear_lista();
    int elementos, aux;

    printf("\n\n\tPRACTICAS 7 y 8: Conjunto de numeros reales");    
    
    printf("\n\n\tNumero de elementos que desea agregar:\t");
    scanf("%d", &elementos);

    for(int i = 0; i < elementos; i++){
        printf("\n\t\tElemento %d: ", i+1);
        scanf("%d", &aux);
        insertar_fin(conjunto, aux);
    }

    printf("\n\n\tEl conjunto queda como: ");
    imprimir_lista(conjunto);
    printf("\n\tCardinalidad:\t%d\n", conjunto->num);
    

    eliminar_lista(conjunto);
}
