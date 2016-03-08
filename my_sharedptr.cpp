// my_sharedptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       04  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.28 Write your own versions of shared_ptr and unique_ptr
//!


#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "DebugDel.h"
#include "shared_pointer.h"
#include "unique_ptr.h"




int main()
{
    std::vector<unique_pointer<int>> v;

    for(int u = 0; u !=10 ; ++u)
        v.push_back(unique_pointer<int>(new int(u)));

    for(auto& sp : v)
        std::cout << *sp << "\n";


}
