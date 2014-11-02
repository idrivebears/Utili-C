#include "string_functions.h"

#define true 1
#define false 0

typedef int boolean;

void convertirMinusculas(char *cadena){
	int i;
	int lol = strlen(cadena);
	for (i = 0; i <= lol; i++){
		cadena[i] = tolower(cadena[i]);
	}
	printf("Minusculas: ");
	printf("%s\n\n", cadena);
}

void print(char *string){
	int size = strlen(string);
	int i;

	for (i = 0; i < size; i++){
		putchar(string[i]);
	}

}

void printCharacters(char *string, boolean isReverse){
	if (!isReverse){
		if (*string != 0){
			putchar(*string);
			printCharacters(string + 1, false);
		}
	}
	else{
		if (*string != 0){
			printCharacters(string + 1, true);
			putchar(*string);
		}
	}

}