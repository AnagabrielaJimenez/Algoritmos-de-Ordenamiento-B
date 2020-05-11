// Programa del algoritmo InsertionSort
#include <iostream> 
using namespace std; 
  
void insertionSort(int array[], int tam) {
  for (int i = 1; i < tam; i++) {
    int aux = array[i];
    int j = i - 1;

    // Compara el auxiliar(aux) con cada elemento a la izquierda del mismo 
    // hasta que se encuentre un elemento más pequeño de lo que se encuentra.
    // Para el orden descendiente , solo se cambia aux<array[j] por aux>array[j].
    while (aux < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = aux;
  }
}
int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    insertionSort(arr, n); 
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}  