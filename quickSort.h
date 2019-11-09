/*Esta función toma el último elemento como pivote, lugares
el elemento pivote en su posición correcta en orden
matriz y coloca todos los más pequeños (más pequeños que el pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int Dividir (int arr[], int nInI, int nInF)  
{  
    int nPivote = arr[nInF]; // pivote
    int i = (nInI - 1); // Índice de elemento más pequeño
  
    for (int j = nInI; j <= nInF - 1; j++)  
    {  
        // Si el elemento actual es más pequeño que el pivote
        if (arr[j] < nPivote)  
        {  
            i++; // índice de incremento del elemento más pequeño
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[nInF]);  
    return (i + 1);  
}  
  
/*La función principal que implementa QuickSort
arr [] -> Matriz para ordenar,
nInI -> Índice inicial,
nInF -> índice final */
void quickSort(int arr[], int nInI, int nInF)  
{  
    if (nInI < nInF)  
    {  
        /* pi es el índice de partición, arr [p] es ahora
        en el lugar correcto */
        int pi = Dividir(arr, nInI, nInF);  
  
        // Separar elementos por separado antes
        //partición y después de la partición
        quickSort(arr, nInI, pi - 1);  
        quickSort(arr, pi + 1, nInF);  
    }  
}  