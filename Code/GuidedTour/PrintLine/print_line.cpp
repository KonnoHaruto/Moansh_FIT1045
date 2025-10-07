#include "splashkit.h"

/**
 * output "-" for input times.
 * 
 * @param length the length of "-"
 */
void print_line(int length)
{
    int i = 0;
    while(i < length)
    {
        write("-");
        i++;
    }
}

int main()
{
    string input;
    int test_length;

    print_line(20);
    write_line("| Line print test  |");
    print_line(20);

    write("Enter a length for a test line: ");
    input = read_line();
    test_length = stoi(input);

    print_line(test_length);

    return 0;
}