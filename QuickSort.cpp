// Programa para el algoritmo QuickSort

#include <iostream>

using namespace std;

void cambio_a(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

// Función para partir el arreglo en las bases del pivote
int partition(int array[], int low, int high) {
  // Seleccionamos el elemento pivote
  int pivot = array[high];
  int i = (low - 1);

  // Colocamos los elementos menores que el pivote a la derecha y 
  // los mayores a la izquierda
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      cambio_a(&array[i], &array[j]);
    }
  }
  cambio_a(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    // Seleccionamos la pocisión del pivote y colocamos los 
    // elementos menores a la derecha y los mayores a la izquierda
    int pi = partition(array, low, high);

    // Ordenamos los elementos a la izquierda de pivote
    quickSort(array, low, pi - 1);

    // Ordenamos los elementos a la derecha del pivote
    quickSort(array, pi + 1, high);
  }
}

int main(){
    int arr[] = {8, 4, 6, 1, 3, 9, 2, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}