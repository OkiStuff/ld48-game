#pragma once
#define PREFIX "?"
#include <Muzzle.h>
#include <stdbool.h>

typedef enum Commands
{
    GO_UP = 0,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    ERR,
    ATTACK_UP,
    ATTACK_DOWN,
    ATTACK_LEFT,
    ATTACK_RIGHT,
    SCAN,
    HELP,
} Commands;

typedef struct Terminal
{
    char input[15+1];
    char *output;
    int letterCount;
} Terminal;

// Initalize Terminal
Terminal InitalizeTerminal();
// Update Terminal
Terminal UpdateTerminal(Terminal t);
// Parse Input from Terminal
Commands ParseInput(char input[15+1]);
// Get Response
const char * GetResponse(Commands input);