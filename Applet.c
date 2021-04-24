#include <Muzzle.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAX_INPUT_CHARS 10

void OnAppletUpdate()
{
    char name[10+1] ="\0";
    int letterCount = 0;

    while (IsAppletAlive())
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                letterCount++;
            }
            key = GetCharPressed();  // Check next character in the queue
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(name,25,10,40,WHITE);
            DrawText("> ", 6, 10, 40, WHITE);
        EndDrawing();
    }
}


// Initalize
int main(void)
{
    Applet ldjam = InitalizeApplet(1280, 720, 60, "Ludum Dare Submission");
    StartApplet(&ldjam);

    QuitMuzzle();
    return 0;
}