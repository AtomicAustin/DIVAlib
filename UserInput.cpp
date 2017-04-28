#include "UserInput.h"

User_Input::User_Input(){}
/*FINDER*/
Finder_Input::Finder_Input()
{}
Finder_Input::Finder_Input(std::string n)
{
	full_str = n;
}
void Finder_Input::setInputString(std::string n)
{
	full_str = n;
}
void Finder_Input::storeSetting(fndr::Display_Type n)
{
	pack.settings.display_type = n;
}
void Finder_Input::storeSetting(int num)
{
	pack.settings.display_num = num;
}
void Finder_Input::storeQuery(std::string to_store)
{
	pack.q_count++;
	pack.m_query.push_back(to_store);
}
void Finder_Input::storeFileName(std::string in)
{
	pack.filename = in;
}
void Finder_Input::storeFileType(std::string in)
{
	pack.filetype = in;
}
std::string Finder_Input::getfullStr()
{
	return full_str;
}
void Finder_Input::setfullStr(std::string in)
{
	full_str = in;
}
fndr::Input_Package Finder_Input::getPackage()
{
	return pack;
}
void Finder_Input::setPackCount(int num)
{
	pack.q_count = num;
}

/*SPLITTER*/
Splitter_Input::Splitter_Input()
{
	d_count = 0;
}
Splitter_Input::Splitter_Input(Splitter_Input& obj)
{
	d_count = 0;

	for (int i = 0; i < obj.getCount(); i++) {
		this->store(obj[i]);
	}
}
void Splitter_Input::store(std::string s_in)
{
	data.push_back(s_in);
	d_count++;
}
int Splitter_Input::getCount()
{
	return d_count;
}
void Splitter_Input::clrdata()
{
	if (!data.empty())
	{
		data.clear();
		d_count = 0;
	}
}
void Splitter_Input::printData()
{
	for (int i = 0; i < d_count; i++) {
		std::cout << data[i] << std::endl;
	}
}
std::string Splitter_Input::operator[](int indx) const
{
	return data[indx];
}
bool Splitter_Input::operator==(std::string n_inp)
{
	if (data[0] == n_inp) {
		return true;
	}

	return false;
}