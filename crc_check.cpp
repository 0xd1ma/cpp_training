#include <iostream>
#include <string>
#include <cstdint>

std::uint8_t steeringCrc(std::uint8_t *buf)
{
    std::uint8_t crc = 0xD3;
    std::uint8_t x_o_r = 0xE9;

    std::uint8_t i = 0;
    for (i = 63; i >= 8; --i)
    {
        if (buf[i / 8] & (1 << (7 - i % 8)))
            crc ^= x_o_r;
        x_o_r = (x_o_r << 1) ^ ((x_o_r & 0x80) ? 0x2F : 0x00);
    }

    return crc;
}

std::uint8_t generalSkodaCrc(std::uint8_t *buf, std::uint32_t id)
{
    std::uint8_t crc = 0x0E;
    std::uint8_t x_o_r = 0x2F;

    std::uint8_t dt[9];
    std::copy(buf, buf + 8, dt);

    dt[8] = id & 0xFF;

    std::uint8_t i = 0;
    for (i = 71; i >= 8; --i)
    {
        if (dt[i / 8] & (1 << (7 - i % 8)))
            crc ^= x_o_r;
        x_o_r = (x_o_r << 1) ^ ((x_o_r & 0x80) ? 0x2F : 0x00);
    }

    return crc;
}

int main(int argc, char ** argv )
{
    /***************************************************************************
     * проверка работы контрольных сумм
    ***************************************************************************/	
	std::uint32_t id0 = 0x130; 
	std::uint8_t buf0[8] = {0x53, 0x87, 0x37, 0x00, 0x08, 0x00, 0x04, 0x00};
	
	std::cout << "log crc: ";
	std::cout << std::hex << std::showbase << static_cast<unsigned int>(*buf0);
	std::cout << " ";
	std::cout << "steeringCrc: "; 
	std::cout << std::hex << static_cast<unsigned int>(steeringCrc(buf0)); 
	std::cout << " ";
	std::cout << "generalSkodaCrc: ";
	std::cout << std::hex << static_cast<unsigned int>(generalSkodaCrc(buf0, id0)); 
	std::cout << std::endl;	
	
	std::cout << std::endl;	

	std::uint32_t id1 = 0x130; 
	std::uint8_t buf1[8] = {0x3C, 0x86, 0x39, 0x00, 0x08, 0x00, 0x04, 0x00};
	
	std::cout << "log crc: ";
	std::cout << std::hex << std::showbase << static_cast<unsigned int>(*buf1);
	std::cout << " ";
	std::cout << "steeringCrc: "; 
	std::cout << std::hex << static_cast<unsigned int>(steeringCrc(buf1)); 
	std::cout << " ";
	std::cout << "generalSkodaCrc: ";
	std::cout << std::hex << static_cast<unsigned int>(generalSkodaCrc(buf1, id1)); 
	std::cout << std::endl;
	
	std::cout << std::endl;			
	
	std::uint32_t id2 = 0x106; 
	std::uint8_t buf2[8] = {0x8A, 0x84, 0x64, 0x00, 0x00, 0x00, 0xA9, 0x10};
	
	std::cout << "log crc: ";
	std::cout << std::hex << std::showbase << static_cast<unsigned int>(*buf2);
	std::cout << " ";
	std::cout << "generalSkodaCrc: ";
	std::cout << std::hex << static_cast<unsigned int>(generalSkodaCrc(buf2, id2)); 
	std::cout << std::endl;
	
	std::cout << std::endl;
	 
	std::uint32_t id3 = 0x106; 
	std::uint8_t buf3[8] = {0x99, 0x83, 0x64, 0x00, 0x00, 0x00, 0xA9, 0x10};
	
	std::cout << "log crc: ";
	std::cout << std::hex << std::showbase << static_cast<unsigned int>(*buf3);
	std::cout << " ";
	std::cout << "generalSkodaCrc: ";
	std::cout << std::hex << static_cast<unsigned int>(generalSkodaCrc(buf3, id3)); 
	std::cout << std::endl;	
	
	std::cout << std::endl;	
	
	std::uint32_t id4 = 0x106; 
	std::uint8_t buf4[8] = {0xFD, 0x82, 0x64, 0x00, 0x00, 0x00, 0xA9, 0x10};
	
	std::cout << "log crc: ";
	std::cout << std::hex << std::showbase << static_cast<unsigned int>(*buf4);
	std::cout << " ";
	std::cout << "generalSkodaCrc: ";
	std::cout << std::hex << static_cast<unsigned int>(generalSkodaCrc(buf4, id4)); 
	std::cout << std::endl;	
	
	return 0;
}
