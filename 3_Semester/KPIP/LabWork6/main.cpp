#include <iostream>
#include <cstdlib>
#include <stdbool.h>
#include <cstring>

class MusicalInstruments
{
protected:
    double price;
    std::string name;
    std::string type;
public:
    MusicalInstruments()
    {
        name = "empty";
        std::cout <<"\n";
        type = "empty";
        std::cout <<"\n";
        price = 0.0 ;

    }
    MusicalInstruments (std::string musicalName, std::string typeName)
    {
        name = musicalName;
        type = typeName;
    }
    virtual ~MusicalInstruments() = 0;

    virtual void outputInformation()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
    }
    virtual void convertInDollars()
    {
        std::cout << "Cost in dollars: ";
        double cost = price/2.6;
        std::cout << cost<< std::endl;
        std::cout <<'\n';
    }

    virtual void convertInEuro()
    {
        std::cout << "Cost in euro: ";
        double cost = price/2.8;
        std::cout << cost<< std::endl;
    }

    virtual void convertInRubles()
    {
        std::cout << "Cost in russian rubles: ";
        double cost = price*29;
        std::cout << cost<< std::endl;
    }

    virtual double inputValidation()
    {
        char number[10];
        std::cin >> number;
        int length = strlen(number);
        int i = 0;
        bool isTrue = true;
        while(isTrue)
        {
            while (i < length)
            {
                if (number[i] < '0' || number[i] > '9')
                {
                    if(number[i] != '.')
                    {
                        isTrue = true;
                        std::cout << "Incorrect value" << std::endl;
                        std::cout << "Try again >>>" << std::endl;
                        std::cin >> number;
                        length = strlen(number);
                        i = 0;
                        break;
                    }
                }
                i++;
                isTrue = false;
            }
        }
        double value = atof(number);

        return value;
    }


    virtual void inputPrice()
    {
        std::cout << "Enter cost of item >>>" << std::endl;
        price = inputValidation();
    }
};


class Keyboard : public MusicalInstruments
{
protected:
    int age;
public:
    Keyboard(std::string name, std::string type, int number):
            MusicalInstruments(name, type)
    {
        age = number;
    }

    ~Keyboard(){}
    void outputInformation()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Age is: " << age << std::endl;
    }
    void inputPrice()
    {
        std::cout << "Enter cost of item >>>" << std::endl;
        price = inputValidation();
    }
    void convertInDollars()
    {
        std::cout << "Cost in dollars: ";
        double cost = price/2.6;
        std::cout << cost<< std::endl;
    }

    void convertInEuro()
    {
        std::cout << "Cost in euro: ";
        double cost = price/2.8;
        std::cout << cost<< std::endl;
    }

    void convertInRubles()
    {
        std::cout << "Cost in russian rubles: ";
        double cost = price * 29.0;
        std::cout << cost<< std::endl;
    }
};

class Piano : public Keyboard
{
protected:
    std::string belonging;
public:
    Piano(std::string name, std::string type, int age, std::string person):
            Keyboard(name,type, age)
    {
        belonging = person;
    }
    ~Piano(){}
    void outputInformation()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Age is: " << age << std::endl;
        std::cout<<"Instrument belongs to: "<< belonging << std::endl;

    }
    void inputPrice()
    {
        std::cout << "Enter cost of item >>>" << std::endl;
        price = inputValidation();
    }
    void convertInDollars()
    {
        std::cout << "Cost in dollars: ";
        double cost = price/2.6;
        std::cout << cost<< std::endl;
    }

    void convertInEuro()
    {
        std::cout << "Cost in euro: ";
        double cost = price/2.8;
        std::cout << cost<< std::endl;
    }

    void convertInRubles()
    {
        std::cout << "Cost in russian rubles: ";
        double cost = price*29;
        std::cout << cost<< std::endl;
    }
};

class Stringed : public MusicalInstruments
{
protected:
    int numberOfStrings;
public:
    Stringed(std::string name, std::string type, int number):
            MusicalInstruments(name, type)
    {
        numberOfStrings = number;
    }
    ~Stringed(){}

    void outputInformation()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Number of strings: "<< numberOfStrings <<std::endl;
    }
    void inputPrice()
    {
        std::cout << "Enter cost of item >>>" << std::endl;
        price = inputValidation();
    }
    void convertInDollars()
    {
        std::cout << "Cost in dollars: ";
        double cost = price/2.6;
        std::cout << cost<< std::endl;
    }

    void convertInEuro()
    {
        std::cout << "Cost in euro: ";
        double cost = price/2.8;
        std::cout << cost<< std::endl;
    }

    void convertInRubles()
    {
        std::cout << "Cost in russian rubles: ";
        double cost = price*29;
        std::cout << cost<< std::endl;
    }

};

int menu()
{
    std::cout << "1 Cost in dollars" << std::endl;
    std::cout << "2 Cost in euro" << std::endl;
    std::cout << "3 Cost in russian rubbles" << std::endl;
    std::cout << "0 Exit" << std::endl;
    int choice;
    std::cout << "Enter choice >>>" << std::endl;
    std::cin >>choice;
    while (choice > 3 || choice < 0)
    {
        std::cout << "Incorrect  value, try again" << std::endl;
        std::cin >> choice;
    }
    return choice;
}



int main()
{
    MusicalInstruments** array = new MusicalInstruments*[3];
    Keyboard* item1 = new Keyboard("Piano", "Keyboard", 5);
    item1->inputPrice();
    array[0] = item1;
    Piano* item2 = new Piano("Piano", "Keyboard",   5, "Maxim");
    item2->inputPrice();
    array[1] = item2;
    Stringed* item3 = new Stringed("Guitar", "Stringed", 6);
    item3->inputPrice();
    array[2] = item3;
    for (int i = 0; i < 3; i++)
    {
        (*(array + i))->outputInformation();
        std::cout << "\n";
    }


    std::cout << "\t\tChoose currency\n" <<std::endl;
    bool isQuite = true;
    while (isQuite) {
        switch (menu()) {
            case 1: {
                for (int i = 0; i < 3; i++) {
                    (*(array + i))->outputInformation();
                    (*(array + i))->convertInDollars();
                    std::cout << "\n";
                }
                break;
            }
            case 2: {
                for (int i = 0; i < 3; i++) {
                    (*(array + i))->outputInformation();
                    (*(array + i))->convertInEuro();
                    std::cout << "\n";
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < 3; i++) {
                    (*(array + i))->outputInformation();
                    (*(array + i))->convertInRubles();
                    std::cout << "\n";
                }
                break;
            }
            case 0:
            {
                isQuite = false;
                break;
            }

        }
    }
    return 0;

}










//цена с клавы, проверка на ввод, перевод в 3 разные валюты в меню