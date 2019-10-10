/usr/adityakaushal/Documents/Programs
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = tmp->right = nullptr;
    return tmp;
}

class Trees
{
public:
    Node *root;
    Trees()
    {
        root = nullptr;
    }
    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void postOrder(Node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }
    void inOrder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    Node *findLCA(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return nullptr;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        Node *left_lca = findLCA(root->left, n1, n2);
        Node *right_lca = findLCA(root->right, n1, n2);

        if (left_lca && right_lca) //when returning 1 then return root.s
        {
            return root;
        }
        return (left_lca != NULL) ? left_lca : right_lca;
    }
};

int main()
{
    Trees t;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);
    
    cout<<"inOrder Traversal"<< ": ";
    t.inOrder(root);
    cout << endl;
    cout<<"preOrder Traversal"<<": ";
    t.preOrder(root);
    cout << endl;
    cout<<"postOrder Traversal"<<": ";
    t.postOrder(root);
    cout << endl;
    int n1, n2;
    cin >> n1 >> n2;
    Node *tmp = t.findLCA(root, n1, n2);
    cout << tmp->data << endl;
    cout << endl;
    return 0;
}
