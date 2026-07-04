#include <bits/stdc++.h>
using namespace std;

bool isIsometric(string s , string t){
    if(s.length() != t.length()) return false;
    
    unordered_map<char,char> mapStoT;
    unordered_map<char,char> mapTtoS;
    
    for(int i = 0 ; i < s.length() ; i++){
        char S = s[i];
        char T = t[i];
        if(mapStoT.count(S) == 1){
            if(mapStoT[S] != T){
                return false;
            }
        } else {
            mapStoT[S] = T;
        }
        if(mapTtoS.count(T) == 1){
            if(mapTtoS[T] != S){
                return false;
            }
        } else {
            mapTtoS[T] = S;
        }
    }
    return true;
}

int main(){
    cout << isIsometric("egg","add") << endl;
    cout << isIsometric("add","end");
    
}
