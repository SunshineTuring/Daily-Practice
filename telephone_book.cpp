// telephone_book.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>



//bool readfile(std::multimap<std::string,std::string> &data,std::string filename){
//	std::ifstream infile(filename);
//	if (!infile)
//	{
//		return false;
//	}
//
//	
//	std::string s;
//	while (std::getline(infile,s))
//	{
//		std::istringstream stream(s);
//		std::string s1;
//		std::string s2;
//		stream >>s1;
//		stream >> s2;
//		data.insert(make_pair(s1,s2));
//	}
//	return true;
//}



int _tmain(int argc, _TCHAR* argv[])
{
	std::multimap<std::string,std::string> data;
	std::string filename = "hello.txt";
	std::ifstream infile(filename);
	if (!infile)
	{
		return false;
	}


	std::string s;
	while (std::getline(infile,s))
	{
		std::istringstream stream(s);
		std::string s1;
		std::string s2;
		stream >>s1;
		stream >> s2;
		data.insert(make_pair(s2,s1));
	}

	return 0;
}

