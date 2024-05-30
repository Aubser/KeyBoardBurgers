#include "Invoker.h"
#include <stack>
using namespace std;

// ----------------------------------------------------------------
// Invoker Constructor
// ----------------------------------------------------------------
Invoker::Invoker()
{
	done = stack<Command*>();
	undone = stack<Command*>();
}

// ----------------------------------------------------------------
// Executes a command and pushes it to the list
// ----------------------------------------------------------------
void Invoker::doCommand(Command* command)
{
	command->execute();
	done.push(command);
}

// ----------------------------------------------------------------
// Undoes the last command done in the list
// ----------------------------------------------------------------
void Invoker::undo()
{
	if (!done.empty())
	{
		Command* lastCommand = done.top();
		undone.push(lastCommand);
		lastCommand->unexecute();
		done.pop();
	}
	
}

// ----------------------------------------------------------------
// Redoes the last command done in the list
// ----------------------------------------------------------------
void Invoker::redo()
{
	if (!undone.empty())
	{ 
		Command* nextCommand = undone.top();
		done.push(nextCommand);
		nextCommand->execute();
		undone.pop();
	}
	
}