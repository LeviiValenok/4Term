//
// Created by gaydi on 29.11.2021.
//

#include "Dish.h"
#include "functions.h"
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <cstring>
#include <string.h>


Dish :: Dish() {
   /* strcpy(name, "Empty");
    strcpy(kitchen, "Empty");
    strcpy(price, "Empty");*/

}


void Dish ::getInformation()
{
    std::cout << "Enter dish name >>>" << std::endl;
    std::cin >> name;
    std::cout << "Enter dish kitchen >>>" << std::endl;
    std::cin >> kitchen;
    std::cout << "Enter price >>>" << std::endl;
    std::cin >> price;

}

void Dish ::outputInformation() {
    std::cout << "Dish name is >>" << std::endl;
    std::cout << "\t" << name << std::endl;
    std::cout << "Kitchen is >>" << std::endl;
    std::cout << "\t" << kitchen << std::endl;
    std::cout << "Price is >>" << std::endl;
    std::cout << "\t" << price << std::endl;
}

void Dish::loadTextFile(std::ifstream &file)
{

    if (!file.is_open()) {
        throw (std::runtime_error("File is not open"));
    }
    file >> *this;

}


std::ostream &operator<< (std::ostream &out, const Dish &dish)
{
    out << dish.name << std::endl;
    out << dish.kitchen << std::endl;
    out << dish.price << std::endl;
    return out;
}

std::istream &operator>> (std::istream &in, Dish &dish)
{
    in >> dish.name;
    in >> dish.kitchen;
    in >> dish.price;
    return in;
}


int Dish::diskCount(const std::string &fileName)
{
    std::ifstream infile;
    infile.open(fileName, std::ios::binary);
    infile.seekg(0, std::ios::end);
    int numberOfDishes;
    int endPosition = infile.tellg();
    numberOfDishes = endPosition/sizeof(Dish);
    return numberOfDishes;
}

void Dish::readBinaryFile(std::ifstream& file) {
    if (!file.is_open()) {
        throw (std::runtime_error("File is not open"));
    }

    try {
        // Read isComplete status
        size_t nameSize;
        file.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        char* temp = new char[nameSize + 1];
        file.read(temp, static_cast<std::streamsize>(nameSize));
        temp[nameSize] = '\0';
        name = temp;

        delete[] temp;


        size_t kitchenSize;
        file.read(reinterpret_cast<char*>(&kitchenSize), sizeof(kitchenSize));

        temp = new char[kitchenSize + 1];
        file.read(temp, static_cast<std::streamsize>(kitchenSize));
        temp[kitchenSize] = '\0';
        kitchen = temp;

        delete[] temp;

        size_t priceSize;
        file.read(reinterpret_cast<char*>(&priceSize), sizeof(priceSize));

        temp = new char[priceSize + 1];
        file.read(temp, static_cast<std::streamsize>(priceSize));
        temp[priceSize] = '\0';
        price = temp;

        delete[] temp;
    }
    catch (std::ifstream::failure& ex) {
        throw std::runtime_error("Invalid read data type");
    }
}

void Dish::saveTxtInBin(std::ofstream &file, const std::string &fileName)
{

    file.open(fileName,  std::ios::binary | std::ios::app );
        if (!file.is_open()) {
            throw (std::runtime_error("File is not open"));
        }


        try {
            std::size_t nameSize = name.size();
            file.write(reinterpret_cast<char *>(&nameSize), sizeof(nameSize));
            file.write(name.c_str(), static_cast<std::streamsize>(nameSize));

            std::size_t kitchenSize = kitchen.size();
            file.write(reinterpret_cast<char * >(&kitchenSize), sizeof(kitchenSize));
            file.write(kitchen.c_str(), static_cast<std::streamsize>(kitchenSize));

            std::size_t priceSize = price.size();
            file.write(reinterpret_cast<char * >(&priceSize), sizeof(priceSize));
            file.write(price.c_str(), static_cast<std::streamsize>(priceSize));


        } catch (std::ofstream::failure &ex) {
            throw std::runtime_error("Invalid write data type");
        }
        file.close();
}



