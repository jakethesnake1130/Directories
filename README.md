# CHALLENGE: DIRECTORIES


## Purpose

The purpose of this assignment is to demonstrate creating  
a program using `ifstream`, `ofstream`, and `string` objects.  

## Skills and Knowledge

This activity will help you practice the following skills that essential to know for basic programming in `C++`:

- Define and use string objects
- Define and use filestream objects
- Format output


This lab will also help you to become familiar with the following important content knowledge in CS:

- Working in your development environment.
- Use built-in class libraries.
- Use basic unit testing to validate your code: `catch2`.

### Files to work on

You will be working the following files:

- All the functions you write, will be part of the library `directories`. The library consist of these two files:
  - `src/directories.cpp`
  - `src/directories.h`.
- Our "driver" will be `src/main.cpp`.
- You will also produce additional output files.

Please **DO NOT MODIFY** any other files. Modifying other files may result 
in the unit tests not passing.

---

## Problem to Solve

Several clubs across campus have contact information stored in files. This 
contact information is stored in plain text files but it is a bit messy. The
names are in different formats, the phone numbers have a variety of
separators or no separators at all, and some of the emails are incomplete.

The clubs would like to have consistent and organized directories. Here is what 
they are expecting.
- phone numbers to use the . as a separator
- names to be in first last format
- emails to be complete
- everything lined up
    - club title at the top of the list, indented 10 spaces
    - one person per line
    - phone numbers line up on the right
    - two blank spaces
    - names line up on the left, maximum of 16 characters showing
    - two blank spaces
    - emails line up on the left 
    
Example:


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Wildcat Trail Runners<br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;347.8392&nbsp;&nbsp;
John Walters&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;johnwalters@gmail.com<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
782.327.4938&nbsp;&nbsp;&nbsp;Gina Sue Ramseys&nbsp;&nbsp;
&nbsp;
&nbsp;ginaramseys2@mail.weber.edu<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
493.721.2039&nbsp;&nbsp;&nbsp;Jane Walker&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;janewalker1@mail.weber.edu<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;721.3954&nbsp;&nbsp;
Bill T. Johnson&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;billyj2938@yahoo.com

The problem is to read in the data from a file and then fix
and print the data as a directory to another file.

---

## Part 1: Fix the Phone Number

Write a function that receives a phone number in any of the formats in the 
original data and returns a phone number in the specified format. The
phone number is to use "." as the separator. It can either be a 7-digit or 
10-digit number. Here is an example the specified format.

    893.3464
    564.893.3464

In the original data,the phone numbers can be in any of the following formats.
None of the original phone numbers are in any other format than the ones
listed below.

    893-3464
    564-893-3464
    8933464
    5648933464
    893.3464
    564.893.3464
    (564)893-3464
    
 Add the function prototype in the `directories.h` file.
 
    std::string FixPhoneNumber(std::string phone);
 
 Write the function definition in the `directories.cpp` file.
 
---

## Part 2: Fix the Name

Write a function that receives a name in any of the formats in the 
original data and returns a name in the specified format. The
name is to written in first middle last format. Middle names are optional and it is possible to have multiple middle
 names. Here are some examples of the 
specified format.

    Bilbo Baggins
    Jessica Peterson
    Caroline B. Wartleton
    Connor William Harold Jones

In the original data,the names can be in any of the following formats.
None of the original names are in any other format than the ones
listed below.

    last, first
    first last
    first middle last
    last, first middle

Examples

    Baggins, Bilbo 
    Jessica Peterson
    Caroline B. Wartleton
    Jones, Connor William Harold 
    
 Add the function prototype in the `directories.h` file.
 
    std::string FixName(std::string name);
 
 Write the function definition in the `directories.cpp` file.
 
 ---

 ## Part 3: Fix the Email
 
 Write a function that receives an email in any of the formats in the 
 original data and returns an email in the specified format. The
 email is to be complete including username, @, and domain. 
 
 In the original data,some of the emails have been abbreviated. If the 
 email only has the username (no @ or domain), it is a student email account.
 In this case, add @mail.weber.edu to the username.
 
        bilbo.baggins
     becomes:
        bilbo.baggins@mail.weber.edu
     
   If the email has the username, an @, and the first part of the domain, add 
   .com at the end.
   
          bilbo.baggins@gmail
               becomes:
          bilbo.baggins@gmail.com
  
  Add the function prototype in the `directories.h` file.
  
     std::string FixEmail(std::string email);
  
  Write the function definition in the `directories.cpp` file.

---

## Part 4: Format the Output

Write a function that receives a phone number, a name, an email, and an 
`ostream` object and writes a single, formatted line to the `ostream` object. 
 The `ostream` object is
where you want the data to be written to. 

Using ostream for the last parameter
allows you to send `cout` or an `ofstream` object. This makes it easy to test this
function with `cout` before you try it with a file. The `ostream` object must be
passed by reference.

The format of the output is very specific. Use `setw` to make sure everything
fits as expected on the line. Each line is to contain the following.

- a phone number 
    - lines up on the right
    - uses 16 spaces
- two blank spaces
- a name 
    - lines up on the left
    - uses 19 spaces
    - when a name is longer than 19 characters, print the first 16 
    characters of the name followed by three dots (...).
- two blank spaces
- an email 
    - lines up on the left
- a carriage return (\n or endl) 


Example 1

      234.543.2432  Bill Collins         collins297@gmail.com


Example 2

          943.6543  Bart Smith           bart.smith@gmail.com


Example 3

      432.543.8432  Harold Bean T. J...  harold.b@gmail.com
 
  Add the function prototype in the `directories.h` file.
  
     void WriteFormatted(std::string phone, std::string name, std::string email, std::ostream& out);
  
  Write the function definition in the `directories.cpp` file.

---

## Part 5: Reading and Writing the Data

Read the data from the original file and print out the updated, formatted 
data to a new file. This will happen from `main.cpp`.


### Part 5.1: Gather filenames from user

Gather the filenames for the input file and the output file from the user. 
If the input file does not exist, notify the user and shut the program
down. The user is to enter 
just the filename and extension. The program is 
to add any path needed for the files to work as expected.

The input and output files are to be in the main directory of the project. 
If you are using CLion, when you open these files you will need to 
prepend `../../` to both the input
filename and the output filename. If you are using another development 
environment it may require a different prefix.



### Part 5.2: Read data from the input file

Read the data from the input file. 

- The first line in the file is the name of the club. 

After that is the data for the members. Each member data
takes up three lines.

 - The first line contains the phone number
 - The second line contains the name (has spaces)
 - The third line contains the email

 Notice how the phone number and the email do not have spaces.
Using >> to read these values is simpler and less prone to errors.
  
You can read the data and store it in arrays if you like. Or you can read in 
 a line, process the data and print it out. I found it easier to read and
 print without storing the data in an array.
 
 
 There are two input files included in the starter code.
 
    wild_runners.txt
    dungeons.txt
    


### Part 5.3: Write data to the output file

Write the data to the output file. 

- The first line in the file is to be the name of the club indented about 
10 spaces. 

After that is the updated, formatted data for the members. Each member data
takes up a single line.

- phone number, name, and email with spacing and alignment as 
indicated in Part 4

---

## Validate your code

Once you are satisfied with your work, run the unit test file:

From the dropdown select main_test and run.

Sample output:

Tests passed: 6 of 6 tests

---

## Submit your code

Zip your src folder and submit in Canvas.
