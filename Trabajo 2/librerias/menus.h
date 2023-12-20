// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

void menu_gestion_usuarios()
{
	system("cls");
	printf("\n ...::: Gestion de Usuarios :::...\n");
	printf(" Opcion 1: Ver informacion de usuarios\n Opcion 2: Buscar usuario por nombre de usuario\n");
	printf(" Opcion 3: Agregar usuarios\n Opcion 4: Guardar informacion\n");
	printf(" Opcion 5: Volver\n");
	printf("\n Ingrese una opcion: ");
}

void main_gestion_usuarios(USUARIO v[], int n)
{
	int op=-1;
	do
	{
		menu_gestion_usuarios();
		
		op = ingresar_rango(1,5);
		
		switch(op){
			case 1:
				printf("\n Actualmente hay %d usuarios registrados.\n",n);
				
				if (n>0)
					mostrar_lista_usuarios(v,n);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 2:
				buscar_usuario_nombre(v, n);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 3:
				agregar_lista_usuarios(v, &n);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 4: // PENDIENTE
				if(n>0)
				{
					escribir_user_file(v, n);
				}else{
					printf(" hay cero usuarios en el sistema\n\n");
				}
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 5:
				// Vuelve a Menu Administrador: main_admin()
				break;
			default:
				printf("\n Error: Opcion no valida\n\n");
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;		
		}
	}while(op!=5);
}

void menu_venta(int admin)
{
	system("cls");
	printf("\n ...::: Menu Venta :::...\n");
	printf(" Opcion 1: Buscar producto por nombre\n");
	if(admin==1)
	{
		printf(" Opcion 2: Ver monto total de ventas\n");
		printf(" Opcion 3: Buscar ganancia por marca\n");
		printf(" Opcion 4: Ver producto con mas ganancia\n");
		printf(" Opcion 5: Volver\n");
	}
	else
	{
		printf(" Opcion 2: Volver\n");
	}
	printf("\n Ingrese una opcion: ");
}

void main_venta(PRODUCTO prods[], int m, int admin)
{
	int op;
	
	do
	{
		menu_venta(admin);
		
		// Limita el acceso segun el tipo de usuario
		if (admin==1)
			op = ingresar_rango(1, 5);
		else
			op = ingresar_rango(1, 2);
		
		switch(op){
			case 1:
				buscar_producto(prods, m, admin);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 2:
				// Si no es administrador, vuelve al menu de productos
				if (admin!=1)
					op = 5; // Vuelve a Menu Productos: main_productos()
				else
				{
					monto_total_ventas(prods, m);
					printf("\n Presione una tecla para continuar...");
					getch();
				}
				
				break;
				
			// Los siguientes casos solo son para usuario administrador
			case 3:
				buscar_ganancia_marca(prods, m);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 4:
				producto_mayor_ganancia(prods, m);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 5:
				// Vuelve a Menu Productos: main_productos()
				break;
			default:
				printf(" Opcion no valida.\n");
				break;
		}
	}while(op != 5);
}

void menu_productos(int admin)
{
	system("cls");
	printf("\n ...::: Menu Productos :::...\n");
	printf(" Opcion 1: Ver lista de productos\n Opcion 2: Buscar productos por tipo\n");
	printf(" Opcion 3: Comprar producto\n");
	if(admin==1)
		printf(" Opcion 4: Volver\n");
	else
		printf(" Opcion 4: Cerrar sesion\n");
	
	printf("\n Ingrese una opcion: ");
}

void main_productos(PRODUCTO prods[], int m, int admin)
{
	int op;
	
	do
	{
		menu_productos(admin);
		
		op = ingresar_rango(1, 4);
		
		switch(op){
			case 1:
				printf("\n Actualmente hay %d productos\n", m);
				
				mostrar_lista_productos(prods, m, admin);
				
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 2:
				buscar_tipo_producto(prods, m, admin);
				printf("\n Presione una tecla para continuar...");
				getch();
				break;
			case 3:
				main_venta(prods, m, admin);
				break;
			case 4:
				// Usuario normal, cierra sesion: vuelve a main_login()
				// Usuario admin, regresa a Menu Administrador: vuelve a main_admin()
				break;
			default:
				printf(" Error: Opcion no valida.\n");
				break;
		}
	}while(op!=4);
}

void menu_admin()
{
	system("cls");
	printf("\n ...::: Menu Administrador :::...\n");
	printf(" Opcion 1: Gestion de usuarios\n Opcion 2: Gestion de productos\n");
	printf(" Opcion 3: Gestion de venta de productos\n Opcion 4: Cerrar sesion\n");
	printf("\n Ingrese una opcion: ");
}

void main_admin(USUARIO v[], int n, PRODUCTO prods[], int m)
{
	int op;
	
	do
	{
		menu_admin();
		
		op = ingresar_rango(1, 4);
		
		switch(op){
			case 1:
				main_gestion_usuarios(v, n);
				break;
			case 2:
				main_productos(prods, m, 1); // Pasamos el valor 1 porque es usuario administrador
				break;
			case 3:
				main_venta(prods, m, 1);
				break;
			case 4:
				// Cierre de sesion: vuelve a main_login()
				break;
			default:
				printf(" Error: Opcion no valida.\n");
				break;
		}
	} while(op!=4);
}

void menu_login(){
	system("cls");
	printf("\n ...::: Bienvenido :::...\n");
	printf(" Opcion 1: Iniciar sesion\n Opcion 2: Salir del programa\n");
	printf("\n Ingrese una opcion: ");
}

void main_login(USUARIO u[], int n, PRODUCTO p[], int m)
{
	USUARIO user;
	char usu[30], clave[30];
	int flag, i, admin, op;
	
	do
	{
		flag=0;
		admin=0;
		menu_login();
		op = ingresar_rango(1, 2);
		
		switch(op)
		{
			case 1:
				// Actualiza la informacion de los usuarios y productos
				leer_user_file(u, &n);
				leer_prod_file(p, &m);
				
				system("cls");
				printf("\n ...::: Inicie sesion :::...\n");
				
				do
				{
					flag = 0;
					printf(" Usuario: ");
					ingresar_usuario(usu, 30);
					printf(" Clave: ");
					ingresar_clave(clave, 30);
					
					for(i=0; i<n; i++)
					{
						desencriptar(u[i].clave, u[i].key);
						
						if (strcmp(usu, u[i].username) == 0 && strcmp(clave, u[i].clave) == 0)
						{
							flag = 1;
							encriptar(u[i].clave, u[i].key);
							user = u[i];
							break;
						}
						
						encriptar(u[i].clave, u[i].key);
					}
					
					if (flag == 0)
					{
						printf("\n Acceso denegado: usuario o clave incorrectos.\n");
						printf(" Ingrese nuevamente.\n\n");
					}
				} while (flag != 1);
				
				// Si el usuario es administrador, entonces la variable admin = 1
				// Esto se utiliza para mostrar menu y opciones especificas de admin.
				if (strcmp(user.tipo_usuario, "administrador") == 0)
					admin=1;
				
				if(admin == 1)
					main_admin(u, n, p, m);
				else
					main_productos(p, m, admin);
					
				break;
			case 2:
				//gone
				break;
			default:
				printf(" Error: Opcion no valida.\n");
				break;
		}
	} while(op!=2);
	
	printf("\n ....:::: Fin del programa ::::....\n");
}
