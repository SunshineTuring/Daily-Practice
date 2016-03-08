#include <iostream>
#include <math.h>
struct point_ 
{
	long x;
	long y;
};

int main(void){
	 
	int num;
	point_  points;
	long x_min_ = NULL;
	long x_max_ = NULL;
	long y_min_ = NULL;
	long y_max_ = NULL;
	char c;
	std::cin >> num;
	for (int j = 0; j < num ; j++)
	{
		std::cin >> points.x >> c >> points.y;
		if (x_min_ == NULL)
		{
			x_min_ = points.x;
			x_max_ = points.x;
			y_min_ = points.y;
			y_max_ = points.y;
		}
		if (points.x < x_min_)
		{
			x_min_ = points.x;
		}
		else if (points.x > x_max_)
		{
			x_max_ = points.x;
		}
		if (points.y < y_min_)
		{
			y_min_ = points.y;
		}
		else if (points.y > y_max_)
		{
			y_max_ = points.y;
		}
	}
	 long result_ = ((y_max_-y_min_)> (x_max_-x_min_))?(y_max_-y_min_)*(y_max_-y_min_):(x_max_-x_min_)*(x_max_-x_min_);
	 std::cout << "the minimum area is : " <<result_<<std::endl;
	 return 0;
 }