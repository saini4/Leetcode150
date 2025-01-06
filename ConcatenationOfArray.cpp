/*
 * Description:
 * - The function `repeatArray` takes a vector `nums` as input and returns a new vector where the elements of `nums` are repeated twice in order.
 * - It uses the modulo operation (`i % n`) to wrap around the indices and repeat the array.

 * Time Complexity:
 * - O(n) where `n` is the size of the input vector `nums`. The loop runs for `2 * n` iterations, but the operations inside the loop are O(1).

 * Space Complexity:
 * - O(n) where `n` is the size of the input vector `nums`. The result vector `ans` stores `2 * n` elements.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> repeatArray(const vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < (2 * n); i++)
        {
            ans.push_back(nums[i % n]);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> ans = solution.repeatArray(nums);

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