void Dish :: loadTxtInBin(std::ifstream &file, const std::string &fileName)
{
    int dishesNumber = diskCount(fileName);

    if (!file.is_open()) {
        file.open(fileName, std:: ios::binary | std::ios::in);
    }

    Dish temp;

    int counter{};
    while (true) {
        temp.readBinaryFile(file);
        if (file.eof()) {
            break;
        }
        counter++;
        std::cout << "\t\t\tNumber is >>> " << counter << std::endl;
       temp.outputInformation();
    }
    file.close();


/*    file.open(fileName,  std::ios::out | std::ios::in);
    Dish temp;
    file.seekg(std::ios::beg);
   *//* try
    {
       if (!file)
       {
           throw CannotOpenFile();
       }
    }
    catch (Dish :: CannotOpenFile)
    {
        std::cout << "Cannot open" << std::endl;
    }


    int counter=0;
    while (counter <= dishesNumber) {

        if (file.eof())
            break;
        file.read((char*)(this->name), sizeof (strlen(this->name)));
        file.read((char*)(this->kitchen), sizeof (strlen(this->kitchen)));
        file.read((char*)(this->price), sizeof (strlen(this->price)));
        counter++;
        std::cout << "\t\t\tNumber is >>> " << counter << std:: endl;
        this->outputInformation();
//        std::cout << *this->getDishName() << " " << *this->getDishKitchen() << " " << this->getDishPrice() << std::endl;

    }*//*
    int numberOfDishes = diskCount(fileName)+1;
    int counter = 0;
    while(true)
    {
        try {
            if (!file.is_open())
            {
                throw CannotOpenFile();
            }
//            file.write(reinterpret_cast<char*>(&detailText_size), sizeof(detailTitle_size));
//            file.read(reinterpret_cast<char*>(&temp.name), sizeof(strlen(temp.name)));
//            file.read(reinterpret_cast<char*>(&temp.kitchen), sizeof(strlen(temp.kitchen)));
//            file.read(reinterpret_cast<char*>(&temp.price), sizeof(strlen(temp.price)));
            file.read((char*)&temp, sizeof(Dish));
            *//*int size = strlen(temp.name);
            temp.name[size + 1] = '\0';
            size = strlen(temp.kitchen);
            temp.kitchen[size+1] = '\0';
            size = strlen(temp.price);
            temp.kitchen[size + 1] = '\0';*//*
//            file >> temp;
            temp.outputInformation();

        }catch (Dish :: CannotOpenFile)
        {
            std::cout << "Cannot open" << std::endl;
        }
        if (file.eof()) {
            break;
        }
        counter++;
    }
    file.close();*/
}

void Dish::saveTxt(std::ofstream &file, const std::string &fileName)
{
    file.open(fileName, std::ios::app);
    try
    {
        if (!file)
            throw CannotOpenFile();
    }
    catch (Dish ::CannotOpenFile)
    {
        std::cout << "Cannot open" << std::endl;
    }
    file << (*this);
    file.close();
}



void Dish::loadTxt(std::ifstream &file, const std::string &fileName)
{
    file.open(fileName, std::ios::out);
    try
    {
        if (!file)
        {
            throw CannotOpenFile();
        }
    }
    catch (Dish :: CannotOpenFile)
    {
        std::cout << "Cannot open" << std::endl;
    }
    int counter = 0;
    Dish* dish = new Dish();
    while (true)
    {
        dish->loadTextFile(file);
        if (file.eof())
            break;
        counter++;
        std::cout << "\t\t\tNumber is >>> " << counter << std:: endl;
        dish->outputInformation();
    }

    file.close();
}

