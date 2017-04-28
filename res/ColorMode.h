/**************************************************
***        D.I.V.A.LIB Color Mode - Beta        ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
***                                             ***
**************************************************/

#ifndef COLORMODE_H
#define COLORMODE_H

#include <iostream>
#include <windows.h>
#include <string>

class ColorMode
{
    public:
        ColorMode();
		//COLOR, OUTPUT
        void ovrd_color(std::string, std::string);
        void setHandles();
        void setColor(std::string);
        int findColor(std::string);
        void setColortoPrev();
        void resetColor();

    private:
        const std::string cName[7] =
        {"BLUE","GREEN","CYAN",
        "RED","PURPLE","YELLOW", "WHITE"};
		//BLUE - System questions
		//GREEN - Formatting
		//CYAN - User input
		//RED - Errors
		//PURPLE - Home messages
		//YELLOW - System output
		//WHITE - Non-DIVA output


        HANDLE m_stdin;
        HANDLE m_stdout;
        int cur_color;
        int prev_color;

        CONSOLE_SCREEN_BUFFER_INFO buff;
};

#endif // COLORMODE_H
