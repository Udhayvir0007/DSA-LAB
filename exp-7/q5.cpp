#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    multiset<int> w(workers.begin(), workers.end());
int p = pills;
for(int i = mid - 1; i >= 0; i--) {
auto it = prev(w.end());
if(*it >= tasks[i]) {
w.erase(it);
} else {
auto it2 = w.lower_bound(tasks[i] - strength);
if(it2 == w.end() || p == 0) return false;
p--;
w.erase(it2);
}
}
return true;
}
int main() {
vector<int> tasks = {3, 2, 1};
vector<int> workers = {0, 3, 3};
int pills = 1, strength = 1;
sort(tasks.begin(), tasks.end());
sort(workers.begin(), workers.end());
int l = 0, r = min(tasks.size(), workers.size()), ans = 0;
while(l <= r) {
int mid = l + (r - l) / 2;
if(check(mid, tasks, workers, pills, strength)) {
ans = mid;
l = mid + 1;
} else {
r = mid - 1;
}
}
cout << "Max tasks completed: " << ans << endl;
return 0;
}