/*
 Problem: LeetCode 125 - Valid Palindrome
 Pattern: Two Pointers (Inward Scan)
 * Concept:
    To check for symmetry without wasting extra memory, we place a 'left' pointer
    at the start of the string and a 'right' pointer at the end. We move them
    inward simultaneously, comparing characters.
 Crucial Mechanics:
    1. Skipping Non-Alphanumeric: We use nested while-loops with `!isalnum()` to
        instantly skip over spaces, punctuation, and symbols without processing them.
    2. Case Insensitivity: We wrap characters in `tolower()` during the comparison
        step so uppercase and lowercase letters are treated identically.
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

/*
* Complexity:
- Time Complexity: O(N) -> In the worst-case scenario, the pointers traverse the
string exactly once.
- Space Complexity: O(1) -> Zero extra arrays or strings are created. The data
is evaluated entirely in place using two integer variables.
*/