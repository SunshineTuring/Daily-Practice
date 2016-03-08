// Liner_list_se.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Liner_list_seq.h"
#include <vector>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	int i[9]={0,1,2,3,4,5,6,7,8};
	//std::vector<int> j(i,i+8);
	LinerList_seq<int>list_(i, i+9);
	//const int *m = list_.get_head();
	std::size_t length = list_.get_length();
	int q =9;
	list_.add_Node(q);
	int p =10;
	list_.add_Node(p);
	int &&mm = list_.check(1);

	int nn = list_.delete_n(1);

	for(int i = 1;i <= list_.get_length();i++){
		std::cout << list_.check(i) << std::endl;
	}
	int * ii = list_.find_(2,std::equal_to<int>());
	return 0;
}

