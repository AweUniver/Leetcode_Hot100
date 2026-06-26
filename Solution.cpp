#include "Solution.h"
#include <algorithm>

#include <unordered_set>
#include <set>
#include <functional>

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

    return {};
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
    std::unordered_set<int> set(nums.begin(), nums.end());

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

int Solution::maxArea(vector<int>& height)
{
    // 减少赋值操作会增加执行速度

    int maxArea = 0;
    int l = 0;
    int r = height.size() - 1;

    // 使用双指针。设置一个指针在数组的左侧，一个指向右侧。总是把指向短板的指针移动。
    // 移动长板，矩形的面积一定会变小，移动短板，矩形的面积可能会变大
    while (l < r)
    {
        int area = min(height[l], height[r]) * (r - l);
        maxArea = max(maxArea, area);

        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return maxArea;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    // 排序后，第一个数大于零总和不可能大于零
    if (nums[0] > 0)
    {
        return {};
    }

    int size = nums.size();
    vector<vector<int>> res;
    //res.reserve(size);

    for (int i = 0; i < size - 2; i++)
    {
        // 排过序，没必要用hash去重
        if (i && nums[i] == nums[i - 1])
        {
            continue;
        }

        int tar = nums[i] * (-1);
        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] < tar)
            {
                left++;
            }
            else if (nums[left] + nums[right] > tar)
            {
                right--;
            }
            else if (nums[left] + nums[right] == tar)
            {
                vector<int> vectar{ nums[left],nums[right],nums[i] };
                res.push_back(vectar);

                // 两个指针都满足条件，同时移动即可
                left++;
                right--;

                //去掉重复的结果
                while (left < right && nums[right] == nums[right + 1])
                {
                    right--;
                }

                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
        }
    }

    return res;
}

vector<int> Solution::inorderTraversal(TreeNode* root)
{
    vector<int> res;

    // auto 声明的 lambda，不能在内部调用自己
    // 先声明 std::function 确定类型，再让 lambda 引用捕获它，就能正常实现递归自调用。
    function<void(TreeNode*)> dfs;

    dfs = [&](TreeNode* node)
        {
            if (!node)
            {
                return;
            }

            // 中序遍历 左 根 右
            dfs(node->left);
            res.push_back(node->val);
            dfs(node->right);

            // 前序遍历  根 左 右
            //res.push_back(node->val);
            //dfs(node->left);
            //dfs(node->right);

            //后序遍历  左 右 根
            //dfs(node->left);
            //dfs(node->right);
            //res.push_back(node->val);
        };
    dfs(root);

    return res;
}