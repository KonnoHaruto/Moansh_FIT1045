#include "splashkit.h"
#include "utilities.h"

using std::to_string;

const int PLAYER_SPEED = 300;

struct player_data
{
    string name;
    int x;
    int y;
};

void update_player(player_data &player)
{
    if (key_down(LEFT_KEY))
    {
        player.x -= PLAYER_SPEED;
    }
    else if (key_down(RIGHT_KEY))
    {
        player.x += PLAYER_SPEED;
    }
}

int main()
{
    string name = "Test name";
    string &ref = name;
    string *ptr = &name;

    string other = "other";

    string another = "five";

    write_line(name);
    write_line(ref);
    write_line(*ptr); //これもoutputがTest nameなのが意外だった。addressだけが出力されると思っていた。

    ref = "test update";
    write_line(name);

    *ptr = "ptr updated";
    write_line(name);

    ptr = &other;
    write_line(*ptr);

    ptr = &another;
    write_line(*ptr);

    return 0;
}