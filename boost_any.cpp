#include <iostream>
#include <typeinfo>
#include <boost/any.hpp>
#include <stdint.h>
#include <string>

int main(int argc, char ** argv )
{
	std::cout << "Lets test it:" << std::endl;
	std::cout << "boost::any" << std::endl;
	std::cout << std::endl;	
	
	boost::any b = 1;

	std::cout << boost::any_cast<int32_t>(b) << std::endl;
	
	// смотрим на тип
	if (!b.empty())
	{
		const std::type_info &ti = b.type();
		std::cout << ti.name() << std::endl;
	}

	// сравниваем типы
	if (typeid(int32_t) == b.type())
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "NACK" << std::endl;
	}
	
	
	try
	{
		b = static_cast<float>(3.14);
		if (typeid(float) == b.type())
		{
			std::cout << "OK" << std::endl;
		}
		else
		{
			std::cout << "NACK" << std::endl;
		}
		// пробуем скастовать
		std::cout << boost::any_cast<float>(b) << std::endl;	
		
	}
	catch (boost::bad_any_cast &e)
	{
		// нет улетаем 
		std::cerr << e.what() << std::endl;
	}

	b = std::string{"privet"};
	
	std::cout << boost::any_cast<const std::string>(b) << std::endl;
	
	if (!b.empty())
	{
		const std::type_info &ti = b.type();
		std::cout << ti.name() << std::endl;
	}		
	
	return 0;
}
