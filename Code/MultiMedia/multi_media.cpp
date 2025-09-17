#include "splashkit.h"

const int MOVE_SPEED = 3;

int main()
{
    open_window("Movement", 800, 600);

    double x = 400;
    color clr = color_black();

    while ( !quit_requested())
    {
        process_events();

        if (key_down(RIGHT_KEY))
        {
            x += MOVE_SPEED;
        }

        if (key_down(LEFT_KEY))
        {
            x -= MOVE_SPEED;
        }

        if (key_typed(SPACE_KEY))
        {
            clr = random_color();
        }

        clear_screen(color_white());
        fill_circle(clr, x, 300, 50);
        refresh_screen(60);
    }
}