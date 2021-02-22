/*# MIT License
# Cleaned version of StringTools library.
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef STRING_TOOLS_HPP
#define STRING_TOOLS_HPP

#include <iostream>
#ifdef _MSC_VER
#include <string>  // VisualC++
#else
#include <cstring>  // Otherwise
#endif

namespace stringtools {
	static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
	    size_t pos = std::string::npos;
   		while((pos = mainString.find(erase)) != std::string::npos) {
   		    mainString.erase(pos, erase.length());
  		}

  		return mainString;
  	}

	static void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    		if(from.empty())
        		return;
    		size_t start_pos = 0;
    		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        		str.replace(start_pos, from.length(), to);
        		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    		}
	}

	static int IntConverterWithWhitespace(char* s) {
		int sum = 0;
  		char ch;
  		std::string conv(s);
  		s = const_cast<char*>(EraseAllSubString(conv, " ").c_str());
 		char sign = *s;
 		if (*s == '-' || *s == '+') s++;
  		while ((ch = *s++) >= '0' && ch <= '9') {
    			sum = sum * 10 - (ch - '0');
  		}
  		if (sign != '-') {
    			sum = -sum;
  		}
  		return sum;
	}

	static int Count(std::string s, char ch) {
  		int count = 0;

	 	for (int i = 0; i < s.size(); i++)
    			if (s[i] == ch) count++;

  		return count;
	}

	/* return as string */
	static std::string GetBetweenString(std::string oStr, std::string sStr1, std::string sStr2) {
    		int start = oStr.find(sStr1);
    		if (start >= 0) {
     			std::string tstr = oStr.substr(start + sStr1.length());
      			int stop = tstr.find(sStr2);
      			if (stop >1)
        			return oStr.substr(start + sStr1.length(), stop);
      			else
        			return "error";
    		}
    		else
       		return "error";
	}
	
	static inline std::string ltrim(std::string s) {
    	return s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
	}

	static bool Find(std::string &data, std::string substring) {
  		size_t check = data.find(substring);

		if (check != std::string::npos) return true; /* Found */
		else 
			return false; /* Not found */

		return false;
	}

    static inline std::string STR(const char* str) {
        return static_cast<std::string>(str);
    }
}

#endif // STRING_TOOLS_HPP
