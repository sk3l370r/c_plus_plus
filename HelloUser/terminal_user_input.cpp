#include "splashkit.h"
using namespace std;

//Return a string of the input line from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//This reads in a string from a user and returns it as an integer
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}