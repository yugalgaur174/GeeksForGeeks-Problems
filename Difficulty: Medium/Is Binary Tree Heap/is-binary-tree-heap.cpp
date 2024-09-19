//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int count(Node* node){
      if(node==nullptr){
          return 0;
          
      }
      int m=1+count(node->left)+count(node->right);
    //   queue<Node*> q;
    //   q.push(node);
    //   int m=0;
    //   while(!q.empty()){
    //       Node* mover=q.front();
    //       q.pop();
    //       m++;
    //       if(mover->left!=nullptr) q.push(mover->left);
    //       if(mover->right!=nullptr)q.push(mover->right);
          
    //   }
      return m;
  }
  bool isCbt(Node* node, int index, int c){
      if(node==nullptr) return true;
      if(index>=c) return false;
      else{
          bool left=isCbt(node->left,2*index+1,c);
          bool right=isCbt(node->right,2*index+2,c);
          return (left&&right);
      }
  }
  bool isMaxOrder(Node* node){
      if(node->left==nullptr && node->right==nullptr) return true;
      if(node->right==nullptr){
          return node->data>node->left->data;
      }
      else{
          return node->data>node->left->data && node->data>node->right->data && isMaxOrder(node->left)&& isMaxOrder(node->right);
      }
  }
    bool isHeap(struct Node* tree) {
        // code here
        if(tree==nullptr) return true;
        if(tree->left==nullptr && tree->right==nullptr) return true;
        int index=0;
        int c=count(tree);
        if(isCbt(tree, index,c) && isMaxOrder(tree)){
            return true;
        }
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends