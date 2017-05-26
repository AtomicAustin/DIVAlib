/**************************************************
***           D.I.V.A.LIB Command - Beta        ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
*** 5/2/2017 - Fixed formatting/colors          ***
*** 5/08/2017 - added < command		            ***
*** 5/08/2017 added filepath                    ***
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
		void storeFilePath(std::string);
		std::string getFilePath();
        void displayCommands();

    private:
		int checkCommand(std::string, int, std::string[]);

	private:
		int cmd_code;

        static const int m_CMD_SIZE = 4;
        static const int s_CMD_SIZE = 6;
        static const int f_CMD_SIZE = 5;

        std::string m_cmd[m_CMD_SIZE] =
        {"/quit", "/about", "/command", "/filepath"};

        std::string s_cmd[s_CMD_SIZE] =
        {"/quit", "/stop", "/back", "/about", "/command", "/filepath" };

        std::string f_cmd[f_CMD_SIZE] =
        {"/quit", "/about", "/command", "/manual", "/filepath" };

		std::string filepath;

        State cur;
};

#endif // COMMAND_H
