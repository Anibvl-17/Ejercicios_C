// Trabajo de Programacion 2
// Claudio Candia Vargas, 20.733.615-7
// Sebastian Medina Zapata, 21.827.836-1

typedef struct producto {
	char nombre[40];
	char marca[30];
	char tipo_producto[30];
	int precio_compra;
	int precio_venta;
	int cant_stock;
	int cant_vendidos;
} PRODUCTO;

typedef struct usuario {
	char username[30];
	int key;
	char clave[30];
	char tipo_usuario[15];
	char nombres[50];
	char ap1[30];
	char ap2[30];
	int edad;
} USUARIO;
