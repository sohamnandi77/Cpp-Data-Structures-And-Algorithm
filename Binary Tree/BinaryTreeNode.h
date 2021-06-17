using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};
