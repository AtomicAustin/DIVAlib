/**************************************************
***           D.I.V.A.LIB Command - Beta        ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
***                                             ***
**************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include "Types.h"
#include "ColorMode.h"

class Command
{
    public:
        Command();
        Command(State);
        void changeState(State);
		int sendCommand(std::string);
		int getCommandCode();
        void displayCommands();

    private:
		int checkCommand(std::string, int, std::string[]);

	private:
		int cmd_code;

        static const int m_CMD_SIZE = 3;
        static const int s_CMD_SIZE = 5;
        static const int f_CMD_SIZE = 4;

        std::string m_cmd[m_CMD_SIZE] =
        {"/quit", "/about", "/command"};

        std::string s_cmd[s_CMD_SIZE] =
        {"/quit", "/stop", "/back", "/about", "/command"};

        std::string f_cmd[f_CMD_SIZE] =
        {"/quit", "/about", "/command", "/manual" };

        State cur;
};

#endif // COMMAND_H
