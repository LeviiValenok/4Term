#include <iostream>
#include <cstring>

#include "functions.h"

template <typename T>
void findSuitableItem(T array[], T key , T value,  int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            std::cout << "Suitable item is >> " << array[i] <<"\n Index is >> " << i << std::endl;
            array[i] = value;
            k++;
        }
    }
    if (k == 0)
    {
        std::cout << "There are no suitable items in integer array" << std::endl;
        return;
    }
    std::cout << "Result is >>" << std:: endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout <<'\n';
}
template <typename T>

void removeDuplicates(T array[], T key, T value, int size)
{
    int k = 0;
    for (int i = 0; i <size; i++)
    {
        if (array[i] == key)
        {
            if (k == 0)
            {
                array[i] = value;
                k++;
            }
            else
            {
                if(i != size - 1)
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        array[j] = array[j + 1];
                    }
                    size--;
                    i--;
                }
                else
                {
                    size--;
                }
            }
        }

    }
    if (k == 0)
    {
        std::cout << "There are no suitable items in integer array" << std::endl;
        return;
    }
    std::cout << "Result is >>" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }

}
template <>
void findSuitableItem(char array[], char key, char letter, int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if(array[i] == key)
        {
            std::cout << "Suitable item is >> " << array[i] <<"\n Index is >> " << i << std::endl;
            array[i] = letter;
            k++;
        }
    }
    if (k == 0)
    {
        std::cout << "There are no suitable items in char sentence" << std::endl;
        return;
    }

    std::cout << "Result is >>" << std:: endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i];
    }
    std::cout << std:: endl;
}

template <>

void removeDuplicates(char array[], char key, char letter, int size)
{
    int k = 0;
    for (int i = 0; i <size; i++)
    {
        if (array[i] == key)
        {
            if (k == 0)
            {
                array[i] = letter;
                k++;
            }
            else
            {
                if (i != size - 1)
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        array[j] = array[j + 1];
                    }
                    size--;
                    array[size] = '\0';
                    i--;
                } else
                {
                    size--;
                    array[size] = '\0';
                }
            }
        }

    }
    if (k == 0)
    {
        std::cout << "There are no suitable items in integer array" << std::endl;
        return;
    }
    std::cout << "Result is >>" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i];
    }
   std::cout << std:: endl;

}




int main()
{
    std::cout << "Enter an integer key >>" << std::endl;
    int key;
    key = inputValidation();
    char keyLetter;
    int array[9]
        {1, 3, 6, 8, 9, 8, 4, 6, 0};
    int size = sizeof(array) / sizeof(key);
    findSuitableItem(array, key, 4, size);

    std::cout << "Enter an integer key >>" << std::endl;
    key = inputValidation();
    removeDuplicates(array, key, 10, size);
    std::cout << '\n';


    char charArray[30];
    inputSentence(charArray);
    int length = strlen(charArray);
    std::cout << "Enter a char key>>" << std::endl;
    std::cin >> keyLetter;
    findSuitableItem(charArray, keyLetter, 'A', length );
    std::cout <<std:: endl;
    std::cout << "Enter a char key >>" << std::endl;
    std::cin >> keyLetter;
    removeDuplicates(charArray, keyLetter, '-', length);


   switch(menu())
   {
       case 1:
       {
           char integerArray[40];
           char alphabetArray[40];
           char marksArray[40];
           char sentence[80];
           inputSentence(sentence);
           std::cout << sentence << std::endl;
           splitStringsWithOption(sentence, integerArray, alphabetArray, marksArray);
           std::cout <<"Integer array : " << integerArray << std:: endl;
           std::cout <<"Alphabet array : " << alphabetArray << std:: endl;
           std::cout <<"Marks array : " << marksArray << std:: endl;
           break;
       }
       case 0:
       {
           break;
       }
   }






//    int i = 0;
//    int a = 0;
//    int m = 0;
//    for (int j = 0; j < strlen(sentence); j++)
//    {
//        if (sentence[j] >= 48 && sentence[j] <=57)
//        {
//            integerArray[i] = sentence[j];
//            i++;
//        }
//        if (sentence[j] >= 68 && sentence[j] <= 122)
//        {
//            alphabetArray[a] = sentence[j];
//            a++;
//        }
//        if ((sentence[j] >= 33 && sentence[j] <= 47) ||
//                (sentence[j] >= 58 && sentence[j] <= 64) ||
//                (sentence[j] >= 91 && sentence[j] <= 96))
//        {
//            marksArray[m] = sentence[j];
//            m++;
//        }
//    }
//
//    alphabetArray[a] = '\0';
//    marksArray[m] = '\0';
//    integerArray[i] = '\0';
//
//    sortEveryString(alphabetArray);
//    sortEveryString(integerArray);
//    sortEveryString(marksArray);
//





    return 0;
}


//ключ задаёт пользователь
//+функция удаления дубликатов
//функкция независимая от предыдущих, будет разбивать чар строку на 3 отдельных массива, 1) от меньшего
//к большему массив чисел, 2) а алфавитном порядке все буквенные значения, 3)все знаки, символы по аски коды,
//ввод строки с клавиатуры. Можно сделать отдельно от основной задачи.