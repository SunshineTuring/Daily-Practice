#include "stdio.h"

int func1(const char *pStr1,const char *pStr2,char *pDes){
	const char *s1 = pStr1;
	const char *s2 = pStr2;
	while((*s1)!='\0'){
		if (*s1!=*s2)
		{
			*pDes = *s1;
			s1++;
			pDes++;
		}
		else{				
			s1++;
			if ((*s2)!='\0')
			{
				s2++;
			}
		}
	}
	return 0;

}

void main(){

	printf("hello world");
	char *pStr1 = "123456";
	char *pStr2 = "12345634";
	char pDes[15];
	func1(pStr1,pStr2,pDes);
	printf("%s",pDes);
}
