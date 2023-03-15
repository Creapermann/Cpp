#include <algorithm>
#include <vector>
#include <iostream>


class Solution
{
public:
    void nextPermutation(std::vector<int>& nums);
};


void Solution::nextPermutation(std::vector<int>& nums)
{
    if(nums.size() == 1)
        return;

    if(nums.size() == 2)
    {
        if(nums[1] > nums[0])
            std::swap(nums[0], nums[1]);
        
        return;
    }
    
    
    for(int i = nums.size() - 1; i > 0; --i)
    {
        if(nums[])
    }
}


int main()
{
    Solution s;
    std::vector<int> val { 1 };
    s.nextPermutation(val);

    for(int i : val)
    {
        std::cout << i << '\n';
    }
}