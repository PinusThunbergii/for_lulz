#include <iostream>
#include <vector>
#include <algorithm>
#include "dog/dog.h"

bool isInsideTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int px, int py)
{
	int f_ab = 0, f_bc = 0, f_ac = 0;

	f_ab = (y1 - y0) * (px - x0) - (x1 - x0) * (py - y0);
	f_bc = (y2 - y1) * (px - x1) - (x2 - x1) * (py - y1);
	f_ac = (x0 - y2) * (px - x2) - (x0 - x2) * (py - y2);
	if(f_ab >= 0 && f_bc >= 0 && f_ac >= 0)
		return true;
	else if(f_ab <= 0 && f_bc <= 0 && f_ac <= 0)
		return true;
	else 
		return false;
}



void triangle(int x0, int y0, int x1, int y1, int x2, int y2)
{
	int left_bottom[2], right_top[2];
	left_bottom[0] = std::min(std::min(x0, x1), x2);
	left_bottom[1] = std::min(std::min(y0, y1), y2);
	right_top[0] = std::max(std::max(x0, x1), x2);
	right_top[1] = std::max(std::max(y0, y1), y2);

	for(int y = 0; y <= right_top[1]; y++)
	{
		if(y < left_bottom[1])
		{
			std::cout << std::endl;
			continue;
		}
		for(int x = 0; x <= right_top[0]; x++)
		{
			if(x < left_bottom[0])
				std::cout << " ";
			else
			{
				if(isInsideTriangle(x0, y0, x1, y1, x2, y2, x, y))
					std::cout << "#";
				else
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	
}
int main(int argc, char **argv)
{
	//Dog dog;
	//std::cout << dog;
	int size = 20;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(i <= size / 2 && (j <= i || j >= size - i - 1)) //j >= size - i - 1
				std::cout << "*";
			else if(i > size / 2 && (j <= size - i - 1 || j >= i))
				std::cout << "*";	
			else
				std::cout << "-";		
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(j <= size / 2 && (i <= j || i >= size - j - 1)) //j >= size - i - 1
				std::cout << "*";
			else if(j > size / 2 && (i <= size - j - 1 || i >= j))
				std::cout << "*";	
			else
				std::cout << "-";		
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	triangle(5, 5, 40, 10, 10, 40);
	std::cin.get();
	return 1;
}
