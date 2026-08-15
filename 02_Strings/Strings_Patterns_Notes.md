# Strings — Complete Pattern Notes
# DSA Prep — Kumar, VJTI MCA 2027

---

## C++ String Basics

```cpp
string s = "hello";
s.length()          // or s.size() — same thing
s[i]                // access character at index i
s.substr(start, len) // substring starting at index, of given length
s.find("ll")        // returns index where substring starts, or string::npos
s + "world"         // concatenation
s[0] = 'H'          // strings are mutable in C++, direct char modification works
```

**Useful character functions:**
```cpp
isalnum(c)   // true if c is a letter or digit
isalpha(c)   // true if c is a letter
isdigit(c)   // true if c is a digit
tolower(c)   // converts char to lowercase
toupper(c)   // converts char to uppercase
```

---

## Pattern 1 — Two Pointer on Strings

### What is it?
Two index variables moving through a string — usually from opposite ends moving inward, or one from each string moving forward.

### When to use (trigger words):
- "check if palindrome"
- "reverse a string"
- "compare characters from both ends"
- "is X a subsequence of Y"

### Template — Reverse String (in-place):
```cpp
void reverseString(vector<char>& s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}
```

### Template — Check Palindrome (ignoring case and non-alphanumeric):
```cpp
bool isPalindrome(string s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        // skip non-alphanumeric on left
        while(left < right && !isalnum(s[left])) left++;
        // skip non-alphanumeric on right
        while(left < right && !isalnum(s[right])) right--;
        // compare lowercase versions
        if(tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}
```

### Template — Two Pointer on Two Strings (Is Subsequence):
```cpp
bool isSubsequence(string s, string t){
    if(s.length() == 0) return true; // empty string edge case
    int left = 0;  // pointer for s (shorter string)
    int right = 0; // pointer for t (longer string)
    for(int i = 0; i < t.length(); i++){
        if(s[left] == t[right]){
            left++;   // match found, advance both
        }
        right++;      // always advance right (t pointer)
        if(left == s.length()) return true; // all of s matched
    }
    return false;
}
```

### Key insights:
- Skip non-alphanumeric characters INDEPENDENTLY on each side
- For subsequence problems: right pointer always moves, left only moves on match
- Time: O(n), Space: O(1)

### Problems solved:
- LC #344 — Reverse String
- LC #125 — Valid Palindrome
- LC #392 — Is Subsequence

---

## Pattern 2 — Character Frequency Map

### What is it?
Count how many times each character appears using unordered_map. Then use those counts to answer questions about the string.

### When to use (trigger words):
- "check if anagram"
- "find most/least frequent character"
- "first unique character"
- "characters appear same number of times"

### unordered_map vs unordered_set reminder:
- unordered_set — use when you only need to know IF something exists
- unordered_map — use when you need to store a COUNT or VALUE alongside each character

### map.count(key) vs map[key]:
- map.count(key) — returns 0 or 1, checks if KEY EXISTS (not the value)
- map[key] — returns the actual VALUE stored for that key
- NEVER use map.count() to check frequency — use map[key] == 1 etc.

### Template — Valid Anagram (single map, increment/decrement):
```cpp
bool isAnagram(string s, string t){
    if(s.length() != t.length()) return false; // length check first
    unordered_map<char,int> freq;
    for(int i = 0; i < s.length(); i++){
        freq[s[i]]++;  // increment for s
        freq[t[i]]--;  // decrement for t
    }
    for(auto x : freq){
        if(x.second != 0) return false; // didn't cancel out
    }
    return true;
}
```

### Template — First Unique Character (two pass):
```cpp
int firstUniqChar(string s){
    unordered_map<char,int> freq;
    // pass 1: build frequency map
    for(int i = 0; i < s.length(); i++){
        freq[s[i]]++;
    }
    // pass 2: check original string ORDER (not map order — map has no order)
    for(int i = 0; i < s.length(); i++){
        if(freq[s[i]] == 1) return i; // first char with count 1
    }
    return -1;
}
```

### Key insights:
- unordered_map does NOT preserve insertion order — always loop through original string for order-dependent problems
- Two pass approach: build map first, then query it in string order
- Single map with increment/decrement is cleaner than two separate maps for anagram check
- Time: O(n), Space: O(n)

### Problems solved:
- LC #242 — Valid Anagram
- LC #387 — First Unique Character in a String

---

## Pattern 3 — Fixed Size Sliding Window

### What is it?
A window of FIXED size k slides through the string/array. Instead of recalculating the entire window each time, add the new element on the right and remove the element leaving on the left.

### When to use (trigger words):
- "find anagram occurrences"
- "window of exactly size k"
- "fixed length substring"

### When to shrink: use IF (not while)
Fixed window can only exceed size by exactly 1 per step — one if-check is enough.

### Template — Find All Anagrams:
```cpp
vector<int> findAnagrams(string s, string p){
    vector<int> result;
    unordered_map<char,int> pFreq, windowFreq;
    
    // build target frequency map once
    for(char c : p) pFreq[c]++;
    
    int left = 0;
    for(int right = 0; right < s.length(); right++){
        windowFreq[s[right]]++; // add new char
        
        if(right - left + 1 > p.length()){ // window too big
            windowFreq[s[left]]--;
            if(windowFreq[s[left]] == 0){
                windowFreq.erase(s[left]); // IMPORTANT: remove zero entries
            }
            left++;
        }
        
        if(windowFreq == pFreq){ // direct map comparison works in C++
            result.push_back(left);
        }
    }
    return result;
}
```

