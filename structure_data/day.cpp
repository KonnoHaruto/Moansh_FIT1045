#include "splashkit.h"
#include "utilities.h"

using std::to_string;

enum day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

const int NUM_DAYS = (int)SUNDAY + 1;


string to_string(day d)
{
    switch(d)
    {
        case 0:
            return "Monday";
        case 1:
            return "Tuesday";
        case 2:
            return "Wednesday";
        case 3:
            return "Thursday";
        case 4:
            return "Friday";
        case 5:
            return "Saturday";
        case 6:
            return "Sunday";
        default:
            return "Invalid day";
    }
}

day read_day(string prompt)
{
    int day_number;
    write_line(prompt);

    for (int i = 0; i < NUM_DAYS; i++)
    {
        day current_day = (day)i;
        write_line(to_string(i) + ": " + to_string(current_day));
    }

    day_number = read_integer("Enter a day number (0 - 6): ");
    return (day)day_number;
}


int main()
{
    day today;

    today = read_day("What day is it today?");

    write_line("Today is " + to_string(today));

    return 0;
}