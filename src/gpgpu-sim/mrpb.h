#ifndef MRPB_H
#define MRPB_H


#include <queue>
#include <vector>
#include <../abstract_hardware_model.h>


class mrpb{

public:
	
	//Constructor
	mrpb(unsigned warpCount);

	//Destructor
	~mrpb();

	//Get the first entry from the queue. Access the queue using the warp id
	std::queue<mem_access_t> getMemAccess (unsigned warpId);

	//Push a memory access object onto the queue
	void pushMemAccess (mem_access_t newAccess);

	//Return the size of the queue for a given warpid
	int retQueueSize (unsigned warpId);

private:
	
	//Queue variable
	std::vector<queue<mem_access_t>> mrpbQueue;
	
	
};

#endif		
