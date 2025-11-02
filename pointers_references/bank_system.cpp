#include "splashkit.h"
#include "utilities.h"

using std::to_string;

const double DAYS_IN_YEAR = 365;

enum actions
{
    PRINT,
    DEPOSIT,
    WITHDRAW,
    ADDINTERSET,
    QUIT,
};

struct user_data
{
    string username;
    double interest_percent;
    double account_balance;
};

double read_positive_integer(string prompt)
{
    double input = read_integer(prompt);
    while (input < 0)
    {
        write_line("Please enter a value larger than or equal to 0");
        input = read_integer(prompt);
    }
    return input;
}

void read_user_data(user_data &user)
{
    user.username = read_string("Enter account name: ");
    user.interest_percent = read_integer("Enter interest percent (+/-): ");
    user.account_balance = read_integer("Enter initial amount: ");
}

void print_user_data(const user_data &user)
{
    write_line("Account: " + user.username);
    write_line("Rate: " + to_string(user.interest_percent) + "%");
    write_line("Balance: " + to_string(user.account_balance));
}

actions read_action()
{
    write_line("Actions:");
    write_line("1: Print account details");
    write_line("2: Deposit");
    write_line("3: Withdraw");
    write_line("4: Add interest");
    write_line("5: Quit");
    int option = read_integer_range("Option: ", 1, 5);

    switch(option)
    {
        case 1:
        return PRINT;
        case 2:
        return DEPOSIT;
        case 3:
        return WITHDRAW;
        case 4:
        return ADDINTERSET;
        case 5:
        return QUIT;
        default:
        return QUIT;
    }
}

void read_deposit(user_data &user)
{
    user.account_balance += read_positive_integer("Amount deposited: ");
    write_line("Balance: " + to_string(user.account_balance));
}

void read_withdraw(user_data &user)
{
    user.account_balance -= read_positive_integer("Amount withdrawn: ");
    write_line("Balance: " + to_string(user.account_balance));
}

double calculate_rate(int days, double rate)
{
    return (rate / DAYS_IN_YEAR) * rate;
}

void add_interest(const user_data &user)
{
    int days = read_positive_integer("Interest for how many days: ");
    double rate_for_days = calculate_rate(days, user.interest_percent);
    double interest = rate_for_days * 100;

    write_line("Rate is" + to_string(user.interest_percent) + "% PA = " + to_string(rate_for_days));
    write_line("Interest = " + to_string(interest));
    write_line("Balance = " + to_string(user.account_balance + interest));
}

bool bank_system(user_data &user)
{
    actions action = read_action();

    switch(action)
    {
        case PRINT:
        print_user_data(user);
        return true;
        case DEPOSIT:
        read_deposit(user);
        return true;
        case WITHDRAW:
        read_withdraw(user);
        return true;
        case ADDINTERSET:
        add_interest(user);
        return true;
        case QUIT:
        return false;
        break;
        default:
        return true;
    }
}

int main()
{
    user_data user;
    bool running = true;

    write_line("Simple transaction record!");
    read_user_data(user);
    
    do
    {
        running = bank_system(user);
    } while (running == true);
    return 0;
}