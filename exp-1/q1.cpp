#include <iostream>
using namespace std;

void arrange(int n, vector<int> &v) {
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (v[i] >= 0)
            pos.push_back(v[i]);
        else
            neg.push_back(v[i]);
    }

    int p = 0, q = 0;

    for (int i = 0; i < n; i += 2) {
        v[i] = pos[p++];
        if (i + 1 < n)
            v[i + 1] = neg[q++];
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    arrange(n, v);

    cout << "Rearranged array:\n";
    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}