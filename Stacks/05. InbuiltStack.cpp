#include <iostream>
#include <stack>
using namespace std;

// # Application of stack
// -> Function calls
// -> Reversing items
// -> Infix to Prefix/Postfix
// -> Evaluation of Postfix/Prefix
// -> Stock Span problem
// -> Undo/Redo or Forward/Backward

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;
    return 0;
}