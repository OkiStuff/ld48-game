#include "tiles.h"
void RenderTiles(Texture2D tex)
{
    for (int x = 0; x < 900; x += 64)
    {
        for (int y = 0; y < 900; y += 64)
        {
            DrawTexture(tex, x, y, WHITE);
        }
        
    }
    
}