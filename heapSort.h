//Para heapificar un subárbol enraizado con el nodo i que es
//un índice en arr []. n es el tamaño del montón
void heapify(int arr[], int n, int i) 
{ 
	int MasGrande = i; //Inicializar más grande como root
	int nIzq = 2*i + 1; //izquierda = 2 *i + 1
	int nDer = 2*i + 2; //right = 2 *i + 2

	// Si el hijo izquierdo es más grande que la raíz
	if (nIzq < n && arr[nIzq] > arr[MasGrande]) 
		MasGrande = nIzq; 

	// Si el niño correcto es más grande que el más grande hasta ahora
	if (nDer < n && arr[nDer] > arr[MasGrande]) 
		MasGrande = nDer; 

	// Si el más grande no es root
	if (MasGrande != i) 
	{ 
		swap(arr[i], arr[MasGrande]); 

		// Heapify recursivamente el subárbol afectado
		heapify(arr, n, MasGrande); 
	} 
} 

// función principal para hacer el montón
void heapSort(int arr[], int n) 
{ 
	// Construir montón (reorganizar matriz)
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// Uno por uno extrae un elemento del montón
	for (int i=n-1; i>=0; i--) 
	{ 
		// Mover la raíz actual al final
		swap(arr[0], arr[i]); 

		// llamar a max heapify en el montón reducido
		heapify(arr, i, 0); 
	} 
} 