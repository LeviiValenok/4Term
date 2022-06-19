//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_TRAIN_H
#define LABWORK11_TRAIN_H

#include "Vehicle.h"
#include "namespace.h"

namespace railway {

    class Train : public railway::Vehicle {
    public :
        int numeration;
        std::string direction;

        Train() : Vehicle() {
            numeration = 0;
            direction = "stop";
        }

        Train(int value, std::string text, int power, std::string type) : Vehicle(power, type) {
            numeration = value;
            direction = text;
        }

        void outputInformationTrain();

        void inputInformationTrain();

    };

}
#endif //LABWORK11_TRAIN_H
