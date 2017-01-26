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
	mem_access_t getMemAccess ();

	//Push a memory access object onto the queue
	void pushMemAccess (mem_access_t newMemAccess, unsigned warpId);

	//Remove a memory access object from the queue
 	void popMemAccess (unsigned warpId);

	//Return the size of the queue for a given warpid
	int retQueueSize (unsigned warpId);
	
 	//Check if a queue is empty
	bool mrpbQueue_empty (unsigned warpId) const;

private:
	
	//Queue variable
	std::vector<std::queue<mem_access_t> > mrpbQueue;
	
	
};

#endif		
