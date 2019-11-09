void printArray (int size, int *arr) {
	int i;
	for (i = 0; i < size; i++) {
   		printf("%d ", arr[i]);
   		if (i < size - 1) {
            printf(" ");
        }
	}
	printf("\n");
}

void swap (int i, int j, int *arr) {
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}