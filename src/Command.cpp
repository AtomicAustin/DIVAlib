#include "Command.h"

Command::Command()
{
    //ctor
	cmd_code = 0;
    cur = MAIN;
}
Command::Command(State n)
{
	cmd_code = 0;
    cur = n;
}
void Command::changeState(State n)
{
    cur = n;
}
int Command::sendCommand(std::string str_cmd)
{
    switch(cur)
    {
        case MAIN:{ return checkCommand(str_cmd, m_CMD_SIZE, m_cmd);}
        case SPLITTER:{ return checkCommand(str_cmd, s_CMD_SIZE, s_cmd);}
        case FINDER:{ return checkCommand(str_cmd, f_CMD_SIZE, f_cmd);}
    }

    return -1;
}
int Command::checkCommand(std::string in_cmd, int CMD_SIZE, std::string cmd[])
{
	//0 = no command
	cmd_code = 0;

    std::string str_cmd = makelower(in_cmd);

    for(int i = 0; i < CMD_SIZE; i ++)
    {
        if(str_cmd == cmd[i]){
            cmd_code = i+1;
        }
    }

	if (cmd_code == 0 && str_cmd[0] == '/') {
		std::cout << "Invalid command." << std::endl;
		cmd_code = -1;
	}

    return cmd_code;
}
int Command::getCommandCode()
{
	return cmd_code;
}
void Command::displayCommands()
{
    ColorMode n_mode;
    n_mode.setColor("YELLOW");

    switch(cur)
    {
        case MAIN:
        {
            std::cout <<
                "Commands: \n" <<
                "/quit - Quit DIVA \n" <<
                "/about - Display about \n" <<
                "/color - Override the output color to BLUE, CYAN, RED, PURPLE, GREEN, YELLOW, WHITE \n" <<
                "/color RESET - Reset the override and display the system's original colors \n" <<
                "/command - Display commands \n\n" <<
                "To run a tool type: \n" <<
                "run [Tool] \n\n" <<
                "Tools include: \n" <<
                "Line Splitter - Allows user to open a text file and replace a character with another \n" <<
                "\t For example, replace all '~' characters with the newline character to read EDI documents \n" <<
                "Finder - Allows the user to search for a value within an EDI document or \n" <<
                "find a value at a segment in an EDI document. It returns all available \n" <<
                "information about the value if found. \n " <<
            std::endl;
            break;
        }
        case SPLITTER:
        {
            std::cout <<
                "Commands: \n " <<
                "/quit - Quit the Line Splitter and return to the main page. \n" <<
                "/stop - Stops the current session, erasing all data and returning to the start of the splitter. \n" <<
                "/back - Move back to edit the previous entered value. \n" <<
                "/about - Display about. \n" <<
                "/command - Display commands. \n" <<
            std::endl;
            break;
        }
        case FINDER:{
			std::cout <<
				"Commands: \n " <<
				"/quit - Quit the Line Splitter and return to the main page. \n" <<
				"/about - Display about. \n" <<
				"/command - Display commands. \n" <<
				"/manual - Display instructions. \n" <<
			std::endl;
            break;
        }
    }

    n_mode.resetColor();
}
