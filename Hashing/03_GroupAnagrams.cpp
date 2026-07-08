#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        for(int i = 0 ; i<strs.size();i++){
            string copy = strs[i];
            sort(copy.begin(),copy.end());
            map[copy].push_back(strs[i]);
        }
        for( auto x : map){
            result.push_back(x.second);
        }
    return result;
}