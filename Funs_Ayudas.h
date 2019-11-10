static double tam = 10000000; // Tamaño de la muesta

void escribirArchivo(char filename[140], char text[300])
{
	FILE *file;
	file = fopen(filename, "a");
	if (file)
	{
		fprintf(file, "%s\n", text);
		fclose(file);
	}
}

void swap(int i, int j, int *arr)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

// generacion de un numero aleatorio 
int randInt(int min, int max)
{
	int randomNum = (int)(rand() % (max - min + 1) + min);
	return randomNum;
}

void GeneradorDeNumeros()
{
	FILE *fp;
	char aux[80];

	fp = fopen("numeros.txt", "wt");

	if (fp == NULL)
	{
		fputs("error de lectura de archivo", stderr);
		exit(1);
	}

	char numero[] = "/0";

	int lg = tam;
	time_t t; // tipo definido en time.h
	register int i;

	srand((int)time(&t)); // Fija la semilla del generador:
						  // Inicializa el generador de numeros
						  // aleatorios con el reloj del sistema
	for (int i = lg; i >= 0; i--)
	{
		sprintf(aux, "%i", randInt(0, 1000000));
		strcat(aux, " ");
		if (i % 10 == 0)
		{
			fprintf(fp, "%s", aux);
			strcpy(aux, "");
		}
	}
	fclose(fp);
}