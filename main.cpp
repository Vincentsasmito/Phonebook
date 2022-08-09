#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
using namespace std;

//global variables
int track = 0;

//phonebook class
class phoneBook{
    public:
    string name;
    long long phoneNumber;
    string address;

    //data entry function
    void enterData()
    {
        cout << "Enter your name: " << endl;
        fflush(stdin);
        getline(std::cin, name);
        cout << "Enter your phone number: " << endl;
        fflush(stdin);
        cin >> phoneNumber;
        cout << "Enter your address: " << endl;
        fflush(stdin);
        getline(std::cin, address);
    }
};

//Function untuk print book
void printBook(phoneBook book1[10])
{
    for(int x = 0; x < track; x++)
    {
        cout << book1[x].phoneNumber << " || " << book1[x].name << " || " << book1[x].address << endl;
    }

}

//fungsi delete
void deleteBook(phoneBook book1[10])
{
    long long deleteNumber;

    cout << "Phone Number : ";
    cin >> deleteNumber;

    for(int x = 0; x < track; x++)
    {
        if(deleteNumber == book1[x].phoneNumber)
        {
            for(int j = x; j < track; j++)
            {
                book1[j].phoneNumber = book1[j+1].phoneNumber;
                track -= 1;
                break;
            }
        }
    }
}

//fungsi sorting secara insertion berdasarkan nama
void sortBook(phoneBook book1[10], int track)
{
    int key, j, i;
    for(i = 1; i < track; i++)
    {
        key = book1[i].phoneNumber;
        j = j - 1;

        while(j >= 0 && book1[j].phoneNumber > key)
        {
            book1[j+1].phoneNumber = book1[j].phoneNumber;
            j = j - 1;
        }
        book1[j+1].phoneNumber = key;

    }

    for(i = 0; i < track; i++)
    {
        cout << book1[i].phoneNumber << " || " << book1[i].name << " || " << book1[i].address << endl;
    }
}

int main()
{
    //Class Declaration + Size
    phoneBook book1[10];
    //Stop variable untuk loop program
    bool stop = false;
    while(stop == false)
    {
        int choice;
        cout << "" << endl;
        cout << "Phone Book"<<endl;
        cout << "1. Enter new number" << endl;
        cout << "2. Display all numbers" << endl;
        cout << "3. Delete data" <<endl;
        cout << "4. Sort data" <<endl;
        cout << "Enter your choice : "<< endl;
        cin  >> choice;
        cout << ""<< endl;
        switch(choice)
        {
            case 1:
            book1[track].enterData();
            track++;
            break;

            case 2:
            cout << "Num          ||      Name     ||           Address" << endl;
            printBook(book1);
            default:
                break;

            case 3:
            cout <<"Enter the data do you want to delete "<< endl;
            deleteBook(book1);

            case 4:
            cout <<"Sort the data"<< endl;
            sortBook(book1, track);

        }

    }

}
