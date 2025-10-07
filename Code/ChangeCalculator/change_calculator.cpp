#include "splashkit.h"

using std::stoi; 
using std::to_string;

int main () 
{ 
    const int NUM_COIN_TYPES = 6;

    const int TWO_DOLLARS = 200; 
    const int ONE_DOLLAR = 100; 
    const int FIFTY_CENTS = 50; 
    const int TWENTY_CENTS = 20; 
    const int TEN_CENTS = 10; 
    const int FIVE_CENTS = 5;

    string again = ""; // used to check if the user want to run again 
    string line; 
    int to_give; 
    int coin_value; 
    string coin_text;

    do 
    { 
        write("Cost of item in cents: "); 
        line = read_line();
        while (!is_integer(line))
        {
            write_line("Please enter a whole number."); 
            write("Cost of item in cents: "); 
            line = read_line(); 
        }

    }
