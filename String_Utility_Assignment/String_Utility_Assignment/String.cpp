#include "String.h"
#include <iostream>
using namespace std;

String::String() { //declaring constructor
	cout << " ++ constructor activated " << endl;
}
String::~String() { //declaring destructor
	cout << "destructor activated";
    delete[] m_data;
}

/// <summary>
/// returns an integer representing the count of characters up to the null terminator character
/// </summary>
/// <returns></returns>
size_t String::Length() const {
    // Initialize a counter to store the length
    size_t length = 0;
    // Iterate through the characters of the string until the null terminator is encountered
    while (m_data[length] != '\0') {
        length++;
    }
    return length;

}
char String::CharacterAt(size_t _index) {
    // Check if the index is valid
    if (_index >= 0 && _index < Length()) {
        return m_data[_index]; // Return the character at the specified index
    }
    else {
        return '\0'; // Return '\0' for invalid index
    }
}