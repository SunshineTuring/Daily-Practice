#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H

#include "DebugDelete.h"
#include <functional>
#include <iostream>
//1.ģ���Ա����֪��ʹ��ʱ��������ȥ����
template<typename T>class share_pointer
{
public:

	//Ĭ�Ϲ��캯��
	share_pointer(){} 


	//��ʽ���幹�캯��������ָ��������ͺ�ɾ�������������β�
	explicit share_pointer(T *t, std::function<void(T*)> d = DebugDelete()):t(t),count(new size_t(1)),Deleter(d){}


	//�������캯��
	share_pointer(share_pointer &sp):count(sp.count),t(sp.t),Deleter(sp.Deleter){
		std::cout << "copy" << std::endl;
		++*count;
	}


	//�ƶ����캯��,share_pointer<int> m(share_pointer<int>(new int(30)))�����ƶ����캯�������ޣ�����ÿ������캯��
	share_pointer(share_pointer &&sp):count(sp.count),t(std::move(sp.t)),Deleter(std::move(sp.Deleter)){
		std::cout << "moving" << std::endl;
		sp.t = nullptr;
	}


	//��ֵ���캯��
	share_pointer &operator=(share_pointer &sp);
	
	
	//����ָ��ָ���ֵ
	T& operator*() const {return *t;}


	//����->
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

	std::size_t *count;//6.����Ϊ��ͬ����Ĺ����������̶���һ��ָ�룬ָ�����ڴ�

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