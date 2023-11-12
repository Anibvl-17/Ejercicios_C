#include<stdio.h>

void transferencia(int cantidad, int *saldo_cuenta_origen, int *saldo_cuenta_dest);

int main()
{
	int cant, saldo_origen, saldo_dest;
	
	printf("Ingrese saldo origen: ");
	saldo_origen = ingresar_int_rango(1, 10000000);
	
	printf("Ingrese saldo destino: ");
	saldo_dest = ingresar_int_rango(1, 10000000);
	
	printf("Ingrese monto a transferir: ");
	cant = ingresar_int_rango(1, saldo_origen);
	
	transferencia(cant, &saldo_origen, &saldo_dest);
	
	printf("\nSaldo final origen: %d\n", saldo_origen);
	printf("Saldo final destino: %d", saldo_dest);
}

void transferencia(int cantidad, int *saldo_cuenta_origen, int *saldo_cuenta_dest)
{
	*saldo_cuenta_origen -= cantidad;
	*saldo_cuenta_dest += cantidad;
}

int ingresar_int_rango(int min, int max)
{
	int n, flag;
	
	do
	{
		flag=1;
		fflush(stdin);
		if (scanf("%d", &n) != 1 || n < min || n > max)
		{
			printf("Error: Valor debe ser entre %d y %d.\n", min, max);
			printf("Ingrese nuevamente: ");
			flag = 0;
		}
	} while(flag!=1);
	
	return n;
}
