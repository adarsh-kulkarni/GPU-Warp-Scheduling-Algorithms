#ifndef MRPB_H
#define MRPB_H


#include <queue>
#include <vector>
#include "../abstract_hardware_model.h"


class Mrpb{

public:
	
	//Constructor
	Mrpb(unsigned warpCount);

	//Destructor
	~Mrpb();

	//Get the first entry from the queue. Access the queue using the warp id
	mem_fetch* getMemAccess ();

	//Push a memory access object onto the queue
	bool pushMemAccess (mem_fetch newMemAccess, unsigned warpId);

	//Remove a memory access object from the queue
 	void popMemAccess (unsigned warpId);

	//Return the size of the queue for a given warpid
	int retQueueSize (unsigned warpId);
	
 	//Check if a queue is empty
	bool mrpbQueue_empty (unsigned warpId) const;

	bool checkEmptyQueue () const;	

private:
	
	//Queue variable
	std::vector<std::queue<mem_fetch> > mrpbQueue;
	
	
};

#endif		
