#include "wrc.h"
#include "shader.h"


Wrc::Wrc(){


	memory_saturation_flag = false;	
	issuedWarp = 0;


}

void Wrc::setIssuedWarp(unsigned warp){

	issuedWarp = warp;
}

unsigned Wrc::retIssuedWarp(){

	return issuedWarp;
}

bool Wrc::retSatFlag(){


	return memory_saturation_flag;

}

void Wrc::setSatFlag(bool satFlag){


	memory_saturation_flag = satFlag;

}
	


