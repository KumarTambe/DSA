/*
 Problem: LeetCode 125 - Valid Palindrome
 Pattern: Two Pointers (Inward Scan)
 * Concept:
    To check for symmetry without wasting extra memory, we place a 'left' pointer
    at the start of the string and a 'right' pointer at the end. We move them
    inward simultaneously, comparing characters.

 */

/*
* Complexity:
- Time Complexity: O(N) -> In the worst-case scenario, the pointers traverse the
string exactly once.
- Space Complexity: O(1) -> Zero extra arrays or strings are created. The data
is evaluated entirely in place using two integer variables.
*/

#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Skip invalid characters from the left end
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        // Skip invalid characters from the right end
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Match check after converting to a uniform case
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
