/**************************************************
***           D.I.V.A.LIB Types - Beta          ***
*** Austin Herman - austin.herman@valvoline.com ***
***     Updated:                                ***
***                                             ***
**************************************************/

#ifndef TYPES_H
#define TYPES_H

enum State { MAIN, SPLITTER, FINDER };

#include <string>
namespace
{
	std::string makelower(std::string in)
	{
		std::string out;
		for (int i = 0; i < in.length(); i++) {
			out += tolower(in[i]);
		}
		return out;
	}
}

namespace spltr
{
enum QuesState { O_FN, DELIMITER, REPLACE, YN, S_FN, DONE };

struct Data 
{
	char delim;
	char rplwth;
	std::string ofn;
	std::string sfn;
};

}

#include <vector>
namespace fndr
{
enum Data_Type { FILE_SEGMENT, FILE_ELEMENT, LIBRARY_SEGMENT, LIBRARY_ELEMENT, NONE };

enum Display_Type { ALL, MORE, SIMPLE, NOTYPE };

enum INPUT_STATE { LOAD, FIND };

struct Display_Settings
{
	int display_num = 5;
	Display_Type display_type = NOTYPE;
};

struct Input_Package
{
	int q_count = 0;
	Display_Settings settings;
	std::vector <std::string> m_query;
	std::string filename = "NOFILENAME";
	std::string filetype = "NOFILETYPE";
};

struct Index
{
	int seg_index = -1;
	int el_index = -1;
};

struct Found_Value
{
	Data_Type type;
	Index file_indx;
	Index lib_indx;
	int file_seg_element_count = 0;
	std::string found_seg = "";
	std::string found_element = "";
	std::string found_lib_seg = "";
	std::string found_lib_element = "";
	std::string full_line = "";
	std::string library_definition = "";
};

struct Doc_Value
{
	int ele_count = 0;
	int seg_line_num = 0;
	std::string segment_ref = "";
	std::string segment = "";
	std::vector <std::string> elements;
};

}
#endif //_TYPES_H
