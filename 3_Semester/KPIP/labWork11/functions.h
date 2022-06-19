//
// Created by gaydi on 17.12.2021.
//

#ifndef LABWORK11_FUNCTIONS_H
#define LABWORK11_FUNCTIONS_H

#include "Train.h"

int inputValidation();
int menu();
int deleteDuplicates(railway::Train *trainArray, int size);
void findInRange(railway::Train *trainArray, int size, int lowBorder, int highBorder);

#endif //LABWORK11_FUNCTIONS_H
