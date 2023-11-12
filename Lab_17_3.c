#include<stdio.h>

void carga(int *C1, int *C2, int *C3, int carga_total);
int ingresar_carga();

int main()
{
	int carga_total, C1=0, C2=0, C3=0;
	
	printf("Ingrese carga total: ");
	carga_total = ingresar_carga();
	
	carga(&C1, &C2, &C3, carga_total);
	
	printf("C1: %d\n", C1);
	printf("C2: %d\n", C2);
	printf("C3: %d\n", C3);
	if (carga_total > 70)
		printf("Sobran %d toneladas.\n", (-70 + carga_total) );
	
}

void carga(int *C1, int *C2, int *C3, int carga_total)
{
	// Capacidades: 
	//  C1 = 30
	//  C2 = 25
	//  C3 = 15
	//  Total = 70
	
	// --- OPCION 1 ---
	
	if (carga_total > 70)
	{
		*C1 = 30;
		*C2 = 25;
		*C3 = 15;
	}
	else if (carga_total > 55)
	{
		*C1 = 30;
		*C2 = 25;
		*C3 = carga_total-55;
	}
	else if (carga_total > 30)
	{
		*C1 = 30;
		*C2 = carga_total-30;
	}
	else if (carga_total <= 30)
	{
		*C1 = carga_total;
	}
	
	// --- FIN OPCION 1 ---
	
	/* --- OPCION 2 ---
	
	if (carga_total >= 30) {
		*C1 = 30;
		carga_total -= 30;
		
		if (carga_total >= 25) {
			*C2 = 25;
			carga_total -= 25;
			
			if (carga_total > 15) {
				*C3 += 15;
			}
			else {
				*C3 += carga_total;
			}
				
		}
		else {
			*C2 += carga_total;
		}
	}
	else {
		*C1 +=carga_total;
	}
	
	--- FIN OPCION 2 --- */
}

int ingresar_carga()
{
	
	int n, flag;
	
	do {
		flag=1;
		fflush(stdin);
		if (scanf("%d", &n) != 1 || n<1)
		{
			printf("Error: valor debe ser mayor que 0.\n");
			printf("Ingrese nuevamente: ");
			flag=0;
		}
	} while (flag!=1);
	
	return n;
}
