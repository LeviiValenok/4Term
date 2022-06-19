//
// Created by gaydi on 17.12.2021.
//
#include <iostream>
#include <cstring>
#include "functions.h"

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
    isTrue = true;
    return value;
}

int menu()
{
    std::cout << "1 to input trains" << std::endl;
    std::cout << "2 to output trains" << std::endl;
    std::cout << "3 to delete duplicates" << std::endl;
    std::cout << "4 to find in range" << std::endl;
    std::cout << "0 to exit " << std::endl;
    std::cout << "Your choice >>> " << std::endl;
    int choice;
    choice = inputValidation();
    while (choice < 0 || choice > 4)
    {
        std::cout << "Incorrect value. Please try again" << std::endl;
        choice = inputValidation();
    }
    return choice;
}

int deleteDuplicates(railway::Train *trainArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (trainArray[i].direction == trainArray[j].direction)
            {
                for (int k = i; k < size - 1; k++)
                {
                    trainArray[k] = trainArray[k + 1];
                }
                size --;
            }
        }
    }
    return size;
}


void findInRange(railway::Train *trainArray, int size, int lowBorder, int highBorder)
{
    int counter = 1;
    for (int i = 0; i < size; i++)
    {
        if (trainArray[i].engine.power > lowBorder && trainArray[i].engine.power < highBorder)
        {
            std::cout << "[" << counter << "]" << std::endl;
            trainArray[i].outputInformationTrain();
            counter ++;
        }
    }
}

/*
int size = 3;
railway::Train* trainArray = new railway::Train [size];
bool isQuite = false;
while (!isQuite) {
switch (menu()) {
case 1: {
for (int i = 0; i < size; i++) {
std::cout << "\t\t\t[" << i << "]" << std::endl;
trainArray[i].inputInformationTrain();
}
std::cout << std::endl;
break;
}
case 2: {
for (int i = 0; i < size; i++) {
std::cout << "\t\t\t[" << i << "]" << std::endl;
trainArray[i].outputInformationTrain();
std::cout << std::endl;
}
std::cout << std::endl;
break;
}
case 3: {
size = deleteDuplicates(trainArray, size);
break;
}
case 4:
{
std::cout << "Enter low border to search>>> " << std::endl;
int lowBorder = inputValidation();
std::cout << "Enter high border to search>>> " << std::endl;
int highBorder = inputValidation();
findInRange(trainArray, size, lowBorder, highBorder);
break;
}
case 0: {
isQuite = true;
break;
}
}
}*/
