#include <iostream>

int LCS(int** DP, int* vec1, int* vec2, int indexVec1, int indexVec2);
void printLCS(int** DP, int* vec1, int* vec2, int currentIndex1, int currentIndex2, bool* printPath);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenVec1, lenVec2, *vec1, *vec2, **DP;
  bool print = false;

  std::cin >> lenVec1 >> lenVec2;

  vec1 = new int[lenVec1];
  vec2 = new int[lenVec2];
  DP = new int*[lenVec1];

  for(int i = 0; i < lenVec1; i++){

    DP[i] = new int[lenVec2];

    for(int j = 0; j < lenVec2; j++)
      DP[i][j] = -1;

    std::cin >> vec1[i];

  }

  for(int j = 0; j < lenVec2; j++)
    std::cin >> vec2[j];

  LCS(DP, vec1, vec2, (lenVec1 - 1), (lenVec2 - 1));
  printLCS(DP, vec1, vec2, (lenVec1 - 1), (lenVec2 - 1), &print);

  std::cout << std::endl;

  return 0;
}

void printLCS(int** DP, int* vec1, int* vec2, int currentIndex1, int currentIndex2, bool* printPath){

  if(currentIndex1 < 0 || currentIndex2 < 0)
    return;

  if(vec1[currentIndex1] == vec2[currentIndex2]){

    printLCS(DP, vec1, vec2, currentIndex1 - 1, currentIndex2 - 1, printPath);

    if((*printPath))
      std::cout << ' ';

    std::cout << vec1[currentIndex1];
    (*printPath) = true;

  }

  else if(currentIndex1 == 0 || currentIndex2 == 0)
    return;

  else if(DP[currentIndex1 - 1][currentIndex2] > DP[currentIndex1][currentIndex2 - 1])
    printLCS(DP, vec1, vec2, currentIndex1 - 1, currentIndex2, printPath);

  else
    printLCS(DP, vec1, vec2, currentIndex1, currentIndex2 - 1, printPath);

}

int LCS(int** DP, int* vec1, int* vec2, int indexVec1, int indexVec2){

  int resultado, tmp1, tmp2;

  if(indexVec1 < 0 || indexVec2 < 0)
    return 0;

  if(DP[indexVec1][indexVec2] != -1)
    return DP[indexVec1][indexVec2];

  if(vec1[indexVec1] == vec2[indexVec2])
    resultado = 1 + LCS(DP, vec1, vec2, indexVec1 - 1, indexVec2 - 1);

  else{

    tmp1 = LCS(DP, vec1, vec2, indexVec1 - 1, indexVec2);
    tmp2 = LCS(DP, vec1, vec2, indexVec1, indexVec2 - 1);

    resultado = std::max(tmp1, tmp2);

  }

  DP[indexVec1][indexVec2] = resultado;

  return DP[indexVec1][indexVec2];

}
