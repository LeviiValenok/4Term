
#include <iostream>
#include "functions.h"
#include <cstring>

int inputValidation()
{
    char number[10];
    std::cin >> number;
    int length = strlen(number);
    int i = 0;
    bool isTrue = true;
    while(isTrue)
    {
        while (i < length)
        {
            if (number[i] < '0' || number[i] > '9')
            {
                    isTrue = true;
                    std::cout << "Incorrect value" << std::endl;
                    std::cout << "Try again >>>" << std::endl;
                    std::cin >> number;
                    length = strlen(number);
                    i = 0;
                    break;

            }
            i++;
            isTrue = false;
        }
    }
    int value = atoi(number);

    return value;
}


void sortEveryString(char* sentence)
{
    for(int i = 0; i < strlen(sentence); i++)
    {
        for (int j = i + 1; j < strlen(sentence); j++)
        {

            if (sentence[j] < sentence[i])
            {
                char temp = sentence[i];
                sentence[i] = sentence[j];
                sentence[j] = temp;

            }

        }
    }
}

int menu()
{
    std::cout << "\t\tDo you want to split string into 3 arrays?" << std::endl;
    std::cout << "1 to split strings" << std:: endl;
    std::cout << "0 to exit" << std::endl;
    int choice = inputValidation();
    return choice;
}

void inputSentence(char sentence[])
{
    do {
        rewind(stdin);
        std::cout << "Enter sentence >>" << std:: endl;
        std::cin.getline(sentence, 80);
    } while (sentence[0] == '\0');

}


void splitStringsWithOption(char sentence[], char array1[], char array2[], char array3[])
{

    int i = 0;
    int a = 0;
    int m = 0;
    for (int j = 0; j < strlen(sentence); j++)
    {
        if (sentence[j] >= 48 && sentence[j] <=57)
        {
            array1[i] = sentence[j];
            i++;
        }
        if (sentence[j] >= 68 && sentence[j] <= 122)
        {
            array2[a] = sentence[j];
            a++;
        }
        if ((sentence[j] >= 33 && sentence[j] <= 47) ||
                (sentence[j] >= 58 && sentence[j] <= 64) ||
                (sentence[j] >= 91 && sentence[j] <= 96))
        {
            array3[m] = sentence[j];
            m++;
        }
    }

    array2[a] = '\0';
    array3[m] = '\0';
    array1[i] = '\0';

    sortEveryString(array2);
    sortEveryString(array1);
    sortEveryString(array3);
}