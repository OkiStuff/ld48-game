#include "top.h"

void RenderTop(Texture2D tex, int level)
{
    if (level == 0)
    {
        for (int i = 0; i < 900; i += 64)
        {
            DrawTexture(tex, i, 0, WHITE);
        }
    }
    
    
    
}