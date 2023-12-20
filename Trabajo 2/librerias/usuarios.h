// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

// Función para ingresar los datos de un usuario
USUARIO agregar_usuario(USUARIO v[], int n){
	
	USUARIO usuario;
	char tipo;
	int flag;
	
	printf(" Ingrese nombre de usuario: ");
	valid_agregar_usuario(usuario.username, 30, v, n);
	printf(" Ingrese clave: ");
	ingresar_clave(usuario.clave, 30);
	usuario.key = 2+rand()%9;
	encriptar(usuario.clave, usuario.key);
	
	printf(" Tipo de usuario: presione \"a\" para administrador o \"n\" para normal\n");
	do {
		fflush(stdin);
		tipo = getch();
		flag=0;
		
		if (tipo == 97) // 97 es el código ASCII de la letra "a"
		{
			strcpy(usuario.tipo_usuario, "administrador");
			printf(" Se asigno tipo de usuario administrador.\n");
			printf(" Nota: la edad del usuario administrador esta entre 18 a 70 anios.\n");
			flag=1;
		}
		else if (tipo == 110) // 110 es el código ASCII de la letra "n"
		{
			strcpy(usuario.tipo_usuario, "normal");
			printf(" Se asigno tipo de usuario normal.\n");
			printf(" Nota: la edad del usuario normal esta entre 14 a 125 anios.\n");
			flag=1;
		}
		else
		{
			printf(" Error: Ingrese un caracter valido.\nTipo de usuario: ");
		}
		
	} while (flag != 1);
		
	printf(" Ingrese nombres: ");
	ingresar_palabra(usuario.nombres, 50);
	printf(" Ingrese primer apellido: ");
	ingresar_palabra(usuario.ap1, 30);
	printf(" Ingrese segundo apellido: ");
	ingresar_palabra(usuario.ap2, 30);	
	printf(" Ingrese edad: ");
	if(tipo == 97) // Usuario normal: 18 a 70 anios
		usuario.edad=ingresar_rango(18, 70);
	else if (tipo == 110) // Usuario administrador: 14 a 125 anios
		usuario.edad=ingresar_rango(14, 125);
	
	return usuario;
}

// Funcion para ingresar 1 o mas usuarios
void agregar_lista_usuarios(USUARIO v[], int *n)
{
	int i, cant;
	
	if (*n >= 40)
		printf("\n No se pueden agregar mas usuarios.\n");
	else
	{
		printf(" Nota: Puede agregar hasta %d usuarios.\n", 40-*n);
		printf(" Ingrese cantidad de usuarios: ");
		cant = ingresar_rango(1, 40-*n);
	
		for(i=0; i<cant; i++)
		{
			printf("\n ..:: Ingrese informacion del usuario %d ::..\n", i+1);
			v[*n+i]=agregar_usuario(v, *n);
		}
		
		*n = *n+cant;
	}
}

// Funcion para mostrar los datos de un usuario especifico.
void mostrar_usuario(USUARIO u)
{
	printf(" Nombre de usuario .. %s\n", u.username);
	printf(" Tipo de usuario .... %s\n", u.tipo_usuario);
	printf(" Nombres ............ %s\n", u.nombres);
	printf(" Primer Apellido .... %s\n", u.ap1);
	printf(" Segundo Apellido ... %s\n", u.ap2);
	printf(" Edad ............... %d\n", u.edad);
}

// Funcion para mostrar los usuarios del vector proporcionado.
void mostrar_lista_usuarios(USUARIO v[], int n)
{
	int i;
	
	for(i=0; i<n; i++)
	{
		printf("\n ..:: Usuario %d ::..\n", i+1);
		mostrar_usuario(v[i]);
	}
}
// Funcion para guardar la informacion de los usuarios en el archivo .txt
void escribir_user_file(USUARIO v[], int n)
{
	FILE *archivo;
	int i;
	char *nombre_archivo = "usuarios.txt";
	archivo = fopen(nombre_archivo, "w");
	USUARIO x;
	if(archivo)
	{
		for(i=0;i<n;i++)
		{
			x = v[i]; // x es una variable auxiliar para comprender mejor el codigo.
			// Se cambian los espacios en blanco por guiones bajo para facilitar
			// la lectura desde el archivo .txt
			cambiar_espacios(x.nombres);
    		cambiar_espacios(x.ap1);
    		cambiar_espacios(x.ap2);
    		
    		// Se escriben los datos en el archivo .txt
			fprintf(archivo, "%s %d %s %s %s %s %s %d \n", x.username, x.key, x.clave, x.tipo_usuario, x.nombres, x.ap1, x.ap2, x.edad);
			
		}
		
		fclose(archivo);
		fprintf(stdout,"\n Se guardo la informacion de usuarios.\n",nombre_archivo);
	}else{
		fprintf(stderr, " Error al abrir el archivo");
	}
}

// Funcion para leer la informacion de los usuarios desde el archivo .txt
void leer_user_file(USUARIO v[], int *n)
{
	FILE *archivo;
	USUARIO x;
	int i=0;
	char *nombre_archivo = "usuarios.txt";
    archivo = fopen(nombre_archivo, "r");
    while (!feof(archivo))
    {
    	// Se leen los datos desde el archivo .txt
    	fscanf(archivo,"%s %d %s %s %s %s %s %d \n", &x.username, &x.key, &x.clave, &x.tipo_usuario, &x.nombres, &x.ap1, &x.ap2, &x.edad);
    	
    	// Se cambian los guiones bajos por espacios en blanco solo en
    	// nombres y apellidos.
    	cambiar_guiones(x.nombres);
    	cambiar_guiones(x.ap1);
    	cambiar_guiones(x.ap2);
		v[i]=x;
		i++;
    }
    
    // *n representa la cantidad de usuarios registrados en el sistema.
    *n = i;
    fclose(archivo);
}

// Funcion para buscar usuarios por nombre de usuario
void buscar_usuario_nombre(USUARIO usuarios[] , int cant_usuario) {
	
	int i, flag=0;
	char busqueda[40];
	
	printf("\n Ingrese nombre de usuario: ");
	ingresar_usuario(busqueda, 40);
	
	printf("\n ..:: Resultados de busqueda ::..\n");
	for (i=0; i<cant_usuario; i++){
		if(strcmp(busqueda, usuarios[i].username)==0){
			printf("\n ..:: Usuario %d ::..\n", i+1);
			mostrar_usuario(usuarios[i]);
			flag=1;
			// Los nombres de usuarios son unicos, por lo tanto al encontrar uno
			// el ciclo se finaliza
			break;
		}
	}
	
	if(flag==0)
		printf("\n No se encontro el usuario \"%s\".\n", busqueda);
}
