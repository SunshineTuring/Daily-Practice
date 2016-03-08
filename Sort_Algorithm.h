#pragma once
#include <vector>
using namespace std;
class Sort_Algorithm
{
public:
	Sort_Algorithm(void);
	~Sort_Algorithm(void);
/*插入排序方法，非降序排序
输入：带排序序列
输出：已排序序列
伪代码：Insertion_Sort(A)
		for j = 2 to A.length                n
			key = A[j]                       n-1
			i = j-1                          n-1
			while i>0 and A[i] > key         tj
				A[i+1] = A[i]                tj-1
				i = i-1                      tj-1
			A[i+1] = key                     n-1
循环不变式：每次迭代前，子数组A[1...j-1]为原数组A[1...j-1]按照非递减顺序排列，子数组A[j+1...A.length]为原数组的A[j+1...A.length]
			的数。
初始化：循环第一次迭代之前，子数组A[1...j-1]为空，循环不变式为真。
保持：在第j此迭代之前，若循环不变式为真，那么第j此迭代时，将A[j-1],A[j-2]..向右移动，知道找到A[j]位置，并插入A[j]
终止：循环终止时j = A.length+1,此时我们有A[1...j-1]为已经排序序列
复杂度：T(n)=n+(n-1)+(n-1)+(j:2,n)tj+(j:2,n)(tj-1)+(j:2,n)(j-1)+n-1 = Q(n^2)
*/	
	vector<double> Insertion_Sort(vector<double> A );

};

