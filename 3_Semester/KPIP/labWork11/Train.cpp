//
// Created by gaydi on 17.12.2021.
//

#include "Train.h"
#include "functions.h"


void railway::Train ::outputInformationTrain()
{
    this->outputInformationVehicle();
    std::cout << "Train numbering is: " << std::endl;
    if (numeration == 0)
    {
        std::cout << "\t\t\tTrain numbering from the head of the train" << std:: endl;
    } else if (numeration == 1)
    {
        std::cout << "\t\t\tTrain numbering from the tail of the train" << std::endl;
    }
    std::cout << "Travel direction is " << std::endl;
    std::cout << "\t\t\t" << direction << std:: endl;
}


void railway::Train :: inputInformationTrain()
{
    inputInformationVehicle();

    std::cout << "Enter 0 - to start numbering from the head of the train >>>"
                 "\n1 - to start numbering from the tail of the train >>>" << std::endl;
    int choice = inputValidation();
    while (choice > 1 || choice < 0)
    {
        std::cout << "Incorrect value. Please try again" << std::endl;
        choice = inputValidation();
    }
    numeration = choice;
    std::cout << "Enter a direction >>>" << std::endl;
    std::cin >> direction;


}