#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    /*******哈希********/
    //两数之和
    vector<int> twoSum(vector<int>& nums, int target);

    //字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string>& strs);

    //最长连续序列
    int longestConsecutive(vector<int>& nums);
    int longestConsecutiveNew(vector<int>& nums);

    /*******双指针********/

    // 移动0
    void moveZeroes(vector<int>& nums);

    //盛最多水的容器
    int maxArea(vector<int>& height);

    // 三数之和
    vector<vector<int>> threeSum(vector<int>& nums);
};