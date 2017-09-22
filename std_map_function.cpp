#include <iostream>
#include <cstdint>
#include <string>
#include <map>
#include <functional>

void function1(void)
{
	std::cout << "функция 1" << std::endl;
}

void function2(void)
{
	std::cout << "функция 2" << std::endl;
}

void function3(void)
{
	std::cout << "функция 3" << std::endl;
}

int main(int argc, char ** argv )
{
	std::cout << "Lets test it"	<< std::endl;
	std::cout << "std::map and function" << std::endl;
	std::cout << std::endl;
	
	std::function< void(void) > test = nullptr;
	//test = function1;
	
	try
	{
		test();
	}
	catch(const std::bad_function_call &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::map< std::uint32_t, std::function< void(void) > > table;
	
	table.insert( std::pair<std::uint32_t, std::function< void(void) >>(3, function1));
	table.insert( std::pair<std::uint32_t, std::function< void(void) >>(34, function2));
	table.insert( std::pair<std::uint32_t, std::function< void(void) >>(56, function3));	
	
	table[34]();
	
/*
	std::map< std::uint32_t, std::function< void(void) > >::iterator it;

	for(it = table.begin(); it != table.end(); ++it)
	{
		it->second();
	}	

	std::map< std::uint32_t, std::function< void(void) > >::reverse_iterator rit;
		
	for(rit = table.rbegin(); rit != table.rend(); ++rit)
	{
		rit->second();
	}
*/	

	return 0;
}
