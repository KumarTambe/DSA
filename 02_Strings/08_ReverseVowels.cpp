#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string reverseVowels(string s){
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int left = 0;
    int right = s.length() - 1;
    while(left < right){
        while(left < right && vowels.count(s[left]) == 0){
            left++;
        }
        while(left < right && vowels.count(s[right]) == 0){
            right--;
        }
        swap(s[left],s[right]);
        left++;
        right--;
    }
    return s;
}

int main(){
    cout << reverseVowels("hello");
}