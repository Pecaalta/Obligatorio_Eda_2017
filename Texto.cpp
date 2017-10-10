
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



// Crea un texto vac�o
Texto CrearTexto() {
  Texto t;
  t = NULL;
  return t;
}

// Inserta una nueva l�nea vac�a al final del texto.
TipoRetorno InsertarLinea(Texto & texto) {
  Palabras nueva = new _palabra; 
  nueva->s = NULL;
  for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA+1; i++){
	nueva->p[i] = NULL;
  }
	
  if (texto == NULL){
  	texto = new _texto;
    texto->i = nueva;
  }else{
  	Palabras aux = texto->i;
  	while(aux->s != NULL)
  		aux = aux->s;
  	aux->s = nueva;
  }
  
  return OK;
}

// Inserta una nueva l�nea vac�a en la posici�n indicada.
TipoRetorno InsertarLineaEnPosicion(Texto & texto, Posicion posicionLinea) {
	
	Palabras nueva = new _palabra;
	for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA+1; i++){
		nueva->p[i] = NULL;
	}
	if (texto == NULL){
		texto = new _texto;
		texto->i = nueva;
		nueva->s = NULL;
	}else{
		if(posicionLinea==1){
		  	nueva->s = texto->i;
			texto->i = nueva;
		}else{
			Palabras aux = texto->i;
			while(posicionLinea != 2 && aux!=NULL) {
				posicionLinea--;
				aux = aux->s;
			}
			if(aux == NULL)
				return ERROR;
			else{
				nueva->s = aux->s;
		  		aux->s = nueva;
			}
		}
	}
	
  
  return OK;
}

// Borra la l�nea en la posici�n indicada.
TipoRetorno BorrarLinea(Texto & texto, Posicion posicionLinea) {
  if (texto == NULL || texto->i == NULL || posicionLinea < 0)
	return ERROR;
  else{
  	Palabras aux = texto->i;
  	Palabras borrar;
  	
  	if(posicionLinea == 1){
  		borrar = texto->i;
  		texto->i = borrar->s;
  		delete borrar;
	}else{
		while(posicionLinea != 2 && aux->s!=NULL) {
			posicionLinea--;
			aux = aux->s;
		}
		if (posicionLinea!=2)
			return ERROR;
		else{
			borrar = aux->s;
	  		aux->s = borrar->s;
	  		delete borrar;
		}
	}
  }
  return OK;
}

// Borra todas las l�neas del texto.
TipoRetorno BorrarTodo(Texto & texto) {
	Palabras borrar;
	if (texto != NULL){
		Palabras aux = texto->i;
		while(aux != NULL) {
			borrar = aux;
			aux = aux->s;
			for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA+1; i++) delete borrar->p[i];
			delete borrar;
		}
		delete texto;
		texto = NULL;
	}
  	return OK;
}

// Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto texto,
                                            Cadena palabraABorrar) {
  int i, pos = 0;
  if(texto != NULL){
  	Palabras aux =  texto->i;
  	while( aux != NULL ){
		if(aux->p[0] != NULL && strcmp (aux->p[0],palabraABorrar)  == 0) aux->p[0]= NULL;
  		for(i = 0; i< MAX_CANT_PALABRAS_X_LINEA+1;i++){
			aux->p[pos] = aux->p[i];
			if(aux->p[i] != NULL && strcmp (aux->p[i],palabraABorrar)  != 0) pos++;
		}
  		for(i = pos; i< MAX_CANT_PALABRAS_X_LINEA+1;i++){
			aux->p[i] = NULL;
		}
  		aux = aux->s;
	}
  }
  return OK;
}

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(Texto texto) {
	if(texto != NULL){
		Palabras aux = texto->i;
		int num = 1;
		while(aux != NULL) {
			printf("%d:", num);
			for(int i = 0; i<MAX_CANT_PALABRAS_X_LINEA; i++)
				if (aux->p[i] != NULL)
					printf("%s ", aux->p[i]);
			printf("\n");
			num++;
			aux = aux->s;
		}
	}else{
		printf("Texto vacio\n");
	}
	return OK; 
}

// Comprime las l�neas.
TipoRetorno ComprimirTexto(Texto texto) {
	if (texto != NULL){
		Palabras aux = texto->i;
		Palabras TEMP= texto->i;
		int pos = 0, i,linea = 1, limite = 0;
		
		while(aux!=NULL){
			limite++;
			for(i = 0; i< MAX_CANT_PALABRAS_X_LINEA;i++)
				if(aux->p[i] != NULL) {
					TEMP->p[pos] = aux->p[i];
					if (pos < MAX_CANT_PALABRAS_X_LINEA-1)
						pos++;
					else{
						TEMP = TEMP->s;
						linea++;
						pos = 0;
					}
						
				}
			aux = aux->s;
		}
		
		for(i = pos; i< MAX_CANT_PALABRAS_X_LINEA;i++)
			TEMP->p[i] = NULL;
		for(i = linea; i< limite;i++)
			BorrarLinea(texto,linea+1);

		
	}
  return OK;
}