void Dish::loadTextFileInReverseOrder(std::ifstream &file, const std::string &fileName)
{
    if (!file.is_open())
    {

        file.open(fileName, std::ios::out);
    }
    int numberOfDishes = 0;
    Dish* dish = new Dish();
    bool isQuite = false;
    while (!isQuite)
    {
        dish->loadTextFile(file);
        if (file.eof())
        {
            break;
        }
        numberOfDishes++;
    }

    file.clear();
    file.seekg(std::ios::beg);
    int k = 0;
    while (numberOfDishes != 0)
    {
        for (int i = 0; i < numberOfDishes; i++)
        {
            dish->loadTextFile(file);
        }
        k++;
        std::cout << "\t\t\tNumber is >>> " << k  <<std :: endl;
        dish->outputInformation();
        file.seekg(std::ios::beg);
        numberOfDishes--;
    }

}


void Dish:: loadBinaryFileInReverseOrder(std::ifstream &file, const std::string &fileName)
{
    bool isQuite = false;
    Dish temp;
    int numberOfDishes = 0;
    file.open(fileName, std::ios::in);
    while (!isQuite)
    {
        temp.readBinaryFile(file);
        if (file.eof())
        {
            isQuite = true;
            break;
        }
        numberOfDishes++;
    }
    file.clear();
    file.seekg(std::ios::beg);
    int number = 0;
    isQuite = false;
    while (!isQuite)
    {
        if (numberOfDishes == 0)
        {
            isQuite = true;
            break;
        }
        for (int i = 0; i < numberOfDishes; i++) {
            temp.readBinaryFile(file);
        }
        numberOfDishes--;
        number++;
        std::cout << "\t\t\tNumber is >>> " << number  << std::endl;
        temp.outputInformation();
        file.seekg(std::ios::beg);
    }
    file.close();
}


void Dish :: searchByTheOption(std::ifstream &file, const std::string &textFileName, const std::string &binaryFileName)
{
    int choice;
    bool isQuite = false;
    std::cout << "1 to search in Binary file" << std::endl;
    std::cout << "2 to search in Text file" << std::endl;
    std::cout << "0 to exit" << std::endl;
    std::cout << "Your choice is >>" << std::endl;
    choice = intInputValidation();
    while (choice < 0 || choice > 2)
    {
        std::cout << "Incorrect value. Please try again" << std::endl;
        choice = intInputValidation();
    }
    while (!isQuite)
    {
        switch (choice)
        {
            case 1:
            {
                menuForSearchByTheOption(file, textFileName, binaryFileName, choice);
                isQuite = true;
                break;
            }
            case 2:
            {
                menuForSearchByTheOption(file, textFileName, textFileName, choice);
                isQuite = true;
                break;
            }
            case 0:
            {
                isQuite = true;
                break;
            }
        }
    }
}

