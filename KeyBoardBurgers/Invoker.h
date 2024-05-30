#pragma once
#include <stack>
#include "Command.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          holding all done/undone commands in the command pattern
//---------------------------------------------------------------------
class Invoker
{
private:
    std::stack<Command*> done;
    std::stack<Command*> undone;
public:
    Invoker();
    void doCommand(Command* command);
    void undo();
    void redo();
    bool isDoneEmpty()
    {
        return (done.size() == 0);
    }
    bool isUndoneEmpty()
    {
        return undone.empty();
    }
};