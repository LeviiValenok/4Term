//
// Created by gaydi on 14.11.2021.
//


#ifndef LABWORK8_LINKEDLIST_H
#define LABWORK8_LINKEDLIST_H

#include <iostream>


struct link
{
    int information;
    link* next;
};

class LinkedList
{
    private:
        link* first;

    public:
    class Empty { };
    class NoSuitable { };
    LinkedList()
    {
        first = NULL;
    }
//    void addItem();
    void addItem(int number);
    void display();
    void deleteItem(int number, int length);
    bool searchByOption(int number);
    int listLength();
    void sortAscending();
    void sortDescending();
    void moveToAnotherPlace();
    void deleteDublicates();

};


#endif //LABWORK8_LINKEDLIST_H
