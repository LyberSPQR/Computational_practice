// 2.5. Описать функцию, которая формирует список элементов L, включив в него элементы,
//  которые входят в один из списков L1 и L2, но в то же время не входят в другой из них.

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* createNode(T value);

template <typename T>
void insertAtEnd(Node<T>*& head, T value);

template <typename T>
void deleteFirstNode(Node<T>*& head);

template <typename T>
void deleteLastNode(Node<T>*& head);

template <typename T>
void Print(Node<T>* L);

template <typename T>
void CreateListL(Node<T>* L1, Node<T>* L2, Node<T>*& L);

int main() {
    const int n = 3;

    Node<char>* L = nullptr;
    Node<char>* L1 = nullptr;
    Node<char>* L2 = nullptr;

    cout << "Enter L1" << endl;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        insertAtEnd(L1, a);
    }

    cout << "Enter L2" << endl;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        insertAtEnd(L2, a);
    }

    cout << endl;

    CreateListL(L1, L2, L);
    Print(L);

    return 0;
}

template <typename T>
Node<T>* createNode(T value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void insertAtEnd(Node<T>*& head, T value) {
    Node<T>* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

template <typename T>
void deleteFirstNode(Node<T>*& head) {
    if (head == nullptr) {
        return;
    }

    Node<T>* current = head;
    head = head->next;
    delete current;
}

template <typename T>
void deleteLastNode(Node<T>*& head) {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    delete current;
}

template <typename T>
void Print(Node<T>* L) {
    if (L == nullptr) {
        return;
    }
    Node<T>* current = L;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void CreateListL(Node<T>* L1, Node<T>* L2, Node<T>*& L) {
    Node<T>* current = L1;
    while (current != nullptr) {
        Node<T>* temp = L2;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == current->data) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertAtEnd(L, current->data);
        }
        current = current->next;
    }

    current = L2;
    while (current != nullptr) {
        Node<T>* temp = L1;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == current->data) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insertAtEnd(L, current->data);
        }
        current = current->next;
    }
}