/**************************************************
***        D.I.V.A.LIB Color Mode - Beta        ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
*** 5/2/2017 - added overide with no newline    ***
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
		//COLOR, OUTPUT, NEWLINE BOOL
		void ovrd_color(std::string, std::string, bool);
        void setHandles();
        void setColor(std::string);
        int findColor(std::string);
        void setColortoPrev();
        void resetColor();

    private:
        const std::string cName[7] =
        {"BLUE","GREEN","CYAN",
        "RED","PURPLE","YELLOW", "WHITE"};

        HANDLE m_stdin;
        HANDLE m_stdout;
        int cur_color;
        int prev_color;

        CONSOLE_SCREEN_BUFFER_INFO buff;
};

#endif // COLORMODE_H
