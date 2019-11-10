#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numeroAleatorio[9]; //Indices de 0 a 9, resultan 10 numeros
    int i, j;
    int hayRepeticiones;

    srand(time(NULL));
    for (i = 0; i <= 9; i++)
    {
        numeroAleatorio[i] = rand() % 29;
    }

    hayRepeticiones = 1;

    //Comprobar repeticiones
    while (hayRepeticiones == 1)
    {
        hayRepeticiones = 0;
        for (i = 0; i <= 9; i++)
        {
            for (j = i + 1; j <= 9; j++)
            {

                if (numeroAleatorio[i] == numeroAleatorio[j] && numeroAleatorio[i] != 29)
                { //Repetición
                    printf("Hay repeticion. Cambio de %d por %d \n", numeroAleatorio[i], numeroAleatorio[i] + 1);
                    numeroAleatorio[i] = numeroAleatorio[i] + 1;
                    hayRepeticiones = 1;
                }
                if (numeroAleatorio[i] == numeroAleatorio[j] && numeroAleatorio[i] == 29)
                { //Repetición
                    numeroAleatorio[i] = numeroAleatorio[i] - rand() % 28 + 1;
                    printf("Hay repeticion de 29. Cambio de 29 por %d \n", numeroAleatorio[i]);
                    hayRepeticiones = 1;
                }
            }
        }
    }

    for (i = 0; i <= 9; i++)
    {
        printf("Aleatorio %d vale: %d\n", i, numeroAleatorio[i]);
    }
    cin.get();
    return 0;
}