void Dish :: searchInBinaryFile(std::ifstream &file, const std::string &binaryFileName, std::string key,  int choice)
{
    Dish *dish = new Dish();
    switch(choice)
    {
        case 1:
        {
            file.open( binaryFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->name == key)
                {
                    std::cout << "Suitable item" << std::endl;
                   dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 2:
        {
            file.open( binaryFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->kitchen == key)
                {
                    std::cout << "Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 3:
        {
            file.open( binaryFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->price == key)
                {
                    std::cout << "\t\t Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 0:
        {
            break;
        }

    }
}

void Dish::searchInTextFile(std::ifstream &file, const std::string &textFileName, std::string key, int choice)
{
    Dish *dish = new Dish();
    switch(choice)
    {
        case 1:
        {
            file.open(textFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->name == key)
                {
                    std::cout << "\t\t Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 2:
        {
            file.open(textFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->kitchen == key)
                {
                    std::cout << "\t\t Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 3:
        {
            file.open(textFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            while (true)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->price == key)
                {
                    std::cout << "Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 0:
        {
            break;
        }

    }
}

void Dish::deleteObjectInFile(std::ifstream &file, const std::string &binaryFileName, const std::string &textFileName)
{
    Dish* dish = new Dish();
    switch(menuForDelete())
    {
        case 1:
        {
            file.open(textFileName, std::ios::in | std::ios::out);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }

            Dish* dishArr = new Dish [numberOfDishes];
//            file.clear();
//            file.seekg(std::ios::beg);
            file.close();
            file.open(textFileName, std::ios::in | std::ios::out);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].loadTextFile(file);
                i++;


            }
            std::cout << "Enter a key name to delete >>> " << std::endl;
            std::string key;
            std::cin >> key;
            file.clear();
            file.seekg(std::ios::beg);
            isQuite = false;
            int counter = 0;
            while (!isQuite)
            {
                dish->loadTextFile(file);
                counter++;
                if (dish->name == key)
                {
                    std::cout << "\t\t Suitable item is: " << std::endl;
                    dish->outputInformation();
                    isQuite = true;
                    break;
                }
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
            }
            for (i = counter-1; i < numberOfDishes - 1; i++)
            {
                dishArr[i] = dishArr[i + 1];
            }
            file.close();
            file.open(textFileName, std::ios::out| std::ios::trunc);
            file.close();
            numberOfDishes--;
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxt(input, textFileName);
            }
            break;
        }
        case 2:
        {
            Dish* dish = new Dish();
            file.open(binaryFileName, std::ios::binary|std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }
            file.close();
            Dish* dishArr = new Dish [numberOfDishes];

            file.open(binaryFileName, std::ios::binary | std::ios::in);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].readBinaryFile(file);
                i++;
            }
            std::cout << "Enter a key name to delete >>> " << std::endl;
            std::string key;
            std::cin >> key;
            file.close();
            file.open(binaryFileName, std::ios::binary | std::ios::in);
            isQuite = false;
            int counter = 0;
            while (!isQuite)
            {
                dish->readBinaryFile(file);
                counter++;
                if (dish->name == key)
                {
                    std::cout << "\t\t Suitable item is: " << std::endl;
                    dish->outputInformation();
                    isQuite = true;
                    break;
                }
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
            }
            for (i = counter-1; i < numberOfDishes - 1; i++)
            {
                dishArr[i] = dishArr[i + 1];
            }
            file.close();
            file.open(binaryFileName, std::ios::binary| std::ios::out| std::ios::trunc);
            file.close();
            numberOfDishes--;
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxtInBin(input, binaryFileName);
            }
            break;
        }
    }
}


void Dish::sortFile(std::ifstream &file, const std::string &textFileName, const std::string &binaryFileName)
{
    switch(menuForSort())
    {
        case 1:
        {
            Dish* dish = new Dish();
            dish->sortTextFile(file, textFileName);
            break;
        }
        case 2:
        {
            Dish* dish = new Dish();
            dish->sortBinaryFile(file, binaryFileName);
            break;
        }
        case 0:
        {
            break;
        }
    }
}

void Dish::sortTextFile(std::ifstream &file, const std::string &textFileName)
{
    switch(menuForChooseOption())
    {
        case 1:
        {
            Dish* dish = new Dish();
            file.open(textFileName, std::ios::in | std::ios::out);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }

            Dish* dishArr = new Dish [numberOfDishes];
            file.close();
            file.open(textFileName, std::ios::in | std::ios::out);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].loadTextFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].name.c_str(), dishArr[j].name.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(textFileName, std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxt(input, textFileName);
            }
            break;
        }
        case 2:
        {
            Dish* dish = new Dish();
            file.open(textFileName, std::ios::in | std::ios::out);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }

            Dish* dishArr = new Dish [numberOfDishes];
            file.close();
            file.open(textFileName, std::ios::in | std::ios::out);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].loadTextFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].kitchen.c_str(), dishArr[j].kitchen.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(textFileName, std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxt(input, textFileName);
            }
            break;
        }
        case 3:
        {
            Dish* dish = new Dish();
            file.open(textFileName, std::ios::in | std::ios::out);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }

            Dish* dishArr = new Dish [numberOfDishes];
            file.close();
            file.open(textFileName, std::ios::in | std::ios::out);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].loadTextFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].price.c_str(), dishArr[j].price.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(textFileName, std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxt(input, textFileName);
            }
            break;
        }
        default:
            break;
    }
}
void Dish::sortBinaryFile(std::ifstream &file, const std::string &binaryFileName)
{
    switch(menuForChooseOption())
    {
        case 1:
        {
            Dish* dish = new Dish();
            file.open(binaryFileName, std::ios::binary|std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }
            file.close();
            Dish* dishArr = new Dish [numberOfDishes];
            file.open(binaryFileName, std::ios::binary | std::ios::in);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].readBinaryFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].name.c_str(), dishArr[j].name.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(binaryFileName, std::ios::binary| std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxtInBin(input, binaryFileName);
            }

            break;
        }
        case 2:
        {
            Dish* dish = new Dish();
            file.open(binaryFileName, std::ios::binary|std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }
            file.close();
            Dish* dishArr = new Dish [numberOfDishes];
            file.open(binaryFileName, std::ios::binary | std::ios::in);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].readBinaryFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].kitchen.c_str(), dishArr[j].kitchen.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(binaryFileName, std::ios::binary| std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxtInBin(input, binaryFileName);
            }

            break;
        }
        case 3:
        {
            Dish* dish = new Dish();
            file.open(binaryFileName, std::ios::binary|std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "\t\t Cannot open" << std::endl;
            }
            int numberOfDishes = 0;
            bool isQuite = false;
            while (!isQuite)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                numberOfDishes++;
            }
            file.close();
            Dish* dishArr = new Dish [numberOfDishes];
            file.open(binaryFileName, std::ios::binary | std::ios::in);
            isQuite = false;
            int i = 0;
            while (i != numberOfDishes)
            {
                if (file.eof())
                {
                    isQuite = true;
                    break;
                }
                dishArr[i].readBinaryFile(file);
                i++;
            }
            file.close();
            for (i = 0; i < numberOfDishes; i++)
            {
                for (int j = i + 1; j < numberOfDishes; j++)
                {
                    if (strcmp(dishArr[i].price.c_str(), dishArr[j].price.c_str()) > 0)
                    {
                        Dish temp = dishArr[i];
                        dishArr[i] = dishArr[j];
                        dishArr[j] = temp;
                    }
                }
            }
            file.open(binaryFileName, std::ios::binary| std::ios::out| std::ios::trunc);
            file.close();
            std::ofstream input;
            for (i =  0; i < numberOfDishes; i++)
            {
                dishArr[i].saveTxtInBin(input, binaryFileName);
            }

            break;
        }
        default:
            break;

    }
}

