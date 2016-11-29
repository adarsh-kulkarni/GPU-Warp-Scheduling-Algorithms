#include <queue>
#include <vector>
#include <../abstract_hardware_model.h>
#include <mrpb.h>


//Constructor Implementation
mrpb::mrpb(unsigned warpCount){

	//Total 48 queues
	for(int i = 0; i < warpCount; i++){
	
		mrpbQueue.push_back(std::queue<mem_access_t>());

	}

}


//Fetch a queue entry based on warp ID
queue<mem_access_t> mrpb::getQueueEntry(unsigned warpId){

	//TO-DO Check if there is an entry and then return
	return mrpbQueue[warpId].back();

}

void mrpb::pushQueueEntry(mem_access_t newMemAccess, unsigned warpId){

	//TO-DO check if there is space in the queue and then add. 8 Entries per queue
	if(mrpbQueue[warpId].size() >= 8){
	//	return something
	}
	mrpbQueue[warpId].push(newMemAccess);

}

//Get the size of a particular queue
int mrpb::retQueueSize(unsigned warpId){

	return mrpbQueue[warpId].size();

}


