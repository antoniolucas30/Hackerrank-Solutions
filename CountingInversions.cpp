#include <iostream>

long long mergeSort(long* vec, long indexLeft, long indexRight);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tests;
  long* currentVec, lenVec;

  std::cin >> tests;

  for(int i = 0; i < tests; i++){

    std::cin >> lenVec;

    currentVec = new long[lenVec];

    for(long i = 0; i < lenVec; i++)
      std::cin >> currentVec[i];

    std::cout << mergeSort(currentVec, 0, (lenVec - 1)) << std::endl;

    delete[] currentVec;

  }

  return 0;
}

long long mergeFcn(long* vec, long indexLeft, long indexMiddle, long indexRight){

  long* temporaryArray = new long[indexRight - indexLeft + 1], changeLeft = indexLeft, changeRight = indexMiddle + 1, changeIndex = 0;
  long long countInversions = 0;

  while((changeLeft <= indexMiddle) && (changeRight <= indexRight)){

    if(vec[changeLeft] <= vec[changeRight])
      temporaryArray[changeIndex++] = vec[changeLeft++];

    else{

      temporaryArray[changeIndex++] = vec[changeRight++];
      countInversions += (indexMiddle - changeLeft) + 1;

    }

  }

  while(changeLeft <= indexMiddle)
    temporaryArray[changeIndex++] = vec[changeLeft++];

  while(changeRight <= indexRight)
    temporaryArray[changeIndex++] = vec[changeRight++];

  for(long i = 0, j = indexLeft; j <= indexRight; i++, j++)
    vec[j] = temporaryArray[i];


  delete[] temporaryArray;

  return countInversions;
}

long long mergeSort(long* vec, long indexLeft, long indexRight){

  int middle;
  long long countInversions = 0;

  if(indexLeft < indexRight){

    middle = (indexLeft + indexRight) / 2;

    countInversions += mergeSort(vec, indexLeft, middle);
    countInversions += mergeSort(vec, middle + 1, indexRight);

    countInversions += mergeFcn(vec, indexLeft, middle, indexRight);

  }

  return countInversions;

}
