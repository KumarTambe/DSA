#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote , string Magazine){
    unordered_map<char,int> map;
    for(int i = 0; i < Magazine.length(); i++){
        map[Magazine[i]]++;
    }
    for(int i = 0 ;i< ransomNote.length();i++){
        map[ransomNote[i]]--;
    }
    for(auto x : map){
        if(x.second < 0){
            return false;
        }
    }
    return true;
}

int main(){
    cout << canConstruct("aa","aab") << endl;
    cout << canConstruct("aa","ab");
}