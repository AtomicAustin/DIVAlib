#include "Command.h"

Command::Command()
{
    //ctor
	cmd_code = 0;
    cur = MAIN;
	filepath = "files/";
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

	if (in_cmd.substr(0, 1) == "<") {
		cmd_code = -2;
	}

    for(int i = 0; i < CMD_SIZE; i ++)
    {
        if(str_cmd == cmd[i]){
            cmd_code = i+1;
        }

		if (in_cmd.size() > 8)
		{
			if (in_cmd.substr(0, 9) == cmd[i]) {
				cmd_code = i + 1;
				storeFilePath(in_cmd.substr(9, in_cmd.length() - 9));
			}
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
void Command::storeFilePath(std::string n_path)
{
	std::string slashChoice = "INVALID";

	for (int i = 0; i < n_path.length(); i++) 
	{
		if (n_path[i] == '\\'){
			slashChoice = "\\\\";
		}
		else if (n_path[i] == '/') {
			slashChoice = "/";
		}
	}

	if (slashChoice == "INVALID") {
		std::cout << "Invalid file path. Please use '/' or '\\\\' to separate directories." << std::endl;
		cmd_code = -1;
	}

	if (n_path.substr(n_path.length() - 2, 2) != slashChoice){
		n_path = n_path + slashChoice;
	}

	filepath = n_path;

}
std::string Command::getFilePath()
{
	return filepath;
}
void Command::displayCommands()
{
    ColorMode n_mode;
    n_mode.setColor("YELLOW");
	n_mode.ovrd_color("GREEN", "---------------------------------------------");
    switch(cur)
    {
        case MAIN:
        {
			n_mode.ovrd_color("PURPLE", "Commands:");
			std::cout <<
				"/quit - Quit DIVA \n" <<
				"/about - Display about \n" <<
				"/command - Display commands \n" <<
				"/filepath - Set the file path to the directory containing your EDI documents. \n" <<
				"< - Returns control to the main state. For example, while in finder you can \n" <<
				"execute any command in main by typing '<[command]'. If in finder you want to\n" <<
				"run the splitter instead, type '<run splitter'. \n\n" <<
                "To run a tool type: \n" <<
                "run [Tool] \n\n" <<
                "Tools include: \n" <<
				"splitter - a line splitter\n" <<
				"finder - searches EDI docuements\n" <<
            std::endl;
            break;
        }
        case SPLITTER:
        {
			n_mode.ovrd_color("PURPLE", "Commands:");
            std::cout <<
                "/quit - Quit the Line Splitter and return to the main page. \n" <<
                "/stop - Stops the current session, erasing all data and returning to the start\n" <<
				"of the splitter. \n" <<
                "/back - Move back to edit the previous entered value. \n" <<
                "/about - Display about. \n" <<
                "/command - Display commands. \n" <<
				"/filepath - Set the file path to the directory containing your EDI documents. \n" <<
				"<[command] - Returns control to main. Will execute [command] in main." <<
            std::endl;
            break;
        }
        case FINDER:
		{
			n_mode.ovrd_color("PURPLE", "Commands:");
			std::cout <<
				"/quit - Quit the Line Splitter and return to the main page. \n" <<
				"/about - Display about. \n" <<
				"/command - Display commands. \n" <<
				"/manual - Display instructions. \n" <<
				"/filepath - Set the file path to the directory containing your EDI documents. \n" <<
				"<[command] - Returns control to main. Will execute [command] in main." <<
			std::endl;
            break;
        }
    }

    n_mode.resetColor();

	n_mode.ovrd_color("GREEN", "---------------------------------------------");
}
