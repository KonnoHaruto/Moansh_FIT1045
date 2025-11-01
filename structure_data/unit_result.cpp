#include "utilities.h"
#include "splashkit.h"

using std::to_string;

struct unit_result
{
    string unit_code;
    string unit_name;
    int score;
};

unit_result read_unit_result(string prompt)
{
    unit_result result;
    write_line(prompt);

    result.unit_code = read_string("What is a unit code?: ");
    result.unit_name = read_string("What is a unit name?: ");
    result.score = read_integer("What is a score?: ");

    return result;
}

void write_unit_result(unit_result result)
{
    write_line("unit code: " + result.unit_code);
    write_line("unit name: " + result.unit_name);
    write_line("score: " + to_string(result.score));

    if (result.score > 80)
    {
        write_line("Congratulations!");
    }
}


int main()
{
    unit_result result;

    result = read_unit_result("Please enter a unit result");
    write_unit_result(result);

    return 0;
}