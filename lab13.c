#include<stdio.h>
#include<string.h>
#include<conio.h>

typedef struct anciano {
	char nombres[50];
	char ape1[30];
	char ape2[30];
	int edad;
} ANCIANO;

typedef struct hogarAncianos {
	char nombre[70];
	char ciudad[50];
	int cant_hospedados;
	ANCIANO ancianos[40];
} HOGAR;

int main()
{
	char usuario[30], clave[30];
	int flag, flag2, flag3, cantHogares, i, j;
	HOGAR hogares[100];
	
	// ---- Login de acceso. ----
	printf(" --- Inicie sesion ---\n");
	do {
		
		printf(" Ingrese usuario: ");
		fflush(stdin);
		gets(usuario);
		printf(" Ingrese clave: ");
		fflush(stdin);
		gets(clave);
		
		if (strcmp(usuario, "Admin") == 0 && strcmp(clave, "pass123") == 0)
			flag = 1;
		else {
			printf(" Error: Usuario o clave incorrecta.\n");
			flag = 0;
		}
	} while (flag != 1);
	
	// ---- Ingreso de informacion de hogares. ----
	printf(" --- Ingrese informacion de los hogares ---\n");
	do {
		
		printf(" Ingrese cantidad de hogares: ");
		scanf("%d", &cantHogares);
		
		if (cantHogares > 0) {
			flag = 1;
					
			for (i=0; i<cantHogares; i++)
			{
				printf(" - Ingrese informacion del hogar %d:\n", i+1);
				do{
					flag2=1;
					
					printf("   Nombre: ");
					fflush(stdin);
					gets(hogares[i].nombre);
					printf("   Ciudad: ");
					fflush(stdin);
					gets(hogares[i].ciudad);
					printf("   Cantidad de hospedados: ");
					scanf("%d", &hogares[i].cant_hospedados);
					
					if (validarPalabra(hogares[i].nombre, 70) == 1 && 
						validarPalabra(hogares[i].ciudad, 50) == 1 &&
						hogares[i].cant_hospedados > 0)
					{
						flag2 = 1;
						
						for (j=0; j<hogares[i].cant_hospedados; j++)
						{
							printf("- Ingrese informacion del anciano %d:\n", j+1);
							do
							{
								printf("   Nombres: ");
								fflush(stdin);
								gets(hogares[i].ancianos[j].nombres);
								printf("   Primer apellido: ");
								fflush(stdin);
								gets(hogares[i].ancianos[j].ape1);
								printf("   Segundo apellido: ");
								fflush(stdin);
								gets(hogares[i].ancianos[j].ape2);
								printf("   Edad: ");
								scanf("%d", &hogares[i].ancianos[j].edad);
								
								if (validarPalabra(hogares[i].ancianos[j].nombres, 50) == 1 &&
									validarPalabra(hogares[i].ancianos[j].ape1, 30) == 1 &&
									validarPalabra(hogares[i].ancianos[j].ape2, 30) == 1 &&
									validarEdad(hogares[i].ancianos[j].edad) )
									flag3=1;
								else {
									printf("   Error: Datos incorrectos.\n");
									flag3=0;
								}
							} while (flag3 != 1);
						}
					} else {
						printf("   Error: Datos incorrectos.\n");
						flag2 = 0;
					}
				} while (flag2 != 1);
			}			
		} else {
			printf(" Error: Cantidad debe ser mayor a 0.\n");
			flag = 0;
		}
		
	} while (flag!=1);
	
	// ------------- Menu -----------------------------------------------
	int op=0, ultimo=0;
	char busqueda[100] = "";
	ANCIANO mayorEdad;
	do {
		flag = 1;
		
		printf("\n\n --- Menu ---\n");
		printf(" Opcion 1: Mostrar la informacion de todos los hogares.\n");
		printf(" Opcion 2: Buscar hogar por nombre.\n");
		printf(" Opcion 3: Buscar hogares por ciudad.\n");
		printf(" Opcion 4: Buscar anciano con mas edad de un hogar.\n");
		printf(" Opcion 5: Agregar un nuevo hogar.\n");
		printf(" Opcion 6: Salir.\n\n");
		printf(" Ingrese opcion: ");
		scanf("%d", &op);
		printf("\n\n");
		
		switch(op){
			case 1: // Mostrar informacion de todos los hogares.
				printf(" --- Informacion de los hogares ---\n");
				for (i=0; i<cantHogares; i++)
				{
					printf(" - Hogar %s\n", hogares[i].nombre);
					printf("   Ciudad: %s\n", hogares[i].ciudad);
					printf("   Cantidad de hospedados: %d\n", hogares[i].cant_hospedados);
					for (j=0; j<hogares[i].cant_hospedados; j++) {
						printf("\n   - Hospedado %d:\n", j+1);
						printf("     Nombres: %s\n", hogares[i].ancianos[j].nombres);
						printf("     Primer apellido: %s\n", hogares[i].ancianos[j].ape1);
						printf("     Segundo apellido: %s\n", hogares[i].ancianos[j].ape2);
						printf("     Edad: %d\n", hogares[i].ancianos[j].edad);
					}
				}
				
				printf("\n\n Presione una tecla para continuar al menu.\n");
				getch();
				break;
				
			case 2: // Buscar hogar por nombre.
				
				do {
					printf(" - Ingrese el nombre del hogar: ");
					fflush(stdin);
					gets(busqueda);
					
					if (validarPalabra(busqueda, 100) == 1){
						flag = 1;
						
						for (i=0; i<cantHogares; i++) {
							
							if (strcmp(busqueda, hogares[i].nombre) == 0)
							{
								printf(" - Se encontro el hogar: \n", busqueda);
								printf("   Nombre: %s\n", hogares[i].nombre);
								printf("   Ciudad: %s\n", hogares[i].ciudad);
								printf("   Cantidad de hospedados: %d\n", hogares[i].cant_hospedados);
								for (j=0; j<hogares[i].cant_hospedados; j++) {
									printf("\n   - Hospedado %d:\n", j+1);
									printf("     Nombres: %s\n", hogares[i].ancianos[j].nombres);
									printf("     Primer apellido: %s\n", hogares[i].ancianos[j].ape1);
									printf("     Segundo apellido: %s\n", hogares[i].ancianos[j].ape2);
									printf("     Edad: %d\n", hogares[i].ancianos[j].edad);
								}
								flag2=1;
								break;
							}
							else
								flag2=0;
						}
						
						if (flag2 == 0)
						{
							printf(" El hogar %s no existe.\n", busqueda);
						}
						
					}
					else {
						printf(" Error: Busqueda invalida.\n");
						flag = 0;
					}
				} while (flag != 1);
				
				printf("\n\n Presione una tecla para continuar al menu.\n");
				getch();
				break;
				
			case 3: // Buscar hogares por ciudad.
				
				do {
					printf(" - Ingrese la ciudad: ");
					fflush(stdin);
					gets(busqueda);
					
					if (validarPalabra(busqueda) == 1)
					{
						flag = 1;
						flag2 = 0;
						for (i=0; i<cantHogares; i++)
						{
							if (strcmp(busqueda, hogares[i].ciudad) == 0){
								flag2=1;
								printf("   Nombre: %s\n", hogares[i].nombre);
								printf("   Ciudad: %s\n", hogares[i].ciudad);
								printf("   Cantidad de hospedados: %s\n", hogares[i].nombre);
								flag2=1;
							}
						}
						
						if (flag2==0){
							printf("  No se encontraron hogares en la ciudad %s.", busqueda);
						}
					}
					else {
						printf(" Error: Busqueda invalida.\n");
						flag=0;
					}
				} while (flag!=1);
				
				printf("\n\n Presione una tecla para continuar al menu.\n");
				getch();
				break;
				
			case 4: // Buscar anciano de mas edad en un hogar.
				
				do {
					
					printf(" - Ingrese el nombre del hogar: ");
					fflush(stdin);
					gets(busqueda);
					
					if (validarPalabra(busqueda, 100) == 1)
					{
						for (i=0; i<cantHogares; i++) {
							
							if (strcmp(busqueda, hogares[i].nombre) == 0)
							{
								mayorEdad=hogares[i].ancianos[0];
								for (j=0; j<hogares[i].cant_hospedados; j++) {
									if (mayorEdad.edad < hogares[i].ancianos[j].edad)
										mayorEdad = hogares[i].ancianos[j];
								}
								printf(" - El anciano de mas edad en el hogar %s es: \n", busqueda);
								printf("   Nombres: %s\n", mayorEdad.nombres);
								printf("   Primer apellido: %s\n", mayorEdad.ape1);
								printf("   Segundo apellido: %s\n", mayorEdad.ape2);
								printf("   Edad: %d\n", mayorEdad.edad);
								flag2=1;
								break;
							}
							else
								flag2=0;
						}
						
						if (flag2 == 0)
						{
							printf(" El hogar %s no existe.\n", busqueda);
						}

					}
					else {
						printf(" Error: Busqueda invalida.\n");
					}
					
				} while (flag!=1);
				
				printf("\n\n Presione una tecla para continuar al menu.\n");
				getch();
				break;
			
			case 5:
				
				if (cantHogares < 100) {
					cantHogares++;
					ultimo = cantHogares-1;
					
					printf(" - Ingrese informacion del hogar %d:\n", i+1);
					
					do{
						flag2=1;
						
						printf("   Nombre: ");
						fflush(stdin);
						gets(hogares[ultimo].nombre);
						printf("   Ciudad: ");
						fflush(stdin);
						gets(hogares[ultimo].ciudad);
						printf("   Cantidad de hospedados: ");
						scanf("%d", &hogares[ultimo].cant_hospedados);
						
						if (validarPalabra(hogares[ultimo].nombre, 70) == 1 && 
							validarPalabra(hogares[ultimo].ciudad, 50) == 1 &&
							hogares[ultimo].cant_hospedados > 0)
						{
							flag2 = 1;
							
							for (j=0; j<hogares[ultimo].cant_hospedados; j++)
							{
								printf("- Ingrese informacion del anciano %d:\n", j+1);
								do
								{
									printf("   Nombres: ");
									fflush(stdin);
									gets(hogares[ultimo].ancianos[j].nombres);
									printf("   Primer apellido: ");
									fflush(stdin);
									gets(hogares[ultimo].ancianos[j].ape1);
									printf("   Segundo apellido: ");
									fflush(stdin);
									gets(hogares[ultimo].ancianos[j].ape2);
									printf("   Edad: ");
									scanf("%d", &hogares[i].ancianos[j].edad);
									
									if (validarPalabra(hogares[ultimo].ancianos[j].nombres, 50) == 1 &&
										validarPalabra(hogares[ultimo].ancianos[j].ape1, 30) == 1 &&
										validarPalabra(hogares[ultimo].ancianos[j].ape2, 30) == 1 &&
										validarEdad(hogares[ultimo].ancianos[j].edad) )
										flag3=1;
									else {
										printf("   Error: Datos incorrectos.\n");
										flag3=0;
									}
								} while (flag3 != 1);
							}
						} else {
							printf("   Error: Datos incorrectos.\n");
							flag2 = 0;
						}
					} while (flag2 != 1);
				}
				else {
					printf(" Error: No se pueden agregar mas hogares.\n");
				}
				
				printf("\n\n Presione una tecla para continuar al menu.\n");
				getch();
				break;
				
			case 6:
				printf(" --- Fin del programa ---\n");
				break;
			default:
				printf(" Error: Opcion incorrecta\n");
				break;
		}
		
	} while (op != 6);
	
	
	
}

