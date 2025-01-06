
/**
 * This solution finds the longest common prefix in a list of strings.
 * The approach starts with the first string in the list and progressively shortens it until it is a common prefix
 * for all the other strings in the list. It uses the `find()` method to check if the prefix is at the start of each string.
 * 
 * Time Complexity:
 * - O(S), where S is the sum of the lengths of all strings in the list.
 *   - For each string, in the worst case, we check if the current prefix exists at the start of the string.
 *   - As the prefix shrinks, the number of comparisons decreases.
 * 
 * Space Complexity:
 * - O(1), not counting the input space, because we only use a few variables to store the prefix and iterate through the list.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};
int main()
{
    vector<string> strs{"flow", "flows", "flowing"};

    Solution solution;
    cout << solution.longestCommonPrefix(strs);

    return 0;
}