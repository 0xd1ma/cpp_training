#include <iostream>
#include <stdint.h>
#include <string>
#include <map>
#include <cstdint>
#include <boost/any.hpp>

    using storage = struct
            {
                bool dataStatus;
                boost::any data;
            };


using canIdToVehicleDataMap = std::map< std::uint32_t, storage >;

int main(int argc, char ** argv )
{

	canIdToVehicleDataMap a;

	
	return 0;
}
