#include <iostream>


long int _allocation_tangguo(long int param1,int param2){
	long int temp = 0;
	if (param1 < param2)
	{
		
		temp = param2;
		param2 = param1;
		param1 = temp;
	}
	long int p = param1*param2;
	while (param2!=0)
	{
		temp=param1%param2;
		param1=param2;
		param2=temp;
	}
 	return  p/param1;
}


long int allocation_tangguo(int num,int* param1){
	if(num == 2){
		return _allocation_tangguo(*(param1),*(num+param1-1));
	}
	
	else {
		int *param2 = param1+1;
		return _allocation_tangguo(allocation_tangguo(num-1, param2),*param1);	
	}
	
}

int main(){
	int num;
	int i[15];
	std::cout <<"�����벿����Ŀ��"<<std::endl;
	std::cin >> num;
	std::cout <<"�������������������"<<std::endl;
	for (int j = 0;j<num;j++)
	{
		std::cin >> i[j];
	}
	
	long int n = allocation_tangguo(num,i);
	std::cout << "�������ŷַ����ǹ�����:" << n ;
	return 0;
}