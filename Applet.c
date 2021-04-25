#include <Muzzle.h>
#include "drawing/top.h"
#include "drawing/tiles.h"
#include "drawing/dragon.h"

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 900
#define MAX_INPUT_CHARS 10
#define PLAYER_WALK_SPEED 3
#define MAX_DRAGONS 5


void OnAppletUpdate()
{
    Sprite2D player = (Sprite2D)
    {
        LoadTexture("sprites/player.png"),
        (Vector2) 
        {
            SCREEN_WIDTH/2,
            0
        },
        WHITE
    };

    Music music = LoadMusicStream("music.wav");
    Texture2D bkg = LoadTexture("sprites/backgound.png");
    Texture2D dragon = LoadTexture("sprites/dragon.png");
    Texture2D red_bubble = LoadTexture("sprites/red_bubble.png");
    Texture2D dragon_fire = LoadTexture("sprites/dragon_fire.png");
    Texture2D tile_ground = LoadTexture("sprites/tile_ground.png");
    Texture2D rock = LoadTexture("sprites/rock");

    Vector2 dragons[MAX_DRAGONS-1];
    int dragons_on_screen = NONE;

    int level = 0;


    music.looping = true;

    PlayMusicStream(music);

    while (IsAppletAlive())
    {
        UpdateMusicStream(music);
        SetMusicVolume(music, 0.7f);
        if (IsKeyDown(KEY_S)) player.position.y += PLAYER_WALK_SPEED;
        else if (IsKeyDown(KEY_W)) player.position.y -= PLAYER_WALK_SPEED;
        else if (IsKeyDown(KEY_A)) player.position.x -= PLAYER_WALK_SPEED;
        else if (IsKeyDown(KEY_D)) player.position.x += PLAYER_WALK_SPEED;
        // -3
        // 850
        // 0
        if (player.position.y < 0) 
        {
            player.position.y  += PLAYER_WALK_SPEED;
            for (int i = 0; i <= dragons_on_screen; i++)
            {
                dragons[i].y += PLAYER_WALK_SPEED;
            }

            if (level > 0) level -= 1;
        }
        if (player.position.y > SCREEN_HEIGHT-58) 
        {
            level += 1;
            player.position.y -= PLAYER_WALK_SPEED;
            // make sure its safe to append new dragon
            if (dragons_on_screen + 1 < MAX_DRAGONS)
            {
                // now its safe to append new dragon 
                dragons_on_screen += 1;
                dragons[dragons_on_screen] = new_dragon(player.position.y);
            }
            //else if (dragons_on_screen + 1 > MAX_DRAGONS)
            //{
            //    for (int i = 0; i < count; i++)
            //    {
            //        /* code */
            //    }
            //    
            //}
            for (int i = 0; i <= dragons_on_screen; i++)
            {
                dragons[i].y -= PLAYER_WALK_SPEED;
                if (CheckCollisionPointCircle(dragons[i+1], dragons[i], 20.f)) dragons[i].x += 20;
                if (CheckCollisionPointCircle(dragons[i-1], dragons[i], 20.f)) dragons[i].x -= 20;
                if (CheckCollisionPointRec(dragons[i], (Rectangle)
                {
                    player.position.x,
                    player.position.y,
                    48, 48
                })) dragons[i].y = -503945;
            }
            
            

        }

        if (player.position.x < -3) player.position.x += PLAYER_WALK_SPEED;
        if (player.position.x > 675) player.position.x -= PLAYER_WALK_SPEED;
        BeginDrawing();
            ClearBackground(BLACK);
            RenderTiles(tile_ground);
            RenderTop(bkg, level);
            
            //DrawRectangle(player.position.x-2, player.position.y-5000+48, 50,5000, BLACK);
            DrawSprite2D(player);
            draw_dragon(dragons, dragons_on_screen, dragon);
            DrawText(TextFormat("%f, %f\nLevel:%i", player.position.x, player.position.y, level), 0, 0, 20, WHITE);
            DrawText(TextFormat("%2i FPS", GetFPS()), 640, 0, 20, WHITE);
        EndDrawing();
    }
}


// Initalize
int main(void)
{
    Applet ldjam = InitalizeApplet(720, 900, 60, "Dig Dug: Infinite");
    InitAudioDevice();
    initalize_srand();
    StartApplet(&ldjam);
    

    QuitMuzzle();
    return 0;
}
