#include "splashkit.h"

using std::to_string;


/**
 * Double passed in positive value
 * 
 * @param value a positive number
 * @return int double value
 * @exception string if value is less than 0
 */
int double_positive(int value)
{
    if (value < 0)
    {
        string message = "value must be positive";
        throw message;
    }

    return value * 2;
}

int main()
{
    int check;

    try 
    {
        check = double_positive(5);
        write_line("Check is " + to_string(check));

        check = double_positive(-1);
        write_line("Check is " + to_string(check));
    }
    catch(string e)
    {
        write_line("Some other exception occurred");
    }

    check = double_positive(-5);

    return 0;
}