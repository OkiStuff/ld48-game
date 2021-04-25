#include "dragon.h"

Vector2 new_dragon(int player_pos)
{
    return (Vector2)
    {
        .x = randomize(0,640),
        .y = randomize(player_pos-300, SCREEN_HEIGHT-58)
    };
}

void draw_dragon(Vector2 dragons[4], int current, Texture2D tex)
{
    if (current != NONE)
    {
        for (int index = 0; index < current; index++)
        {
            DrawTexture(tex, dragons[index].x, dragons[index].y, WHITE);
        }
    }
}