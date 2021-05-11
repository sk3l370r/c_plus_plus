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

    while (not is_integer(line))
    {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }
    return convert_to_integer(line);
}

//This reads in a string from a user and returns it as a double
double read_double(string prompt)
{
    string line;
    line = read_string(prompt);

    while (not is_double(line))
    {
        write_line("Please enter a number.");
        line = read_string(prompt);
    }
    return convert_to_double(line);
}

int read_integer(string prompt, int min, int max)
{
    int result;

    result = read_integer(prompt);

    while (result < min or result > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }

    return result; 
}

double read_double_range(string prompt, double min, double max)
{
    double result;

    result = read_double(prompt);

    while (result < min or result > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_double(prompt);
    }

    return result;
}

bool read_boolean(string prompt)
{
    string line;
    bool result;

    line = read_string(prompt);
    line = trim(to_lowercase(line));

    while ( line != "yes" && line != "y" && line != "no" && line != "n" )
    {
        write_line("Please answer either yes or no.");
        line = read_string(prompt);
        line = trim(to_lowercase(line));
    }

    if (line == "yes" or line == "y")
    {
        result = true;
    }

    if (line == "no" or line == "n")
    {
        result = false;
    }
    
    return result;
}