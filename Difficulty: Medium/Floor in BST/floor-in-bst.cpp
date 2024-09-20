//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        if(root==nullptr) return -1;
        Node* mover=root;
        Node* mark=root;
        while(mover){
            if(mover->data==x) return x;
            if(mover->data>x && mover->left){
                mover=mover->left;
            }
            else if(mover->data<x && mover->right){
                mark=mover;
                mover=mover->right;
            }
            else if(mover->data<x){
                return mover->data;
            }
            else{
                if(mark->data<x){
                    return mark->data;
                    
                }
                else{
                    return -1;
                }
            }
        }
        return root->data;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends