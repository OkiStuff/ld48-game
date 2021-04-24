#include "terminal.h"
#include <stdlib.h>
#include <ctype.h>
Terminal InitalizeTerminal()
{
    return (Terminal)
    {
        .input="\0",
        .letterCount=0,
        .output="\0"
    };
}

Commands ParseInput(char input[15+1])
{
    if (tolower(input) == (PREFIX "go down")) return GO_DOWN;
    else if (tolower(input) == (PREFIX "go up")) return GO_UP;
    else if (tolower(input) == (PREFIX "go left")) return GO_LEFT;
    else if (tolower(input) == (PREFIX "go right")) return GO_RIGHT;
    else if (tolower(input) == (PREFIX "attack up")) return ATTACK_UP;
    else if (tolower(input) == (PREFIX "attack down")) return ATTACK_DOWN;
    else if (tolower(input) == (PREFIX "attack left")) return ATTACK_LEFT;
    else if (tolower(input) == (PREFIX "attack right")) return ATTACK_RIGHT;
    else if (tolower(input) == (PREFIX "scan")) return SCAN;
    else if (tolower(input) == (PREFIX "help")) return HELP;

    else return ERR;
}

const char * GetResponse(Commands input)
{
    // TODO: ADD CODE TO EXECUTE COMMANDS
    switch (input)
    {
    case GO_DOWN:
        return "Going Down...";
        break;

    case GO_UP:
        return "Going Up...";
        break;

    case GO_RIGHT:
        return "Going Right...";
        break;

    case GO_LEFT:
        return "Going Left...";
        break;

    case ATTACK_UP:
        return execute_attack_up();
        break;

    case ATTACK_DOWN:
        return execute_attack_down();
        break;

    case ATTACK_LEFT:
        return execute_attack_left();
        break;

    case ATTACK_RIGHT:
        return execute_attack_right();
        break;

    case SCAN:
        return execute_scan();
        break;

    
    case HELP:
        return "Commands:\n?go [direction]\n?attack [direction]\n ?scan";
        break;

    default:
        return "Unknown Command";
        break;
    }
}

Terminal UpdateTerminal(Terminal t)
{
    int key = GetCharPressed();
    char * response;
    while (key > 0)
    {
    // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (t.letterCount < 15))
        {
            t.input[t.letterCount] = (char)key;
            t.letterCount++;
        }
        key = GetCharPressed();  // Check next character in the queue
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        t.output = GetResponse(ParseInput(t.input));
    }

}