#include "splashkit.h"
#include "utilities.h"

using std::to_string;

enum genre_data
{
    ROMANCE,
    HORROR,
    SUSPENSE,
};

const int GENRE_LENGTH = SUSPENSE + 1;

int main()
{
    int row;
    bool isRead;

    for (row = 0; row < GENRE_LENGTH; row++)
    {
        write_line(to_string((genre_data)row));
    }
    return 0;
}

struct unit_result
{
    string unit_code;
    string unit_name;
    int score;
};

unit_result read_unit_result()
{
    unit_result result;

    result.unit_code = read_string("Enter unit code: ");
    result.unit_name = read_string("Enter unit name: ");
    result.score = read_integer("Enter your score: ");

    return result;
}

void write_unit_result(unit_result result)
{
    write(result.unit_code + ", " + result.unit_name + ", " + to_string(result.score));

    if(result.score >= 80)
    {
        write_line("Congratulations!");
    }
    else
    {
        write_line();
    }
}

