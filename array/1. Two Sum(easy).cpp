/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

很简单的一题，类似的有部分和问题，可以回忆一下
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto n = nums.size();
        map<int, int> m;
        int i = 0;
        for(i = 0; i < n; ++i){
            if(m.count(target - nums[i]))
                break;
            else
                m[nums[i]] = i;
        }
    return vector<int>{i, m[target - nums[i]]};
    }
};