// MaxSubSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <iostream>
typedef long int l_int;

l_int max3(l_int left,l_int right, l_int cross );
l_int re_MaxSubSum1(std::vector<int> data , int left, int right);

l_int MaxSubSum1(std::vector<int> data){
	time_t t1,t2;
	time(&t1);	
	l_int sum = re_MaxSubSum1(data,0,data.size()-1);
	time(&t2);
	std::cout<<"MaxSubSum1: "<<sum<<" time:"<<t2-t1<<std::endl;
	return sum;
}

l_int re_MaxSubSum1(std::vector<int> data , int left, int right){
	if (left == right)
	{
		
		//return (data[left]>0?data[left]:0);
		return data[left];
	}
	int cent = (left+right)/2;
	l_int MaxLeft = re_MaxSubSum1(data, left,cent);
	l_int MaxRight = re_MaxSubSum1(data,cent+1,right);


	l_int CrossSum_Ltemp = 0;
	l_int CrossSumL = 0;
	for (int i = cent;i>=left;i--)
	{
		CrossSum_Ltemp += data[i];
		if (CrossSum_Ltemp>CrossSumL)
		{
			CrossSumL = CrossSum_Ltemp;
		}
	}

	l_int CrossSum_Rtemp = 0;
	l_int CrossSumR = 0;
	for (int i = cent+1;i<=right;i++)
	{
		CrossSum_Rtemp += data[i];
		if (CrossSum_Rtemp>CrossSumR)
		{
			CrossSumR = CrossSum_Rtemp;
		}
	}
	l_int SumCross = CrossSumL+CrossSumR;
	return max3(MaxLeft,MaxRight,SumCross);
}

l_int max3(l_int left,l_int right, l_int cross ){
	l_int temp = left;
	if (temp < right)
	{
		temp = right;
	}
	if (temp < cross)
	{
		temp = cross;
	}
	return temp;
}

l_int MaxSubSum2(std::vector<int> data){
	time_t t1,t2;
	time(&t1);
	l_int sum = 0;
	for (int i=0;i<data.size();i++)
	{
		for (int j=i;j<data.size();j++)
		{
			l_int temp = 0;
			for (int k=i;k<j;k++)
			{
				temp += data[k];
			}
			if (temp > sum)
			{
				sum = temp;
			}
		}
	}
	time(&t2);
	std::cout<<"MaxSubSum2: "<<sum<<" time:"<<t2-t1<<std::endl;
	return sum;
}

l_int MaxSubSum3(std::vector<int> data){
	time_t t1,t2;
	time(&t1);
	l_int sum = 0;
	for (int i=0;i<data.size();i++)
	{
		l_int temp = 0;
		for (int j=i;j<data.size();j++)
		{
			temp += data[j];
			if (temp > sum)
			{
				sum = temp;
			}
		}
	}
	time(&t2);
	std::cout<<"MaxSubSum3: "<<sum<<" time:"<<t2-t1<<std::endl;
	return sum;
}

l_int MaxSubSum4(std::vector<int> data){
	time_t t1,t2;
	time(&t1);
	l_int sum = 0;
	l_int temp = 0;
	for (int i=0;i<data.size();i++)
	{
			temp += data[i];
			if (temp > sum)
			{
				sum = temp;
			}
			else if(temp<0){
				temp = 0;
			}
	}
	time(&t2);
	std::cout<<"MaxSubSum4: "<<sum<<" time:"<<t2-t1<<std::endl;
	return sum;
}

bool readfile(std::vector<int> &data,std::string filename){
	std::ifstream infile(filename);
	if (!infile)
	{
		return false;
	}
	int s;
	while (infile>>s)
	{
		data.push_back(s);
	}
	return true;
}

bool writefile(l_int num,int max_nun,std::string filename = "text.txt"){
	std::ofstream outfile(filename);
	if (!outfile)
	{
		return false;
	}
	std::uniform_int_distribution<int> u(0,max_nun);
	std::default_random_engine e;
	for (int i =0;i<num;i++)
	{
		
		outfile<<(u(e)%2==0?u(e):~u(e))<<'\n';
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int a[]={-2,11,-4,13,-5,-2};
	//std::vector<int> data;
	//for (int i=0;i<6;i++)
	//{
	//	data.push_back(a[i]);
	//}
	if(!writefile(100000,200)){
		return 0;
	}
	std::vector<int> data;
	if(!readfile(data,"text.txt")){
		return 0;
	}	
	l_int sum4 = MaxSubSum4(data);
	l_int sum3 = MaxSubSum3(data);
	l_int sum1 = MaxSubSum1(data);
	l_int sum2 = MaxSubSum2(data);
	return 0;
}

