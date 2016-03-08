#include <iostream>
using namespace std;
void string_inv(char str[], unsigned int len);
int main(){
	char str[] = "Wuhan Hubei to Welcom";
	unsigned int len = 20;
	string_inv(str, len);
	return 0;
}
void string_inv(char str[], unsigned int len){
	char *b = str+len;
	char *e = str+len;
	for (;b != str;b=e)
	{		
		while(*(--e)!=' '&& e != str){			
		}
		//memcpy(tem, e+1, (b -e)/sizeof(char));
		for (char *temp = (str == e)?e:e+1;temp < b+1;temp++)
		{
			cout << *temp ;
		}
		cout << endl;
		if(e-- == str)
			break;
	}

} 
