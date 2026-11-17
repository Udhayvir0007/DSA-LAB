#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    bool isLeftThread;
    bool isRightThread;

    Node(int v) : val(v), left(nullptr), right(nullptr), isLeftThread(false), isRightThread(false) {}
};

class DoubleThreadedBinaryTree {
private:
    void convertUtil(Node* curr, Node*& prev) {
        if (!curr) return;

        if (!curr->isLeftThread && curr->left) {
            convertUtil(curr->left, prev);
        }
        if (!curr->left) {
            curr->left = prev;
            curr->isLeftThread = true;
        }
        if (prev && !prev->right) {
            prev->right = curr;
            prev->isRightThread = true;
        }

        prev = curr;
        if (!curr->isRightThread && curr->right) {
            convertUtil(curr->right, prev);
        }
    }

public:
    void convertToDoubleThreaded(Node* root) {
        if (!root) return;
        Node* prev = nullptr;
        convertUtil(root, prev);
    }

    void inorderTraversal(Node* root) {
        if (!root) return;

        Node* curr = root;
        while (curr && !curr->isLeftThread && curr->left) {
            curr = curr->left;
        }

        while (curr != nullptr) {
            cout << curr->val << " ";

            if (curr->isRightThread) {
                curr = curr->right;
            } 
            else {
                curr = curr->right;
                while (curr && !curr->isLeftThread && curr->left) {
                    curr = curr->left;
                }
            }
        }
        cout << endl;
    }
};

int main() {

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    DoubleThreadedBinaryTree dtbt;

    dtbt.convertToDoubleThreaded(root);
    cout << "Inorder Traversal (Stackless & Recursionless): ";
    dtbt.inorderTraversal(root); 
    return 0;
}