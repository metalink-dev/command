#include "Globals.ih"

std::string Globals::XMLSafe(std::string value)
{
	//Entities
	string froma[] = {
		"&",
		"<",
		">",
		""
	};
	
	string tob[] = {
		"&amp;",
		"&lt;",
		"&gt;"
	};
	
	
	for(unsigned i(0); froma[i].size(); ++i)
	{
		string const &from(froma[i]);
		string const &to(tob[i]);
		string::size_type offset(0);
		
		while(true)
		{
			string::size_type pos = value.find(from, offset);
			
			if(pos == string::npos)
				break;
			value = value.substr(0, pos) + to + value.substr(pos + from.size());
			offset += pos + to.size();
		}
	}
	return value;
}
