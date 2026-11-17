#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
int n, k;
cout << "Enter size: ";
cin >> n;
vector<int> stress(n);
cout << "Enter stress values: ";
for(int i = 0; i < n; i++) cin >> stress[i];
cout << "Enter K: ";
cin >> k;
deque<int> max_q, min_q;
int l = 0, ans = 0;
for(int r = 0; r < n; r++) {
while(!max_q.empty() && stress[max_q.back()] <= stress[r]) max_q.pop_back();
max_q.push_back(r);
while(!min_q.empty() && stress[min_q.back()] >= stress[r]) min_q.pop_back();
min_q.push_back(r);
while(stress[max_q.front()] - stress[min_q.front()] > k) {
l++;
if(max_q.front() < l) max_q.pop_front();
if(min_q.front() < l) min_q.pop_front();
}
ans = max(ans, r - l + 1);
}
cout << "Max consecutive passengers: " << ans << endl;
return 0;
}