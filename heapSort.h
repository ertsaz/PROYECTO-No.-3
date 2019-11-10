//Para heapificar un subárbol enraizado con el nodo i que es
//un índice en arr []. n es el tamaño del montón
void heapify (int *arrNumeros, int nTam, int i) {
    int nMayor = i;  //Inicializar más grande como root
    int nIzq = 2*i + 1;  //izquierda = 2 *i + 1
    int nDer = 2*i + 2;  //derecha = 2 *i + 2
    int tmp;

    //Si el hijo izquierdo es más grande que la raíz
    if (nIzq < nTam && arrNumeros[nIzq] > arrNumeros[nMayor]) {
        nMayor = nIzq;
    }

    //Si el hijo derecho es más grande que el mayor hasta ahora
    if (nDer < nTam && arrNumeros[nDer] > arrNumeros[nMayor]) {
        nMayor = nDer;
    }

    //Si el más grande no es root
    if (nMayor != i) {
        swap(i, nMayor, arrNumeros);

        //Heapify recursivamente el subárbol afectado
        heapify(arrNumeros, nTam, nMayor);
    }
}

//función principal para hacer la ordenación del montón
void heapSort (int *arrNumeros, int nTam) {
    int i, tmp;
    // (reorganizar el arreglo)
    for (i = nTam / 2 - 1; i >= 0; i--) {
        heapify(arrNumeros, nTam, i);
    }

    //Uno por uno extrae un elemento del montón
    for (i = nTam-1; i >= 0; i--) {
        //Mover la raíz actual al final
        swap(0, i, arrNumeros);

        //llama maximo heapify en el montón reducido
        heapify(arrNumeros, i, 0);
    }
}