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
 * @brief Prompts the user for input and reads the text that the user enters at the terminal
 * This will read in a line of text and return this as a double
 * 
 * @param prompt    The message displayed to the user
 * @return double   The double the user enters
 */
double read_double(string prompt);

/**
 * @brief prompts the user for input and tests that it's between and minimum
 * and maximum value. 
 * This will read in a line of text and return it as an integer.
 * 
 * @param prompt    The message displayed to the user
 * @param min       The minimum value
 * @param max       The maximum value
 * @return int      The integer the user enters
 */
int read_integer(string prompt, int min, int max);

/**
 * @brief Prompts the user for input of type double and tests that it is between
 * a minimum and maximum value. 
 * This will read in a line of text, convert it to double, and check min/max. 
 * 
 * @param prompt    The message displayed to the user
 * @param min       The minimum value
 * @param max       The maximum value
 * @return double   The double the user enters
 */
double read_double_range(string prompt, double min, double max);

/**
 * @brief takes user input, converts to lowercase, trims start and end spaces
 * checks if input is valid, then returns true or false values accordingly
 * 
 * @param prompt    The message displayed to the user
 * @return true     If the condition is true
 * @return false    If the condition is false
 */
bool read_boolean(string prompt);

#endif