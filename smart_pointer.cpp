// smart_pointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DebugDelete.h"
#include <iostream>
#include "share_pointer.h"
#include <functional>
#include <utility>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	share_pointer<int> p(new int(20));
	share_pointer<int> s(new int(30));
	share_pointer<int> q(s);
	s = p;
	share_pointer<int> m(share_pointer<int>(new int(30)));
	int mm = *m;
	share_pointer<std::string> n(share_pointer<std::string>(new std::string("hello")));
	n.reset();
	m.reset(new int(32));
	p.reset(new int(43),DebugDelete());
	
	return 0;
}

