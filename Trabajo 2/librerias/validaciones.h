// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

// Valida que un entero se encuentre dentro de un rango determinado
// Incluye los extremos.
int ingresar_rango(int min, int max)
{
	if (min == max)
		return min;
	
	int x, flag;
	do
	{
		flag = 1;
		fflush(stdin);
		if(scanf("%d", &x) != 1 || x<min || x>max)
		{
			printf(" Error: valor debe ser entre %d y %d.\n", min, max);
			printf(" Ingrese nuevamente: ");
			flag = 0;
		}
	} while(flag != 1);
	
	return x;
}

// Valida la longitud del nombre de usuario.
// Este puede contener mayusculas, minusculas y los caracteres:
// Guion - || Guion bajo _ || Punto .
void ingresar_usuario(char cad[], int largo)
{
	int i, flag;
	
	do{
		flag=1;
		fflush(stdin);
		gets(cad);
		
		if(strlen(cad)<1 || strlen(cad)>largo)
		{
			flag=0;
			printf(" Error: No se ingreso el dato o excede el largo (%d caracteres).\n", largo);
			printf(" Ingrese nuevamente: ");
		}
		else
		{
			flag=1;
			
			for(i=0;i<strlen(cad);i++)
			{	
				if(cad[i]!=45 && cad[i]!=46 && cad[i]!=95)
				{
					if(cad[i]<48 || cad[i]>122 || (cad[i]>57 && cad[i]<65) || (cad[i]>90 && cad[i]<97))
					{
						flag=0;
						printf(" Error: El dato tiene caracteres erroneos.\n");
						printf(" Ingrese nuevamente: ");
						break;
					}
				}
			}		
		}
	} while(flag != 1);	
}

// Funcion que verifica que el usuario nuevo sea unico.
void valid_agregar_usuario(char cad[], int largo, USUARIO v[], int cant_usuario)
{
	int i, flag;
	
	do{
		flag=1;
		
		// Valida la longitud y caracteres correctos.
		ingresar_usuario(cad, largo);
		
		// Verifica si ya existe un usuario con el mismo nombre de usuario.
		for (i=0; i<cant_usuario; i++){
			if(strcmp(cad, v[i].username)==0)
			{
				flag=0;
				printf(" Error: el usuario \"%s\" ya existe.\n", cad);
				printf(" Ingrese nuevamente: ");
				break;
			}
		}
	} while(flag != 1);	
}

// Valida la longitud de la clave
// Para facilitar la lectura desde el archivo, la clave no puede
// contener el caracter espacio (" ")
void ingresar_clave(char cad[], int largo) {
	int i, flag;

	do {
		fflush(stdin);
		gets(cad);
		flag=1;
	
		// Verifica el largo de la cadena.
		if (strlen(cad) < 1 || strlen(cad) > largo)
		{
			flag = 0;
			printf(" Error: No se ingreso el dato o excede el largo (%d caracteres).\n", largo);
			printf(" Ingrese la clave nuevamente: ");
		}
		else
		{
			for(i=0;i<strlen(cad);i++)
			{
				if(cad[i]==32)
				{
					printf(" Error: La clave no puede contener el caracter espacio.\n");
					printf(" Ingrese nuevamente: ");
					flag=0;
					break;
				}
			}
		}
	} while (flag != 1);	
}

// Comprueba que el largo de la cad sea correcto (0 < x <= largo)
// La cadena puede contener: Mayusculas, minusculas, espacio.
void ingresar_palabra(char cad[], int largo)
{
	int i, flag=1;
	
	do{
		fflush(stdin);
		gets(cad);
		
		if(strlen(cad)<1 || strlen(cad)>largo)
		{
			flag=0;
			printf(" Error: No se ingreso el dato o excede el largo (%d caracteres).\n", largo);
			printf(" Ingrese la clave nuevamente: ");
		}
		else{	
			flag=1;
			
			for(i=0;i<strlen(cad);i++){
				if(cad[i]!=32)
				{
					if((cad[i]<65) || (cad[i]>122 )|| (cad[i]>90 && cad[i]<97))
					{
						printf(" Error: El dato tiene caracteres erroneos.\n");
						printf(" Ingrese nuevamente: ");
						flag=0;			
						break;
					}
				}
			}
		}
	} while(flag != 1);
}

// Comprueba que el largo de la cad sea correcto (0 < x <= largo)
// La cadena puede contener: Mayusculas, minusculas, espacios y/o numeros.
void ingresar_palabra_numeros(char cad[], int largo)
{
	int i, flag=1;
	
	do{
		fflush(stdin);
		gets(cad);
		
		if(strlen(cad)<1 || strlen(cad)>largo)
		{
			flag=0;
			printf(" Error: No se ingreso el dato o excede el largo (%d caracteres).\n", largo);
			printf(" Ingrese la clave nuevamente: ");
		}
		else{	
			flag=1;
			
			for(i=0;i<strlen(cad);i++){
				if(cad[i]!=32)
				{
					if(cad[i]<48 || cad[i]>122 || (cad[i]>57 && cad[i]<65) || (cad[i]>90 && cad[i]<97))
					{
						printf(" Error: El dato tiene caracteres erroneos.\n");
						printf(" Ingrese nuevamente: ");
						flag=0;			
						break;
					}
				}
			}
		}
	} while(flag != 1);
}

// Función para cambiar espacios en blanco (" ") por guión bajo ("_").
// Se utiliza para facilitar la lectura desde archivos cuando se ingresen
// nombres, apellidos y marcas con más de una palabra.
// (Ejemplo: Be Active -> Be_Active)
void cambiar_espacios(char cad[])
{
	int n = strlen(cad),i;
	for(i=0; i<n; i++)
		if(cad[i] == 32) // 32 es el codigo ASCII de espacio en blanco
			cad[i] = 95; // 95 es el codigo ASCII para el guion bajo _
}

// Función para cambiar guion bajo ("_") por espacios en blanco (" ").
// Se utiliza para normalizar los nombres, apellidos y marcas con
// más de una palabra. (Ejemplo: Sky_Airlines -> Sky Airlines)
void cambiar_guiones(char cad[])
{
	int tam = strlen(cad),i;
	for(i=0; i<tam; i++)
		if(cad[i] == 95) // 95 es el cod ASCII para el _
			cad[i] = 32; // 32 es el cod ASCII de espacio en blanco
}

// Funcion para encriptar una clave, utilizando el cifrado de Cesar
void encriptar(char clave[], int key)
{
	int n = strlen(clave), i;
	
	for(i=0; i<n; i++)
	{
		clave[i] = clave[i] + key;
	}
}

// Funcion para desencriptar una clave, utilizando el cifrado de Cesar
void desencriptar(char clave[], int key)
{
	int n = strlen(clave), i;
	
	for(i=0; i<n; i++)
	{
		clave[i] = clave[i] - key;
	}
}
