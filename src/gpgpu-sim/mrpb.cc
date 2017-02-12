#include <queue>
#include <vector>
#include "shader.h"
#include "mrpb.h"


//Constructor Implementation
Mrpb::Mrpb(unsigned warpCount){

	//Total 48 queues
	for(unsigned i = 0; i < warpCount; i++){
	
		mrpbQueue.push_back(std::queue<mem_access_t>());

	}

}


//Fetch a queue entry based on warp ID
mem_access_t Mrpb::getMemAccess(){

	//TO-DO Check if there is an entry and then return
//	return mrpbQueue[warpId].back();

	for(std::vector<std::queue<mem_access_t>>::iterator iter = mrpbQueue.begin(); iter != mrpbQueue.end(); iter++){

                if(!((*iter).empty())){

                        return (*iter).front();

                        }
                }

}

bool Mrpb::pushMemAccess(mem_access_t newMemAccess, unsigned warpId){

	if(retQueueSize(warpId) > 8){
		
		return true;

	}	

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

