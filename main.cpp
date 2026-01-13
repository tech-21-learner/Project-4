// Name: Siddh Patel
// ID: 200543710
// Date: 14/08/2025
// Purpose: Implementing the Dynamic Array of char values and converting the lower cases to upper cases values

#include <iostream> // including the libraries  
#include <cctype> // including the library to change lower case to the upper case character and check for alphabates

using namespace std;

int main() // start of main function
{
    int cap = 2;  // initializing the capacity to 2
    int length; // declaring the length
    char* array = new char[cap]; // declaring the dynamic character array by keyword new

    while(true) // infinite while loop
    {
        char ch; // declaring the character variable
        length = 0; // reseting the length to the zero after ever run of while loop
        cout << "Enter the characters: "; // prompt user to enter characters

        while (cin.get(ch) && ch != '\n') // while loop that takes the input from the user by .get() function and check wheather input value is newline character or not 
        {          
            if (length >= cap) // check if there is enough space for storing the characters in the array 
            {
                cap += 3; // increase the storage capacity when needed by 3
                char* newArray = new char[cap]; // declaring the dynamic array inorder to store new more characters 
                for (int i = 0; i < length; i++) // loop to check all values stored in the array
                {
                    newArray[i] = array[i]; // copyiny the char value from the array to newArray
                }
                delete[] array; // delete the dynamic array to free the space
                array = newArray; // changing the pointer address.
            }
            array[length] = ch; // store the character in the current position
            length++; // move the index to the next empty spot by incrementing the length value  
        }

        cout << "The upper case characters are: "; // prompt reflected on the console

        for (int i = 0; i < length; i++) // for loop in order to check all the char values
        {
            if (isalpha(array[i])) // check if all the values are alphabates from A-Z by inline function isalpha()
            {
        // (char) is used for type-casting, it converts the int values to the character values
            cout << (char)toupper(array[i]);// convert the lower case character to upper case by toupper()
            }
            else
            cout << array[i]; // non-alphabets are printed as it is 
        }
        cout << endl; // print line

        cout << "The array length is: " << length << endl; // prompt reflected on the console shows the length
        cout << "The array capacity is: " << cap << endl; // prompt reflected on the console shows the capacity

    } // infinite loop ends manually by the user

    delete[] array; // free the space occupied by the dynamic array 
    return 0; // exit program
}
