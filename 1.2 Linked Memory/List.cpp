#include <iostream>

template <typename T>
class ListNode {
public:
    T &data;
    ListNode *next;

    ListNode(T &data) : data(data), next(NULL) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T> *head; // Pointer to the first node

public:
    LinkedList() : head(NULL) {}

    // Add a new node to the end of the list
    void append(T &data) {
        ListNode<T> *newNode = new ListNode<T>(data);
        if (head == NULL) {
            head = newNode; // If the list is empty, the new node becomes the head
        } else {
            ListNode<T> *current = head;
            while (current->next != NULL) {
                current = current->next; // Traverse to the end of the list
            }
            current->next = newNode; // Link the last node to the new node
        }
    }

    // Print all the elements in the list
    void printList() {
        ListNode<T> *current = head;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        ListNode<T> *current = head;
        while (current != NULL) {
            ListNode<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    int a = 10, b = 20, c = 30;

    // Create a LinkedList and add nodes
    LinkedList<int> list;
    list.append(a);
    list.append(b);
    list.append(c);

    // Print the list
    list.printList(); // Output: 10 20 30

    return 0;
}
