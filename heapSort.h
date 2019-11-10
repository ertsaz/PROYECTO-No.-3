//Para heapificar un subárbol enraizado con el nodo i que es
//un índice en arr []. n es el tamaño del montón
void heapify (int *numbers, int size, int i) {
    int largest = i;  //Inicializar más grande como root
    int l = 2*i + 1;  //izquierda = 2 *i + 1
    int r = 2*i + 2;  //right = 2 *i + 2
    int tmp;

    //Si el hijo izquierdo es más grande que la raíz
    if (l < size && numbers[l] > numbers[largest]) {
        largest = l;
    }

    //Si el hijo derecho es más grande que el mayor hasta ahora
    if (r < size && numbers[r] > numbers[largest]) {
        largest = r;
    }

    //Si el más grande no es root
    if (largest != i) {
        swap(i, largest, numbers);

        //Heapify recursivamente el subárbol afectado
        heapify(numbers, size, largest);
    }
}

//función principal para hacer la ordenación del montón
void heapSort (int *numbers, int size) {
    int i, tmp;
    //Build heap (reorganizar matriz)
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(numbers, size, i);
    }

    //Uno por uno extrae un elemento del montón
    for (i = size-1; i >= 0; i--) {
        //Mover la raíz actual al final
        swap(0, i, numbers);

        //call max heapify en el montón reducido
        heapify(numbers, i, 0);
    }
}