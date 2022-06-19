#include <iostream>


class MusicalInstruments
{
    public:
        std::string name;
        std::string type;
        MusicalInstruments()
        {
            name = "empty";
            std::cout <<"\n";
            type = "empty";
            std::cout <<"\n";

        }
        MusicalInstruments (std::string musicalName, std::string typeName)
        {
            name = musicalName;
            type = typeName;
        }

        void outputInformation()
        {
            std::cout<<"Name is: "<< name <<std::endl;
            std::cout<<"Type is: "<< type <<std::endl;

        }

};




class Keyboard : virtual public MusicalInstruments
{
public:
    int age;
    Keyboard(std::string name, std::string type, int number):
        MusicalInstruments(name, type)
    {
        age = number;
    }

    ~Keyboard()
    {

    }
/*    Keyboard(std::string Name, std::string Type, int number): age(number)
    {
        type = Type;
        name = Name;
    }*/
    void displayAge()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Age is: " << age << std::endl;
    }
};

class Piano : public Keyboard
{
public:
    std::string belonging;
    Piano(std::string name, std::string type, int age, std::string person):
    Keyboard(name,type, age)
    {
        belonging = person;
    }

    void displayPiano()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Age is: " << age << std::endl;
        std::cout<<"Instrument belongs to: "<< belonging << std::endl;

    }
};

class Stringed : virtual public MusicalInstruments
{
public:
    int numberOfStrings;
    Stringed(std::string name, std::string type, int number):
        MusicalInstruments(name, type)
    {
        numberOfStrings = number;
    }
    void displayNumberOfStrings()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Number of strings: "<< numberOfStrings <<std::endl;
    }
};

class Guitar: public Stringed
{
public:
    std::string model;
    Guitar(std::string name, std::string type, int numberOfStrings, std::string Model):
            Stringed(name, type, numberOfStrings)
    {
        model = Model;
    }

    ~Guitar()
    {

    }

    void displayModel()
    {
        std::cout<<"Name is: "<< name <<std::endl;
        std::cout<<"Type is: "<< type <<std::endl;
        std::cout<<"Number of strings: "<< numberOfStrings <<std::endl;
        std::cout <<"Model is: "<< model <<std::endl;
    }

};


class MusicBand: public Guitar, public Piano
{
public:
    std::string bandName;
    int numberOfMembers;

    MusicBand(std::string name, std::string type,int numberOfStrings, std::string Model,
              int age, std::string person, std::string BandName, int NumberOfMembers):
              Guitar(name, type, numberOfStrings, Model),
                Piano(name, type, age, person),
                MusicalInstruments(name, type)
    {

        numberOfMembers = NumberOfMembers;
        bandName = BandName;
    }

    void displayListOfBand()
    {
        std::cout<<"Band name is: "<<bandName<<std::endl;
        std::cout<<"Number of members is: "<< numberOfMembers << std::endl;
        std::cout<<"Musical instrument mame is: "<< name <<std::endl;
        std::cout<<"Musical instrument type is: "<< type <<std::endl;
        std::cout <<"Model is: "<< model <<std::endl;
        std::cout<<"Instrument belongs to: "<< belonging << std::endl;
        std::cout<<"Age is: " << age << std::endl;
        std::cout<<"Number of strings: "<< numberOfStrings <<std::endl;

    }
};


int main()
{
    MusicalInstruments guitar("Guitar", "Stringed");
    Stringed instrument("Guitar", "Stringed", 6);
    instrument.outputInformation();
    instrument.displayNumberOfStrings();

    Guitar force("Guitar", "Stringed", 6, "BigCompany");
    force.outputInformation();
    force.displayNumberOfStrings();
    force.displayModel();

//    guitar.outputInformation();
//    Keyboard piano("Piano", "Keyboard", 10);
//    piano.outputInformation();
//    piano.displayAge();

    Piano item("Piano", "Keyboard", 10, "Stas");
    item.outputInformation();
    item.displayAge();
    item.displayPiano();


    /*MusicBand(std::string name, std::string type,int numberOfStrings, std::string Model,
            int age, std::string person, std::string BandName, int NumberOfMembers): Guitar(name, type, numberOfStrings, Model),
            Piano(name, type, age, person)*/

    MusicBand group("Piano", "Keyboard", 0, "Belarus", 10, "Stas", "NaviBand", 2);
    group.displayListOfBand();
    return 0;
}
