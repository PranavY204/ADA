/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool exists(struct TreeNode* root, int num){
    if (!root) return false;
    int temp = root->val;
    if (temp == num){
        return true;
    } else if (temp > num){
        return exists(root->left, num);
    } else if (temp < num){
        return exists(root->right, num);
    }
    return false;
}

void findComplement(struct TreeNode* head, struct TreeNode* root,  bool *res, int k){
    if (!root) return;
    if (*res) return;
    int temp = k - root->val;
    if (temp > root->val){
        if (exists(head, temp)){
            *res = true;
            return;
        }
    } else if (temp < root->val){
        if (exists(head, temp)){
            *res = true;
            return;
        }
    }
    findComplement(head, root->left, res, k);
    findComplement(head, root->right, res, k);
}
bool findTarget(struct TreeNode* root, int k) {
    if (!root) return false;
    bool res = false;
    findComplement(root, root, &res, k);
    return res;
}
