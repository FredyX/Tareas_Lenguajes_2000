#include<stdio.h>
//cuenta el numero de palabras,lineas y caracteres
#define OUT 0 // salio de una palabra
#define IN  1 // entro a una nueva palabra
int main(){
	int caracter, contadorLineas, contadorPalabras, contadorCaracteres = 0 ;
	int estado = OUT;
	while((caracter = getchar()) != EOF){
		//putchar(caracter);
		contadorCaracteres++;
		if(caracter == '\n')
			contadorLineas++;
		if(caracter =='\n' || caracter =='\t' || caracter ==' ')
			estado = OUT;
		else
			if(estado == OUT){
				
				contadorPalabras++;
				estado = IN;
			}
	}
	printf("%s\n%s %d, %s %d, %s %d\n","El fichero contiene lo siguiente","numero de palabras",contadorPalabras
			,"El numero de lineas es ",contadorLineas,"El numero de caracteres es ",contadorCaracteres);
}