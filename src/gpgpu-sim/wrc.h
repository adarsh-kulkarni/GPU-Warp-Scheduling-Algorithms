#ifndef WRC_H
#define WRC_H

class Wrc{

	public:
	
		//Constructor
		Wrc();

		
		//Destructor
		~Wrc();
	
		void setIssuedWarp (unsigned warp); 
				
		unsigned retIssuedWarp ();

		bool retSatFlag();

		void setSatFlag(bool satFlag);
	
	private:
		
		//Accessed by the WST. Used for stalling the warp
		unsigned issuedWarp;	


		//Signal from the L1 Cache indicating memory resources are depleting :)
		bool memory_saturation_flag;
		
	
};

#endif
