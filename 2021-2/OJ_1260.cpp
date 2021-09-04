//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--){//Test cases
    int n;
    cin >> n;
    vector<int> v;
    int suma=0;
    for(int i=0; i<n; ++i){
      int aux;
      cin >> aux;//Va leyendo la entrada valor por valor
      v.push_back(aux);
      int j;
      for(j=v.size()-2; j>=0; --j){//Por cada valor nuevo, lo compara hacia atras hasta que encuentra el primer valor menor a el, la idea es dejar el arreglo ordenado.
        if(v[j]>aux)v[j+1]=v[j];
        else{
          break;
        }
      }
      v[j+1]=aux;
      suma+=j+1; //agrega a la suma la posición del valor. la posición del valor es igual a cuantos valores son menores o iguales a el puesto que el vector está ordenado.
    }
    cout << suma << "\n";
  }
  return 0;
}