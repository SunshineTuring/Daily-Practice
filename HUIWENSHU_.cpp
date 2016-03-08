#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,int *argv[])
{
	int num1,num2,temp;
	int a,b; 
	printf("please input 2 number:");
	scanf("%d,%d",&num1,&num2);

	if (num1 < num2) //the result is num1 > num2

	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	a = num1;
	b = num2;

	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	printf("最大公约数:%d,最小公倍数:%d\n",a,num1 * num2 / a);
	system("pause");
	return 0;
}