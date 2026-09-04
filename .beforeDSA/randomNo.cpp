#include<bits/stdc++.h>
using namespace std;

bool perfectNumber(int n){
    int sum = 1;
    if(n == 1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n % i == 0){
            sum += i;
        }
    }
    if(sum == n){
        return true;
    }
    return false;
}

int main(){
    cout << perfectNumber(28);
}