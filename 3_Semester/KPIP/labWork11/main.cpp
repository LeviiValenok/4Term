#include <iostream>
#include "Locomotive.h"
#include "RailwayCarriage.h"
#include "namespace.h"
#include "functions.h"
#include <stdbool.h>


int main()
{


    railway::Train* train = new railway::Train();
    train->inputInformationTrain();
    train->outputInformationTrain();


    return 0;
}
