#include "splashkit.h"
#include <format>

using std::stoi;
using std::to_string;
using std::format;

int main()
{
    string name, line;
    int age;
    double value;

    write("Enter your name: ");
    name = read_line();

    write_line("Hello " + name + "!");

    write("How old are you? Enter your age: ");

    line = read_line();
    while( ! is_integer(line) )
    {
        write_line("Sorry, I cannot convert that to a number");
        write("How old are you? Enter your age: ");
        line = read_line();
    }

    age = stoi(line);

    write_line("You are " + to_string(age) + "!");

    value = age * 1.333;

    string message = format("Adding a 1/3 of your age gives: {:.2}", value);
    write_line(message);

    return 0;
}