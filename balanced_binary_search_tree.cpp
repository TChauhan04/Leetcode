 
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to perform inorder traversal and collect nodes
    void inorderTraversal(TreeNode* root, std::vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }

    // Function to build a balanced BST from a sorted array
    TreeNode* buildBalancedBST(const std::vector<int>& nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBalancedBST(nodes, start, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, end);
        return root;
    }

    // Function to convert a given BST to a balanced BST
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> nodes;
        inorderTraversal(root, nodes);
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
};

// Helper function to print inorder traversal of the BST
void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);

    std::cout << "Inorder traversal of the balanced BST: ";
    printInorder(balancedRoot);
    std::cout << std::endl;

    return 0;
}
