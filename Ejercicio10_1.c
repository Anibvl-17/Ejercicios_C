#include<stdio.h>
#include<string.h>

// Cree un programa en C que permita ingresar el nombre, primer
// apellido y segundo apellido de una persona. La información ingresada
// debe ser validada, es decir, no se deben permitir nombres con
// caracteres no alfabéticos (exceptuando el “espacio” como en los
// apellidos San Martin, van Baster, van der Sar, etc)

int main()
{
	char nombre[30], primerApellido[30], segundoApellido[30], nombrePersona[93] = "";
	int i, flag;
	
	do
	{
		flag = 0;
		
		printf("Ingrese nombre: ");
		fflush(stdin);
		gets(nombre);
		
		printf("Ingrese primer apellido: ");
		fflush(stdin);
		gets(primerApellido);
		
		printf("Ingrese segundo apellido: ");
		fflush(stdin);
		gets(segundoApellido);
				
		if (validarPalabra(nombre, 30) == 0 ||
			validarPalabra(primerApellido, 30) == 0 ||
			validarPalabra(segundoApellido, 30) == 0)
			{
				flag = 1;
				printf("\nError: Palabra invalida.\n\n");
			}
		
	} while (flag==1);
	
	strcat(nombre, " ");
	strcat(nombrePersona, nombre);
	strcat(primerApellido, " ");
	strcat(nombrePersona, primerApellido);
	strcat(segundoApellido, " ");
	strcat(nombrePersona, segundoApellido);
	
	printf("\nEl nombre completo de la persona es: %s\n\n", nombrePersona);
	
	main();
}

// Comprueba que el largo de la cadena sea > 0
// y menor que el largo especificado.
// Ademas valida que la cadena de caracteres contenga solo
// mayusculas, minusculas y/o espacio.
// Devuelve 1 como verdadero (cadena valida)
// Devuelve 0 como falso (cadena invalida)
int validarPalabra(char palabra[], int largo)
{
	int i;
	
	// Verifica el largo de la cadena.
	if (strlen(palabra) < 1 || strlen(palabra) > largo)
		return 0; // Devuelve falso (cadena invalida)
	
	// Recorre la cadena de caracteres.
	for (i=0; i<strlen(palabra); i++)
	{
		// 32 = Caracter espacio (" ").
		if (palabra[i] != 32)
		{
			if (
				(palabra[i] < 65) || (palabra[i] > 122) || 
				(palabra[i] > 90 && palabra[i] < 97)
				)
				return 0; // Devuelve falso (cadena invalida)
		}
	}
	return 1;
}

