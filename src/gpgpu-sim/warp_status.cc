#include <vector>
#include "warp_status.h"



	//Constructor
	WST::WST(unsigned warpCount){

	for(unsigned i = 0; i < warpCount; ++i)

		statusTable.push_back(table_entry());


	}


	char WST::getStallBit (unsigned warpId) const {
		

		
		return statusTable[warpId].stallBit;

	}

	void WST::setStallBit (bool stallBit, unsigned warpId) {

		
		statusTable[warpId].stallBit = stallBit;

	}	


	char WST::getMemoryBit (unsigned warpId) const {

		
		return statusTable[warpId].stallBit;

	}

	void WST::setMemoryBit (bool bitValue, unsigned warpId) {

		
		statusTable[warpId].memBit = bitValue;

	}		

	void WST::modifyBits (bool bitValue, unsigned warpId) {

		statusTable[warpId].ctrlBit = bitValue;

	}
	
	void WST::clearBits () {
		
		for (std::vector<table_entry>::iterator it = statusTable.begin() ; it != statusTable.end(); ++it){

	
			it.ctrlBit = false;
	
		}	


	}
