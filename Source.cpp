#include <iostream>
#include <algorithm>

using namespace std;

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size_ размер массива.
 * \return заполненный массив.
 */
int* InputArray(const size_t size_);

/**
 * \brief Вывод массива на консоль.
 * \param array массив.
 * \param size_ размер массива.
 */
void ArrayPrint(const int* array, const size_t size_);


/**
 * \brief Сортировка пузырьком.
 * \param array массив.
 * \param size_ размер массива.
 */
void bubbleSort(int* array, const size_t size_);

int main() 
{
  size_t size;
  int* NewArray = nullptr;
  
  cout<<"Введите кол-во перменных ";
    cin >> size;
  
    if(size<=0){ 
      cout<<"You entered wrong size!\n";
      return 1;
    }
      
  NewArray = InputArray(size);

  ArrayPrint(NewArray, size);

  bubbleSort(NewArray,size);
  
  ArrayPrint(NewArray, size);

  delete[] NewArray;

  
  return 0;
}
  
int* InputArray(const size_t size_){

  int* array = new int[size_];

  cout<<"Введите данные в массив\n";
  
  for (size_t index = 0 ; index < size_; index++){
      cin >> array[index];
    }

  return array;
}

void ArrayPrint(const int* array, const size_t size_){
  for(size_t index =0;index < size_ ;index++){
    cout << array[index]<<" ";
  }
  cout<<"\n";
}

void bubbleSort(int* array, const size_t size_)
{
  int tmp = 0;
  for(int i = 0 ; i < size_; i++){
    for(int j = (size_-1) ; j >= (i+1) ; j--){
      if(array[j] < array[j-1]){
        tmp = array[j];
        array[j]=array[j-1];
        array[j-1]=tmp;
      }
    }
  }
}
