//q21  Write a program to implement priority Queue using linked list.  
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    Node* next;
};

// Class for Priority Queue
class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = NULL;
    }

    // Function to insert an element into the priority queue
    void enqueue(int item, int priority) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->priority = priority;
        newNode->next = NULL;

        // Case 1: Queue is empty or new node has higher priority than front
        if (front == NULL || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } 
        else {
            // Traverse the list and find the position to insert
            Node* temp = front;
            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted item " << item << " with priority " << priority << endl;
    }

    // Function to remove an element from the priority queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow (empty queue)" << endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted item: " << temp->data << " with priority " << temp->priority << endl;
        front = front->next;
        delete temp;
    }

    // Function to display the queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "\nPriority Queue (item | priority):" << endl;
        while (temp != NULL) {
            cout << temp->data << " | " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

// Main function
int main() {
    PriorityQueue pq;
    int choice, item, priority;

    do {
        cout << "\n----- Priority Queue Menu -----" << endl;
        cout << "1. Insert (Enqueue)" << endl;
        cout << "2. Delete (Dequeue)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item and its priority: ";
            cin >> item >> priority;
            pq.enqueue(item, priority);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


//q 22 Write a program to implement priority Queue 
// (with five levels of priority) using multiple queues.

#include <iostream>
using namespace std;

class PriorityQueue {
    int queue[5][10];     // 5 queues (priority 1 to 5), each can hold up to 10 elements
    int front[5], rear[5]; // front and rear pointers for each queue

public:
    PriorityQueue() {
        for (int i = 0; i < 5; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
    }

    // Enqueue an element in a specific priority queue
    void enqueue(int item, int priority) {
        if (priority < 1 || priority > 5) {
            cout << "Invalid priority! (Choose between 1 and 5)" << endl;
            return;
        }

        int p = priority - 1; // index (0–4)
        if (rear[p] == 9) {
            cout << "Queue Overflow at priority " << priority << endl;
            return;
        }

        // Insert element
        if (front[p] == -1)
            front[p] = 0;
        rear[p]++;
        queue[p][rear[p]] = item;

        cout << "Inserted " << item << " at priority " << priority << endl;
    }

    // Dequeue the element from the highest available priority
    void dequeue() {
        for (int p = 0; p < 5; p++) {
            if (front[p] != -1) {
                cout << "Deleted element: " << queue[p][front[p]] 
                     << " from priority " << (p + 1) << endl;

                // Shift front pointer
                if (front[p] == rear[p]) {
                    front[p] = rear[p] = -1; // queue becomes empty
                } else {
                    front[p]++;
                }
                return;
            }
        }
        cout << "All queues are empty (Underflow)" << endl;
    }

    // Display all queues
    void display() {
        for (int p = 0; p < 5; p++) {
            if (front[p] == -1) {
                cout << "Priority " << (p + 1) << " queue is empty." << endl;
            } else {
                cout << "Priority " << (p + 1) << " queue: ";
                for (int i = front[p]; i <= rear[p]; i++) {
                    cout << queue[p][i] << " ";
                }
                cout << endl;
            }
        }
    }
};

// Main program
int main() {
    PriorityQueue pq;
    int choice, item, priority;

    do {
        cout << "\n----- Priority Queue Menu -----" << endl;
        cout << "1. Insert (Enqueue)" << endl;
        cout << "2. Delete (Dequeue)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item and priority (1 to 5): ";
            cin >> item >> priority;
            pq.enqueue(item, priority);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


//q 23 Write a program to implement  double ended Queue.
#include <iostream>
using namespace std;

class Deque {
    int arr[10];    // Array to store elements
    int front, rear;
    int capacity;   // Maximum size of deque

public:
    Deque() {
        capacity = 10;
        front = -1;
        rear = -1;
    }

    // Check if deque is full
    bool isFull() {
        return ((front == 0 && rear == capacity - 1) || (front == rear + 1));
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert element at front
    void insertFront(int item) {
        if (isFull()) {
            cout << "Deque Overflow (cannot insert at front)" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = capacity - 1;
        else
            front = front - 1;

        arr[front] = item;
        cout << "Inserted " << item << " at front." << endl;
    }

    // Insert element at rear
    void insertRear(int item) {
        if (isFull()) {
            cout << "Deque Overflow (cannot insert at rear)" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1)
            rear = 0;
        else
            rear = rear + 1;

        arr[rear] = item;
        cout << "Inserted " << item << " at rear." << endl;
    }

    // Delete element from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow (nothing to delete at front)" << endl;
            return;
        }

        cout << "Deleted element from front: " << arr[front] << endl;

        if (front == rear) { // Only one element left
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
            front = 0;
        else
            front = front + 1;
    }

    // Delete element from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow (nothing to delete at rear)" << endl;
            return;
        }

        cout << "Deleted element from rear: " << arr[rear] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear = rear - 1;
    }

    // Display deque contents
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Deque dq;
    int choice, item;

    do {
        cout << "\n----- Double Ended Queue Menu -----" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            dq.insertFront(item);
            break;
        case 2:
            cout << "Enter item: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

//q 24 Write a program to implement a queue using stack (s). 
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
    stack<int> s1, s2;  // Two stacks to simulate queue behavior

public:
    // Enqueue operation — push into stack s1
    void enqueue(int item) {
        s1.push(item);
        cout << "Enqueued: " << item << endl;
    }

    // Dequeue operation — remove element from front of queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow (empty queue)" << endl;
            return;
        }

        // Move elements from s1 to s2 only if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Dequeued: " << s2.top() << endl;
        s2.pop();
    }

    // Display all elements in queue order
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        stack<int> temp1 = s1, temp2 = s2;
        cout << "Queue elements (front → rear): ";

        // Display elements in s2 first (already in correct order)
        stack<int> printOrder;

        while (!temp2.empty()) {
            printOrder.push(temp2.top());
            temp2.pop();
        }

        while (!printOrder.empty()) {
            cout << printOrder.top() << " ";
            printOrder.pop();
        }

        // Then elements from s1 (reverse order)
        stack<int> rev;
        while (!temp1.empty()) {
            rev.push(temp1.top());
            temp1.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStack q;
    int choice, item;

    do {
        cout << "\n----- Queue Using Stacks Menu -----" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Delete)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            q.enqueue(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

//q 25 Write a program to implement a stack using queue.
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
    queue<int> q1, q2;  // Two queues for implementation

public:
    // Push operation (insert element)
    void push(int item) {
        // Step 1: Push the new item into q2
        q2.push(item);
        cout << "Pushed: " << item << endl;

        // Step 2: Move all elements from q1 → q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2 (so q1 always has the latest order)
        swap(q1, q2);
    }

    // Pop operation (remove element from top)
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow (empty stack)" << endl;
            return;
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    // Peek operation (get top element)
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    // Display the stack elements (top to bottom)
    void display() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        queue<int> temp = q1;
        cout << "Stack elements (top → bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

// Main function
int main() {
    StackUsingQueue s;
    int choice, item;

    do {
        cout << "\n----- Stack Using Queues Menu -----" << endl;
        cout << "1. Push (Insert)" << endl;
        cout << "2. Pop (Delete)" << endl;
        cout << "3. Peek (Top)" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            s.push(item);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

//  q 26 Write a program to implement binary search tree using linked implementation program should 
// have functions for insert operations and display functions for inorder, preorder 
// and postorder traversal. 

#include <iostream>
using namespace std;

// Node structure for the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to insert a new node in the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    // duplicate values ignored
    return root;
}

// Inorder traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left → Right → Root)
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n----- Binary Search Tree Menu -----\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

//q 27 Write a program for level order traversal of binary (search) tree 
// which is implemented using linked node approach.  

#include <iostream>
#include <queue>  // for using queue in level order traversal
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a new node in BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    // Duplicate values are ignored
    return root;
}

// Function for Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Level Order Traversal: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        // Enqueue left child
        if (current->left != NULL)
            q.push(current->left);

        // Enqueue right child
        if (current->right != NULL)
            q.push(current->right);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n----- Binary Search Tree Menu -----\n";
        cout << "1. Insert Node\n";
        cout << "2. Level Order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            levelOrder(root);
            break;

        case 3:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

// q 28 Write a program to implement binary search tree using a single dimension array. Program 
// should have all functions as in P26.   
#include <iostream>
using namespace std;

const int MAX = 100;

// Array to store the BST
int bst[MAX];

// Function to initialize array
void initialize() {
    for (int i = 0; i < MAX; i++)
        bst[i] = -1; // -1 means empty
}

// Function to insert a new value in BST array
void insert(int value) {
    int index = 0;

    while (index < MAX) {
        if (bst[index] == -1) {     // Empty spot found
            bst[index] = value;
            return;
        } 
        else if (value < bst[index]) {  // Go to left child
            index = 2 * index + 1;
        } 
        else if (value > bst[index]) {  // Go to right child
            index = 2 * index + 2;
        } 
        else {
            cout << "Duplicate value " << value << " ignored!\n";
            return;
        }
    }
    cout << "Tree overflow — cannot insert more nodes!\n";
}

// Inorder traversal (Left → Root → Right)
void inorder(int index) {
    if (index >= MAX || bst[index] == -1)
        return;

    inorder(2 * index + 1);
    cout << bst[index] << " ";
    inorder(2 * index + 2);
}

// Preorder traversal (Root → Left → Right)
void preorder(int index) {
    if (index >= MAX || bst[index] == -1)
        return;

    cout << bst[index] << " ";
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

// Postorder traversal (Left → Right → Root)
void postorder(int index) {
    if (index >= MAX || bst[index] == -1)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    cout << bst[index] << " ";
}

int main() {
    initialize();
    int choice, value;

    while (true) {
        cout << "\n----- Binary Search Tree (Array Implementation) -----\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(0);
            cout << endl;
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(0);
            cout << endl;
            break;

        case 4:
            cout << "Postorder Traversal: ";
            postorder(0);
            cout << endl;
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

//q 29 Write a program to implement heap data structure using an array as a container. The program 
// should have functions for insert and delete root operations. 
#include <iostream>
using namespace std;

class Heap {
    int arr[100];   // Array container for heap
    int size;       // Current number of elements

public:
    Heap() {
        size = 0;
    }

    // Function to insert an element into the heap
    void insert(int value) {
        if (size >= 100) {
            cout << "Heap Overflow! Cannot insert more elements.\n";
            return;
        }

        size++;
        int index = size;
        arr[index] = value;

        // Move up (heapify-up)
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }

        cout << "Inserted " << value << " successfully.\n";
    }

    // Function to delete the root (maximum element)
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty! Nothing to delete.\n";
            return;
        }

        cout << "Deleted root: " << arr[1] << endl;

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Move down (heapify-down)
        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;
            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // Function to display heap elements
    void display() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap h;
    int choice, value;

    while (true) {
        cout << "\n----- Heap Implementation Menu -----\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Root\n";
        cout << "3. Display Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            h.insert(value);
            break;

        case 2:
            h.deleteRoot();
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

//q 30 Write a program to implement heap sort.
#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
// n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    heapSort(arr, n);

    cout << "\n\nSorted array (Heap Sort): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
