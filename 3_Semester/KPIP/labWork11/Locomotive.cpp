//
// Created by gaydi on 17.12.2021.
//

#include "Locomotive.h"

railway::Locomotive ::Locomotive() {
    driverItem.driver = "empty";
    locomotiveName = "empty";
}

void railway::Locomotive ::outputInformationLocomotive()
{
    outputInformationTrain();
    std::cout << "The driver is >>> " << std::endl;
    std::cout << "\t\t\t" << driverItem.driver << std::endl;
    std::cout << "The locomotive name is >>>" << std::endl;
    std::cout << "\t\t\t" << locomotiveName << std::endl;
}

void railway::Locomotive::inputInformationLocomotive()
{
    inputInformationTrain();
    std::cout << "Enter the driver name >>>" << std::endl;
    std::cin >> driverItem.driver;
    std::cout << "Enter the locomotive name >>>" << std::endl;
    std::cin >> locomotiveName;
}