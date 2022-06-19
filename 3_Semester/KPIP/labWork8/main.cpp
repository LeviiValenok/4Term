#include <iostream>
#include "functions.h"
#include "LinkedList.h"
#include <exception>

int main()
{
    LinkedList* list = new LinkedList();
    std::set_unexpected(myUnexpected);
    bool isQuite = false;
    bool isContinue = false;
    int choice;
    while (!isQuite) {
        switch(menu()) {

            case 1: {
                list->addItem(8);
                list->addItem(3);
                list->addItem(6);
                list->addItem(7);
                list->addItem(6);
                list->addItem(4);
               /* while(!isContinue){
                    std::cout << "Do you want to add more?" << std::endl;
                    std::cout << "1 to continue" << std::endl;
                    std::cout << "0 to break" << std::endl;
                    choice = inputValidation();
                    while (choice > 1 || choice < 0)
                    {
                        std::cout << "Incorrect value. Please try again" << std::endl;
                        choice = inputValidation();
                    }
                    if (choice == 1)
                    {
                        list->addItem();
                    }
                    else if(choice == 0)
                    {
                        isContinue = true;
                    }

                }
                isContinue = false;*/
                break;
            }

            //3 6 7 9 4
            //3 9 6 7 41
            //4 1 7 6 3
                                        //1 4 7 6 3
                                        //4 6 1 7 3
            //4 3 1 7 6
            case 2: {
                try {
                    list->display();
                }
                catch(LinkedList :: Empty) {
                    std::cout << "List is empty :( " << std::endl;
                }
                break;
            }
            case 3: {/*

                std::cout << "Length is " << length << std::endl;
                std::cout << "Your number is >>" << std::endl;
                int number = inputValidation();
                try {
                    list->deleteItem(number);
                } catch(LinkedList :: Empty) {
                    std::cout << "List is empty :( " << std::endl;
                }
                length = list->listLength();
                std::cout << "Length is " << length << std::endl;*/
                std::cout << "Your number is >>" << std::endl;
                int number = inputValidation();
                int length = list->listLength();
                try {
                    list->deleteItem(number, length);
                } catch(LinkedList :: NoSuitable) {
                    std::cout << "There is no suitable item :(" << std::endl;
                } catch (LinkedList :: Empty) {
                    std::cout << "List is empty :( " << std::endl; }

                break;
            }
            case 4: {
                std::cout << "1 to sort ascending" << std::endl;
                std::cout << "2 to sort descending" << std::endl;
                choice = inputValidation();
                while (choice > 2 || choice < 1){
                    std::cout << "Incorrect value. Please try again" << std::endl;
                    choice = inputValidation();
                }
                if (choice == 1)
                {
                    list->sortAscending();
                } else if (choice == 2)
                {
                    list->sortDescending();
                }

                break;
            }
            case 5:{
                std::set_terminate(myTerm);
                try {
                    list->moveToAnotherPlace();
                } catch (LinkedList ::NoSuitable){
                    std::cout << "There is no suitable item :(" << std::endl;
                }
                break;
            }
            case 6:{
                std::set_unexpected(myUnexpected);
                try {
                    list->deleteDublicates();
                }catch (LinkedList :: Empty) {
                    std::cout << "List is empty :( " << std::endl; }
                break;
            }
            case 0:{
                isQuite = true;
                break;
            }

        }
    }

//    std::set_terminate(myTerm);
//    try
//    {
//        list->display();
//
//        list->display();
//
////        list->searchByOption(15);
//        list->searchByOption(8);
//
//    }
//
//    catch(LinkedList::NoSuitable)
//    {
//        std::cout << "There is no suitable item :(" << std::endl;
//    }
//    list->display();
}





//меню, добавить, просмотрть, удлить
//везде где возможно ошибки прописать
//отсорировать список по усмотрению(на выбор пользователя)
//перемещение элементов на указанную пользователем позицию
//удаление дубликатов