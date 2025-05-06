#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main ( ) {
    string str , str2;
    int choice;

    cout << "Enter the first string: ";
    getline ( cin , str );

    cout << "Enter the second string (for comparison, append, etc.): ";
    getline ( cin , str2 );

    do {
  
        cout << "\nSelect a string function to demonstrate:\n";
        cout << "1. Length of the string\n";
        cout << "2. Substring\n";
        cout << "3. Append another string\n";
        cout << "4. Compare two strings\n";
        cout << "5. Find a character in the string\n";
        cout << "6. Replace part of the string\n";
        cout << "7. Find substring in string\n";
        cout << "8. Convert to uppercase\n";
        cout << "9. Convert to lowercase\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore ( );  
        switch ( choice ) {
            case 1: {
            cout << "Length of the string: " << str.length ( ) << endl;
            break;
            }
            case 2: {
            int pos , len;
            cout << "Enter the position to start the substring: ";
            cin >> pos;
            cout << "Enter the length of the substring: ";
            cin >> len;
            cin.ignore ( ); 
            cout << "Substring: " << str.substr ( pos , len ) << endl;
            break;
            }
            case 3: {
            cout << "Original string: " << str << endl;
            str.append ( str2 );
            cout << "After appending the second string: " << str << endl;
            break;
            }
            case 4: {
            int result = str.compare ( str2 );
            if ( result == 0 )
                cout << "Both strings are equal.\n";
            else if ( result > 0 )
                cout << "First string is greater than second string.\n";
            else
                cout << "First string is smaller than second string.\n";
            break;
            }
            case 5: {
            char ch;
            cout << "Enter the character to find: ";
            cin >> ch;
            size_t found = str.find ( ch );
            if ( found != string::npos )
                cout << "Character '" << ch << "' found at position " << found << endl;
            else
                cout << "Character '" << ch << "' not found.\n";
            break;
            }
            case 6: {
            int startPos;
            string replacement;
            cout << "Enter the position to replace from: ";
            cin >> startPos;
            cin.ignore ( );  
            cout << "Enter the string to replace with: ";
            getline ( cin , replacement );
            str.replace ( startPos , replacement.length ( ) , replacement );
            cout << "After replacement: " << str << endl;
            break;
            }
            case 7: {
            string subStr;
            cout << "Enter the substring to find: ";
            getline ( cin , subStr );
            size_t found = str.find ( subStr );
            if ( found != string::npos )
                cout << "Substring '" << subStr << "' found at position " << found << endl;
            else
                cout << "Substring '" << subStr << "' not found.\n";
            break;
            }
            case 8: {
            for ( char& ch : str ) {
                ch = toupper ( ch );
                }
            cout << "String in uppercase: " << str << endl;
            break;
            }
            case 9: {
            for ( char& ch : str ) {
                ch = tolower ( ch );
                }
            cout << "String in lowercase: " << str << endl;
            break;
            }
            case 10: {
            cout << "Exiting the program.\n";
            break;
            }
            default: {
            cout << "Invalid choice. Please try again.\n";
            break;
            }
            }
        } while ( choice != 10 );

        return 0;
    }
