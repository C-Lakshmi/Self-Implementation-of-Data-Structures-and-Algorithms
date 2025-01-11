using namespace std;
class Node {
    public:
    int val;
    struct Node *left, *right;
    Node(): left(nullptr), right(nullptr){}
};

class BST {
private: Node* root;
public:
BST(Node* Root) {
    root=Root;
}
Node* createNode(int item) {
    Node* temp = new Node;
    temp->val = item;
    temp->left = temp->right = nullptr;
    return temp;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout<<root->val<<" ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}

Node* insertNode(Node* node, int value) {
    if (node == nullptr)
        return createNode(value);

    if (value < node->val)
        node->left = insertNode(node->left, value);
    else
        node->right = insertNode(node->right, value);

    return node;
}

void searchNode(Node* node, int value) {
    if (node == nullptr)
        cout<<"Value Not Found"<<endl;
    else if (node->val==value) { cout<<"Value Found"<<endl; return; }
    else if (value < node->val) searchNode(node->left, value);
    else searchNode(node->right, value);
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
    } else {
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->val = succ->val;

        delete succ;
        return root;
    }
}
};