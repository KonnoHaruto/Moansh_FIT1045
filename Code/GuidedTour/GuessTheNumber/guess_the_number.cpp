#include "splashkit.h"
#include "utilities.h"

using std::stoi;
using std::to_string;


int read_integer_range(string prompt, int low, int high)
{
    int input = read_integer(prompt);
    if (input < low || input > high)
    {
        write_line("Please enter a number between " + to_string(low) + "" + to_string(high));
        int input = read_integer(prompt);
    }
    return input;
}

bool perform_guess(int guess_number, int target)
{
    int guess;

    guess = read_integer("Guess" + to_string(guess_number) + " : ");
    if (target < guess)
    {
        write_line("The number is less than " + to_string(guess));
    }
    else if (target > guess)
    {
        write_line("The number is larger than " + to_string(guess));
    }
    else 
    {
        write_line("Well done... The number was " + to_string(target));
    }

    return guess == target;
}

bool start_play_game()
{
    const int MAX_GUESSES = 7;
    const int MAX_NUMBER = 100;

    int my_number, guess_number;
    bool got_it = false;

    my_number = rnd(100);
    guess_number = 0;

    write_line("I am thinking of a number between 0 and " + to_string(MAX_NUMBER));
    do 
    {
        guess_number++;
        got_it = perform_guess(guess_number, my_number);
    }
    while ( !got_it && guess_number < MAX_GUESSES );

    if (!got_it)
    {
        write_line("You ran out of guesses.... The number was " + to_string(my_number));
    }

    return got_it;
}

void print_line(int length)
{
    int i;
    i = 0;

    while(i < length)
    {
        write_line("-");
        i++;
    }

    write_line();
}


int main()
{
    string again;

    do 
    {
        start_play_game();
        write_line();

        print_line(50);
        again = read_string("Play again? [Y or n]: ");
    } while (again != "n" && again != "N");

    write_line("\n Bye - enjoy the rest of your day!");
    return 0;
}