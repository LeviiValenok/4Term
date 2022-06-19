//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_RAILWAYCARRIAGE_H
#define LABWORK11_RAILWAYCARRIAGE_H
#include "Conductor.h"
#include "Train.h"
#include "functions.h"
#include "namespace.h"
//TODO: Add conductor age
namespace railway {
    class Conductor;

    class RailwayCarriage : public Train {
        Conductor conductor;
        int carriageNumber;

        RailwayCarriage() {
            conductor.conductorName = "empty";
            carriageNumber = 0;
        }

        ~RailwayCarriage() {};

        RailwayCarriage(Conductor item, int number, int numeration, std::string direction, int power, std::string type)
                : Train(numeration, direction, power, type) {
            conductor = item;
            carriageNumber = number;

        }

        void outputInformationCarriage();
        void inputInformationCarriage();
    };

}
#endif //LABWORK11_RAILWAYCARRIAGE_H
