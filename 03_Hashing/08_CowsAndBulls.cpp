#include<bits/stdc++.h>
using namespace std;

string cowsAndBulls(string secret, string guess){
    int bulls = 0, cows = 0;
    unordered_map<char,int> secretFreq,guessFreq;
    for(int i=0;i<num.size();i++){
        if(secret[i] == guess[i]){
            bulls++;
        } else {
            secretFreq[secret[i]]++;
            guessFreq[guess[i]]++;
        }
    }
    for(auto x : secretFreq){
        if(guessFreq.count(x.first)){
            cows += min(x.second, map[guessFreq[x.first]]);
        }
    }
    return to_string(bulls)+"A"+to_string(cows)+"B";
}

int main(){
    cout << cowsAndBulls("1122","1221");
}