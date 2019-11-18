/*
             ███████████                                   ██████   █████  ████████
            ░░███░░░░░███                                 ░░██████ ░░███  ███░░░░███
             ░███    ░███ ████████   ██████  █████ ████    ░███░███ ░███ ░░░    ░███
             ░██████████ ░░███░░███ ███░░███░░███ ░███     ░███░░███░███    ██████░
             ░███░░░░░░   ░███ ░░░ ░███ ░███ ░███ ░███     ░███ ░░██████   ░░░░░░███
             ░███         ░███     ░███ ░███ ░███ ░███     ░███  ░░█████  ███   ░███
             █████        █████    ░░██████  ░░███████     █████  ░░█████░░████████
            ░░░░░        ░░░░░      ░░░░░░    ░░░░░███    ░░░░░    ░░░░░  ░░░░░░░░
                                              ███ ░███
                                             ░░██████
                                              ░░░░░░
             ██████████              █████                        █████ █████
            ░░███░░░░███            ░░███                        ░░███ ░░███
             ░███   ░░███  ██████   ███████    ██████   █████     ░███  ░███
             ░███    ░███ ░░░░░███ ░░░███░    ███░░███ ███░░      ░███  ░███
             ░███    ░███  ███████   ░███    ░███ ░███░░█████     ░███  ░███
             ░███    ███  ███░░███   ░███ ███░███ ░███ ░░░░███    ░███  ░███
             ██████████  ░░████████  ░░█████ ░░██████  ██████     █████ █████
            ░░░░░░░░░░    ░░░░░░░░    ░░░░░   ░░░░░░  ░░░░░░     ░░░░░ ░░░░░
*/

