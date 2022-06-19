//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_CONDUCTOR_H
#define LABWORK11_CONDUCTOR_H
#include <iostream>
#include "namespace.h"

namespace railway {
    class Conductor {
    public:
        std::string conductorName;
        int age;

        Conductor() {
            conductorName = "empty";
            age = 0;
        }

        ~Conductor() {};

        Conductor(std::string name, int conductorAge) {
            conductorName = name;
            age = conductorAge;
        }
    };
}

#endif //LABWORK11_CONDUCTOR_H
