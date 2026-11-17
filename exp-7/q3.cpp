#include <iostream>
#include <stack>
#include <string>
using namespace std;
class postfix{
public:
int precedence(char c){
if (c == '^') return 3;
if (c == '*' || c == '/') return 2;
if (c == '+' || c == '-') return 1;
return 0;
}
string topostfix(string s){
stack<char> st;
string res = "";
for(int i = 0; i < s.length(); i++){
char c = s[i];
if(c == ' ') continue;
if(isalnum(c)){
while(i < s.length() && isalnum(s[i])){
res += s[i];
i++;
}
i--;
res += ' ';
}
else if(c == '(') st.push(c);
else if(c == ')'){
while(!st.empty() && st.top() != '('){
res += st.top();
res += ' ';
st.pop();
}
if(!st.empty()) st.pop();
}
else{
while(!st.empty() && st.top() != '(' &&
(precedence(st.top()) > precedence(c) ||
(precedence(st.top()) == precedence(c) && c != '^'))){
res += st.top();
res += ' ';
st.pop();
}
st.push(c);
}
}
while(!st.empty()){
res += st.top();
res += ' ';
st.pop();
}
return res;
}
};
int main(){
postfix pf;
string s = "1*2^2^3/4*21 -(67*34/67)";
cout << pf.topostfix(s) << endl;
return 0;
}