/* 
Prof. Crispina Ramos
    TEMA: Métodos y algoritmos de estructuras de datos complejas
    OBJETIVOS:
        -Algoritmo de ordenamiento y su eficiencia Quicksort vs Heapsort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //
#include <time.h>
#include <windows.h>
#include "Funs_Ayudas.h"                // funciones que son comunes entre archivos
#include "Algoritmo_De_Ordenamientos.h" // Llaman a los dos algoritmos de ordenamiento

// Funcion que crea y genera un archivo para registrar
// las acciones del programa
void printLog(char text[300])
{
    char NombreArch[300];
    sprintf(NombreArch, "resultados/output.log"); // crea la carpeta y guarda la informacion para ver despues
    escribirArchivo(NombreArch, text);
}

// Funcion que crea un archivo excel con los datos del algoritmo de turno
void printResult(char *cNom_Algorit, int nTam, double tTiempoEjec, int nInter)
{
    char NombreArch[300];
    sprintf(NombreArch, "resultados/C_%s.csv", cNom_Algorit); // crea la carpeta y guarda la informacion
    char log[300];
    char logt[300];

    if (nTam > 10)
    {
        sprintf(log, "%d, %f, %i", nTam, tTiempoEjec, nInter);
        escribirArchivo(NombreArch, log);
    }
    else
    {
        sprintf(logt, "%s, %s, %s \n", "tam del arreglo", "tiempo", "intercambio");
        sprintf(log, "%d, %f, %i", nTam, tTiempoEjec, nInter);
        strcat(logt, log);
        escribirArchivo(NombreArch, logt);
    }
}

// Funcion que crea un archivo excel con los datos del algoritmo de turno
void printMuestra(char *cNom_Algorit, int nTam, int *arrNumeros, const char *modo)
{
    char NombreArch[300];
    sprintf(NombreArch, "resultados/C_muestra_%s.csv", cNom_Algorit); // crea la carpeta y guarda la informacion
    char log[3000] = " ";
    char logtemp[300] = " ";
    strcpy(log, modo);
    strcat(log, "\n");
    for (int i = 0; i < nTam; i++)
    {
        if (i < nTam - 1)
        {
            sprintf(logtemp, "%d, ", arrNumeros[i]);
        }
        else if (i == nTam - 1)
        {
            sprintf(logtemp, "%d\n", arrNumeros[i]);
        }
        strcat(log, logtemp);
    }
    escribirArchivo(NombreArch, log);
    strcpy(log, "");
}

void CompaAlgorit(char *cNom_Algorit, int nTam, int *arrNumeros)
{
    char log[300];
    int nInter = 0;

    sprintf(log, "----------------------------------------------------------------");
    printLog(log);
    sprintf(log, "Lenguaje C");
    printLog(log);
    sprintf(log, "Nombre del algoritmo: %s", cNom_Algorit);
    printLog(log);
    sprintf(log, "TAmaño del Arreglo: %d", nTam);
    printLog(log);

    LARGE_INTEGER frequency;
    LARGE_INTEGER t1, t2;
    double tTiempoEjec;
    QueryPerformanceFrequency(&frequency);

    if (nTam == 10 || nTam == 100)
        printMuestra(cNom_Algorit, nTam, arrNumeros, "original");

    if (strcmp(cNom_Algorit, "heapSort") == 0)
    {
        QueryPerformanceCounter(&t1);
        heapSort(arrNumeros, nTam, &nInter);
    }
    else if (strcmp(cNom_Algorit, "quickSort") == 0)
    {
        QueryPerformanceCounter(&t1);
        quickSort(0, nTam - 1, arrNumeros, &nInter); // arreglado daba basura
    }

    QueryPerformanceCounter(&t2);
    tTiempoEjec = (float)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;

    sprintf(log, "La tarea del algoritmo ha tomado %f segundos", tTiempoEjec);
    printLog(log);
    printResult(cNom_Algorit, nTam, tTiempoEjec, nInter);
    nInter = 0;

    if (nTam == 10 || nTam == 100)
        printMuestra(cNom_Algorit, nTam, arrNumeros, "ordenado");
}

//Leer números del archivo y almacenarlo en una matriz en la memoria
void LeerNumeroArchivo(int nTam, int *arrNumeros)
{
    int i = 0;
    char fileArchivo[] = "numeros.txt";
    char str[10000];

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
    int nAlgoritmo = 0, nTam = 0, nIncreTam = 0, nIncreTamAux = 1;

    // genera numeros al azar
    GeneradorDeNumeros();

    char cNom_Algorit[50]; // almacena los nombres de los algoritmos
    int *arrNumeros;       // arreglo dinamico
    // Ciclo que aumenta el tamaño del areglo de 10 en 10
    for (nIncreTam = 10, nIncreTamAux = 1, nTam = 10; nTam <= 10000000; nTam += nIncreTam)
    {

        // condicion para incrementar el tamaño
        // del arreglo de 10 en 10 modificando nIncreTam
        if (nIncreTamAux % 10 == 0)
        {
            nIncreTamAux = 1;
            nIncreTam = nIncreTam * 10;
        }

        // Ciclo for{} realiza los dos algoritmos  con el mismo tamaño de arreglo
        // automaticamente uno seguido de otro con
        for (nAlgoritmo = 0; nAlgoritmo < 2; nAlgoritmo++)
        {
            strcpy(cNom_Algorit, (nAlgoritmo == 0) ? "heapSort" : "quickSort");

            // Se crea un arreglo de tamaño dinamico para los
            // diferentes casos
            arrNumeros = (int *)malloc(sizeof(int) * nTam);

            // Leer números del archivo
            LeerNumeroArchivo(nTam, arrNumeros);

            // Ejecutar algoritmo de ordenación
            // dependiendo de el algoritmo
            CompaAlgorit(cNom_Algorit, nTam, arrNumeros);

            printf("Algoritmo %-10s Porcesos completos [%-7i/%i]\n", cNom_Algorit, nTam, 1000000); // muestra progreso
        }

        nIncreTamAux++;
    }
    free(arrNumeros);
    return 0;
    exit(1); //cerrado automatico
}
