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

#endif