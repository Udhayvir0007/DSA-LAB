#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    bool isLeftThread;
    bool isRightThread;

    Node(int v) : val(v), left(nullptr), right(nullptr), isLeftThread(false), isRightThread(false) {}
};

class SearchEngineIndex {
private:
    Node* root;

    Node* insertBST(Node* curr, int val) {
        if (!curr) return new Node(val);
        if (val < curr->val) curr->left = insertBST(curr->left, val);
        else if (val > curr->val) curr->right = insertBST(curr->right, val);
        return curr;
    }

    void convertUtil(Node* curr, Node*& prev) {
        if (!curr) return;
        if (!curr->isLeftThread && curr->left) convertUtil(curr->left, prev);

        if (!curr->left) {
            curr->left = prev;
            curr->isLeftThread = true;
        }
        if (prev && !prev->right) {
            prev->right = curr;
            prev->isRightThread = true;
        }
        prev = curr;

        if (!curr->isRightThread && curr->right) convertUtil(curr->right, prev);
    }

    Node* findNode(Node* curr, int x) {
        while (curr) {
            if (curr->val == x) return curr;
            if (x < curr->val) {
                if (curr->isLeftThread) break;
                curr = curr->left;
            } else {
                if (curr->isRightThread) break;
                curr = curr->right;
            }
        }
        return nullptr;
    }

    Node* getLeftmost(Node* curr) {
        while (curr && !curr->isLeftThread && curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* getRightmost(Node* curr) {
        while (curr && !curr->isRightThread && curr->right) {
            curr = curr->right;
        }
        return curr;
    }

public:
    SearchEngineIndex() : root(nullptr) {}

    void build(const vector<int>& scores) {
        for (int s : scores) {
            root = insertBST(root, s);
        }
    }

    void convert() {
        Node* prev = nullptr;
        convertUtil(root, prev);
    }

    Node* getSuccessor(int x) {
        Node* curr = findNode(root, x);
        if (!curr) return nullptr;

        if (curr->isRightThread) {
            return curr->right;
        }
        return getLeftmost(curr->right);
    }

    Node* getPredecessor(int x) {
        Node* curr = findNode(root, x);
        if (!curr) return nullptr;

        if (curr->isLeftThread) {
            return curr->left;
        }
        return getRightmost(curr->left);
    }

    vector<int> getRange(int L, int R) {
        vector<int> result;
        Node* curr = root;
        Node* firstInRange = nullptr;

        while (curr) {
            if (curr->val >= L) {
                firstInRange = curr;
                if (curr->isLeftThread) break;
                curr = curr->left;
            } else {
                if (curr->isRightThread) break;
                curr = curr->right;
            }
        }

        curr = firstInRange;
        while (curr && curr->val <= R) {
            result.push_back(curr->val);
            if (curr->isRightThread) {
                curr = curr->right;
            } else {
                curr = getLeftmost(curr->right);
            }
        }
        return result;
    }

    int getKthSmallest(int k) {
        Node* curr = getLeftmost(root);
        int count = 0;
        while (curr) {
            count++;
            if (count == k) return curr->val;
            
            if (curr->isRightThread) {
                curr = curr->right;
            } else {
                curr = getLeftmost(curr->right);
            }
        }
        return -1; 
    }
};

int main() {
    SearchEngineIndex engine;
    vector<int> scores = {40, 20, 60, 10, 30, 50, 70};

    engine.build(scores);
    engine.convert();

    cout << "NEXT 30 = ";
    Node* succ = engine.getSuccessor(30);
    if (succ) cout << succ->val << endl; else cout << "NULL\n";

    cout << "PREV 30 = ";
    Node* pred = engine.getPredecessor(30);
    if (pred) cout << pred->val << endl; else cout << "NULL\n";

    cout << "RANGE = [";
    vector<int> rangeRes = engine.getRange(25, 60);
    for (int i = 0; i < rangeRes.size(); i++) {
        cout << " " << rangeRes[i] << (i + 1 == rangeRes.size() ? " " : ",");
    }
    cout << "]\n";

    cout << "KTH 5 = " << engine.getKthSmallest(5) << endl;

    return 0;
}