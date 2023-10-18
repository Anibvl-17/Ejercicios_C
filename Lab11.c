#include<stdio.h>
#include<string.h>

// Cree un programa que permita ingresar una N cantidad de usuarios (datos de usuarios:
// nombre completo, nombre usuario, clave, edad) y luego realice las siguientes acciones:
// 	a. Mostrar todos los datos de los usuarios
// 	b. Buscar la información de un usuario por nombre de usuario
// 	c. Mostrar la información de todos los usuarios que tiene una edad igual a X
// 	   (ingresada por teclado)
//
// Consideraciones:
// - Para acceder a la información de los puntos a, b y c, se debe implementar
//   un “login” de acceso.
// - Los datos ingresados deben estar validados
// - Para facilitar el registro de información, las letras deben ser almacenadas en
//   mayúsculas, es decir, si se ingresa alguna letra en minúscula, su programa
//   deberá transformarla a mayúsculas.

// PENDIENTE PUNTOS b y c.

typedef struct usuario {
	char nombre[100];
	char usuario[30];
	char clave[30];
	int edad;
} USU;

int main()
{
	int flag; // 0 = falso, 1 = verdadero.
	char usuario[30], clave[30];
	
	printf("--- Inicio de sesion ---\n");
	do
	{
		flag = 1;
		printf("Ingrese usuario: ");
		fflush(stdin);
		gets(usuario);
		printf("Ingrese clave: ");
		fflush(stdin);
		gets(clave);
		
		if (strcmp(usuario, "Admin") != 0 || strcmp(clave, "pass123"))
		{
			printf("Error: Usuario o clave incorrectos.\n");
			flag = 0;
		}
		
	} while(flag == 0);
	
	// char usuario[30] y clave[30] se reutilizan.
	char nombre[100];
	int edad, n, i; // n: cantidad de usuarios.
	
	printf("\n--- Registro de estudiantes ---\n");
	do
	{
		printf("Ingrese la cantidad de usuarios: ");
		scanf("%d", &n);
		
		if (n<=0)
			printf("Error: Cantidad de usuarios debe ser mayor a 0.");
	} while(n <= 0);
	
	USU usuarios[n];
	for (i=0; i<n; i++)
	{
		printf("- Datos de usuario %d:\n", i+1);
		do
		{
			flag = 1;
			printf("Nombre completo: ");
			fflush(stdin);
			gets(usuarios[i].nombre);
			printf("Nombre de usuario: ");
			fflush(stdin);
			gets(usuarios[i].usuario);
			printf("Clave: ");
			fflush(stdin);
			gets(usuarios[i].clave);
			printf("Edad: ");
			fflush(stdin);
			scanf("%d", &usuarios[i].edad);
			
			if (validarPalabra(usuarios[i].nombre, 100) == 0 ||
				validarUsuario(usuarios[i].usuario, 30) == 0 ||
				validarEdad(usuarios[i].edad) == 0)
			{
				printf("\nError: Datos incorrectos.\n");
				flag = 0;
			}
			
		} while (flag == 0);
	}
	
	// Muestra los usuarios registrados.
	printf("\n--- Usuarios registrados --- \n");
	for (i=0; i<n; i++)
	{
		printf("- %s, %s, %s, %d anios\n", usuarios[i].nombre, usuarios[i].usuario, usuarios[i].clave, usuarios[i].edad);
	}
	
}

// Comprueba que el largo de la cadena sea > 0 y menor que el largo especificado.
// Valida que la cadena de caracteres contenga solo mayusculas, minusculas y/o espacio.
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

// Comprueba que el largo de la cadena sea > 0 y menor que el largo especificado.
// Valida que la cadena de caracteres contenga solo mayusculas, minusculas y
// los caracteres especiales ".", "-", "_", y los numeros 0 al 9.
// Devuelve 1 como verdadero (cadena valida)
// Devuelve 0 como falso (cadena invalida)
int validarUsuario(char palabra[], int largo)
{
	int i;
	
	// Verifica el largo de la cadena.
	if (strlen(palabra) < 1 || strlen(palabra) > largo)
		return 0; // Devuelve falso (cadena invalida)
	
	// Recorre la cadena de caracteres.
	for (i=0; i<strlen(palabra); i++)
	{
		// Valida caracteres "-", ".", "_" respectivamente.
		if (palabra[i] != 45 && palabra[i] != 46 && palabra[i] != 95)
		{
			// Valida letras minusculas, mayusculas y numeros.
			if (
				(palabra[i] < 48) || (palabra[i] > 122) || 
				(palabra[i] > 57 && palabra[i] < 65) ||
				(palabra[i] > 90 && palabra[i] < 97)
				)
				return 0; // Devuelve falso (cadena invalida)
		}
	}
	return 1; // Devuelve verdadero (cadena valida).
}

// Valida que el valor ingresado corresponda a una edad valida.
// Valores estandar: 0 a 125 años.
// Devuelve 1 como verdadero (cadena valida)
// Devuelve 0 como falso (cadena invalida)
int validarEdad(int e)
{	
	if (e < 0 || e > 125)
		return 0; // Devuelve falso (edad invalida).
	else	
		return 1;
}

