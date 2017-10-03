#include <queue>
#include <vector>
#include "shader.h"
#include "mrpb.h"


//Constructor Implementation
Mrpb::Mrpb(unsigned warpCount){

	//Total 48 queues
	for(unsigned i = 0; i < warpCount; i++){
	
		mrpbQueue.push_back(std::queue<mem_fetch>());

	}

}


//Fetch a queue entry based on warp ID
//The warp ID parameter to the function is used to return the warp ID to the calling function
mem_fetch* Mrpb::getMemAccess(){


	//warp_id=0;
	//TO-DO Check if there is an entry and then return
//	return mrpbQueue[warpId].back();

	for(std::vector<std::queue<mem_fetch>>::iterator iter = mrpbQueue.begin(); iter != mrpbQueue.end(); iter++){

                if(!((*iter).empty())){

                        return &((*iter).back());

                        }

	//	++warp_id;
                }

}


bool Mrpb::checkEmptyQueue() const{


	for(std::vector<std::queue<mem_fetch>>::const_iterator iter = mrpbQueue.begin(); iter != mrpbQueue.end(); iter++){

                if(!((*iter).empty())){

                        return false;

                        }
                }
		return true;
}




bool Mrpb::pushMemAccess(mem_fetch newMemAccess, unsigned warpId){

/*	if(retQueueSize(warpId) >= 8){
		
		return true;

	}*/

	mrpbQueue[warpId].push(newMemAccess);

	return false;

}


//method to pop a memory access object

void Mrpb::popMemAccess(unsigned warpId){

 	mrpbQueue[warpId].pop();

}

//Get the size of a particular queue
int Mrpb::retQueueSize(unsigned warpId){

	return mrpbQueue[warpId].size();

}

bool Mrpb::mrpbQueue_empty(unsigned warpId) const { 

	return mrpbQueue[warpId].empty(); 
}

