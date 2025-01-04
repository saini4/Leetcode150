#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Description:
 * - Checks if there are duplicates in the `nums` vector using an unordered set.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 2};

    if (solution.containsDuplicate(nums))
    {
        cout << "Duplicate found!" << endl;
    }
    else
    {
        cout << "No duplicates." << endl;
    }

    return 0;
}
