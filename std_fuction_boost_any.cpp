#include <iostream>
#include <cstdint>
#include <functional>
#include <boost/any.hpp>

// преобразование массива чаров в инт (little-endian)
uint32_t charArrToInt(const uint8_t * buf)
{
	uint32_t tmp = 0;

	tmp |= buf[0] << 0;
	tmp |= buf[1] << 8;
	tmp |= buf[2] << 16;
	tmp |= buf[3] << 24;

	return tmp;
}

// инициализируем структуру по-умолчанию с использованием конструктора
using vehicle_storage = struct t
		{
			bool isDataChanged;
			boost::any data;
			
			t() : isDataChanged(false), data(777)
			{
				;
			}
		};

// используем инициализацию с++11
using vehicle_steering = struct
		{
			std::int32_t angle{123};
		};
		
boost::any steeringConverting(std::uint8_t * buf)
{
	vehicle_steering tmp;

	tmp.angle = charArrToInt(buf);

	return tmp;
}

std::uint8_t buffer[4] = {0x44, 0x33, 0x22, 0x11};

int main(int argc, char ** argv)
{
	vehicle_storage stock;
	vehicle_steering steer;

	std::cout << boost::any_cast<std::int32_t>(steer.angle) << std::endl;	
	steer.angle = 321;
	std::cout << stock.isDataChanged << " " << boost::any_cast<std::int32_t>(stock.data) << std::endl;
	std::cout << boost::any_cast<std::int32_t>(steer.angle) << std::endl;
	
	std::function< boost::any(std::uint8_t *) > steeringConverting_ptr = nullptr;
	steeringConverting_ptr = steeringConverting;

	stock.data = 56;
	stock.isDataChanged = true;	
	
	std::cout << boost::any_cast<std::int32_t>(stock.data) << std::endl;	
	
	stock.data = steeringConverting_ptr(buffer);
	stock.isDataChanged = true;	
	
    std::cout << std::showbase 			// show the 0x prefix
			  << std::internal;			// fill between the prefix and the number
         
	std::cout << std::hex << boost::any_cast< vehicle_steering >(stock.data).angle << std::endl;		

	return 0;
}
