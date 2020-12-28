#include "diffOfTwo.hpp"
#include <algorithm>
#include <iostream>


//Constructor
diffOfTwo::diffOfTwo(const TIntVec& mainVec) {
	auto PairVec = initPairVec(mainVec);
	auto resVec = eraseUnnesecary(PairVec);
	printRes(resVec);
}



//Methods
TOptIntPairVec diffOfTwo::initPairVec(const TIntVec& mainVec) {

	TOptIntPairVec pairVec(mainVec.size());                     /*important to alloc the size of the Vector, else you get a error code because the transform 
																method doesnt know where to start because it doesnt know if v.begin() even exists*/ 

	std::transform(mainVec.begin(), mainVec.end(), pairVec.begin(), [mainVec = mainVec](auto e) -> TOptIntPair {

		auto temp = TOptIntPair();                                                                //creates a temperary Optional-Int-Pair
 
		auto it = std::find_if(mainVec.begin(), mainVec.end(), [e = e](auto o) -> bool {          //srches for any elem of the vector which - 2 with another equals 2
			if (o - e == 2)
				return true;
			else
				return false;
			});

		if (it != mainVec.end()) {                                                                //if a elem which - 2 with another elem == 2, temp gets inited to these two, else
			temp = { e, *it };                                                                    //it stays empty (optionals can be checked if they contain smth or not)
		}

		return temp;                                                                              //returns previous created "temp" to another Vec "pairVec" (3rd argument of std::transform)
		});

	return pairVec;
}

TOptIntPairVec diffOfTwo::eraseUnnesecary(const TOptIntPairVec& pairVec) {

	auto pairVecCopy = pairVec;

	auto itToPartEnd = std::partition(pairVecCopy.begin(), pairVecCopy.end(), [](auto& o) -> bool {          //does a partition with the elements of "pairVecCopy"
		if (o)																					             //it's getting devided by the "question" if the certain obj of the vector
			return true;																					 //contains anything. It is optional, so it doesnt need to contain anything
		else
			return false;
		});


	pairVecCopy.erase(itToPartEnd, pairVecCopy.end());                                                        //previous from the vector devided objects are getting erased

	return pairVecCopy;
}



void diffOfTwo::printRes(const TOptIntPairVec& optPairVec) {

	
	//transfroming from TOptIntPairVec to TIntPairVec cause you cant acess the individ. elements of optPairs "!(o.first)" what you need to print the vector out
	auto resPairVec = convOptVecToNonOptVec(optPairVec);
	

	for (auto& o : resPairVec) {
		std::cout << o.first << " " << o.second << std::endl;
	}
}

TIntPairVec diffOfTwo::convOptVecToNonOptVec(const TOptIntPairVec& optPairVec) {

	TIntPairVec resPairVec(optPairVec.size());                              //the size of the vector needs to get allocated! 
	
	std::transform(optPairVec.begin(), optPairVec.end(), resPairVec.begin(), [](auto& e) -> TIntPair {

		return *e;                                                          //optionals work similar to pointers, so you are able to dereference them and pass their
																			//values to another also non-optional, in this case std::pair<int>
		});

	return resPairVec;
}