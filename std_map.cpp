#include <iostream>
#include <stdint.h>
#include <string>
#include <map>

#include <cstdint>

int main(int argc, char ** argv )
{
	std::int32_t i;
	
	i = 0;
	std::cout << i;
	
	std::cout << "Lets test it"	<< std::endl;
	std::cout << "std::map" << std::endl;
	std::cout << std::endl;
	
	std::map<int, int> table;
	std::map<int, int> * ptr;
	
	ptr = &table;	
	
	table[10] = 1;
	table[145] = 2;
	table[23] = 3;
	table[21] = 4;
	table[534] = 5;
	
	(*ptr)[65] = 123;
	
	
	
	std::cout << table[534] << std::endl;
	
	std::cout << table.count(10) << std::endl;
	
	std::cout << table.size() << std::endl;
	std::cout << table.max_size() << std::endl;	


	table.insert( std::pair<int, int>(3,6));	
	// проверки на существование элемента в словаре
	// 1 тупо пушим элемент
	std::pair<std::map<int,int>::iterator,bool> ret;
	ret = table.insert( std::pair<int, int>(10, 1) );
	if (ret.second==false) 
	{
		std::cout << "element already existed" << std::endl;
	}
	
	// 2 каждый элемент ключ уникальный
	if (table.count(145))
	{
		std::cout << "element already existed" << std::endl;		
	}
	
	// 3 use find
	auto search = table.find(23);
	if (search != table.end())
	{
		std::cout << "element already existed" << std::endl;	
	}
	
	
	std::cout << std::endl;
	
	for(auto &x : table)
	{
		std::cout << x.first << ", " << x.second << std::endl;
	}

	std::cout << std::endl;	
	std::cout << "REMOVE" << std::endl;
	
	table.erase(10);
	
	for(auto &x : table)
	{
		std::cout << x.first << ", " << x.second << std::endl;
	}	
	

	
	return 0;
}
