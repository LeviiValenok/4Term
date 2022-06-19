#include <iostream>
#include <cstring>
#include <stdbool.h>
#include <limits>

using namespace std;

class String
{
    private:

        int number;
        enum
        {
            size = 50
        };
        char sentence[size];
        char matrixOfSymbols[2][10]{};

    public:
        String()
        {
            number = 0;
            strcpy(sentence, "");
        }

        String (char source[])
        {
            strcpy(sentence, source);
        }
        void putSentence()
        {

            cout << "Enter a sentence" << endl;


            // sentence = new char[20];
//            cin >> sentence;
//            cin.ignore(1, '\n');
//            cin.clear();
            rewind(stdin);
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(sentence, size);

//            cin.clear();



        }
        void outputNumber()
        {
            cout << "Number is" << endl;
            cout << '\t' << number << endl;
        }

       String& operator=(const String& t)
       {
           String temp{t};
           strcpy((*this).sentence, temp.sentence);
           return *this;
       }

       char& operator[](int index)
       {
            return sentence[index];
       }

        void outputSentence()
        {
            cout <<"Sentence is" << endl;
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"\t"<<sentence<< endl;
        }
        char& operator()(int line, int position)
        {
            if (line > 1 || position > 9)
            {
                cout << "Ooops, there are no items with this indexes" << endl;
                exit(1);
            }
            return matrixOfSymbols[line][position];
        }

        bool operator== (String item1) const
        {
           if (strcmp(item1.sentence, sentence) == 0)
           {
               return true;
           }
           else
           {
               return false;
           }
        }

//        void operator++ ()
//        {
//           ++number;
//        }

        String& operator++()
        {
            int length = strlen(sentence);
            char temp;
            for(int i = 0; i < length; i++)
            {
                temp = sentence[i];
                sentence[i] = (sentence[i]+1);
            }
            return *this;
        }

        String& operator++(int a)
        {
            int length = strlen(sentence);
            char temp;
            for(int i = 0; i < length; i++)
            {
                temp = sentence[i];
                sentence[i] = (sentence[i]+1);
            }
            return *this;
        }

        String operator+ (String item)
        {
           String temp;
           if ((strlen(item.sentence) + strlen(sentence))<50)
           {
               strcpy(temp.sentence, sentence);
               strcat(temp.sentence, item.sentence);
           }
           else
           {
               cout << "Sentences are too long";
               exit(1);
           }
           return temp;
        }
        operator char*()
        {
            return sentence;
        }
        friend String operator-- (String& item);
        friend ostream& operator<< (ostream &out, const String& item);
};

String operator-- (String& item)
{
    item.number--;
    return item;
}
ostream& operator<< (ostream &out, const String& item)
{
    out << "Sentence is\t" <<item.sentence << '\n' << "Size is\t" << item.size <<'\n';
    return out;
}

int menu()
{
    cout << '\t' <<"1 to overload =" << endl;
    cout << '\t' <<"2 to overload ()" << endl;
    cout << '\t' <<"3 to overload []" << endl;
    cout << '\t' <<"4 to overload ==" << endl;
    cout << '\t' <<"5 to overload +" << endl;
    cout << '\t' <<"6 to overload ++" << endl;
    cout << '\t' <<"7 to overload --" << endl;
    cout << '\t' <<"8 to overload <<" << endl;
    cout << '\t' <<"9 Convert to built-in type" << endl;
    cout << '\t' <<"10 convert to a custom type" << endl;
    cout << '\t' <<"11 to overload ++ for string(prefixed)" <<endl;
    cout << '\t' <<"12 to overload ++ for string(postfix)" << endl;
    cout << '\t' <<"13 string3 = ++string1+string2++" <<endl;
    cout << '\t' <<"0 to exit" << endl;
    cout << "Enter a choice: " << endl;
    bool isRight = true;
    int number;
    while (isRight)
    {
        cin >> number;
        cin.ignore(32767, '\n');
        if (cin.fail() || ( number < 0 || number > 13))
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
    cin.clear();
    return number;
}

int main()
{
    bool isQuite = false;
    String sentence1, sentence2, sentence3;
    while (!isQuite)
    {
        switch (menu())
        {
            case 1:
            {
                sentence1.putSentence();
                sentence1.outputSentence();
                sentence2.putSentence();
                sentence2.outputSentence();
                /*sentence3.outputSentence();*/
                sentence1 = sentence2;
                sentence1.outputSentence();
                break;
            }
            case 2:
            {
                cout << "Enter a letters " << endl;
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        cin >> sentence3(i, j);
                    }
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Result" << endl;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << sentence3(i, j);
                    }
                    cout << '\n';

                }
                break;
            }
            case 3:
            {
                sentence1.putSentence();
                int index;
                char letter;
                cout << "Enter an index" << endl;
                cin >> index;
                letter = sentence1[index];
                cout << "Letter is  " << letter << endl;
                break;
            }
            case 4:
            {
                sentence1.putSentence();
                sentence1.outputSentence();
                sentence2.putSentence();
                sentence2.outputSentence();
                if (sentence1 == sentence2) {
                    cout << "They are the same " << endl;
                } else {
                    cout << "They are different" << endl;
                }

                break;
            }
            case 5:
            {
                sentence1.putSentence();
                sentence1.outputSentence();
                sentence2.putSentence();
                sentence2.outputSentence();
                sentence3 = sentence1 + sentence2;
                sentence3.outputSentence();
                break;
            }
            case 6:
            {
                sentence1.outputNumber();
                ++sentence1;
                sentence1.outputNumber();
                break;
            }
            case 7:
            {
                sentence1.outputNumber();
                --sentence1;
                sentence1.outputNumber();
                break;
            }
            case 8:
            {
                sentence1.putSentence();

                sentence1.outputSentence();
                cout<<'\n';
                cout << sentence1;
                break;
            }
            case 9:
            {
                sentence1.putSentence();
                cout<<static_cast<char*>(sentence1);
                cout<<'\n';
                break;
            }
            case 10:
            {
                int size = 30;
                char source[30];
                cout << "Enter a sentence" << endl;
                rewind(stdin);
                cin.getline(source, size);
                sentence1 = source;
                sentence1.outputSentence();
                break;
            }
            case 11:
            {
                sentence1.putSentence();
                sentence1.outputSentence();
                ++sentence1;
                sentence1.outputSentence();
                break;
            }
            case 12:
            {
                sentence2.putSentence();
                sentence2.outputSentence();
                cout << sentence2++;
                sentence2.outputSentence();
                break;
            }
            case 13:
            {
                sentence1.putSentence();
                sentence1.outputSentence();

                sentence2.putSentence();
                sentence2.outputSentence();
//                sentence3 = ++sentence1 + sentence2++;
                sentence3 = ++sentence1 + sentence2;
                sentence2++;
                cout <<"Final sentence" << endl;
                sentence3.outputSentence();
                cout << "The first sentence" << endl;
                sentence1.outputSentence();
                cout << "The second sentence" << endl;
                sentence2.outputSentence();
                break;
            }
            case 0:
            {
                isQuite = true;
                break;
            }
        }
    }

    return 0;
}
