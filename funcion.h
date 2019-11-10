static double tam = 100000; // Tamaño de la muesta

void printArray(int size, int *arr)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		if (i < size - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void swap(int i, int j, int *arr)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int randInt(int min, int max)
{
	int randomNum = (int)(rand() % (max - min + 1) + min);
	return randomNum;
}

void GeneradorDeNumeros()
{
	FILE *fp;

	fp = fopen("numeros.txt", "wt");

	if (fp == NULL)
	{
		fputs("error de lectura de archivo", stderr);
		exit(1);
	}

	char numero[] = "/0";

	double lg = tam;
	time_t t; // tipo definido en time.h
	register int i;

	srand((int)time(&t)); // Fija la semilla del generador:
						  // Inicializa el generador de numeros
						  // aleatorios con el reloj del sistema
	for (double i = lg; i >= 0; i--)
	{
		fprintf(fp, "%i", randInt(0,10000));
		fprintf(fp, " ");
	}
	fclose(fp);
}