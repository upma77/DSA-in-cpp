#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    } 
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void DeleteDuplicateNode(Node* &head) {
    Node* curr_node = head;
    while (curr_node != NULL && curr_node->next != NULL) {
        if (curr_node->val == curr_node->next->val) {
            Node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            delete temp;  // correct memory deallocation
        } else {
            curr_node = curr_node->next; // move forward only when values differ
        }
    }
}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(3);

    cout << "Before removing duplicates:" << endl;
    ll.display();

    DeleteDuplicateNode(ll.head);

    cout << "After removing duplicates:" << endl;
    ll.display();

    return 0;
}
