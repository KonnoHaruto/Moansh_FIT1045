#include "splashkit.h"

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

    for (row = 0; row < GENRE_LENGTH; row++)
    {
        write_line(to_string((genre_data)row));
    }
    return 0;
}