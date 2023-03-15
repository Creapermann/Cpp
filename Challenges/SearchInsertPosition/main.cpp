#include <iostream>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target);
};


int Solution::searchInsert(std::vector<int>& nums, int target)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] >= target)
            return i;
    }

    return nums.size();
}



int main()
{
    std::vector<int> data = { 1,3,5,6 };
    int target = 7;

    Solution solution;
    std::cout << solution.searchInsert(data, target) << "\n";

    return 1;
}