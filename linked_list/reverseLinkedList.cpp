#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *prev = NULL;;
    Node *curr = head;
    Node *nxt = head->next;

    while (curr->next != NULL) {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = curr->next;
    }

    curr->next = prev;
    return curr;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}
