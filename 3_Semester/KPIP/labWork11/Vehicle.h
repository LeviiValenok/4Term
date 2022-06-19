//
// Created by gaydi on 17.12.2021.
//


#ifndef LABWORK11_VEHICLE_H
#define LABWORK11_VEHICLE_H

#include <iostream>
#include "namespace.h"


namespace railway {

    class Engine {
    public:
        int power;

        Engine() {
            power = 0;
        }

        Engine(int p) {
            power = p;
        }

        ~Engine() {};
    };


    class Vehicle {
    public:
        Engine engine;

        ~Vehicle() {};
        std::string vehicleType;

        Vehicle(int power, std::string type);

        Vehicle();

        void outputInformationVehicle();

        void inputInformationVehicle();

    };
}

#endif //LABWORK11_VEHICLE_H
