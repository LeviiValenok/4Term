#include <iostream>
#include <cstring>
#include <cctype>

class Text
{
private:
    char** text{};
    int numberOfSymbols = 30;
    int rows = 2;
public:

    Text()
    {
        text = new char* [rows];
        for (int i = 0; i < rows; i++)
        {

            text[i] = new char[numberOfSymbols];
            rewind(stdin);
            text[i] = NULL;
        }

    }
    Text(char** source, int size)
    {
        text = new char* [20];
        for (int i = 0; i < size; i++)
        {
            int length = sizeof(source[i]);
            text[i] = new char[length];
            strcpy(text[i], source[i]);
        }
    }

    Text(Text& item)

    {

        numberOfSymbols = item.numberOfSymbols;
        rows = item.rows;
        for (int i = 0; i < numberOfSymbols; i++)
            for (int j = 0; j < rows; j++)
                text[i][j] = item.text[i][j];
        std::cout << "All is ok (:" << std::endl;
    }
    /*        ~Text()
            {
                for (int i = 0; i < rows; i++)
                {
                    delete [] text[i];
                }
                delete [] text;
            }*/
    /*        void inputSizeOfText()
            {
                std::cout <<"Number of rows is" <<std::endl;
                std::cin >> rows;
                std::cout <<"Number of symbols is" <<std::endl;
                std::cin >> numberOfSymbols;

            }

            void outputSizeOfText()
            {
                std::cout <<"Number of rows is \t" << rows << std::endl;
                std::cout << "Number of symbols is \t" << numberOfSymbols << std::endl;

            }*/
    static void operator delete (void* pointer);

    static void operator delete[](void* pointer);

    void inputText()
    {
        std::cout << "Input a text" << std::endl;
        text = new char* [rows];
        for (int i = 0; i < rows; i++)
        {
            text[i] = new char[numberOfSymbols];

            rewind(stdin);
            std::cin.getline(text[i], numberOfSymbols);
        }
    }
    void outputText()
    {
        std::cout << "Your text is" << std::endl;
        for (int i = 0; i < rows; i++)
        {
            std::cout << '\t' << text[i] << std::endl;
        }
    }

    void* operator new(size_t size)
    {
        void* textPointer;
        textPointer = ::operator new(size);
        if (textPointer == 0)
        {
            std::cout << "Error. Memory is not allocated!" << std::endl;
        }
        //            std::cout << '\t'<<"Memory is allocated" << std::endl;
        return textPointer;
    }



    void* operator new[](size_t size)
    {
        void* textPointer;
        textPointer = ::operator new(size);
        if (textPointer == 0)
        {
            std::cout << '\t' << "Error. Memory is not allocated!" << std::endl;
        }
        //            std::cout <<'\t'<<"Memory is allocated" << std::endl;
        return textPointer;
    }
    void sortEveryString()
    {
        for(int a=0;a<rows;a++)
            for (int i = 0; i < strlen(text[a]); i++)
            {
                for (int j = i + 1; j < strlen(text[a]); j++)
                {
                    if (text[a][i] > text[a][j])
                    {
                        char tmp = text[a][i];
                        text[a][i] = text[a][j];
                        text[a][j] = tmp;

                    }
                }
            }

    }
};

void Text::operator delete (void* pointer)
{
    std::cout << "Delete work" << std::endl;
    ::operator delete(pointer);
}

void Text::operator delete[](void* pointer) {
    std::cout << "Delete work" << std::endl;
    ::operator delete[](pointer);
}

int main()
{
    Text* textArray;
    textArray = new Text[3];
    Text* text_1 = new Text;
    text_1->inputText();
    text_1->outputText();
    text_1->sortEveryString();
    text_1->outputText();
    delete text_1;
    for (int i = 0; i < 3; i++)
    {
        (textArray + i)->inputText();
        (textArray + i)->sortEveryString();
    }
    for (int i = 0; i < 3; i++)
    {
        (textArray + i)->outputText();
    }

    getchar();
    return 0;
}