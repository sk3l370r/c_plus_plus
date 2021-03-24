#include "splashkit.h"
#include "terminal_user_input.h"
#include <string>
using namespace std;

#define STROUHAL 0.33

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

//You can have comments wherever you like if it helps explain your code.

int main()
{
    //Declare variables 
    string name;
    int age;
    string bird;
    int freq, amp1;

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
    freq = read_integer("Enter the frequency of your bird: ");
    amp1 = read_integer("Enter the amplitude of your bird: ");

    //output air speed
    write_line("");
    output_air_speed(bird, freq, amp1);

    //SIT102 comment out when functional
    //output_air_speed("African Swallow", 15, 21);
    //output_air_speed("European Swallow", 14, 21);
    
    write_line("* End of Program.*");

    return 0;
}