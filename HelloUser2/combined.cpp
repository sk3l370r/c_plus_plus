//Start terminal_user_input.h
#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

/**
 * @brief Prompts the user for input and reads the text that the user enters at the Terminal
 * This will read in a line of text and return this as a string.
 * 
 * @param prompt    The message displayed to the user
 * @return string   The text the user enters
 */
string read_string(string prompt);

/**
 * @brief Prompts the user for input and reads the text that the user enters at the Terminal
 * This will read in a line of text and return this as an integer
 * 
 * @param prompt    The message displayed to the user
 * @return int      The integer the user enters
 */
int read_integer(string prompt);


/**
 * @brief Prompts the user for input and reads the test that the user enters at the terminal
 * This will read in a line of text and return this as a double
 * 
 * @param prompt    The message displayed to the user
 * @return double   The double the user enters
 */
double read_double(string prompt);

#endif
//end terminal_user_input.h

//start terminal_user_input.cpp
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

//This reads in a string from a user and returns it as an integer
double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}
//end terminal_user_input.cpp

//start program.cpp
#include "splashkit.h"
#include "terminal_user_input.h"
#include <string>
using namespace std;

#define STROUHAL 0.33
#define PI 3.141

//Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed(int freq, int amp)
{
    double result;
    result = freq * amp * 0.01 / STROUHAL;
    return result;
}

//This takes the user input from main, and outputs the name and the airspeed 
//after first calling the "calculate air speed" procedure
void output_air_speed(string name, int freq, int amp)
{
    write(name + ": ");
    write_line(calculate_air_speed(freq, amp));
}

//Calculates circle area using global constant PI and returns the area result 
double calculate_area(double radius)
{
    double result;
    result = radius * radius * PI;
    return result;
}

void output_circle_area(double radius)
{
    write("The area of the circle is: ");
    write(calculate_area(radius));
    write_line(" cm squared");
}

//You can have comments wherever you like if it helps explain your code.

int main()
{
    //Declare variables 
    string name;
    int age;
    string bird;
    double freq, amp1, radius;

    //Get User Details
    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    //Output to terminal
    write_line("");
    write("Hello, ");
    write_line(name + "!");
    write("Age: ");
    write_line(age);

   //Get Bird Details
    write_line("");
    bird = read_string("Please name your bird: ");
    freq = read_double("Enter the frequency of your bird: ");
    amp1 = read_double("Enter the amplitude of your bird: ");

    //output air speed
    write_line("");
    output_air_speed(bird, freq, amp1);

    //Get cirlce radius
    write_line("");
    radius = read_double("Enter the radius of your circle in cm: ");

    //Output the circle area
    write_line("");
    output_circle_area(radius);

    //SIT102 comment out when functional
    //output_air_speed("African Swallow", 15, 21);
    //output_air_speed("European Swallow", 14, 21);
    
    write_line("* End of Program.*");

    return 0;
}

//end program.cpp 
