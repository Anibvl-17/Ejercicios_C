#include<stdio.h>

int ingresar_int_rango(int min, int max);
void llenar_vector(int v[], int tam);
void mostrar_promedio(int v[], int tam);
void mostrar_mayoritario(int v[], int tam);
int es_palindromo(int v[], int tam);
void buscar_repeticiones(int v[], int tam);

int main()
{
	int tam, x;
	
	printf("- Ingrese tamanio del vector: ");
	tam = ingresar_int_rango(1, 100);
	int v[tam];
	llenar_vector(v, tam);
	
	printf("\n");
	
	mostrar_promedio(v, tam);
	mostrar_mayoritario(v, tam);
	
	if (es_palindromo(v, tam) == 1)
		printf("c. El vector es palindromo.\n\n");
	else
		printf("c. El vector no es palindromo.\n\n");
		
	buscar_repeticiones(v, tam);
}

void mostrar_promedio(int v[], int tam)
{
	int i, suma=0;
	for (i=0; i<tam; i++)
	{
		suma += v[i];
	}

	printf("a. El promedio es: %.3f\n\n", (suma/(float)tam) );
}

void mostrar_mayoritario(int v[], int tam)
{
	int i, j, cont=0, mayoritario=-1;
	
	for (i=0; i<tam; i++)
	{
		cont=0;
		
		for (j=0; j<tam; j++)

			if (v[i] == v[j])
				cont++;

		if (cont >= tam/(float)2)
			mayoritario=v[i];
	}
	
	if (mayoritario==-1)
		printf("b. No hay elemento mayoritario.\n\n");
	else
		printf("b. Elemento mayoritario: %d\n\n", mayoritario);
}

int es_palindromo(int v[], int tam)
{
	int i, j=tam-1, n=1;
	
	for (i=0; i<tam; i++)
	{
		if (v[i] != v[j])
			n=0;
		j--;
	}
	return n;
}

void buscar_repeticiones(int v[], int tam)
{
	int x, i, cont=0;
	printf("d. Ingrese valor a buscar: ");
	x = ingresar_int_rango(-1000000, 1000000);
	
	for (i=0; i<tam; i++)
		if(v[i] == x)
			cont++;
	
	if (cont>1)
		printf("   El valor %d se repite %d veces.\n\n", x, cont);
	else if (cont>0)
		printf("   El valor %d se repite 1 vez.\n\n", x);
	else
		printf("   El valor %d no esta en el vector.\n\n");
	
}

// Valida un rango [min, max]
int ingresar_int_rango(int min, int max)
{
	int n, flag;
	
	do
	{
		flag=1;
		fflush(stdin);
		if (scanf("%d", &n) != 1 || n < min || n > max)
		{
			printf("- Error: Valor debe ser entre %d y %d.\n", min, max);
			printf("- Ingrese nuevamente: ");
			flag = 0;
		}
	} while(flag!=1);
	
	return n;
}

void llenar_vector(int v[], int tam)
{
	int i;
	for (i=0; i<tam; i++)
	{
		printf("  v[%d]: ", i);
		v[i] = ingresar_int_rango(-1000000, 1000000);
	}
}
