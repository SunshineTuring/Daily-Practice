#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H
#include <iostream>
 class DebugDelete
{
public:
	DebugDelete(std::ostream &s = std::cerr):os(s){}  //���޷�������
	template<typename T> void operator()(T* t)const
	{
		os << "deleting ptr" << std::endl;
		//std::cout << "t:" << t <<" &t:"<< &t <<" *t:" <<*t << std::endl;
		delete t;
		//std::cout << "t:" << t <<" &t:"<< &t <<" *t:" <<*t << std::endl;
	}
private:
	std::ostream &os;//���޷�������
 };
#endif