void Dish::rangeSearch(std::ifstream &file, const std::string &textFileName, const std::string &binaryFileName)
{
    switch(menuForSearch())
    {
        case 1:
        {
            Dish* dish = new Dish();
            char left, right;
            std::cout << "Enter left value of range >>>" << std::endl;
            std::cin >> left;
            std::cout << "Enter right value of range >>>" << std::endl;
            std::cin >> right;
            while (left > right)
            {
                std::cout << "Incorrect value. Left should be less than right. Please try again" << std::endl;
                std::cout << "Enter left value of range >>>" << std::endl;
                std::cin >> left;
                std::cout << "Enter right value of range >>>" << std::endl;
                std::cin >> right;
            }
            file.open(textFileName,  std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->loadTextFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->name[0] >= left && dish->name[0] <= right)
                {
                    std::cout << "\t\t Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
        case 2:
        {
            Dish* dish = new Dish();
            char left, right;
            std::cout << "Enter left value of range >>>" << std::endl;
            std::cin >> left;
            std::cout << "Enter right value of range >>>" << std::endl;
            std::cin >> right;
            while (left > right)
            {
                std::cout << "Incorrect value. Left should be less than right. Please try again" << std::endl;
                std::cout << "Enter left value of range >>>" << std::endl;
                std::cin >> left;
                std::cout << "Enter right value of range >>>" << std::endl;
                std::cin >> right;
            }
            file.open(binaryFileName, std::ios::binary | std::ios::in);
            try
            {
                if (!file)
                    throw CannotOpenFile();
            }
            catch (Dish ::CannotOpenFile)
            {
                std::cout << "Cannot open" << std::endl;
            }
            while (true)
            {
                dish->readBinaryFile(file);
                if (file.eof())
                {
                    break;
                }
                if (dish->name[0] >= left && dish->name[0] <= right)
                {
                    std::cout << "\t\t Suitable item" << std::endl;
                    dish->outputInformation();
                }
            }
            file.close();
            break;
        }
    }
}
void Dish :: deleteDuplicates(std::ifstream &file, const std::string &binaryFileName, const std::string &textFileName)
{

    switch(menuForDuplicates())
    {
        case 1:
        {
            switch(menuForChooseOptionDuplicates())
            {
                case 1:
                {
                    Dish* dish = new Dish();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->loadTextFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].loadTextFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].name == dishArr[j].name)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(textFileName, std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxt(input, textFileName);
                    }
                    break;
                }
                case 2:
                {
                    Dish* dish = new Dish();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->loadTextFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].loadTextFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].kitchen == dishArr[j].kitchen)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(textFileName, std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxt(input, textFileName);
                    }
                    break;
                }
                case 3:
                {
                    Dish* dish = new Dish();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->loadTextFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(textFileName, std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].loadTextFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].price == dishArr[j].price)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(textFileName, std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxt(input, textFileName);
                    }
                    break;
                }
            }
            break;
        }
        case 2:
        {
            switch(menuForChooseOptionDuplicates())
            {
                case 1:
                {
                    Dish* dish = new Dish();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->readBinaryFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].readBinaryFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].name == dishArr[j].name)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(binaryFileName, std::ios::binary|std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxtInBin(input, binaryFileName);
                    }
                    break;
                }
                case 2:
                {
                    Dish* dish = new Dish();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->readBinaryFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].readBinaryFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].kitchen == dishArr[j].kitchen)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(binaryFileName, std::ios::binary|std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxtInBin(input, binaryFileName);
                    }
                    break;
                }
                case 3:
                {
                    Dish* dish = new Dish();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    try
                    {
                        if (!file)
                            throw CannotOpenFile();
                    }
                    catch (Dish ::CannotOpenFile)
                    {
                        std::cout << "\t\t Cannot open" << std::endl;
                    }
                    int numberOfDishes = 0;
                    bool isQuite = false;
                    while (!isQuite)
                    {
                        dish->readBinaryFile(file);
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        numberOfDishes++;
                    }

                    Dish* dishArr = new Dish [numberOfDishes];
                    file.close();
                    file.open(binaryFileName, std::ios::binary|std::ios::in | std::ios::out);
                    isQuite = false;
                    int i = 0;
                    while (i != numberOfDishes)
                    {
                        if (file.eof())
                        {
                            isQuite = true;
                            break;
                        }
                        dishArr[i].readBinaryFile(file);
                        i++;
                    }
                    file.close();
                    isQuite = false;
                    int counter = 0;
                    for (i = 0; i < numberOfDishes; i++)
                    {
                        for (int j = i + 1; j < numberOfDishes; j++)
                        {
                            if (dishArr[i].price == dishArr[j].price)
                            {
                                for (int k = j; k < numberOfDishes-1; k++)
                                {
                                    dishArr[k] = dishArr[k + 1];
                                }
                                numberOfDishes--;
                            }
                        }
                    }
                    file.open(binaryFileName, std::ios::binary|std::ios::out| std::ios::trunc);
                    file.close();

                    std::ofstream input;
                    for (i =  0; i < numberOfDishes; i++)
                    {
                        dishArr[i].saveTxtInBin(input, binaryFileName);
                    }
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
}

//функция сортировки объектов по любому полю(перезаись даных в файле), пользователь выбирает поле
//поиск по диапазону (прайс), или от a до z
//удаление дубликатов