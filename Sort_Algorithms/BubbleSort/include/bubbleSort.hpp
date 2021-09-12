#include <vector>

using TIntVec = std::vector<int>;

class bubbleSort {
public:
	bubbleSort(const TIntVec&);
    TIntVec sortVec(const TIntVec&);          //sorts the vector ascending
private:
	void printResVec(const TIntVec&);         //prints the vector
};
