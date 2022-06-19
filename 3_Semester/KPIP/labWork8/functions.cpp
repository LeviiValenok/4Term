//
// Created by gaydi on 15.11.2021.
//

#include "functions.h"
#include <cstring>

void myUnexpected()

{
    std:: cout<<"my_unexpected handler"<< std:: endl;

    throw LinkedList();

}
void  myTerm()

{
    std:: cout<<"Terminate() exception";
    exit(1);

}


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
    bool isTrue = true;
    int choice;
    std::cout << "1 to add item" << std::endl;
    std::cout << "2 to display a list" << std::endl;
    std::cout << "3 to delete item" << std::endl;
    std::cout << "4 to sort the list" << std::endl;
    std::cout << "5 to move item" << std::endl;
    std::cout << "6 to delete dublicates" << std::endl;
    std::cout << "0 to exit" << std::endl;
    while(isTrue)
    {
        choice = inputValidation();
        if (choice > 6 || choice < 0)
        {
            std::cout << "Incorrect choice. Try again" << std::endl;
        }
        else
        {
            isTrue = false;
        }
    }

    return choice;
}






