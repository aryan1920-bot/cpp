#include <iostream> 
#include <vector> 
using namespace std; 
class PriorityQueue { 
private: 
struct Node { 
int value; 
int priority; 
Node(int v, int p) : value(v), priority(p) {} 
}; 
vector<Node> heap; 
int parent(int i) { return (i - 1) / 2; } 
int lc(int i) { return 2 * i + 1; } 
int rc(int i) { return 2 * i + 2; } 
void siftUp(int i) { 
while (i > 0 && heap[parent(i)].priority < heap[i].priority) { 
swap(heap[parent(i)], heap[i]); 
i = parent(i);
} 
} 
void siftDown(int i) { 
int maxIndex = i; 
int l = lc(i); 
if (l < heap.size() && heap[l].priority > heap[maxIndex].priority) 
maxIndex = l; 
int r = rc(i); 
if (r < heap.size() && heap[r].priority > heap[maxIndex].priority) 
maxIndex = r; 
if (i != maxIndex) { 
swap(heap[i], heap[maxIndex]); 
siftDown(maxIndex); 
} 
} 
public: 
void enqueue(int value, int priority) { 
Node node(value, priority); 
heap.push_back(node); 
siftUp(heap.size() - 1); 
} 
int dequeue() { 
int result = heap[0].value; 
heap[0] = heap[heap.size() - 1]; 
heap.pop_back(); 
siftDown(0); 
return result;
} 
bool isEmpty() { 
return heap.empty(); 
} 
bool isFull() { 
return false; 
} 

}; 
int main() { 
PriorityQueue pq; 
pq.enqueue(10, 2); 
pq.enqueue(20, 1); 
pq.enqueue(30, 3); 
pq.enqueue(40, 2); 
cout << pq.dequeue() << endl; 
cout << pq.isEmpty() << endl; 
cout << pq.isFull() << endl; 
return 0; 
}