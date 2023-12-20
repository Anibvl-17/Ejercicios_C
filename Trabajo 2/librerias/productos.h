// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

// Funcion para mostrar los datos de un producto especifico.
void mostrar_producto(PRODUCTO p, int admin)
{
	printf(" Nombre de producto .. %s\n", p.nombre);
	printf(" Marca del producto .. %s\n", p.marca);
	printf(" Tipo de producto .... %s\n", p.tipo_producto);
	if (admin==1)
		printf(" Precio de compra .... $%d\n", p.precio_compra);
	printf(" Precio de venta ..... $%d\n", p.precio_venta);
	printf(" Cantidad en stock ... %d\n", p.cant_stock);
	if (admin==1)
		printf(" Cantidad vendidos ... %d\n", p.cant_vendidos);
}

// Funcion para mostrar todos los productos del arreglo.
void mostrar_lista_productos(PRODUCTO v[], int n, int admin)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("\n ..:: Informacion producto %d ::..\n", i+1);
		mostrar_producto(v[i], admin);
	}
}

// Funcion para buscar y mostrar productos por tipo
void buscar_tipo_producto(PRODUCTO prods[], int cant_producto, int admin){
	
	int i, flag=0;
	char busqueda[40];
	
	printf(" Ingrese tipo de producto: ");
	ingresar_palabra(busqueda, 40);
	
	printf("\n ..:: Resultados de busqueda ::.. \n");
	for(i=0; i<cant_producto; i++)
	{
		if(strcmp(busqueda, prods[i].tipo_producto)==0)
		{
			printf("\n ..:: Producto %d ::..\n", i+1);
			mostrar_producto(prods[i], admin);
			flag=1;
		}
	}
	
	if(flag==0)
		printf(" La categoria %s no existe.\n", busqueda);
}

// Funcion para mostrar el monto total de las ventas.
void monto_total_ventas(PRODUCTO prods[], int m){
	
	int i, monto=0;
	
	for(i=0; i<m; i++)
		monto += prods[i].cant_vendidos * prods[i].precio_venta;
	
	printf("\n El monto total de ventas es: $%d\n", monto);
}

// Funcion para buscar la ganancia que deja una marca determinada.
void buscar_ganancia_marca(PRODUCTO prods[], int cant_producto)
{
	int i, flag=0, ganancia=0, total_prods, costo, ingreso;
	char busqueda[40];
	
	printf("\n Ingrese marca: ");
	ingresar_palabra(busqueda, 30);
	
	for(i=0; i<cant_producto; i++){
		if(strcmp(busqueda, prods[i].marca) == 0){
			// Calcula el total de productos que hay en esa marca
			total_prods = prods[i].cant_stock + prods[i].cant_vendidos;
			// Calcula el costo por comprar todos los productos
			costo = total_prods * prods[i].precio_compra;
			// Calcula el ingreso al vender todos los productos
			ingreso = total_prods * prods[i].precio_venta;
			// Calcula la utilidad de la marca.
			ganancia += ingreso - costo;
			flag=1;
		}
	}
	
	if(flag==0)
		printf("\n La marca %s no existe.\n", busqueda);
	else
		printf("\n La marca \"%s\" deja una ganancia de $%d al vender todos sus productos.\n", busqueda, ganancia);
}

// Funcion para buscar y mostrar el producto que deja mas ganancia.
void producto_mayor_ganancia(PRODUCTO prods[], int cant_producto)
{
	PRODUCTO prod_mas_ganancia = prods[0];
	int i, mas_gan = prod_mas_ganancia.precio_venta - prod_mas_ganancia.precio_compra, gan;
	
	for (i=0; i<cant_producto; i++)
	{
		gan = prods[i].precio_venta - prods[i].precio_compra;
		
		if (gan >= mas_gan)
		{
			mas_gan = gan;
			prod_mas_ganancia = prods[i];
		}
	}
	
	printf("\n ..:: Producto con mayor ganancia ::..\n");
	// La funcion producto_mayor_ganancia() es exclusiva de administrador.
	// Por lo tanto le pasamos el valor 1 a mostrar_producto()
	mostrar_producto(prod_mas_ganancia, 1);
	printf(" Ganancia ............ $%d\n", mas_gan);
}

