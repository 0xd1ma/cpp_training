#include <iostream>
#include <string>
#include <cstdint>

int main(int argc, char ** argv )
{

	bool sign;
	std::int32_t data;
	double result;
	
	sign = false;
	data = 235;
	
	if (sign)
	{

	}
	else
	{
		data = -data;
	}
	
	
	result = data - 1.6;
	
	std::cout << result;

	
	return 0;
}
