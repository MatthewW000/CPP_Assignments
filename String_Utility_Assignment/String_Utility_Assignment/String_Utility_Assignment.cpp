
#include "String.h"
#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const String& str) {
    // Assuming you have a method CStr() that returns a const char* to the internal string data
    os << str.CStr();
    return os;
}

int main() {

   
    // Test default constructor
    String empty;
    cout << "Testing default constructor (should be empty): '" << empty.CStr() << "'" << endl;

    // Test constructor with const char* parameter
    String hello("Hello, World!");
    cout << "Testing constructor with const char* parameter: '" << hello.CStr() << "'" << endl;

    // Test copy constructor
    String helloCopy(hello);
    cout << "Testing copy constructor (should match Hello, World!): '" << helloCopy.CStr() << "'" << endl;

    // Memory cleanup for dynamically allocated String (if any)
    // No dynamic allocation used in these tests, so nothing to clean up here.

    String myString("Hello, world!");
    cout << "The length of the string is: " << myString.Length() << endl;

    String emptyString("");
    String testString("How Long is this word?");

    cout << "The length of an empty string is: " << emptyString.Length() << endl;

    // Test CharacterAt( index ) function:
    cout << testString.CharacterAt(9) << endl; // should return 'i'

    // Test EqualTo(str)
    String testString2("How Long is this word?");
    cout << "Test results should return a 1 if EqualTo: " << testString.EqualTo(testString2) << endl;

    // ------- problems here

    // Create two String instances
    String initialString("Hello");
    String stringToAppend(" World!");

    // Use the Append function
    initialString.Append(stringToAppend);

    cout << initialString;

    return 0;
}
