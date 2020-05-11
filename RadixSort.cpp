//Programa para el algoritmo RadixSort

#include <iostream>

using namespace std;

//Función para obtener el elemento más grande del arreglo
int max_C(int array[], int tam) {
  int max = array[0];
  for (int i = 1; i < tam; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Utilizamos counting sort para ordenar los elementos en las bases
// de los dígitos significativos
void countingSort(int array[], int tam, int dig) {
  const int max = 10;
  int result[tam];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculamos count de los elementos
  for (int i = 0; i < tam; i++)
    count[(array[i] / dig) % 10]++;

  // Calculamos recuento acumulativo
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Colocamos los elementos ordenados en orden xd
  for (int i = tam - 1; i >= 0; i--) {
    result[count[(array[i] / dig) % 10] - 1] = array[i];
    count[(array[i] / dig) % 10]--;
  }

  for (int i = 0; i < tam; i++)
    array[i] = result[i];
}

void radixsort(int array[], int tam) {
  // Obtenemos el elemento más grande
  int max = max_C(array, tam);

  // Aplicamos counting sort para ordenar de acuerdo 
  // a sus dígitos
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, tam, place);
}

int main(){
    int arr[] = {121, 432, 564, 23, 1, 45, 788, 999};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}