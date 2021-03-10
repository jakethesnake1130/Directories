#include <iostream>
#include "directories.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //File read/write objects
    ifstream in;
    ofstream out;

    string clubName;
    string phoneNumber;
    string name;
    string email;

    //Begin by opening the file to be written in/read
    out.open("../../Directory_Fixed.txt");
    in.open("../../dungeons.txt");
    //Failsafe
    if(in.fail())
    {
        cout << "Unable to open file. Goodbye." << endl;
        return 0;
    }

    //Keep these out of the loop to ensure variables store the proper data
    getline(in, clubName);
    //Formatting club title w/ indentation
    out << "               " << clubName << endl;

    //Loop through the file until no more data to be found
    while(getline(in, phoneNumber))
    {
        getline(in, name);
        getline(in, email);

        //Write the fixed directory with this method, adding a new line each loop
        WriteFormatted(phoneNumber, name, email, out);
    }

    //Close the read file and open the next
    //Write file is left open to continue adding info
    in.close();
    in.open("../../wild_runners.txt");
    //Failsafe
    if(in.fail())
    {
        cout << "Unable to open file. Goodbye." << endl;
        return 0;
    }

    //Same exact functionality as above, applied to different file
    getline(in, clubName);

    out << "               " << clubName << endl;

    while(getline(in, phoneNumber))
    {
        getline(in, name);
        getline(in, email);

        WriteFormatted(phoneNumber, name, email, out);
    }

    //close read/write files
    out.close();
    in.close();

    //end program
    return 0;
}