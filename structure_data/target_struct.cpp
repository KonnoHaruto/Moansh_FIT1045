#include "splashkit.h"

using std::to_string;

const double MAX_TARGET_RADIUS = 200;
const double MIN_TARGET_RADIUS = 10;

struct target_data
{
    double x;
    double y;
    double radius;
};

/**
 * Represents the data of the reaction game, including the current target and the number of hits.
 */
struct reaction_game_data
{
    target_data target;
    int hits;
};

void draw_target(target_data target)
{
    fill_circle(COLOR_BLACK, target.x, target.y, target.radius);
}

target_data new_target(double x, double y, double radius)
{
    target_data target;
    target.x = x;
    target.y = y;
    target.radius = radius;

    return target;
}

target_data random_target()
{
    int radius = rnd(MAX_TARGET_RADIUS - MIN_TARGET_RADIUS);

    return new_target(
        rnd(radius, screen_width() - radius),
        rnd(radius, screen_height() - radius),
        radius
    );
}

bool mouse_over_target(target_data target)
{
    return point_in_circle(mouse_x(), mouse_y(), target.x, target.y, target.radius);
}

/**
 * @brief Creates a new reaction game with a random target and zero
 * @return The newly created reaction game
 */
reaction_game_data new_reaction_game()
{
    reaction_game_data result;
    result.target = random_target();
    result.hits = 0;

    return result;
}

int calculate_time(reaction_game_data game)
{
    int hits = game.hits;
    int time = current_ticks();

    return time / hits;
} 

void draw_game(reaction_game_data game)
{
    int time = calculate_time(game);
    clear_screen(COLOR_WHITE);

    draw_text("Hits: " + to_string(game.hits), COLOR_BLACK, 5, 5);
    draw_text("Average Time/Hits: " + to_string(time), COLOR_BLACK, 5, 20);


    draw_target(game.target);
    refresh_screen();
}

int main()
{
    open_window("Reaction Timer", 800, 600);

    // target_data target;
    // target.x = 600;
    // target.y = 300;
    // target.radius = 100;

    // target_data target = random_target();
    reaction_game_data game = new_reaction_game();

    while (!quit_requested())
    {
        process_events();

        if (mouse_clicked(LEFT_BUTTON) && mouse_over_target(game.target))
        {
            game.target = random_target();
            game.hits++;
        }

        draw_game(game);

    }


    return 0;
}