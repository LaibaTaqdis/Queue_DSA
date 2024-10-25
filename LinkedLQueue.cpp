#include <iostream>
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue - adds an element at the end of the queue
    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (rear == nullptr) {
            front = rear = newNode;  // If queue is empty, both front and rear are the new node
            cout << value << " enqueued into the queue." << endl;
            return;
        }
        rear->next = newNode;  // Link the new node at the end of the queue
        rear = newNode;        // Move rear to the new node
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue - removes an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;  // Move front to the next node
        cout << temp->data << " dequeued from the queue." << endl;
        delete temp;

        // If front becomes nullptr, set rear to nullptr as well
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Display the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        QueueNode* temp = front;
        cout << "Queue elements are: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();  // Displays the queue

    q.dequeue();  // Removes 10
    q.dequeue();  // Removes 20

    q.display();  // Displays the remaining elements

    return 0;
}

