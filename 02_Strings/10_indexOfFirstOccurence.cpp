#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
        int n = needle.size();
        for(int i=0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                int startingPoint = i;
                int right = i;
                int j = 0;
                while(right < haystack.size() && j < needle.size() && haystack[right] == needle[j]){
                    right++;
                    j++;
                }
                if(j==n){
                    return startingPoint;
                }
            }
        } 
        return -1;
    }
