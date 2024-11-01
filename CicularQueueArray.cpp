#include <iostream>
using namespace std;

int front = -1, rear = -1, size;
int* arr;

bool isFull() {
    return (rear + 1) % size == front;
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. " << value << " cannot be enqueued." << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    arr[rear] = value;
    cout << "Enqueued: " << value << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    size = 5;
    arr = new int[size];  // Dynamically allocate memory for the queue array

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);  // This will show that the queue is full
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    display();

    delete[] arr;  
    return 0;
}

