//
// Created by gaydi on 17.12.2021.
//

#include "Vehicle.h"
#include "functions.h"

railway::Vehicle :: Vehicle (int power, std::string type)
{
    engine.power = power;
    vehicleType = type;
}

void railway::Vehicle ::outputInformationVehicle()
{
    std::cout << "Power of engine is >>>" << std::endl;
    std::cout << "\t\t\t" << engine.power << std::endl;
    std::cout << "Vehicle type is >>>" << std::endl;
    std::cout << "\t\t\t" << vehicleType << std::endl;
}

void railway::Vehicle ::inputInformationVehicle()
{
    std::cout << "Enter a power of engine >>>" << std::endl;
    engine.power = inputValidation();
    std::cout << "Enter a vehicle type >>>" << std::endl;
    std::cin >> vehicleType;
}

railway::Vehicle::Vehicle()
{

    vehicleType = "empty" ;
}
