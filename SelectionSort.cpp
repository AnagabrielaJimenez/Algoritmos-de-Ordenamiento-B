//Programa para el algoritmo SelectionSort

#include <iostream>
using namespace std;

//Función para el cambio de elementos
void cambio_a(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void selectionSort(int array[], int tam) {
  for (int i=0; i<tam-1; i++) {
    int min = i;
    for (int j=i+1; j<tam; j++) {

      // Para el orden descendente, solo se cambia > a < en esta línea.
      // Selecciona el número mínimo en cada iteración.
      if (array[j] < array[min])
        min = j;
    }

    // cambio de posición
    cambio_a(&array[min], &array[i]);
  }
}

int main() {
  int arr[] = {2, 3, 6, 1, 4, 9, 8, 7, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}