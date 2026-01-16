#include <iostream>
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

    int getLength(Node* head) {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    Node* moveHeadByK(Node* head, int k) {
        Node* ptr = head;
        while (k-- && ptr != NULL) {
            ptr = ptr->next;
        }
        return ptr;
    }

    Node* getIntersection(Node* head1, Node* head2) {
        int l1 = getLength(head1);
        int l2 = getLength(head2);

        Node* ptr1;
        Node* ptr2;

        if (l1 > l2) {
            ptr1 = moveHeadByK(head1, l1 - l2);
            ptr2 = head2;
        } else {
            ptr1 = head1;
            ptr2 = moveHeadByK(head2, l2 - l1);
        }

        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1 == ptr2) {
                return ptr1;   // intersection found
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL; // no intersection
    }
};

int main() {
    LinkedList ll1, ll2;

    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    ll2.insertAtTail(6);
    ll2.insertAtTail(7);

    // Creating intersection at node with value 4
    ll2.head->next->next = ll1.head->next->next->next;

    cout << "List 1: ";
    ll1.display();

    cout << "List 2: ";
    ll2.display();

    Node* intersection = ll1.getIntersection(ll1.head, ll2.head);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

