#include "TicketSystemFunctions.h"

int main(){

    Line normalLine;
    Line priorityLine;

    InitializeLine(&normalLine);
    InitializeLine(&priorityLine);
    Menu(normalLine, priorityLine);

    return 1;
}