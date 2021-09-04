//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>

using namespace std;

int scores[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60}; //arreglo de puntajes

int permutar(int i, int j, int k){//dada una combinación, ve si hay igualdades entre los 3 valores para devolver 1, 3 o 6 permutaciones.
  int permutations=6;
  if(i==j){
    permutations=3;
  }
  if(j==k){
    permutations-=3;
  }
  if(permutations==6 && i==k){
    permutations=3;
  }
  if(!permutations)++permutations;
  return permutations;
}

int main() {
  int score;
  cin >> score;
  while(score>0){//lee la entrada mientras sea mayor a 0
    int combinations=0, permutations=0;
    for(int i=0; i<43; ++i){
      for(int j=i; j<43; ++j){
        for(int k=j; k<43; ++k){//itera en todas las combinaciones de puntajes
          if(scores[i]+scores[j]+scores[k]>score)break;
          else if(scores[i]+scores[j]+scores[k]==score){//suma a combinations cuando encuentra una combinación
            ++combinations;
            //cerr << combinations << ": " << scores[i] << " " << scores[j] << " " << scores[k] << "\n";
            permutations+=permutar(i,j,k);//por cada combinación, calcula cuantas permutaciones sumar
          }
        }
        if(scores[i]+scores[j]>score)break;
      }
      if(scores[i]>score/3)break;
    }
    if(combinations){//imprime
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << combinations << ".\n";
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << permutations << ".\n";
    }
    else cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
    int aux=70;
    while(aux--)cout << "*";
    cout << "\n";
    cin >> score;
  }
  cout << "END OF OUTPUT\n";
}