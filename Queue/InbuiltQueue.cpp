#include <iostream>
#include <queue>
using namespace std;

// # Application of Queue
// -> Single Resource and Multiple Consumers
// -> Synchronization between slow and fast devices
// -> In Operating System (Semaphores, FCFS Sheduling,Spooling, buffers for devices like Keyboard)
// -> In computer Networks (Routers/Switches and mail Queues)
// -> Variations: Deque, Priority Queue(Heap),Doubly Ended Priority Queue

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << q.size() << endl;
    cout << q.empty() << endl;

    // print the queue
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}