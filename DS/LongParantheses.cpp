#include<bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {

    stack< int > stack;
    stack.push(-1);

    int ans = 0, n=s.size();

    for (int i=0; i<n; i++){

        if (s[i]=='('){
            stack.push(i);
        }
        else{
            stack.pop();

            if (stack.empty()) stack.push(i);
            else ans = max(ans, i - stack.top());
        }
    }

    return ans;
}

int main() {
    string brackets = ")()))((()()()))";

    cout << "Size of Longest Valid Substing of parantheses in "
         << brackets << " is: " << longestValidParentheses(brackets) << endl;
    return 0;
}
