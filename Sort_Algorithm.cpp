#include "Sort_Algorithm.h"


Sort_Algorithm::Sort_Algorithm(void)
{
}


Sort_Algorithm::~Sort_Algorithm(void)
{
}

std:vector<double> Insertion_Sort(std::vector<double> A ){
		INT32 size = m_Result.Size;
		INT32 i = 0;
		INT32 j = 0;
		for (j = 1;j<size;j++){
			i = j-1;
			double  key = A[i];
			whiel(i>0&&A[i]>key){
				A[i+1] = A[i];
				i = i-1;
			}
		A[i+1] = key;
		}
		return A;
	}