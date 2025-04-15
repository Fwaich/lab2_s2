#pragma once

template <typename T>
class LinkedList
{
private:
    struct  Node
    {
        T value;
        Node* next;
        Node* prev;
        Node(T new_value, Node* new_next = nullptr, Node* new_prev = nullptr):
        value(new_value), next(new_next), prev(new_prev) {};
    };

    Node* head;
    Node* tail;
    size_t length;
    
public:
    LinkedList();
    LinkedList(T* items, size_t count);
    ~LinkedList();

    void append(T item);


    void print() {
        Node* node = head;
        while (node != nullptr) {
            cout << node->value << endl;
            node = node->next;
        }
    }
};

template <typename T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), length(0){}

template <typename T>
LinkedList<T>::LinkedList(T* items, size_t count){
    length = 0;
    for (int i = 0; i < count; i++){
        append(items[i]);
    }
};

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* node = head;
    while (node != tail){
        node = node->next;
        delete node->prev;
    }
    delete node;
    cout << "delete ll" << endl;
};

template <typename T>
void LinkedList<T>::append(T item){
    Node* node = new Node(item);

    if (length == 0) {
        head = node;
        tail = node;
        length++;
        return; 
    }

    tail->next = node;
    node->prev = tail;
    tail = node;
    length++;
};