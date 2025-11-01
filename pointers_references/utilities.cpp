#include "utilities.h"
#include "splashkit.h"

using std::to_string;

string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string line = read_string(prompt);
    while (!is_integer(line))
    {
    write_line("Please enter a whole number.");
    line = read_string(prompt);
    }
    return stoi(line);
}

int read_integer_range(string prompt, int low, int high)
{
    int line = read_integer(prompt);
    while(line < low || line > high)
    {
        write_line("Please enter value between " + to_string(low) + "and" + to_string(high));
        line = read_integer(prompt);
    }
    return line;
}

// このcppファイルもコンパイルすることで、このutilityを使用することができる。
// main.cppがあるとすれば以下のコマンドで実行可能
// clang++ main.cpp utilities.cpp -l Splashkit -o main