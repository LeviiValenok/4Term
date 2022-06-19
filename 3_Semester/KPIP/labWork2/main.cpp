#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdbool.h>


using namespace std;


class Product
{
    private:
        static int id;
        char name2[50];
        int cost;

    public:
        Product ()
        {
//            ++id;
            cost = 0;
            name2[0]= '\0';
        }

        Product (int value)
        {
            ++id;
            cost = value;

        }

        ~Product()
        {};

     void enterName()
     {
         cout << "Enter product name" << endl;

         cin >> name2;

         for (int i = 0; i < strlen(name2); i++)
         {
             if (name2[i] == '-' || (name2[i] > 49 && name2[i] < 58))
             {
                 cout << "Incorrect input. Please try again" << endl;
                 cin >> name2;
             }
         }


     }

     void changeID()
     {
         id++;
     }
     void setID()
     {
         id = 0;
     }

     friend void outputInformation (Product &item);
     friend class Seller;




};
 int Product :: id =0;


Product rightEnter()
{
    bool isRight = true;
    int number;
    while (isRight)
    {
        cout << "Enter an integer" << endl;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect value, try again" << endl;
        }
        else
        {
            isRight = false;
        }
    }
    return number;

}

void outputInformation(Product &item)
{
    cout <<"Name is:" << endl;
//    cout <<"\t"<<item.name << endl;
    cout <<"\t" << item.name2 <<endl;
    cout << "Price is:" << endl;
    cout << "\t"<<item.cost << endl;
    cout << "ID is:" << endl;
    cout << "\t"<<item.id << endl;
    cout << "\n" << endl;
}

class Seller
{
public:
    int rightEnter(Product& item)
    {
        bool isRight = true;
        int number;
        while (isRight)
        {
            cout << "Enter an integer" << endl;
            cin >> number;
            cin.ignore(32767, '\n');
            if (cin.fail() || number > 100)
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Incorrect value, try again" << endl;
            }
            else
            {
                isRight = false;
            }
        }
        return number;

    }
    void enterCost(Product &product)
    {

        do {
            cout << "Enter the cost of the product" << endl;
            product.cost = rightEnter(product);

        } while (product.cost >= 100);
    }

    void changeObject(Product& item, Seller &seller)
    {

        cout <<"\t1 to change the name" << endl;
        cout <<"\t2 to change the price" << endl;
        cout <<"\t3 to change all options" << endl;
        cout <<"\t0 if you don't want change anything" << endl;
        int choice;
        cout <<"Your choice\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                item.enterName();
                break;
            }
            case 2:
            {
                seller.enterCost(item);
                break;
            }
            case 3:
            {
                item.enterName();
                seller.enterCost(item);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }

    friend class Product;
};


int rightNumber(int lowBorder, int highBorder)
{
    bool isRight = true;
    int number;
    while (isRight)
    {
        cout << "Enter an integer" << endl;
        cin >> number;
        cin.ignore(32767, '\n');
        if (cin.fail() || ( number < lowBorder && number > highBorder))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect value, try again" << endl;
        }
        else
        {
            isRight = false;
        }
    }
    return number;
}

int menu()
{
    int choice;
    cout << "\t 1 to add new object" << endl;
    cout << "\t 2 to output all information" << endl;
    cout << "\t 3 to change an object" << endl;
    cout << "\t 4 to set price" << endl;
    cout << "\t 0 to quite" << endl;
    choice = rightNumber(0, 4);
    return choice;
}

int main()
{
    Product product1, product2, product3;
    Seller seller;
    /*Product product1(0.0);
    product1.enterName();
    outputInformation(product1);
    seller.enterCost(product1);

    outputInformation(product1);
    Product product2( 0.0);
    product2.enterName();
    outputInformation(product2);
    seller.enterCost(product2);

    outputInformation(product2);*/

    Product newObjects[2];
    bool isQuite = false;
    while (!isQuite)
    {

        switch (menu())
        {
            case 1:
            {
                cout << "\tEnter information" << endl;
//TODO: change numbers
                rewind(stdin);
                product1.enterName();
                seller.enterCost(product1);
                rewind(stdin);
                product2.enterName();
                seller.enterCost(product2);
                rewind(stdin);
                product3.enterName();
                seller.enterCost(product3);
                break;
            }
            case 2:
            {
//TODO: change numbers
                product1.setID();
                product1.changeID();
                outputInformation(product1);

                product2.changeID();
                outputInformation(product2);

                product3.changeID();
                outputInformation(product3);
                break;
            }
            case 3:
            {
                cout <<"Enter a number of object you want to change" << endl;
//TODO: change numbers
                int choice;
                choice = rightNumber(0,3);
                switch (choice)
                {
                    case 1:
                    {
                        seller.changeObject(product1, seller);
                        break;
                    }
                    case 2:
                    {
                        seller.changeObject(product2, seller);
                        break;
                    }
                    case 3:
                    {
                        seller.changeObject(product3, seller);
                        break;
                    }
                    default:
                        break;
                }

                break;
            }
            case 4:
            {
                bool isExit = false;
                cout <<"Enter a number of object you want to set price" << endl;
                int choice = rightNumber(0, 3);

                if (choice == 1)
                {
                    seller.enterCost(product1);
                    break;
                }
                else if (choice == 2)
                {
                    seller.enterCost(product2);
                    break;
                }
                else if (choice == 3)
                {
                    seller.enterCost(product3);
                    break;
                }
                else if (choice == 0)
                {
                    break;
                }

                break;
            }
            case 0:
            {
                isQuite = true;
                break;
            }
            default:
                break;

        }
    }




    return 0;
}

