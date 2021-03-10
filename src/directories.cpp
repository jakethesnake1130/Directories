#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Properly format the phone number
 *
 * string phone stores the phone number being corrected
 * int position tracks the location of various potential informalities in 'phone'
 */
std::string FixPhoneNumber(std::string phone)
{
    int position;

    //Begin by removing improper characters
    position = phone.find("-");

    while(position != string::npos)
    {
        phone.replace(position, 1, "");
        position = phone.find("-");
    }

    position = phone.find("(");

    while(position != string::npos)
    {
        phone.replace(position, 1, "");
        position = phone.find(")");
    }

    //Check if proper formatting is present
    if(phone.find(".") == string::npos)
    {
        //Different placement based on inclusion/exclusion of area code
        if(phone.length() == 7)
        {
            phone.insert(3, ".");
        }
        else if(phone.length() == 10)
        {
            phone.insert(6, ".");
            phone.insert(3, ".");
        }
    }

    return phone;
}

/*
 * Properly format the name as First Middle Last
 *
 * string name stores the name being corrected
 * int position used to search for commas
 */
std::string FixName(std::string name)
{
    int position;
    position = name.find(",");

    //conditional checks for the presence of a comma
    if (position != string::npos)
    {
        //Separate first and last name
        string lastName = name.substr(0, position);
        string firstName = name.substr(position);
        //Remove the comma and space succeeding it
        firstName.replace(0, 2, "");
        //Reorder name in proper format
        name = firstName + " " + lastName;
    }

    return name;
}

/*
 * Properly format the email to contain the entire address
 *
 * string name stores the email being corrected
 */
std::string FixEmail(std::string email)
{
    //If there is no "@" symbol, WSU address is assumed
    if(email.find("@") == string::npos)
    {
        email = email + "@mail.weber.edu";
    }
    //If there is an "@" symbol but no ".com", then ".com" will be added
    else if (email.find(".com") == string::npos)
    {
        email = email + ".com";
    }

    return email;
}

/*
 * Write the corrected directory to the proper output file
 *
 * string phone - read in from file in main(), stores the phone number to be corrected
 * string name - read in from file in main(), stores the name to be corrected
 * string email - read in from file in main(), stores the email to be corrected
 * ostream out - read in from file in main(), stores the ostream to be corrected
 * string nameFixed - after the name has been corrected, checks for variable length
 *                    and corrects accordingly
 */
void WriteFormatted(std::string phone, std::string name, std::string email, std::ostream& out)
{
    string nameFixed;

    //Run the functions detailed above in this class on variables as they are passed in
    phone = FixPhoneNumber(phone);
    name = FixName(name);
    email = FixEmail(email);

    //Check for length of string name and truncate if found to be too long
    if(name.length() > 19)
    {
        nameFixed = name.substr(0,16) + "...";
    }
    else
    {
        nameFixed = name;
    }

    //Print to file (defined in main()) in proper format
    out
    << right
    << setw(16) << phone
    << "  " << left
    << setw(19) << nameFixed
    << "  "
    << email
    << endl;
}

