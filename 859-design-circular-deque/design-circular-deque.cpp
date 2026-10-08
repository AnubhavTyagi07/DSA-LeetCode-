class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);

        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        // If empty, insert at front/rear position
        if (isEmpty()) {
            front = 0;
            rear = 0;
            arr[front] = value;
        }
        else {
            // Move front backwards circularly
            front = (front - 1 + capacity) % capacity;
            arr[front] = value;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        // If empty
        if (isEmpty()) {
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        else {
            // Move rear forward circularly
            rear = (rear + 1) % capacity;
            arr[rear] = value;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */