#include "splashkit.h"

using std::stod;
using std::string;
using std::to_string;



int main()
{
    string line;
    double total = 0;
    int count = 0;
    double value;
    double minValue = 0;
    double maxValue = 0;
    string again;

    write("Welcome to the simple stats calculator:");
    write_line();

    while (true)
    {
        write("Enter value: ");
        line = read_line();
        value = stod(line);
        count++;
        total += value;
        if (count == 1)
        {
            minValue = value;
            maxValue = value;
        }
        if (count != 0 && minValue > value)
        {
            minValue = value;
        }
        if (count != 0 && maxValue < value)
        {
            maxValue = value;
        }
    
        double average = total / count;
        write_line("Count: " + to_string(count));
        write_line("Total: " + to_string(total));
        write_line("Min: " + to_string(minValue));
        write_line("Max: " + to_string(maxValue));
        write_line("Average: " + to_string(average));
        write_line();
    
        write("Add another value: [y/n] ");
        again = read_line();
        if (again != "y")
        {
            write_line("I hope you got the information you are after!");
            break;
        }
    }
return 0;
}