// Funcion para guardar la informacion de los productos en el archivo .txt
void escribir_prod_file(PRODUCTO v[], int n)
{
	FILE *archivo;
	int i;
	char *nombre_archivo = "productos.txt";
	archivo = fopen(nombre_archivo,"w");
	PRODUCTO x;
	if(archivo)
	{
		for(i=0;i<n;i++)
		{
			x = v[i]; // x es una variable auxiliar para comprender mejor el codigo.
			// Se cambian los espacios en blanco por guiones bajo para facilitar
			// la lectura desde el archivo .txt
			cambiar_espacios(x.nombre);
			cambiar_espacios(x.marca);
			cambiar_espacios(x.tipo_producto);
			
			// Se escriben los datos en el archivo .txt
			fprintf(archivo,"%s %s %s %d %d %d %d\n", x.nombre, x.marca, x.tipo_producto, x.precio_compra, x.precio_venta, x.cant_stock, x.cant_vendidos);
			
		}
		fclose(archivo);
		//fprintf(stdout,"El archivo %s se a creado.\n", nombre_archivo);
	}
	else
		fprintf(stderr, " Error al abrir el archivo");
}

// Funcion para leer la informacion de los productos desde el archivo .txt
void leer_prod_file(PRODUCTO v[], int *n)
{
	FILE *archivo;
	PRODUCTO x;
	int i=0;
	char *nombre_archivo = "productos.txt";
    archivo = fopen(nombre_archivo, "r");
    while (!feof(archivo))
    {
    	// Se leen los datos desde el archivo .txt
    	fscanf(archivo,"%s %s %s %d %d %d %d\n", &x.nombre, &x.marca, &x.tipo_producto, &x.precio_compra, &x.precio_venta, &x.cant_stock, &x.cant_vendidos);
    	
    	// Se cambian los guiones bajos por espacios en blanco solo en
    	// nombre, marca y tipo de producto
    	cambiar_guiones(x.nombre);
    	cambiar_guiones(x.marca);
    	cambiar_guiones(x.tipo_producto);
		v[i]=x;
		i++;
    }
    
    // *n representa la cantidad de productos guardados
    *n = i;
    
	fclose(archivo);
}

// Funcion para realizar la compra de un producto.
void comprar(PRODUCTO prods[], int cant_producto, int pos)
{
	int cant, flag;
	char confirmar;
	
	printf("\n Se encontro el producto: \n\n");
	mostrar_producto(prods[pos], 0);
	
	if (prods[pos].cant_stock == 1)
	{
		printf("\n Solo queda 1 unidad disponible.\n");
		printf(" Presione una tecla para continuar...");
		cant = 1;
		getch();
	}
	else 
	{
		printf("\n Ingrese cuantos productos desea comprar: ");
		cant = ingresar_rango(1, prods[pos].cant_stock);
	}
	
	system("cls");
	
	printf("\n ...::: Confirmar Compra :::...\n");
	printf(" Nombre del producto .... %s\n", prods[pos].nombre);
	printf(" Marca del producto ..... %s\n", prods[pos].marca);
	printf(" Cantidad de productos .. %d\n", cant);
	printf(" Precio por unidad ...... $%d\n", prods[pos].precio_venta);
	printf("\n Precio final ........... $%d\n", prods[pos].precio_venta * cant);
	printf("\n Presione \"s\" para confirmar o \"n\" para cancelar: ");
	
	do {
		fflush(stdin);
		confirmar = getch();
		flag=0;
		
		if (confirmar == 115) // 115 es el codigo ASCII para la letra "s"
		{
			prods[pos].cant_stock -= cant; // Disminuye la cantidad en stock del producto
			prods[pos].cant_vendidos += cant; // Aumenta la cantidad de vendidos del producto
			
			printf("\n\n ...::: Compra Confirmada :::...\n");
			printf(" Gracias por comprar \"%s\", que lo disfrutes!\n", prods[pos].nombre);
			
			flag=1;
			
			// Actualiza la informacion de los productos en el archivo .txt
			escribir_prod_file(prods, cant_producto);
		}
		else if (confirmar == 110) // 110 es el codigo ASCII para la letra "n"
		{
			printf("\n Se cancelo la compra.\n");
			flag=1;
		}
		else
			printf(" Error: Ingrese un caracter valido: ");
			
	} while (flag != 1);
}

// Funcion para buscar un producto por nombre.
// Es utilizada al momento de realizar la compra.
void buscar_producto(PRODUCTO prods[], int cant_producto, int admin){
	
	int i, flag=0;
	char busqueda[40];
	
	printf("\n Ingrese nombre de producto: ");
	ingresar_palabra_numeros(busqueda, 40);
	
	for(i=0; i<cant_producto; i++){
		if(strcmp(busqueda, prods[i].nombre)==0){
			flag=1;
			break;
		}
	}
	
	if(flag==0)
		printf(" El producto %s no existe.\n", busqueda);
	else if (prods[i].cant_stock < 1) // Verifica el stock del producto.
		printf(" Lo sentimos, no queda stock del producto %s.\n", busqueda);
	else
		comprar(prods, cant_producto, i);
}