// ----- Funciones de validacion -----

// Comprueba que el largo de la cadena sea > 0 y menor que el largo especificado.
// Valida que la cadena de caracteres contenga solo mayusculas, minusculas y/o espacio.
// Devuelve 1 como verdadero (cadena valida) y devuelve 0 como falso (cadena invalida)
int validarPalabra(char palabra[], int largo)
{
	int i; // Contador para ciclo for.
	
	// Verifica el largo de la cadena.
	if (strlen(palabra) < 1 || strlen(palabra) > largo)
		return 0; // Devuelve falso (cadena invalida)
	
	// Recorre la cadena de caracteres.
	for (i=0; i<strlen(palabra); i++)
	{
		// Valida caracter espacio (" ").
		if (palabra[i] != 32)
		{
      // Valida letras minusculas y mayusculas.
			if (
				(palabra[i] < 65) || (palabra[i] > 122) || 
				(palabra[i] > 90 && palabra[i] < 97)
				)
				return 0; // Devuelve falso (cadena invalida).
		}
	}
	return 1; // Devuelve verdadero (cadena valida).
}

// Comprueba que el largo de la cadena sea > 0 y menor que el largo especificado.
// Valida que la cadena de caracteres contenga solo mayusculas, minusculas y
// los caracteres especiales ".", "-", "_".
// Devuelve 1 como verdadero (cadena valida) y devuelve 0 como falso (cadena invalida)
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
// Devuelve 1 como verdadero (edad valida) y devuelve 0 como falso (edad invalida)
int validarEdad(int e)
{	
	if (e < 0 || e > 125)
		return 0; // Devuelve falso (edad invalida).
	else	
		return 1;
}

