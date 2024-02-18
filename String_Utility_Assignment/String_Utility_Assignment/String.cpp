#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

String::String() { //declaring constructor
    m_data = new char[1];
    m_data[0] = '\0'; // Ensures an empty string
    cout << "++ constructor activated" << endl;
}

/// <summary>
/// overload contructor for handling the const char* to allocate enough space for the string and the null terminator, then copies string into 'm_data'
/// </summary>
/// <param name="_str"></param>
String::String(const char* _str) {
    if (_str) {
        m_data = new char[strlen(_str) + 1]; // +1 for the null terminator
        strcpy(m_data, _str);
    }
    else {
        m_data = new char[1];
        m_data[0] = '\0'; // Handle null input by creating an empty string
    }
    cout << "++ constructor activated" << endl;
}

/// <summary>
/// overload constructor to implement the copy constructor correctly, allocating memory for m_data.
/// </summary>
/// <param name="_other"></param>
String::String(const String& _other) : m_data(new char[_other.Length() + 1]) {
    strcpy(m_data, _other.m_data); // Copy the content
    cout << "++ constructor activated" << endl;
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

/// <summary>
/// Input a string to add to the end of the string
/// </summary>
/// <param name="_str"></param>
/// <returns></returns>
String& String::Append(const String& _str) {
    //Calculate length of new combined array
    size_t newLength = Length() + _str.Length();

    //Allocate the memory for our new string data.
    char* newData = new char[newLength + 1]; // Remember to allocate the null terminator.

    //Copy current string array into the new data.
    strcpy(newData, m_data);

    //then we concatenate the string
    strcat(newData, _str.m_data);

    //delete the old memory from our old string
    delete[] m_data;

    //update to point at new data
    m_data = newData;

    return *this;
}

/// <summary>
/// Input a string to add the beginning of the string
/// </summary>
/// <param name="_str"></param>
/// <returns></returns>
String& String::Prepend(const String& _str) {
    //Calculate and determine new size of the string after prepending
    size_t newLength = Length() + _str.Length();

    //Allocate the memory for the new string data
    char* newData = new char[newLength + 1]; // Remember to allocate the null terminator.

    //Copy the string from _str to the new data array
    strcpy(newData, _str.m_data);

    //Append string to the new data string
    strcat(newData, m_data);

    //delete old string data
    delete[] m_data;

    //update to point at new data
    m_data = newData;

    return *this;
}

/// <summary>
/// return the const char * that is usable with std::cout. eg: std::cout<< str.cstr() << std::endl;
/// </summary>
/// <returns></returns>
const char* String::CStr() const {
    return m_data;
}

/// <summary>
/// Converts all characters to lowercase
/// </summary>
/// <returns></returns>
String& String::ToLower() {
    for (size_t i = 0; i < Length(); ++i) {
        m_data[i] = std::tolower(m_data[i]); // lowercase current string char in array.
    }
    return *this;

}

/// <summary>
/// Converts all characters to uppercase
/// </summary>
/// <returns></returns>
String& String::ToUpper() {
    for (size_t i = 0; i < Length(); ++i) {
        m_data[i] = std::toupper(m_data[i]); // uppercase current string char in array.
    }
    return *this;

}

/// <summary>
/// Returns the location of the findString. If not found, return -1 (relies on String::Find)
/// </summary>
/// <param name="_str"></param>
/// <returns></returns>
size_t String::Find(const String& _str) {
    return Find(0, _str);
}

/// <summary>
/// Returns the location of the strToFind. Beginning the search from startIndex. If not found, return -1
/// </summary>
/// <param name="_startIndex"></param>
/// <param name="_str"></param>
/// <returns></returns>
size_t String::Find(size_t _startIndex, const String& _str) {
    //If Index is out of bounds, return -1
    if (_startIndex >= Length())
    {
        return -1;
    }
    const char* startPos = strstr(m_data + _startIndex, _str.m_data); //cstring strstr() to find first occurence
    if (startPos != nullptr)
    {
        return startPos - m_data;
    }
    else {
        return -1;
    }
}

/// <summary>
/// Replaces all occurrences of findString with replaceString this code is copied from STACKOVERFLOW
/// </summary>
/// <param name="_find"></param>
/// <param name="_replace"></param>
/// <returns></returns>
String& String::Replace(const String& _find, const String& _replace) {
    size_t startPos = 0;
    while ((startPos = Find(startPos, _find)) != -1) {
        // Create a new string to hold the replaced content
        string replacedContent = string(m_data, m_data + startPos) + _replace.CStr() +
            string(m_data + startPos + _find.Length());

        // Allocate memory for the new string data
        char* newData = new char[replacedContent.length() + 1]; // +1 for null terminator

        // Copy the replaced content to the new buffer
        strcpy(newData, replacedContent.c_str());

        // Deallocate the old string data
        delete[] m_data;

        // Update m_data to point to the new buffer
        m_data = newData;

        startPos += _replace.Length(); // Move the start position past the replaced substring
    }
    return *this;
}


/// <summary>
/// Wait for input in the console window and store the result
/// </summary>
/// <returns></returns>
String& String::ReadFromConsole() {
    // Assume maximum input size is 1024 characters
    const size_t maxInputSize = 1024;
    char input[maxInputSize];
    cin.getline(input, maxInputSize);
    *this = input; // Assign the input to the string
    return *this;
}

/// <summary>
/// Write the string to the console window.
/// </summary>
/// <returns></returns>
String& String::WriteToConsole() {
    cout << m_data;
    return *this;
}

/// <summary>
/// Returns true if lhs == rhs.
/// </summary>
/// <param name="_other"></param>
/// <returns></returns>
bool String::operator==(const String& _other) {
    return strcmp(m_data, _other.m_data) == 0;
}

/// <summary>
/// returns true if lhs is not equal to rhs.
/// </summary>
/// <param name="_other"></param>
/// <returns></returns>
bool String::operator!=(const String& _other) {
    return !(*this == _other);
}

/// <summary>
/// Replaces the characters in lhs with the characters in rhs.
/// </summary>
/// <param name="_str"></param>
/// <returns></returns>
String& String::operator=(const String& _str) {
    if (this != &_str) { // Check for self-assignment
        delete[] m_data; // Deallocate old data
        m_data = new char[_str.Length() + 1]; // Allocate new memory
        strcpy(m_data, _str.m_data); // Copy data
    }
    return *this;
}


/// <summary>
/// Subscript operator returns character located at position n.
/// </summary>
/// <param name="_index"></param>
/// <returns></returns>
char& String::operator[](size_t _index) {
    return m_data[_index];
}

/// <summary>
/// Returns true if this string comes before rhs in the alphabet (const version)
/// </summary>
/// <param name="_index"></param>
/// <returns></returns>
const char& String::operator[](size_t _index) const {
    return m_data[_index];
}

bool String::operator<(const String& _other) {
    return strcmp(m_data, _other.m_data) < 0;
}

String String::operator+=(const String& _other) {
    // Calculate the new length of the string after appending
    size_t newLength = Length() + _other.Length();

    // Allocate memory for the new string data
    char* newData = new char[newLength + 1]; // +1 for null terminator

    // Copy the current string data to the new buffer
    strcpy(newData, m_data);

    // Append the string data from rhs to the new buffer
    strcat(newData, _other.m_data);

    // Deallocate the old string data
    delete[] m_data;

    // Update m_data to point to the new buffer
    m_data = newData;

    return *this;
}
