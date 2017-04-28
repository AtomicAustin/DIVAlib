#include "ColorMode.h"

ColorMode::ColorMode()
{
    m_stdin   = GetStdHandle(STD_INPUT_HANDLE);
    m_stdout  = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(m_stdout, &buff);
}
void ColorMode::setHandles()
{
    m_stdin   = GetStdHandle(STD_INPUT_HANDLE);
    m_stdout  = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(m_stdout, &buff);
}
void ColorMode::ovrd_color(std::string M_COLOR, std::string M_OUTPUT)
{
    setHandles();
    SetConsoleTextAttribute(m_stdout, findColor(M_COLOR));

    std::cout << M_OUTPUT << std::endl;

    setColortoPrev();
}
int ColorMode::findColor(std::string COLOR)
{
    if(COLOR == "WHITE"){
        resetColor();
    }

    for(int i = 0; i < 6; i ++)
    {
        if(COLOR == cName[i]){
            return i+9;
        }
    }
}
void ColorMode::setColor(std::string M_CHOICE)
{
    if(M_CHOICE == "WHITE"){
        resetColor();
    }

    for(int i = 0; i < 6; i ++)
    {
        if(M_CHOICE == cName[i]){

            if(prev_color != cur_color){
                prev_color = cur_color;
            }

            cur_color = i+9;

            SetConsoleTextAttribute(m_stdout, cur_color);
            return;
        }
    }
}
void ColorMode::setColortoPrev()
{
    if(cur_color > 0){
        SetConsoleTextAttribute(m_stdout, cur_color);
    }
    else if(cur_color == -1){
        resetColor();
    }
}
void ColorMode::resetColor()
{
    if(prev_color != cur_color){
        prev_color = cur_color;
    }

    cur_color = -1;

    FlushConsoleInputBuffer(m_stdin);
    SetConsoleTextAttribute(m_stdout, buff.wAttributes);
}
