#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define OUT 0 // salio de una palabra.
#define IN 1 // Entro a una palabra.
bool palabraConNumero(char caracter, int numero);

int main(){
	
	FILE *archivo;
	int caracter, cantidadPalabrasNumeros, cantidadPalabras, cantidadNumeros = 0;
	bool estadoPalabra = 0;
	bool estadoNumero = 0;
	archivo = fopen("archivo.txt","r");

	if(archivo == NULL)
		printf("%s\n","Error al intentar abrir el archivo");
	else{
		while((caracter = fgetc(archivo)) != EOF){
			if(caracter == '\n' || caracter == ' ' || caracter =='\t'){
				estadoPalabra = OUT;
				estadoNumero = OUT;
			}
			else{
				
				if(estadoPalabra == OUT){
					cantidadPalabras++;
					estadoPalabra =IN;
				}				

				if(estadoPalabra == IN && estadoNumero == OUT){
					if(palabraConNumero(caracter, 9)){
						estadoNumero == IN;
						cantidadPalabrasNumeros++;
						cantidadPalabras -= 1;
						estadoNumero = IN;	
					}
					
				}
					
					
			}
		}
	}
	fclose(archivo);
	printf("%s\n%s %d\n%s %d","Este programa cuenta numero de palabras con numero y sin numeros", 
			"El numero de palabras sin numero es : ",cantidadPalabras,
			"El numero de palabras con numero es : ",cantidadPalabrasNumeros
			 );
	return 0;
}

bool palabraConNumero(char caracter,int numero){
	bool resultado = 1;
	if(caracter != numero){
		if(numero == 0){
			resultado = 0;
			return resultado;
		}
		palabraConNumero(caracter,numero -1);
	}
	else
		return resultado;
}