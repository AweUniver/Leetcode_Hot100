#include "Solution.h"
#include <algorithm>

#include <unordered_set>
#include <set>

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
    vector<vector<string>> res;
    std::unordered_map<string, vector<string>> map;

    if (strs.size() == 1)
    {
        res.push_back(strs);
        return res;
    }

    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());

        auto it = map.find(s);
        if (it != map.end())
        {
            it->second.push_back(strs[i]);
        }
        else
        {
            map[s] = { strs[i] };
        }
    }

    for (auto& pair : map)
    {
        res.push_back(pair.second);
    }

    return res;
}

int Solution::longestConsecutive(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    //sort(nums.begin(), nums.end());
    set<int> set(nums.begin(), nums.end());
    int max = 1;
    int flag = 1;
    int size = set.size();

    for (auto it = set.begin(); it != set.end(); )
    {
        auto a = *it + 1;
        ++it;               // 先推进迭代器
        if (it == set.end())
        {
            break;          // 到达末尾，不再取第二个元素，直接结束
        }
        auto b = *it;       // 此时解引用是安全的
        if (a == b)
        {
            flag++;
        }
        else
        {
            flag = 1;
        }

        max = flag > max ? flag : max;
    }

    return max;
}

int Solution::longestConsecutiveNew(vector<int>& nums)
{
std:unordered_set<int> set(nums.begin(), nums.end());

    int max = 0;

    for (auto& num : set)
    {
        int len = 1;
        auto it = set.find(num - 1);

        // 找起始数，找到后进行 对起始数进行num + length的查找。
        if (it == set.end())
        {
            while (1)
            {
                if (set.find(num + len) == set.end())
                    break;
                len++;
            }
            max = len > max ? len : max;
        }
        else
        {
            continue;
        }
    }

    return max;
}