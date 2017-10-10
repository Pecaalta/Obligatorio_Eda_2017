#include "Palabras.h"
#include <stdlib.h>
#include <stdio.h>

// Crea un conjunto de palabras vacio
Palabras CrearPalabras() {
  Palabras p = NULL;
  return p;
}
void pruebas(_retorno val){
	switch(val){
		case OK:
			printf("ok\n");
		break;
		case ERROR:
			printf( "ERROR\n");
		break;
		case NO_IMPLEMENTADA:
			printf("NO_IMPLEMENTADA\n");
		break;
	}
}
// Inserta una palabra en la posicion dada.
TipoRetorno InsertarPalabra(Palabras & palabras, Posicion posicionPalabra,
                            Cadena palabraAIngresar) {
    if(posicionPalabra<1 || posicionPalabra>MAX_CANT_PALABRAS_X_LINEA)
    	return ERROR;
    else{
    	if (palabras == NULL && posicionPalabra == 1){
    		palabras = new _palabra;
    	    palabras->s = NULL;
    	    palabras->p[0] = palabraAIngresar;
		    for (int i = 1; i < MAX_CANT_PALABRAS_X_LINEA+1; i++)
		 		palabras->p[i] = NULL;
		}else
			if(palabras == NULL)
				return ERROR;
			else{
				Cadena temp = palabraAIngresar;
		    	for(int i = posicionPalabra-1; i< MAX_CANT_PALABRAS_X_LINEA;i++){
		    		temp = palabras->p[i];
					palabras->p[i] = palabraAIngresar;
					palabraAIngresar = temp;
				}
				if (temp != NULL)
					InsertarPalabra(palabras->s,1,temp);
			}

	}
    	
  	return OK;
}

// Borra la palabra que se encuentra en la posición dada.
TipoRetorno BorrarPalabra(Palabras & palabras, Posicion posicionPalabra) {
	if (palabras == NULL || posicionPalabra < 1 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA)
		return ERROR;
	else
		palabras->p[posicionPalabra] = NULL;
}

// Borra todas las ocurrencias de una palabra.
TipoRetorno BorrarOcurrenciasPalabra(Palabras & palabras,
                                            Cadena palabraABorrar) {
 	int pos = 0;
    for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA; i++)
 		if (palabras->p[i] != palabraABorrar){
 			palabras->p[pos] = palabras->p[i];
 			pos++;
		}
    for (int i = pos; i < MAX_CANT_PALABRAS_X_LINEA; i++)
 		palabras->p[i] = NULL;
    
  return NO_IMPLEMENTADA;
}

// Borrar todo.
void BorrarTodoPalabras(Palabras & palabras) {
	if (palabras!=NULL){
		Palabras borrar = palabras;
		palabras = NULL;
		for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA; i++) delete borrar->p[i];
		delete borrar;
	}
}

// Imprime la línea en pantalla.
void ImprimirPalabras(Palabras palabras) {
	if (palabras!=NULL){
		printf("->");
		for(int i = 0; i< MAX_CANT_PALABRAS_X_LINEA;i++)
			if (palabras->p[i] != NULL) printf("%s ",palabras->p[i]);
		printf("\n");
	}else{
		printf("Linea Vacia\n");
	}
}

// Devuelve la cantidad de palabras.
unsigned int CantidadPalabras(Palabras palabras) {
	unsigned int num =0;
	if (palabras!=NULL){
		for(int i = 0; i< MAX_CANT_PALABRAS_X_LINEA;i++)
			if (palabras->p[i] != NULL) num++;
		return num;
	}else
  		return 0;
}

// Devuelve en palabra una copia de la palabra que se encuentra
// en la posición dada.
TipoRetorno PalabraEnPosicion(Palabras palabras, Posicion posicionPalabra,
                              Cadena & palabra) {
	if (palabras == NULL || posicionPalabra < 1 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA)
		return ERROR;
	else
		palabra = palabras->p[posicionPalabra];
  return OK;
}




int main(){
	Palabras prueba = CrearPalabras();
	InsertarPalabra(prueba,1,"pal1");
	InsertarPalabra(prueba,2,"pal2");
	InsertarPalabra(prueba,3,"pal3");
	ImprimirPalabras(prueba);
	system("pause");
	BorrarOcurrenciasPalabra(prueba,"pal1");
	ImprimirPalabras(prueba);
	system("pause");
	InsertarPalabra(prueba,2,"pal3");
	ImprimirPalabras(prueba);
	return 0;
}




