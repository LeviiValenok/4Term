//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_LOCOMOTIVE_H
#define LABWORK11_LOCOMOTIVE_H

#include "Train.h"
#include "Vehicle.h"
#include "Driver.h"
#include "namespace.h"
namespace railway {
    class Driver;

    class Locomotive : public Train {
    public:
        Driver driverItem;
        std::string locomotiveName;

        Locomotive();

        ~Locomotive() {};

        Locomotive(Driver item, std::string locomotiveText, std::string direction,
                   int numeration, int power, std::string type) : Train(numeration, direction, power, type) {
            driverItem = item;
            locomotiveName = locomotiveText;
        }

        void outputInformationLocomotive();

        void inputInformationLocomotive();
    };

}

#endif //LABWORK11_LOCOMOTIVE_H
