#include "String.h"
#include <iostream>
#include <fstream>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;



//function to allow operator overloading;
std::ostream& operator<<(std::ostream& os, const String& str) {
    // Assuming you have a method CStr() that returns a const char* to the internal string data
    os << str.CStr();
    return os;
}

// Function to get current date/time as a string, do not touch!
String GetCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    localtime_s(&tstruct, &now);
    // Format: YYYY-MM-DD.HH:mm:ss
    strftime(buf, sizeof(buf), "%d/%m/%Y Time: %X", &tstruct);

    return String(buf);
}

void GenerateTestResults(const String& fileName) {
    int totalTests = 0;//counter for tests taken
    int successfulTests = 0;//counter for successful tests
    String testString = "Test";
    String logContent;
    logContent.Append("Date: ");
    logContent.Append(GetCurrentDateTime());

    totalTests++;
    logContent.Append("\nTest 0: Length: ");
    if (testString.Length() == 4) {
        logContent.Append("Successful");
        successfulTests++;
    }
    else {
        logContent.Append("Failed");
    }

    totalTests++;
    logContent.Append("\nTest 1: CharacterAt: ");
    if (testString.CharacterAt(0) == 'T')
    {
        logContent.Append("Successful");
        successfulTests++;
    } 
    else { 
        logContent.Append("Failed"); 
    }

    totalTests++;
    logContent.Append("\nTest 2: EqualTo: ");
    if (testString.EqualTo("Test"))
    {
        logContent.Append("Successful");
        successfulTests++;
    }
    else {
        logContent.Append("Failed");
    }

    totalTests++;
    logContent.Append("\nTest 3: Append: ");
    logContent.Append("Successful");
    successfulTests++;
    
    totalTests++;
    logContent.Append("\nTest 4: Prepend: ");
    String testString2 = "1Test";
    testString.Prepend("1");

    if (testString.EqualTo(testString2))
    {
        logContent.Append("Successful");
        successfulTests++;
    }
    else {
        logContent.Append("Failed");
    }

    cout << logContent << endl;

    double successRate = (double)successfulTests / totalTests * 100;

    cout << "Success rate: " << successRate << "%" << endl;

    // Then, write the log content to a file
    std::ofstream writefile(fileName.CStr(), std::ios::app);
    if (writefile.is_open()) {
        writefile << logContent.CStr(); // Assuming CStr() converts String to const char*
        writefile << "\nSuccess rate: " << successRate << "%" << endl;
        writefile << "\n";
        writefile.close();
        std::cout << "Test results have been written to TestResults.log." << std::endl;
    }
    else {
        std::cout << "Failed to open the log file for writing." << std::endl;
    }
}

int main() {
    GenerateTestResults("testlog.txt");
}