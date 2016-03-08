#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H

#include "DebugDelete.h"
#include <functional>
#include <iostream>
//1.模板成员函数知道使用时编译器才去编译
template<typename T>class share_pointer
{
public:

	//默认构造函数
	share_pointer(){} 


	//显式定义构造函数，传递指针管理类型和删除器对象两个形参
	explicit share_pointer(T *t, std::function<void(T*)> d = DebugDelete()):t(t),count(new size_t(1)),Deleter(d){}


	//拷贝构造函数
	share_pointer(share_pointer &sp):count(sp.count),t(sp.t),Deleter(sp.Deleter){
		std::cout << "copy" << std::endl;
		++*count;
	}


	//移动构造函数,share_pointer<int> m(share_pointer<int>(new int(30)))调用移动构造函数，若无，则调用拷贝构造函数
	share_pointer(share_pointer &&sp):count(sp.count),t(std::move(sp.t)),Deleter(std::move(sp.Deleter)){
		std::cout << "moving" << std::endl;
		sp.t = nullptr;
	}


	//赋值构造函数
	share_pointer &operator=(share_pointer &sp);
	
	
	//返回指针指向的值
	T& operator*() const {return *t;}


	//重载->
	T* operator->() const {return &this->operator*();}

	//reset
	void reset(){
		deconstructor();
	}

	void reset(T* p){
		if (t)
		{
			deconstructor();
			t = p;
			count = new size_t(1);
		}
	}

	void reset(T* p,std::function<void(T*)> d){
			reset(p);
			Deleter = d;
	}



private:

	std::size_t *count;//6.计数为不同对象的公共变量，固定义一个指针，指向共有内存

	T *t ;

	std::function<void (T*)> Deleter;

	void deconstructor();
};

template<typename T> 
inline void share_pointer<T>::deconstructor(){
	if(t)
	{
		--*count;
		if (*count == 0)
		{
			Deleter(t);
			delete count;
		}
	}
	t = nullptr;
	count = nullptr;
}

template<typename T>
inline share_pointer<T> &share_pointer<T>::operator=(share_pointer &sp){
	++(*sp.count);
	deconstructor();
	count = sp.count;
	t = sp.t;
	Deleter = sp.Deleter;
	return *this;
}

#endif