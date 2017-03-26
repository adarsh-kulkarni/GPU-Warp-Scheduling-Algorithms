#ifndef WST_H
#define WST_H

#include <vector>
#include "../abstract_hardware_model.h"


class WST{

public:
	
	//Constructor
	WST(unsigned warpCount);


	//Destructor
	~WST();

	//Get the stall info from the table. Access the table using the warp id
	char getStallBit (unsigned warpId) const;

	//Change the Memory access bit of the table given the warp Id and the value
	void setStallBit (bool stallBit, unsigned warpId);


	//Get the memory access info from the table. Access the table using the warp id
	char getMemoryBit (unsigned warpId) const;

	//Change the Memory access bit of the table given the warp Id and the value
	void setMemoryBit (bool stallBit, unsigned warpId);

	void modifyBits (bool bitValue, unsigned warpId);

	void clearBits ();


private:

	struct table_entry{

		union{
			unsigned char ctrlBit;

			struct {

			//Two bits of information per warp. First bit says whether the warps next inst will access mem.
			//The second bit tells the scheduler to stall issuing of the warp's inst.
			unsigned char memBit:1,stallBit:1;

			};

		     };


		table_entry(){

			ctrlBit = false;
			memBit = false;
			stallBit = false;	

		}
		
	};


	//Container that holds the struct entries
	std::vector< table_entry > statusTable;	
	
};

#endif		


