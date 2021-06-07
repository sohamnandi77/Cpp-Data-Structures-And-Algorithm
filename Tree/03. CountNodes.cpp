#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

int countNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
        ans += countNodes(root->children[i]);

    return ans;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of Chlidren of " << front->data << endl;

        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << endl;
            cin >> childData;
            //! TreeNode<int> child(childData); // don't allocate statically

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << countNodes(root) << endl;

    return 0;
}