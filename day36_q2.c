class MyCircularDeque {
public:
    int *arr;
    int front, rear, size, cap;

    MyCircularDeque(int k) {
        cap = k;
        arr = new int[k];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == cap;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool insertFront(int value) {
        if(isFull()) return false;

        if(isEmpty()) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + cap) % cap;
        }

        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if(isFull()) return false;

        if(isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % cap;
        }

        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % cap;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) return false;

        if(front == rear) {
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + cap) % cap;
        }

        size--;
        return true;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
};