// binary_qufan.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	
	//unsigned int i = 240;
	//unsigned int re = 0;
	//unsigned int temp = 1;
	////scanf("������һ��������u%",&i);
	//for (int j = 1;j < 33;j++)
	//{
	//	if ((i&temp)!=0)
	//	{
	//		printf("1");
	//		re +=1<<(32-j);
	//	}	
	//	else
	//
	//		printf("0");

	//	temp = temp << 1;
	//	//printf("temp:%u",temp);
	//	
	//}
	//printf("\n%u",re);
	char **p = new char* [10];
	char key[50] = {'\0'} ;
	int i = 0;
	int *num = new int[10];
	*(p++) = "wang fei";
	 *(p++) = "zhang man yu";
	 *(p++) = "zhang zhi yi";
	 *(p++) = "li li";
	 *(p++) = "li xioa man";
	 *(p++) = "li yu cun";
	 *(p++) = "yang ni";
	 *(p++) = "xiao tong";
	 *(p++) = "li lei";
	 *(p++) = "zhang san";
	 *(p) = NULL;
	 
	 //scanf("����������%s",&key);
	 gets(key);
	 printf("%s",key);

	 for (;key[i] != '\0';i++)
	 {
		 if (key[i] != '*'){
		 int j = 0;
		 for (j = i+1;key[j] != '\0';j++)
		 {
			 //if (key[j] == '\0')
			 //{
				// break;
			 //}
			  printf("%c %c",key[i],key[j]);
			 if (key[i] == key[j])
			 {
				
				 key[j] = '*';
			 }
		 }
		 }

	 }
	 for (p=p-10;p!=NULL;p++)
	 {
		 
		 int q = 0;
		
		 for (;int((**p))!=0;(*p)++)
		 {
			  //printf("%c",(**p));
			 while(key[q]!='\0'){
			
			 if (key[q]!='*'&&key[q]!=' ')
			 {
				 if ((**p) == key[q])
				 {
					 (*num)+=1;
				 }
			 }
			 q++;
			}
			 
		 }	
		 
		
	 }

	printf("%s",num);

	return 0;
}

