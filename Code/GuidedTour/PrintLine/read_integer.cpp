#include "splashkit.h";

using std::stoi;
using std::to_string;



int read_integer(string prompt, int low, int high)
{
    int input = read_integer(prompt);
    while (input < low || input > high)
    {
        write_line("Please enter a value between " + to_string(low) + "" + to_string(high));
        input = read_integer(prompt);
    }
    return input;
}