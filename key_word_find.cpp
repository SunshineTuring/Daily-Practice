// key_word_find.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
//#include <cctype>
#include <iostream>
#include <locale>

void read_file(std::vector<std::string> &vec,std::string filename){
	std::ifstream is(filename);
	std::string text;
	std::locale loc;
	while(std::getline(is,text)){
		for (int i = 0;i < text.length();i++)
		{
			std::cout <<int(text[i]);
			if (0<int(text[i])&&int(text[i])<256)
			{
				if(ispunct(text[i]))
				{
					text[i] = ' ';
				}			

				else if (text[i] == ' ')
				{
					text.erase(text.begin()+i);
					i--;
				}
			}
		}
		std::istringstream line(text);
		std::string word;
		while(line >> word){
			vec.push_back(word);
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::string> keyword_vec;
	std::vector<std::string> text_vec;
	read_file(keyword_vec,"key_word.txt");
	read_file(text_vec,"dianping.txt");
	return 0;
}

