#include<iostream>
#include <math.h>
#include "stdlib.h"
using namespace std;
int main(void){
	int N;	
	cin >> N;
	if (N <3)
	{
		return -1;
	}
	unsigned long s1= N*(N-1)*(N-2)/6;
	if (N>3)
	{
		for (int i= 4; i<N;i++)
		{
			s1 += (i-3)*(i-3);
		}
	}
	cout << s1;
	system("pause");
	return 0;
}