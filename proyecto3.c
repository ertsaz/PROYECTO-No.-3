#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // 
#include "Funs_Ayudas.h" // funciones que son comunes entre archivos
#include "Algoritmo_De_Ordenamientos.h" // Llaman a los dos algoritmos de ordenamiento

void printLog(char text[300])
{
    char filename[300];
    sprintf(filename, "output.log");
    escribirArchivo(filename, text);
}

void printResult(char *algorithm, int size, double timeSpent)
{
    char filename[300];
    sprintf(filename, "CPP_%s.csv", algorithm);
    char log[300];
    sprintf(log, "%d, %f", size, timeSpent);
    escribirArchivo(filename, log);
}

void CompaAlgorit(char *cNom_Algorit, int nTam, int *arrNumeros)
{
    char log[300];

    sprintf(log, "----------------------------------------------------------------");
    printLog(log);
    sprintf(log, "Lenguaje C");
    printLog(log);
    sprintf(log, "Nombre del algoritmo: %s", cNom_Algorit);
    printLog(log);
    sprintf(log, "nTam de Arreglo: %d", nTam);
    printLog(log);

    // Get init time
    clock_t tIni_Tiemp, tFin_Tiemp;
    double timeSpent = (double)(tFin_Tiemp - tIni_Tiemp) / CLOCKS_PER_SEC;

    // Sort cNom_Algorit
    if (strcmp(cNom_Algorit, "heapSort") == 0)
    {
        tIni_Tiemp = clock();
        heapSort(arrNumeros, nTam);
    }
    else if (strcmp(cNom_Algorit, "quickSort") == 0)
    {
        tIni_Tiemp = clock();
        quickSort(0, nTam, arrNumeros);
    }

    tFin_Tiemp = clock();
    timeSpent = (double)(tFin_Tiemp - tIni_Tiemp) / CLOCKS_PER_SEC;

    sprintf(log, "La tarea del algoritmo ha tomado% f segundos", timeSpent);
    printLog(log);
    printResult(cNom_Algorit, nTam, timeSpent);
}

//Leer números del archivo y almacenarlo en una matriz en la memoria
void LeerNumeroArchivo(int nTam, int *arrNumeros)
{
    int i = 0;
    char fileArchivo[] = "numeros.txt";
    char str[1000];

    FILE *file;
    file = fopen(fileArchivo, "r");
    if (file)
    {
        while (i < nTam && fscanf(file, "%s", str) != EOF)
        {
            arrNumeros[i] = atoi(str);
            i++;
        }
        fclose(file);
    }
}

int main(int argc, char const *argv[])
{
    int nAlgoritmo = 0, nTam = 0, nIncreTam = 10, nIncreTamAux = 1;

    GeneradorDeNumeros();

    char cNom_Algorit[50];
    int *arrNumeros;

    for (nIncreTam = 10, nIncreTamAux = 1, nTam = 10; nTam <= 1000000; nTam += nIncreTam)
    {
        if (nIncreTamAux % 10 == 0)
        {
            nIncreTamAux = 1;
            nIncreTam = nIncreTam * 10;
        }

        for (nAlgoritmo = 0; nAlgoritmo < 2; nAlgoritmo++)
        {
            strcpy(cNom_Algorit, (nAlgoritmo == 0) ? "heapSort" : "quickSort");

            arrNumeros = (int *)malloc(sizeof(int) * nTam);

            //Leer números del archivo
            LeerNumeroArchivo(nTam, arrNumeros);

            //Ejecutar algoritmo de ordenación
            CompaAlgorit(cNom_Algorit, nTam, arrNumeros);
        }

        nIncreTamAux++;
    }
    free(arrNumeros);
    return 0;
}
