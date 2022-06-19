#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int main() {
//    char firstSentence[80];

    char *firstSentence = (char *) calloc(80, sizeof(char));
    char *secondSentence = (char *) calloc(80, sizeof(char));
//    char secondSentence[80];
    do {
        cout << "Enter first sentence" << endl;
//        fgets (firstSentence, 80, stdin);
        cin.getline(firstSentence, 80);
    } while (firstSentence[0] == '\0');


    do {
        cout << "Enter second sentence" << endl;
        cin.getline(secondSentence, 80);
//        fgets (secondSentence, 80, stdin);
    } while (secondSentence[0] == '\0');


    int compareIndex;
    /*compareIndex = stricmp (firstSentence, secondSentence);
    if (compareIndex < 0)
    {

        cout << "The longest string" << endl;
        cout << secondSentence << endl;
    }
    else if (compareIndex > 0)
    {

        cout << "The longest string" << endl;
        cout << firstSentence << endl;
    }
    else
    {
        cout << "Equal length strings" << endl;
        cout << firstSentence << endl;
        cout << secondSentence << endl;
    }*/
    int firstSentenceLength = strlen(firstSentence);
    int secondSentenceLength = strlen(secondSentence);
//    int amountOfSymbolFirstSentence = 0;
    int amountOfNumbersFirstSentence = 0;
    for (int i = 0; i < firstSentenceLength; i++)
    {
        if (firstSentence[i] >= '0' && firstSentence[i] <= '9')
        {
            amountOfNumbersFirstSentence++;
        }

    }
    int amountOfLettersSecondSentence = 0;
    for (int i = 0; i < secondSentenceLength; i++)
    {
        if (secondSentence[i] >= 'A' && secondSentence[i] <= 'Z' ||
            secondSentence[i] >= 'a' && secondSentence[i] <= 'z' && secondSentence[i] != 32) {
            amountOfLettersSecondSentence++;
        }

    }
    if (amountOfNumbersFirstSentence > amountOfLettersSecondSentence) {
        cout << "Most items in the first string" << endl;
        cout << firstSentence << endl;
    } else if (amountOfNumbersFirstSentence < amountOfLettersSecondSentence) {
        cout << "Most items in the second string" << endl;
        cout << secondSentence << endl;
    } else if (amountOfLettersSecondSentence == amountOfNumbersFirstSentence) {
        cout << "Equal amount of items" << endl;
        cout << firstSentence << endl;
        cout << secondSentence << endl;
    }
    return 0;

}
