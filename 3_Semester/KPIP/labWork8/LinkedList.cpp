//
// Created by gaydi on 14.11.2021.
//

#include "LinkedList.h"
#include "functions.h"
#include <exception>
#include <algorithm>


/*void LinkedList :: addItem()
{
    std::cout << "Your number is >>" << std::endl;
    int number = inputValidation();
    link* newItem = new link();
    newItem->information = number;
    newItem->next = first;
    first = newItem;
}*/


void LinkedList :: addItem(int number)
{
//    std::cout << "Your number is >>" << std::endl;
//    int number = inputValidation();
    link* newItem = new link();
    newItem->information = number;
    newItem->next = first;
    first = newItem;
}
void LinkedList :: display()
{
    link* current = first;
    if (current == NULL)
    {
        throw Empty();
    }
    while (current)
    {
        std::cout << "Item is >>> " << current->information << std::endl;
        current = current->next;
    }

    std::cout << "\n";
}

void LinkedList ::deleteItem(int number, int length)
{
    link* current = first;
    link* previous = current;
    if (current == NULL)
    {
        throw Empty();
    }
    int counter = 0;
    while (current->information != number)
    {
        previous = current;
        current = current->next;
        counter++;
        if (counter == length && current == NULL)
        {
            throw NoSuitable();
        }
    }

    if (counter == length )
    {
        if (current->next == NULL)
        {
            delete current;
            previous->next = NULL;
            return;
        }
        else
        {
            throw NoSuitable();
        }
    }
    if (current == first)
    {
        first = first->next;
        delete current;
        return;
    }
    previous->next = current->next;
    delete current;
    return;



//    link* temp = first;
//
//    first = current;

//    delete temp;

}

bool LinkedList ::searchByOption(int number)
{
    bool isTrue = false;
    link* current = first;
    int counter = 0;
    while(current)
    {
        if(current->information == number)
        {

            counter++;
            isTrue = true;
        }
        current = current->next;
    }
    if (counter == 0)
    {
        throw NoSuitable();
    }
    return isTrue;
}


int LinkedList :: listLength()
{
    link* current = first;
    int length = 0;
    while (current != NULL)
    {
        current = current->next;
        length++;
    }
    return length;
}

void LinkedList ::sortAscending() {
    link* current = first;
    link* nextItem;
    int temp;
    link* tempNext;
    bool unsorted = true;
    while (unsorted)
    {
        unsorted = false;
        current = first;
        while (current->next != NULL)
        {
            nextItem = current->next;
            if(current->information > nextItem->information)
            {
                temp = current->information;
                current->information = nextItem->information;
                nextItem->information = temp;
                unsorted = true;
            }
            current = current->next;
        }
    }
}
void LinkedList ::sortDescending() {
    link* current = first;
    link* nextItem;
    int temp;
    link* tempNext;
    bool unsorted = true;
    while (unsorted)
    {
        unsorted = false;
        current = first;
        while (current->next != NULL)
        {
            nextItem = current->next;
            if(current->information < nextItem->information)
            {
                temp = current->information;
                current->information = nextItem->information;
                nextItem->information = temp;
                unsorted = true;
            }
            current = current->next;
        }
    }
}



void LinkedList ::moveToAnotherPlace() {
    link *current = first;
    link *rootFirst = first;
    link *selected;
    link *previous;
    int length = listLength();
    int chosenPosition;
    int counter = 0;
    std::cout << "Enter an item which you want to move" << std::endl;
    int chosenItem = inputValidation();
    searchByOption(chosenItem);
    std::cout << "Available positions : " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "\t[" << i << "]" << std::endl;
    }
    std::cout << "Choose a counter >>" << std::endl;
    chosenPosition = inputValidation();
    while (chosenPosition < 0 || chosenPosition > (length - 1)) {
        std::cout << "Incorrect value. Please try again" << std::endl;
        chosenPosition = inputValidation();
    }
    if (chosenPosition == 0) {
        while (current->information != chosenItem) {
            previous = current;
            current = current->next;
            selected = current;
        }
        previous->next = current->next;
        current = first;
        first = selected;
        selected->next = current;
        return;


    }
    while (current->information != chosenItem) {
        previous = current;
        current = current->next;
        selected = current;

    }
    previous->next = current->next;
    current = first;
    while (counter != chosenPosition) {
        previous = current;
        current = current->next;
        counter++;
    }
    previous->next = selected;
    selected->next = current;
}

void LinkedList :: deleteDublicates()
{
    link* current = first;
    link* nextItem = current->next;
    while(current->next != NULL)
    {
        while(nextItem->next !=NULL)
        {
            if(current->information == nextItem->information)
            {
                deleteItem(current->information, listLength());
                current = first;
                nextItem = current->next;
            }
            nextItem = nextItem ->next;
        }

        current = current ->next;
        nextItem = current->next;
    }
}


