#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertNode(Node* &tail, int d) {
    Node* newNode = new Node(d);
    if (tail == NULL) {
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

int getMax(Node* &head) {
    Node* temp = head->next;
    int max = head->data;
    while (temp != NULL) {
        if (max < temp->data) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void countSort(Node* &head, int div) {
    int max, min;
    max = getMax(head);

    // Find the minimum value
    Node* temp = head;
    min = head->data;
    while (temp != NULL) {
        if (min > temp->data) {
            min = temp->data;
        }
        temp = temp->next;
    }

    int range = max - min;

    vector<int> count(range + 1, 0);
    temp = head;

    while (temp != NULL) {
        // Calculate the count index using the remainder operator %
        int index = ((temp->data - min) / div) % 10;
        count[index]++;
        temp = temp->next;
    }

    temp = head;
    Node* result = NULL;
    Node* resultTail = NULL;

    for (int i = 0; i <= range; i++) {
        while (count[i] > 0) {
            Node* newNode = new Node(i * div + min);

            if (!result) {
                result = newNode;
                resultTail = result;
            }
            else {
                resultTail->next = newNode;
                resultTail = newNode;
            }

            count[i]--;
        }
    }
    head = result;
}

void radixSort(Node* &head) {
    int max = getMax(head);
    for (int div = 1; max / div > 0; div *= 10) {
        countSort(head, div);
    }
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node = new Node(0);
    Node* head = node;
    Node* tail = node;
    for (int i = 0; i < 5; i++) {
        int temp;
        cout<<"enter number";
        cin >> temp;
        insertNode(tail, temp);
    }
    radixSort(head);
    print(head);
    return 0;
}
