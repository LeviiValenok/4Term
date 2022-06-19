#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include "Dish.h"
#include "functions.h"
#include <stdbool.h>


int main()
{
    std::ofstream input;
    std::ifstream output;
    bool isMenuExit = false;
    std::string fileNameTxtInBin = "txtInBin.txt";
    std::string fileNameBinBin = "BinBin.bin";
    std::string fileNameTxtTxt = "TxtText.txt";

    input.open(fileNameBinBin, std::ios::trunc);
    input.close();

    input.open(fileNameTxtTxt, std::ios::trunc);
    input.close();
    Dish* dish = new Dish();
    while (!isMenuExit)
    {
        switch (menu())
        {
            case 1:
            {
                int choice;
                bool isQuite = false;
                dish->getInformation();
                dish->saveTxtInBin(input, fileNameBinBin);
                while (!isQuite)
                {
                    std::cout << "Do you want to continue?" << std::endl;
                    std::cout << "1 to continue \n0 to exit " << std::endl;
                    std::cout << "Choice is >>> " << std::endl;
                    choice = intInputValidation();
                    if (choice == 0)
                    {
                        isQuite = true;
                    }
                    else
                    {
                        dish->getInformation();
                        dish->saveTxtInBin(input, fileNameBinBin);
                    }

                }
                break;

            }
            case 2: {
                dish->loadTxtInBin(output, fileNameBinBin);
                break;
            }
            case 3: {
                int choice;
                bool isQuite = false;
                dish->getInformation();
                dish->saveTxt(input, fileNameTxtTxt);
                while (!isQuite) {
                    std::cout << "Do you want to continue?" << std::endl;
                    std::cout << "1 to continue \n0 to exit " << std::endl;
                    std::cout << "Choice is >>> " << std::endl;
                    choice = intInputValidation();
                    if (choice == 0) {
                        isQuite = true;
                    } else {
                        dish->getInformation();
                        dish->saveTxt(input, fileNameTxtTxt);
                    }
                }
                break;
            }
            case 4:
            {
                dish->loadTxt(output, fileNameTxtTxt);
                break;
            }
            case 5:
            {
                outputInReverseOrder(output, fileNameTxtTxt, fileNameBinBin);
                break;
            }
            case 6:
            {
                dish->searchByTheOption(output, fileNameTxtTxt, fileNameBinBin);
                break;
            }
            case 7:
            {
                dish->deleteObjectInFile(output, fileNameBinBin, fileNameTxtTxt);
                break;
            }
            case 8:
            {
                dish->sortFile(output, fileNameTxtTxt, fileNameBinBin);
                break;
            }
            case 9:
            {
                dish->rangeSearch(output, fileNameTxtTxt, fileNameBinBin);
                break;
            }
            case 10:
            {
                dish ->deleteDuplicates(output, fileNameBinBin, fileNameTxtTxt);
                break;
            }
            case 0:
            {
                isMenuExit = true;
                break;
            }

        }
    }



    return 0;
}












