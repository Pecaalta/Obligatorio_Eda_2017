#ifndef TEXTO_H
#define TEXTO_Hs

#include "Constantes.h"
#include "Palabras.h"


struct _texto{
	Palabras i;
};

typedef struct _texto * Texto;

// Crea un texto vac�o
Texto CrearTexto();

// Inserta una nueva l�nea vac�a al final del texto.
TipoRetorno InsertarLinea(Texto & texto);

// Inserta una nueva l�nea vac�a en la posici�n indicada.
TipoRetorno InsertarLineaEnPosicion(Texto & texto, Posicion posicionLinea);

// Borra la l�nea en la posici�n indicada.
TipoRetorno BorrarLinea(Texto & texto, Posicion posicionLinea);

// Borra todas las l�neas del texto.
TipoRetorno BorrarTodo(Texto & texto);

// Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto texto, Cadena palabraABorrar);

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(Texto texto);

// Comprime las l�neas.
TipoRetorno ComprimirTexto(Texto texto);

// Inserta una palabra en una l�nea en la posicion dada.
TipoRetorno InsertarPalabraEnLinea(Texto texto, Posicion posicionLinea,
                                   Posicion posicionPalabra,
                                   Cadena palabraAIngresar);

// Borra la palabra de una linea que se encuentra en la posici�n dada.
TipoRetorno BorrarPalabraEnLinea(Texto texto, Posicion posicionLinea,
                                 Posicion posicionPalabra);

// Borra todas las ocurrencias de una palabra en la l�nea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto texto, Posicion posicionLinea,
                                            Cadena palabraABorrar);

// Imprime la l�nea por pantalla.
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea);

#endif
