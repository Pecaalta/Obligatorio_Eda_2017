#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

#include "Texto.h"

#include "Texto.cpp"
#include "Palabras.cpp"


using namespace std;


void imprimirResultado(int retorno){

     switch(retorno){
        case 0:
             printf("Resultado: %s\n\n", "OK");
             break;
        case 1:
             printf("Resultado: %s\n\n", "ERROR");
             break;
        case 2:
             printf("Resultado: %s\n\n", "NO_IMPLEMENTADA");
             break;
     }
}



int main(int argc, char *argv[])
{
    Texto texto = CrearTexto();
    int numOper = 0;
    bool salir = false;
    TipoRetorno retorno = NO_IMPLEMENTADA;
    Posicion posicionLinea = 0;
    Posicion posicionPalabra = 0;
    char opcion = 'n';
    Cadena palabraAux = NULL;

    do {


    printf("Estructuras de Datos y Algoritmos - Obligatorio 1\n");
    printf("### PROCESADOR DE TEXTOS ###\n\n");

    printf("Lista de operaciones disponibles:\n");
    printf("1)  InsertarLinea\n");
    printf("2)  InsertarLineaEnPosicion\n");
    printf("3)  BorrarLinea\n");
    printf("4)  BorrarTodo\n");
    printf("5)  BorrarOcurrenciasPalabraEnTexto\n");
    printf("6)  ImprimirTexto\n");
    printf("7)  ComprimirTexto\n");
    printf("8)  InsertarPalabra\n");
    printf("9)  BorrarPalabra\n");
    printf("10) BorrarOcurrenciasPalabraEnLinea\n");
    printf("11) ImprimirLinea\n");
    printf("12) Salir\n\n");

    printf("Ingrese el numero de la operacion a realizar: ");
    fflush(stdin);
    scanf("%d", &numOper);

    switch (numOper){
           case 1:
                  retorno = InsertarLinea(texto);
                  imprimirResultado(retorno);
                  break;
           case 2:
                  printf("Ingrese la posicion de la nueva linea (debe ser >= 1 y <= cant lineas + 1): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  fflush(stdin);
                  retorno = InsertarLineaEnPosicion(texto,posicionLinea);
                  imprimirResultado(retorno);
                  break;
           case 3:
                  printf("Ingrese la posicion de la linea a borrar (debe ser >= 1 y <= cant lineas): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  retorno = BorrarLinea(texto,posicionLinea);
                  imprimirResultado(retorno);
                  break;
           case 4:
                  printf("Esta seguro de que desea borrar todas las lineas del texto (s/n)?: ");
                  fflush(stdin);
                  scanf("%c", &opcion);
                  if (opcion == 's' || opcion == 'S'){
                     retorno = BorrarTodo(texto);
                     imprimirResultado(retorno);
                  }
                  break;
           case 5:
                  printf("Ingrese la palabra que desea borrar: ");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                  fflush(stdin);
                  scanf("%s", palabraAux);
                  retorno = BorrarOcurrenciasPalabraEnTexto(texto, palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 6:
                  retorno =  ImprimirTexto(texto);
                  imprimirResultado(retorno);
                  break;
           case 7:
                  retorno = ComprimirTexto(texto);
                  imprimirResultado(retorno);
                  break;
           case 8:
                  printf("Ingrese la palabra que desea agregar: ");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                  fflush(stdin);
                  scanf("%s", palabraAux);
                  printf("Ingrese la posicion de la linea donde la va a agregar (debe ser >= 1 y <= cant lineas): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  printf("Ingrese la posicion que debe tener la palabra dentro de las palabras de la linea (debe ser >= 1 y <= cant palabaras en la linea + 1): ");
                  fflush(stdin);
                  scanf("%d", &posicionPalabra);
                  retorno = InsertarPalabraEnLinea(texto,posicionLinea,posicionPalabra,palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 9:
                  printf("Ingrese la posicion de la linea donde se encuentra la palabra a borrar (debe ser >= 1 y <= cant lineas): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  printf("Ingrese la posicion de la palabra a borrar (debe ser >= 1 y <= cant palabaras en la linea): ");
                  fflush(stdin);
                  scanf("%d", &posicionPalabra);
                  retorno = BorrarPalabraEnLinea(texto,posicionLinea,posicionPalabra);
                  imprimirResultado(retorno);
                  break;
           case 10:
                  printf("Ingrese la palabra que desea borrar: ");
                  palabraAux = new char [MAX_LARGO_PALABRA];
                  fflush(stdin);
                  scanf("%s", palabraAux);
                  printf("Ingrese la posicion de la linea donde se debe borrar la palabra (debe ser >= 1 y <= cant lineas): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  retorno =  BorrarOcurrenciasPalabraEnLinea(texto,posicionLinea,palabraAux);
                  imprimirResultado(retorno);
                  delete palabraAux;
                  break;
           case 11:
                  printf("Ingrese la posicion de la linea que desea imprimir (debe ser >= 1 y <= cant lineas): ");
                  fflush(stdin);
                  scanf("%d", &posicionLinea);
                  retorno =  ImprimirLinea(texto, posicionLinea);
                  imprimirResultado(retorno);
                  break;
           case 12:
                  salir = true;
                  break;
           default:
                   printf("No ingreso una opcion valida, vuelva a intentarlo...\n");
           }

    printf("\n");
    system("PAUSE");

    system("cls");

    } while (!salir);

    return EXIT_SUCCESS;
}
