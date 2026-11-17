#include <iostream>
#include <vector>
using namespace std;
class sol{
public:
vector<int> lengthh(string s){
vector<int> v;
stack<int> st;
st.push(-1);
int size=0;
int max_size=0;
int leng=0;
bool inavlid= false;
for(int i=0; i<s.length(); i++){
if(s[i]=='('){
st.push(i);
size++;
max_size= max(size, max_size);
}
else{
st.pop();
size--;
if(st.empty()){
st.push(i);
inavlid= true;
}
else{
leng= max(leng, i- st.top());
}
}
}
if(st.size()>1){
inavlid= true;
}
if(inavlid) cout << "There is error in string!!"<<endl;
v.push_back(size);
v.push_back(leng);
return v ;
}
};
int main(){

sol sl;
string s = ")()())";
vector <int> v= sl.lengthh(s);
cout << "Lenght of maximum substring is:"<< v.back()<<endl;
cout << "Size of the stack grown is:"<< v.front()<<endl;
return 0;
}