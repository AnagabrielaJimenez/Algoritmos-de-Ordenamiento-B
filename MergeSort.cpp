//Programa para el algoritmo MergeSort

#include <iostream>

using namespace std;

//Función fusionar dos subarreglos L y M en el arreglo array
void fusion_C(int array[], int p, int q, int r) {
  
  // Creamos L ← A[p..q] y M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = array[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = array[q + 1 + j];

  //Mantenemos el índice actual de los sub-arreglos y arreglo principal
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Hasta que alcanzemos cualquer elemento final de cualquier sub-arreglo
  // sub-arreglo seleccionamos el elemento más grande entre los elementos de L y M 
  // de L y M para colocarlo en la posición correcta en A[p..r].
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = M[j];
      j++;
    }
    k++;
  }

  // Cuando nos quedemos sin elementos en L o en M, tomamos los 
  // elementos restantes y los colocámos en A[p..r].
  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = M[j];
    j++;
    k++;
  }
}

// Función para dividir el arreglo en dos sub-arreglos
// ordenándolos y fusionándolos.
void mergeSort(int array[], int l, int r) {
  if (l < r) {
    // m es el punto en dónde se dividen en dos
    int m = l + (r - l) / 2;

    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);

    // Se fusionan los arreglos ordenados
    fusion_C(array, l, m, r);
  }
}

int main(){
    int arr[] = {1, 9, 3, 7, 4, 8, 5, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}