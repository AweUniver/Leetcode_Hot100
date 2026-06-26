#include "Solution.h"

using namespace std;

int main()
{
    Solution solution;

    //vector<int> vec = { 2,7,11,15 };
    //solution.twoSum(vec, 9);

    //vector<int> vec = { 0 };
    //vector<int> vec = { 0,1,0,3,12 };
    //solution.moveZeroes(vec);

    //vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
    //solution.groupAnagrams(vec);

    //vector<int> vec = { 1 };
    //solution.longestConsecutiveNew(vec);

    //vector<int> vec = { 8,7,2,1 };
    //solution.maxArea(vec);

    vector<int> vec = { -100,-70,-60,110,120,130,160 };
    solution.threeSum(vec);

    return 0;
}