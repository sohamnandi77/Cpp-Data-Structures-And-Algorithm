#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of Chlidren of " << front->data << endl;
        int numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << endl;
            cin >> childData;
            //! TreeNode<int> child(childData); // don't allocate statically

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(&child);
            pendingNodes.push(child);
        }
    }
}

int main()
{

    return 0;
}