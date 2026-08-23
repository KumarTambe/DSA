#include<bits/stdc++.h>
using namespace std;
int ReversePolish(vector<string>&tokens) {
	stack<int> st;
	int result = 0;
	for(string token : tokens) {
		if(token == "+" || token == "-" || token == "*" || token == "/") {
			int b = st.top();st.pop();
			int a = st.top();st.pop();
			if(token == "+") st.push(a + b);
			else if(token == "-") st.push(a - b);
			else if(token == "*") st.push(a * b);
			else if(token == "/") st.push(a / b);
		} else {
			st.push(stoi(token));
		}
	}
	return st.top();
}