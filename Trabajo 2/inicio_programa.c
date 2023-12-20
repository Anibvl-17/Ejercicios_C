// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

#include "estructuras.h" 

#include "librerias/validaciones.h"
#include "librerias/usuarios.h"
#include "librerias/productos.h"
#include "librerias/menus.h"

int main()
{
	USUARIO usuarios[40], usu;
	PRODUCTO prods[100];
	
	int n=0, m=0, pos=-1, admin=0;
	
	// Lee la informacion de los usuarios y productos desde los archivos .txt
	leer_user_file(usuarios, &n);
	leer_prod_file(prods, &m);
	
	main_login(usuarios, n, prods, m);
}




