#include <iostream>

using namespace std;

// Definition of a tree node
class TreeNode {
public:
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int v) : value(v) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree {
private:
    TreeNode* root = nullptr;

    void insert(int v, TreeNode*& subtree) {
        if (subtree == nullptr) {
            subtree = new TreeNode(v);
        } else if (v < subtree->value) {
            insert(v, subtree->left);
        } else {
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const {
        if (!subtree) return;
        cout << subtree->value << " ";
        preOrderTraversal(subtree->left);
        preOrderTraversal(subtree->right);
    }

    void inOrderTraversal(TreeNode* subtree) const {
        if (!subtree) return;
        inOrderTraversal(subtree->left);
        cout << subtree->value << " ";
        inOrderTraversal(subtree->right);
    }

    void postOrderTraversal(TreeNode* subtree) const {
        if (!subtree) return;
        postOrderTraversal(subtree->left);
        postOrderTraversal(subtree->right);
        cout << subtree->value << " ";
    }

    int min(TreeNode* subtree) const {
        while (subtree->left != nullptr)
            subtree = subtree->left;
        return subtree->value;
    }

    int max(TreeNode* subtree) const {
        while (subtree->right != nullptr)
            subtree = subtree->right;
        return subtree->value;
    }

    bool contains(int value, TreeNode* subtree) const {
        if (!subtree) return false;
        if (value == subtree->value) return true;
        if (value < subtree->value) return contains(value, subtree->left);
        return contains(value, subtree->right);
    }

    void remove(int value, TreeNode*& subtree) {
        if (!subtree) return;

        if (value < subtree->value) {
            remove(value, subtree->left);
        } else if (value > subtree->value) {
            remove(value, subtree->right);
        } else {
            
            if (!subtree->left && !subtree->right) {
                delete subtree;
                subtree = nullptr;
            }
            
            else if (!subtree->left) {
                TreeNode* temp = subtree;
                subtree = subtree->right;
                temp->right = nullptr;
                delete temp;
            } else if (!subtree->right) {
                TreeNode* temp = subtree;
                subtree = subtree->left;
                temp->left = nullptr;
                delete temp;
            }
            
            else {
                TreeNode* successor = subtree->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                subtree->value = successor->value;
                remove(successor->value, subtree->right);
            }
        }
    }

public:
    void insert(int value) {
        insert(value, root);
    }

    void preOrderTraversal() const {
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal() const {
        inOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal() const {
        postOrderTraversal(root);
        cout << endl;
    }

    int min() const {
        return min(root);
    }

    int max() const {
        return max(root);
    }

    bool contains(int value) const {
        return contains(value, root);
    }

    void remove(int value) {
        remove(value, root);
    }

    ~Tree() {
        delete root;
    }
};


int main() {
    Tree t;
    int value;

    cout << "Enter values to insert (-1 to stop): ";
    while (cin >> value && value != -1) {
        t.insert(value);
    }

    cout << "\nEnter values to delete (-1 to stop): ";
    while (cin >> value && value != -1) {
        t.remove(value);
        cout << "Pre-order: ";
        t.preOrderTraversal();
        cout << "In-order: ";
        t.inOrderTraversal();
        cout << "Post-order: ";
        t.postOrderTraversal();
        cout << endl;
    }

    return 0;
}
