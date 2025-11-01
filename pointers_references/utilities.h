#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

/**
 * Read a string from the user
 *
 * @param prompt the message to show the user
 * @returns the string entered
 */
string read_string(string prompt);

/**
 * Read an integer from the user
 *
 * @param prompt the message to show the user
 * @returns the integer entered
 */
int read_integer(string prompt);

/**
 * 
 * @param prompt the message to show the user
 * @param low upper range for the input
 * @param high lower range for the input
 * @returns the integer entered under the condition (range)
 */
int read_integer_range(string prompt, int low, int high);

#endif