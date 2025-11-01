#include "splashkit.h"
#include "utilities.h"


enum role_level
{
    NO_ACCESS,
    USER,
    ADMIN,
    SUPER_USER
};

struct user_data
{
    string username;
    string password;
    role_level role;
};


role_level read_role()
{
    int role_input = read_integer_range(" Enter role level (0 for NONE, 1 for USER, 2 for ADMIN): ", 0, 2);
    switch(role_input)
    {
        case 0:
        return NO_ACCESS;
        case 1:
        return USER;
        case 2:
        return ADMIN;
        default:
        write_line("Invalid role level. Setting role to NONE.");
        return NO_ACCESS;
    }
}

string to_string(role_level role)
{
    switch(role)
    {
        case NO_ACCESS:
        return "None";
        case USER:
        return "User";
        case ADMIN:
        return "Admin";
        default:
        return "Unknown";
    }
}

void print_user(user_data user)
{
    write_line(" User details: ");
    write_line(" Username: " + user.username);
    write_line(" Role: " + to_string(user.role));
}

//TODO: 機能追加
void update_user(user_data &user)
{
    write_line(" Update user details: ");
    user.username = read_string(" Username: ");
    user.password = read_string(" Password: ");
    user.role = read_role();
}


int main()
{
    user_data user = {
        "Konno Haruto",
        "password",
        ADMIN,
    };
    print_user(user);
    update_user(user);
    print_user(user);
    return 0;
}