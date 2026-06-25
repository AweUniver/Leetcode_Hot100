#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    //两数之和
    vector<int> twoSum(vector<int>& nums, int target);

    // 移动0
    void moveZeroes(vector<int>& nums);

    //字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string>& strs);

    //最长连续序列
    int longestConsecutive(vector<int>& nums);
};