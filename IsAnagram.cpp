#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Description:
 * - Checks if two strings `s` and `t` are anagrams by sorting and comparing.
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main()
{
    Solution solution;
    string s = "anagram";
    string t = "nagaram";

    if (solution.isAnagram(s, t))
    {
        cout << "The strings are anagrams!" << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
