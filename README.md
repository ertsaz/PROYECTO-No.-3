```
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
```

Prof. Crispina Ramos
>TEMA: Métodos y algoritmos de estructuras de datos complejas

>OBJETIVOS: Algoritmo de ordenamiento y su eficiencia 
>Quicksort vs Heapsort

# Comencemos!
desarrollamos un programa que permite generar numeros aleatorios y almacenarlos en un archivo de texto, esto con el fin de poder analizar el mismo conjunto de datos entre los diferentes algoritmos

```
// genera numeros al azar
    GeneradorDeNumeros();
```

### Resultados

da como resultado una tabla de datos en formato cvs.

tam del arreglo| tiempo| intercambio| Nombre de algoritmo 
| ------ | ------ |------ |------ |
|10| 0.000003| 6| quickSort|
|10| 0.000003| 2| heapSort|
|20| 0.000004| 13| quickSort|
|20| 0.000004| 11| heapSort|
|30| 0.000005| 19| quickSort|
|30| 0.000018| 19| heapSort|
|40| 0.000127| 26| quickSort|
|40| 0.000008| 24| heapSort|
|50| 0.000010| 31| quickSort|
|50| 0.000010| 32| heapSort|


