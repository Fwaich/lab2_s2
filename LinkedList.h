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
    void prepend(T item);
    T get(int index);
    T get_first();
    T get_last();


    void print() {
        Node* node = head;
        int i = 0;
        while (node != nullptr) {
            cout << "{" << i++ << "}: " << node->value << endl;
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

template <typename T>
void LinkedList<T>::prepend(T item){
    if (length == 0){
        append(item);
        return;
    }

    Node* node = new Node(item);
    node->next = head;
    head->prev = node;
    head = node;
    length++;
}

template <typename T>
T LinkedList<T>::get(int index){
    if (index >= length || index < 0){
        throw out_of_range("List: Index out of bounds");
    }

    Node* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return node->value;
}

template <typename T>
T LinkedList<T>::get_first(){
    return head->value;
}

template <typename T>
T LinkedList<T>::get_last(){
    return tail->value;
}