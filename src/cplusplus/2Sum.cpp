// Source : https://leetcode.com/problems/two-sum
// Author : eshenhu
// Date   : 2018-09-05

/********************************************************************************** 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
************************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        
        int index = 0;
        std::for_each(nums.begin(), nums.end(), [&](int &n){
            map.emplace(n, index++);
        });
        
        index = 0;      
        std::vector<int> value; 
        
        std::for_each(nums.begin(), nums.end(), [&](int& n){
            auto iter = map.find(target - n);
            if (iter != map.end())
                value = {index, iter->second};
            ++index;
        });
        
        if (!value.empty())
            return value;
        else
            throw std::runtime_error("not found");
    }
};
 
int main() 
{
    std::vector<int> test{2,5,7,10};
    Solution s = Solution();
    auto v = s.twoSum(test, 9);
    
    for(int n : v) {
        std::cout << "-" << n;
    }
    std::cout << std::endl;
}
