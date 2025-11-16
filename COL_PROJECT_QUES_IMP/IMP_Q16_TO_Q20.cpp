   //q16: tower of hanoi
   #include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
    // Base condition: if only one disk, move it directly
    if (n == 1) {
        cout << "Move disk 1 from " << source << " → " << destination << endl;
        return;
    }

    // Step 1: Move top (n-1) disks from source to helper
    towerOfHanoi(n - 1, source, destination, helper);

    // Step 2: Move remaining disk from source to destination
    cout << "Move disk " << n << " from " << source << " → " << destination << endl;

    // Step 3: Move the (n-1) disks from helper to destination
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSteps to solve Tower of Hanoi:\n";
    towerOfHanoi(n, 'A', 'B', 'C'); // A = Source, B = Helper, C = Destination

    return 0;
}

// q 17 ->  Write a program which checks a string of ( , ), [, ], {, } symbols
//  for parenthesis balance check problem. 

#include <iostream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        // If opening bracket, push to stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }

        // If closing bracket, check top of stack
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty())    // No opening bracket to match
                { 
                return false;
                }

            char top = s.top();
            s.pop();

            // Check matching type
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    // If stack is empty → all brackets matched
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Parentheses are Balanced ✅" << endl;
    else
        cout << "Parentheses are NOT Balanced ❌" << endl;

    return 0;
}

//q 18 Write a program to convert infix expression into postfix form. 

#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to check if a character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if a character is operand (letter or digit)
bool isOperand(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand → directly add to postfix
        if (isOperand(ch)) {
            postfix += ch;
        }

        // If '(' → push to stack
        else if (ch == '(') {
            s.push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();  // Remove '('
        }

        // If operator → pop higher/equal precedence operators
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
// q 19 Write a program to implement circular queue using an array.
//  The program should take care of  overflow condition. 
// #include <iostream>
// using namespace std;

// #define SIZE 5   // maximum size of the queue

// class CircularQueue {
//     int arr[SIZE];
//     int front, rear;

// public:
//     CircularQueue() {
//         front = -1;
//         rear = -1;
//     }

//     // Check if queue is full
//     bool isFull() {
//         return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
//     }

//     // Check if queue is empty
//     bool isEmpty() {
//         return (front == -1);
//     }

//     // Insert an element in the queue
//     void enqueue(int value) {
//         if (isFull()) {
//             cout << "Queue Overflow! Cannot insert " << value << endl;
//             return;
//         }

//         if (front == -1)   // first element
//             front = 0;

//         rear = (rear + 1) % SIZE;   // circular increment
//         arr[rear] = value;

//         cout << "Inserted " << value << " into queue.\n";
//     }

//     // Delete an element from the queue
//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue Underflow! Cannot delete element.\n";
//             return;
//         }

//         cout << "Deleted element: " << arr[front] << endl;

//         if (front == rear)  // only one element was there
//             front = rear = -1;
//         else
//             front = (front + 1) % SIZE;  // circular increment
//     }

//     // Display the queue elements
//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty.\n";
//             return;
//         }

//         cout << "Circular Queue elements: ";
//         int i = front;
//         while (true) {
//             cout << arr[i] << " ";
//             if (i == rear)
//                 break;
//             i = (i + 1) % SIZE;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue q;
//     int choice, value;

//     cout << "\n--- Circular Queue using Array ---\n";

//     do {
//         cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//         case 1:
//             cout << "Enter value to insert: ";
//             cin >> value;
//             q.enqueue(value);
//             break;
//         case 2:
//             q.dequeue();
//             break;
//         case 3:
//             q.display();
//             break;
//         case 4:
//             cout << "Exiting program.\n";
//             break;
//         default:
//             cout << "Invalid choice! Try again.\n";
//         }

//     } while (choice != 4);

//     return 0;
// }



// no.2
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;        // dynamic array for queue elements
    int front, rear; // indices
    int size;        // maximum size of queue

public:
    // Constructor to initialize queue
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (front == -1) // first element
            front = 0;

        rear = (rear + 1) % size; // circular increment
        arr[rear] = value;
        cout << "Inserted " << value << " into queue.\n";
    }

    // Delete an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete element.\n";
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear) // only one element
            front = rear = -1;
        else
            front = (front + 1) % size;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] arr;
    }
};

// Main function
int main() {
    int n;
    cout << "Enter size of circular queue: ";
    cin >> n;

    CircularQueue q(n);
    int choice, value;

    cout << "\n--- Circular Queue using Array ---\n";

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

