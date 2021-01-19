/*#include <ctime>
#include <iostream>

void date() {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout <<"\nriui> date is"<< (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
}*/

//You can try the following cross-platform code to get current date/time:

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "\nriui> date is: %Y-%m-%d\nriui> time is: %X", &tstruct);

    return buf;
}

void date() {
    std::cout << "\nriui> date and time are  " << currentDateTime() <<"\n\n";
    //getchar();  // wait for keyboard input
}
