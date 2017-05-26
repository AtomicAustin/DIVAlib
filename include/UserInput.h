/**************************************************
***        D.I.V.A.LIB User Input - Beta        ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
*** 5/8/2017 - added delimiter setter           ***
**************************************************/

#pragma once
#ifndef H_USERINPUT
#define H_USERINPUT

#include <iostream>
#include <string>
#include <vector>
#include "Types.h"
#include "ColorMode.h"

class User_Input
{
public:
	User_Input();
};


class Finder_Input : User_Input
{
public:
	Finder_Input();
	Finder_Input(std::string); //set full string
	void setInputString(std::string);
	void storeSetting(fndr::Display_Type);
	void storeSetting(int);
	void storeQuery(std::string);
	void storeFileName(std::string);
	void storeFileType(std::string);
	void storeDelimiter(std::string);
	void storeFilepath(std::string);
	std::string getfullStr();
	void setfullStr(std::string);
	void setPackCount(int);
	fndr::Input_Package getPackage();

private:
	std::string full_str;
	fndr::Input_Package pack;

};


class Splitter_Input : User_Input
{
public:
	Splitter_Input();
	Splitter_Input(Splitter_Input&); //cptor
	void store(std::string);
	int getCount();
	void clrdata();
	void printData();
	std::string operator[](int) const;
	bool operator==(std::string);

private:
	std::vector<std::string>data;
	int d_count;
};

#endif //H_USERINPUT