### Key insights:
- Remove zero-count entries from windowFreq — otherwise map comparison fails
- C++ unordered_map supports direct == comparison
- Window size is always p.length() — no variability
- Time: O(n), Space: O(n)

### Problems solved:
- LC #438 — Find All Anagrams in a String

---

## Pattern 4 — Variable Size Sliding Window

### What is it?
A window whose size changes dynamically based on a condition. Grows by moving right pointer forward, shrinks by moving left pointer forward when condition is violated.

### When to use (trigger words):
- "longest substring with [condition]"
- "longest substring without repeating characters"
- "at most K distinct characters"
- "smallest substring containing..."

### When to shrink: use WHILE (not if)
Variable window may need to shrink multiple times before condition is restored — while loop keeps shrinking until valid.

### Fixed vs Variable — the key distinction:
- Fixed size window → IF to maintain exact size
- Variable size window → WHILE to shrink until condition satisfied

### Template — Longest Substring Without Repeating Characters:
```cpp
int lengthOfLongestSubstring(string s){
    unordered_set<char> window; // use SET for existence check only
    int left = 0;
    int maxLength = 0;
    
    for(int right = 0; right < s.length(); right++){
        // shrink window until no duplicate
        while(window.count(s[right]) == 1){
            window.erase(s[left]); // remove leftmost char
            left++;
        }
        window.insert(s[right]); // always insert AFTER while loop (not in else)
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}
```

### Key insights:
- Insert is ALWAYS unconditional after the while loop — not in an else branch
- Use unordered_set (not map) when you only need existence check
- Window length formula: right - left + 1
- Time: O(n) — each element added and removed at most once
- Space: O(n) — set can hold up to n characters
- Common mistake: using IF instead of WHILE causes incorrect shrinking

### Problems solved:
- LC #3 — Longest Substring Without Repeating Characters

---

## Pattern 5 — Expand Around Center

### What is it?
For palindrome problems, instead of checking every possible substring (O(n³)), pick each character as a potential center and expand outward as long as characters match on both sides.

### When to use (trigger words):
- "longest palindromic substring"
- "count palindromic substrings"
- "find all palindromes"

### Two types of centers (IMPORTANT):
- Odd length palindromes: single character center — "racecar" center is 'e'
- Even length palindromes: two character center — "abba" center is between 'b' and 'b'
- Must check BOTH for every position

### Template — expand helper function:
```cpp
int expand(string& s, int left, int right){
    // bounds check MUST come before character comparison
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    // when loop exits, left and right are ONE STEP outside the palindrome
    // length = right - left - 1 (not +1, because both pointers overshot)
    return right - left - 1;
}
```

### Why right - left - 1 and not + 1?
When loop exits, left is one position BEFORE the palindrome starts, and right is one position AFTER it ends. So actual length = right - left - 1.

### Template — Longest Palindromic Substring:
```cpp
string longestPalindrome(string s){
    int start = 0;
    int maxLen = 1; // minimum palindrome is single character
    
    for(int i = 0; i < s.length(); i++){
        int odd = expand(s, i, i);     // odd length — single center
        int even = expand(s, i, i+1);  // even length — two char center
        
        if(odd > maxLen){
            maxLen = odd;
            start = i - (odd-1)/2;     // start of odd palindrome
        }
        if(even > maxLen){
            maxLen = even;
            start = i - (even/2) + 1;  // start of even palindrome
        }
    }
    return s.substr(start, maxLen);
}
```

### Key insights:
- Always check both odd and even centers at every position
- Bounds check before character comparison in while condition
- Time: O(n²) — n centers, each expansion up to O(n)
- Space: O(1) — no extra data structure

### Problems solved:
- LC #5 — Longest Palindromic Substring

---

## Complexity Summary

| Pattern | Time | Space |
|---|---|---|
| Two Pointer | O(n) | O(1) |
| Character Frequency Map | O(n) | O(n) |
| Fixed Sliding Window | O(n) | O(n) |
| Variable Sliding Window | O(n) | O(n) |
| Expand Around Center | O(n²) | O(1) |

---

## Common Mistakes — Strings

1. Using map.count() to check frequency — it checks KEY EXISTENCE, not value
2. Looping through map for order-dependent problems — map has no order, loop through original string
3. Using IF instead of WHILE for variable sliding window shrinking
4. Putting insert inside else branch in sliding window — always insert unconditionally after while loop
5. Forgetting to erase zero-count entries when comparing maps
6. Not handling edge cases: empty string, single character, all same characters
7. Bounds check order in expand — check left>=0 and right<length BEFORE s[left]==s[right]
8. Using right - left + 1 instead of right - left - 1 in expand helper

---

## Problems Solved — Strings (7 total)

| # | Problem | LC # | Pattern |
|---|---|---|---|
| 1 | Reverse String | #344 | Two Pointer |
| 2 | Valid Palindrome | #125 | Two Pointer |
| 3 | Valid Anagram | #242 | Character Frequency Map |
| 4 | First Unique Character | #387 | Character Frequency Map |
| 5 | Longest Substring No Repeat | #3 | Variable Sliding Window |
| 6 | Find All Anagrams | #438 | Fixed Sliding Window |
| 7 | Longest Palindromic Substring | #5 | Expand Around Center |

---
