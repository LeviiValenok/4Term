//
// Created by gaydi on 17.12.2021.
//

#include "RailwayCarriage.h"

void railway::RailwayCarriage ::outputInformationCarriage()
{
    outputInformationTrain();
    std::cout << "Conductor name is >>> " << std::endl;
    std::cout << "\t\t\t " << conductor.conductorName << std::endl;
    std::cout << "Carriage number is >>> " << std::endl;
    std::cout << "\t\t\t" << carriageNumber;
}

void railway::RailwayCarriage ::inputInformationCarriage()
{
    inputInformationTrain();
    std::cout << "Enter the name of conductor >>>" << std::endl;
    std::cin >> conductor.conductorName;
    std::cout << "Enter a carriage number >>>" << std::endl;
    carriageNumber = inputValidation();
}