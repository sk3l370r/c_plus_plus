#include "splashkit.h"

int main()
{
    double x, y, radius;
    color circle_color = COLOR_GREEN;
    const int min_radius = 10; 
    const int max_radius = 200;

    open_window("Shape Shifter by Jill", 800, 600);

    x = screen_width() / 2;
    y = screen_height() / 2;
    radius = 100;

    while( not quit_requested() )
    {
        process_events();

        //changes circle colour on C key press
        if (key_typed( C_KEY ) )
        {
            circle_color = random_color();
        }

        //moves circle left or right by 1 pixel 
        if ( key_down(RIGHT_KEY) )
        {
            x +=1;
        }
        if ( key_down(LEFT_KEY) )
        {
            x -=1;
        }

        //makes sure circle stays on screen on x-axis
        if ( x + radius > screen_width() )
        {
            x = screen_width() - radius;
        }
        if ( x - radius < 0 )
        {
            x = radius;
        }

        //moves circle up or down by 1 pixel
        if ( key_down(UP_KEY) )
        {
            y -=1;
        }
        if ( key_down(DOWN_KEY) )
        {
            y +=1;
        }

        //makes sure circle stays on screen on y-axis
        if ( y + radius > screen_height() )
        {
            y = screen_height() - radius;
        }
        if ( y - radius < 0 )
        {
            y = radius;
        }

        //changes the radius of the circle by 1 pixel
        if ( key_down(MINUS_KEY) )
        {
            radius -=1;
        }
        if ( key_down(EQUALS_KEY) )
        {
            radius +=1;
        }

        //makes sure the circle stays larger than min and smaller than max radius
        if ( radius <= min_radius )
        {
            radius = min_radius;
        }
        if ( radius >= max_radius )
        {
            radius = max_radius;
        }

        //resets x and y location to the middle of the screen. 
        //instructions did not say to reset colour or radius
        if ( key_down(SPACE_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2; 
        }

        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x, y, radius);
        refresh_screen(60);
    }
    
    return 0;
}