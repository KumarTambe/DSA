#include<bits/stdc++.h>
using namespace std;

int calculateNumber(int n){
    int newNum = 0;
    while(n != 0){
        int digit = n % 10;
        newNum += digit * digit;
        n /= 10;
    }
    return newNum;
}


bool happyNumber(int n){
    unordered_set<int> set;
    while (n != 1 ){
        if(set.count(n)==1){
            return false;
        } else {
            set.insert(n);
            n = calculateNumber(n);
        }
    }
    return true;
}

int main(){
    cout << happyNumber(7);
}