// Inserta una palabra en una l�nea en la posicion dada.
TipoRetorno InsertarPalabraEnLinea(Texto texto, Posicion posicionLinea,
                            Posicion posicionPalabra, Cadena palabraAIngresar) {
	int i = 0;
	posicionLinea--;
	Palabras aux = texto->i;
	posicionPalabra--;
	Cadena temp = new char [MAX_LARGO_PALABRA];
	while(i != MAX_LARGO_PALABRA){
		temp[i] = palabraAIngresar[i];
		i++;
	}
//	strcpy (temp,palabraAIngresar);
	palabraAIngresar = temp;
	if (posicionPalabra < 0 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA-1  || texto == NULL || posicionLinea < 0 )
		return ERROR;
	else{
		while(posicionLinea != 0 && aux!= NULL ){
			aux = aux->s;
			posicionLinea--;
		}
		if (aux == NULL)
			return ERROR;
		else{
			while( aux->s != NULL){
				for(i = posicionPalabra; i< MAX_CANT_PALABRAS_X_LINEA;i++){
					temp = aux->p[i];
					aux->p[i] = palabraAIngresar;
					palabraAIngresar = temp;
					if (palabraAIngresar == NULL) break;
				}
				posicionPalabra = 0;
				aux = aux->s;
			}
			for(i = posicionPalabra; i< MAX_CANT_PALABRAS_X_LINEA;i++){
				temp = aux->p[i];
				aux->p[i] = palabraAIngresar;
				palabraAIngresar = temp;
			}
			if(temp != NULL){
				InsertarLinea(texto);
				aux->s->p[0] = temp;
			}
		}
	}
	
    return OK;
}

// Borra la palabra de una linea que se encuentra en la posici�n dada.
TipoRetorno BorrarPalabraEnLinea(Texto texto, Posicion posicionLinea,
                          Posicion posicionPalabra) {
 	if (texto == NULL || posicionLinea < 1 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA || posicionPalabra < 1 )
		return ERROR;
	else{
		Palabras aux = texto->i;
		while(posicionLinea != 1 && aux != NULL){
			aux = aux->s;
			posicionLinea--;
		}
		if (aux == NULL)
			return ERROR;
		else{
			for(int i = posicionPalabra-1; i< MAX_CANT_PALABRAS_X_LINEA-1;i++)
				aux->p[i] = aux->p[i+1];
			aux->p[MAX_CANT_PALABRAS_X_LINEA-1] = NULL;
		}
		
	}
  return OK;
}

// Borra todas las ocurrencias de una palabra en la l�nea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto texto, Posicion posicionLinea,
                                            Cadena palabraABorrar) {
  if(texto == NULL)
    return ERROR;
  else{
  	int i, e,pos = 0;
  	Palabras aux = texto->i;
  	while( posicionLinea != 1 && aux != NULL)	{
	  aux = aux->s;
	  posicionLinea--;
  	}	
	if (aux == NULL)
		return ERROR;
	else{
  		system("pause");
		if(aux->p[0] != NULL && strcmp (aux->p[0],palabraABorrar)  == 0) aux->p[0]= NULL;
  		for(i = 0; i< MAX_CANT_PALABRAS_X_LINEA+1;i++){
			aux->p[pos] = aux->p[i];
			if(aux->p[i] != NULL && strcmp (aux->p[i],palabraABorrar)  != 0) pos++;
		}
  		for(i = pos; i< MAX_CANT_PALABRAS_X_LINEA+1;i++){
			aux->p[i] = NULL;
		}
		
	}
  }
  return OK;
}

// Imprime la l�nea por pantalla.
TipoRetorno ImprimirLinea(Texto texto, Posicion posicionLinea) {
  	if (texto == NULL || posicionLinea < 1 )
		return ERROR;
	else{
		Palabras aux = texto->i;
		int pos = posicionLinea;
		while(pos != 1 && aux != NULL){
			aux = aux->s;
			pos--;
		}
		if (aux == NULL)
			return ERROR;
		else{
			printf("%d:",posicionLinea);
			for(int i = 0; i< MAX_CANT_PALABRAS_X_LINEA;i++)
				if (aux->p[i] != NULL) printf("%s ",aux->p[i]);
			printf("\n");
		}
	}
	return OK;
}



