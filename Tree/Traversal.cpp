// ---------------------------------PRE-ORDER---------------------------

vector<int> preorderTraversal(Node* root){
    vector<int> arr;
    preOrder(root, arr);
    return arr;
}

void preOrder(Node* root, vector<int> &arr){
    if(root == nullptr) return;

    arr.push_back(root->val, arr);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

// ---------------------------------IN-ORDER---------------------------

vector<int> inorderTraversal(Node* root){
    vector<int> arr;
    inOrder(root, arr);
    return arr;
}

void inOrder(Node* root, vector<int> &arr){
    if(root == nullptr) return;

    inOrder(root->left, arr);
    arr.push_back(root->val, arr);
    inOrder(root->right, arr);
}

// ---------------------------------POST-ORDER---------------------------

vector<int> postorderTraversal(Node* root){
    vector<int> arr;
    preOrder(root, arr);
    return arr;
}

void postOrder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    
    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->val, arr);
}

// --------------------------------Level-Order---------------------------

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}