#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Метод, возвращающий заполненный пользователем массив.
 * @param size_ размер массива.
 * @return заполненный массив.
 */
int* InputArray(const size_t size_);

/**
 * @brief Вывод массива на консоль.
 * @param array массив.
 * @param size_ размер массива.
 */
void To_String(const int* array, const size_t size_);


/**
 * @brief Сортировка пузырьком.
 * @param array массив.
 * @param size_ размер массива.
 */
void BubbleSort(int* array, const size_t size_);

/**
 * @brief ввод и проверка на корректное число элементов массива
 * @param message вывод определённой фразы при выполнении
 * @param size размер массива
 */
size_t get_size(const std::string& message);

int main()
{
  size_t sizeArr;

  try{
    sizeArr = get_size("Input size array: ");
  }
  catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
  }

  size_t size = sizeArr;
  int* NewArray = nullptr;


  NewArray = InputArray(size);

  To_String(NewArray, size);

  BubbleSort(NewArray,size);

  To_String(NewArray, size);

  if (NewArray != nullptr)
{
   delete[] NewArray;
   NewArray = nullptr;
}


  return 0;
}

size_t get_size(const std::string& message)
{
    int size = -1;
    std::cout << message;
    std::cin >> size;

    if (size <= 0)
    {
        throw std::out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return size;
}

int* InputArray(const size_t size_){

  int* array = new int[size_];

  cout<<"Введите данные в массив\n";

  for (size_t index = 0 ; index < size_; index++){
      cin >> array[index];
    }

  return array;
}

void To_String(const int* array, const size_t size_){

  // Проверка массива на сущестование
    if (array == nullptr)
    {
        throw std::logic_error("Array = nullptr");
    }

  for(size_t index = 0;index < size_ ;index++){
    cout << std::to_string(array[index])<<" ";
  }
  cout<<"\n";
}

void BubbleSort(int* array, const size_t size_)
{
  size_t tmp = 0;
  for(size_t i = 0 ; i < size_; i++){
    for(size_t j = (size_-1) ; j >= (i+1) ; j--){
      if(array[j] < array[j-1]){
        tmp = array[j];
        array[j]=array[j-1];
        array[j-1]=tmp;
      }
    }
  }
}
