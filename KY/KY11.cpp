#include <iostream>
#include <string>
using namespace std;
int t;
string pre;
struct TreeNode{
    char val;
    TreeNode* left, *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* Create_Tree(){
    char c = pre[t++];
    //若是‘#’，说明该节点为空返回上一级节点
    if(c == '#') return NULL;
    TreeNode* root = new TreeNode(c);//若不是#，为本节点赋值
    root->left = Create_Tree();//递归创建左子树
    root->right = Create_Tree();//递归创建右子树
    return root;
}
void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
int main(){
    while(cin >> pre){
        t = 0;
        TreeNode* root = NULL;
        root = Create_Tree();
        inOrder(root);
        cout << endl;
    }
    return 0;
}