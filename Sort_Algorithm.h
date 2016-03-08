#pragma once
#include <vector>
using namespace std;
class Sort_Algorithm
{
public:
	Sort_Algorithm(void);
	~Sort_Algorithm(void);
/*�������򷽷����ǽ�������
���룺����������
���������������
α���룺Insertion_Sort(A)
		for j = 2 to A.length                n
			key = A[j]                       n-1
			i = j-1                          n-1
			while i>0 and A[i] > key         tj
				A[i+1] = A[i]                tj-1
				i = i-1                      tj-1
			A[i+1] = key                     n-1
ѭ������ʽ��ÿ�ε���ǰ��������A[1...j-1]Ϊԭ����A[1...j-1]���շǵݼ�˳�����У�������A[j+1...A.length]Ϊԭ�����A[j+1...A.length]
			������
��ʼ����ѭ����һ�ε���֮ǰ��������A[1...j-1]Ϊ�գ�ѭ������ʽΪ�档
���֣��ڵ�j�˵���֮ǰ����ѭ������ʽΪ�棬��ô��j�˵���ʱ����A[j-1],A[j-2]..�����ƶ���֪���ҵ�A[j]λ�ã�������A[j]
��ֹ��ѭ����ֹʱj = A.length+1,��ʱ������A[1...j-1]Ϊ�Ѿ���������
���Ӷȣ�T(n)=n+(n-1)+(n-1)+(j:2,n)tj+(j:2,n)(tj-1)+(j:2,n)(j-1)+n-1 = Q(n^2)
*/	
	vector<double> Insertion_Sort(vector<double> A );

};

