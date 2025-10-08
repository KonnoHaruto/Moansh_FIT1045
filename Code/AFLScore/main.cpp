#include "splashkit.h"

using std::string;
using std::to_string;
using std::stoi;

string team1_name;
string team2_name;
int team1_goals;
int team1_behinds;
int team2_goals;
int team2_behinds;

string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string line = read_string(prompt);
    while ( !is_integer(line) )
    {
        write("Please enter a whole number \n");
        line = read_string(prompt);
    }

    return stoi(line);
}

int read_integer_range(string prompt, int low, int high)
{
    int input = read_integer(prompt);
    while ( input < low || input > high )
    {
        write_line("Please enter a number between " + to_string(low) + " and " + to_string(high));
        input = read_integer(prompt);
    }

    return input;
}

string read_yn(string prompt)
{
    string line = read_string(prompt);
    while ( line != "y" && line != "n" && line != "Y" && line != "N" )
    {
        write_line("Please enter y or n \n");
        line = read_string(prompt);
    }

    return line;
}

int calculate_result(int goals, int behinds)
{
    const int POINTS = 6;
    int score;

    score = goals * POINTS + behinds;
    return score;
}

int calculate_winner()
{
    int score1 = calculate_result(team1_goals, team1_behinds);
    int score2 = calculate_result(team2_goals, team2_behinds);

    write("Calculating details...\n");

    if (score1 > score2)
    {
        return 1;
    }
    else if (score2 > score1)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void output_team1()
{
    int score = calculate_result(team1_goals, team1_behinds);
    write_line(team1_name + ": " + to_string(team1_goals) + ", " + to_string(team1_behinds) + ", " + to_string(score));
}

void output_team2()
{
    int score = calculate_result(team2_goals, team2_behinds);
    write_line(team2_name + ": " + to_string(team2_goals) + ", " + to_string(team2_behinds) + ", " + to_string(score));
}

void print_details()
{
    int result = calculate_winner();

    if (result == 1)
    {
        write_line("The " + team1_name + " are winning");
    }
    else if (result == 2)
    {
        write_line("The " + team2_name + " are winning");
    }
    else
    {
        write_line("It is currently a draw!");
    }

    write_line();

    output_team1();
    output_team2();
}

void start_program()
{
    write("Enter team 1 details: \n");
    team1_name = read_string("name: ");
    team1_goals = read_integer("goals: ");
    team1_behinds = read_integer("behinds: ");

    write_line();

    write("Enter team 2 details: \n");
    team2_name = read_string("name: ");
    team2_goals = read_integer("goals: ");
    team2_behinds = read_integer("behinds: ");

    write_line();

    print_details();
}

void show_menu()
{
    bool running = true;

    do
    {
        write_line();
        write_line("Menu:");
        write_line("1: Update " + team1_name + " goals");
        write_line("2: Update " + team1_name + " behinds");
        write_line("3: Update " + team2_name + " goals");
        write_line("4: Update " + team2_name + " behinds");
        write_line("5: Print details");
        write_line("6: Quit");

        int option = read_integer_range("Option: ", 1, 6);
        bool show_summary = false;

        switch (option)
        {
            case 1:
                team1_goals = read_integer("goals: ");
                break;
            case 2:
                team1_behinds = read_integer("behinds: ");
                break;
            case 3:
                team2_goals = read_integer("goals: ");
                break;
            case 4:
                team2_behinds = read_integer("behinds: ");
                break;
            case 5:
                show_summary = true;
                break;
            case 6:
            {
                string quit_choice = read_yn("Are you sure you want to quit? [Y/n]: ");
                if (quit_choice == "y" || quit_choice == "Y")
                {
                    running = false;
                }
                break;
            }
        }

        if (show_summary)
        {
            write_line();
            print_details();
        }
    }
    while (running);
    write_line();
    write_line("Bye!");
}

int main()
{
    write_line("Welcome to the AFL score calculator!");

    start_program();
    show_menu();

    return 0;
}
