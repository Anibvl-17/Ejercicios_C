// INCLUIR string.h
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

// INCLUIR string.h
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
			// Valida letras minusculas y mayusculas.
			if (
				(palabra[i] < 65) || (palabra[i] > 122) || 
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
