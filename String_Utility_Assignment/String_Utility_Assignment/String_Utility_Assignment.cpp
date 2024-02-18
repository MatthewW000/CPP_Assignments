
#include "String.h"
#include <iostream>
using namespace std;

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

    return 0;
}
