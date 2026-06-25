#include "Solution.h"
#include <algorithm>
#include <map>

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    //hashmap解法：map的key存放值，map的value存放下标。通过find查找map内是否已有target-当前值的数值，来找到下标。

    std::unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = hashmap.find(target - nums[i]);

        if (it != hashmap.end())
        {
            return { it->second,i };
        }

        hashmap[nums[i]] = i;
    }

    return {  };
}

void Solution::moveZeroes(vector<int>& nums)
{
    int i = 0;
    int size = nums.size();
    int start = 0;

    // 找到第一个0开始的地方
    while (nums[start] != 0 && start != size)
    {
        start++;
        if (start == size)
        {
            return;
        }
    }

    int flag = start;

    for (i = start; i < size; i++)
    {
        // 右指针  等于0继续往后走
        if (nums[i] == 0)
        {
            continue;
        }
        else
        {
            // 不等于0时，右指针跟左指针交换，左指针往后走到0处

            nums[flag] = nums[i];
            nums[i] = 0;

            while (nums[flag] != 0 && flag != size)
            {
                flag++;
            }
        }
    }
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
    std::multimap<string, string> multimap;
    vector<string> key;
    vector<vector<string>> res;

    if (strs.size() == 1)
    {
        res.push_back(strs);
        return res;
    }

    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());

        auto it = multimap.find(s);
        if (it == multimap.end())
        {
            key.push_back(s);
        }

        multimap.insert(std::make_pair(s, strs[i]));
    }

    for (string str : key)
    {
        std::multimap<string, string>::iterator m;
        std::multimap<string, string>::iterator beg = multimap.lower_bound(str);
        std::multimap<string, string>::iterator end = multimap.upper_bound(str);

        vector<string> strRes;

        for (m = beg; m != end; m++)
        {
            strRes.push_back(m->second);
        }

        res.push_back(strRes);
    }

    return res;
}

vector<vector<string>> Solution::groupAnagramsNew(vector<string>& strs)
{
    return vector<vector<string>>();
}