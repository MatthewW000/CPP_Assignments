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

/// <summary>
/// CharacterAt Function will return a char representing the character at the location,
///  if Index is less than 0 or greater than length, this will return \0.(non const version)
/// </summary>
/// <param name="_index"></param>
/// <returns></returns>
char& String::CharacterAt(size_t _index) {
    // Check if the index is valid
    if (_index >= 0 && _index < Length()) {
        return m_data[_index]; // Return the character at the specified index
    }
    else {
        // Handle the case of an invalid index
        // For simplicity, throw an exception
        throw std::out_of_range("Index out of range");
    }
}

/// <summary>
/// CharacterAt Function will return a char representing the character at the location,
///  if Index is less than 0 or greater than length, this will return \0.(const version)
/// </summary>
/// <param name="_index"></param>
/// <returns></returns>
const char& String::CharacterAt(size_t _index) const {
    // Check if the index is valid
    if (_index >= 0 && _index < Length()) {
        return m_data[_index]; // Return the character at the specified index
    }
    else {
        // Handle the case of an invalid index
        // For simplicity, throw an exception
        throw std::out_of_range("Index out of range");
    }
}

/// <summary>
/// Returns True if string contains the same characters.
/// </summary>
/// <param name="_other"></param>
/// <returns></returns>
bool String::EqualTo(const String& _other) const {
    //Are both strings same length?
    if (Length() != _other.Length()) 
    {
        return false;
    }

    // Compare each character of the Strings
    for (size_t i = 0; i < Length(); i++)
    {
        if (m_data[i] != _other.m_data[i]) // Check if member data is not equal by looping through each char.
        {
            return false;
        }
    }
    return true; // all checks pass, return true.
}