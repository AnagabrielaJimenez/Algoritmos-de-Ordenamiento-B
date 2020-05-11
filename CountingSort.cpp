//Programa para el algoritmo CountingSort

#include <iostream>

using namespace std;

void countSort(int array[], int tam){
  // El tamaño de count debe ser (max +1) pero
  // no podemos declarar count[max+1] en C++ ya que
  // no admite la asignación dinámica de memoria.
  // Entonces, lo declaramos con espacio estático suficiente para las siguientes operaciones.
  int resultado[10];
  int count[10];
  int max = array[0];

  //Buscamos el elemento máximo del arreglo
  for (int i = 1; i < tam; i++){
    if (array[i] > max)
      max = array[i];
  }

  // Inicializamos count con 0 en todos sus elementos
  for (int i = 0; i <= max; ++i){
    count[i] = 0;
  }

  // Almacenamos las repeticiones de cada elemento.
  for (int i = 0; i < tam; i++) {
    count[array[i]]++;
  }

  // Reasignamos los valores de count por la suma del elemento a reemplazar con el elemento anterior.
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  //Asignamos los valores del arreglo resultado, tomando cada elemento del arreglo array para buscar 
  //el índice el arreglo count, y el valor almacenado en ese índice es restado en 1 para buscar el
  //índice del arreglo resultado y asignar como valor el elemento que habíamos tomado de array anteriormente.
  for (int i = tam - 1; i >= 0; i--) {
    resultado[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  //Finalmente copiamos los elementos ordenados en los elementos de array.
  for (int i = 0; i < tam; i++) {
    array[i] = resultado[i];
  }
}

int main(){
    int arr[] = {1, 2, 2, 5, 7, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}