//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_DRIVER_H
#define LABWORK11_DRIVER_H
#include <iostream>
#include "namespace.h"

namespace railway {
    class Driver {
    public:
        std::string driver;

        Driver() {
            driver = "empty";
        }

        ~Driver() {};

        Driver(std::string DriverName) {
            driver = DriverName;
        }
    };
}

#endif //LABWORK11_DRIVER_H
