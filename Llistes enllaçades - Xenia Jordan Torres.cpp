// Llistes enllaçades - Xenia Jordan Torres.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class List {
public:
    // Constructor and destructor
    List() = default;
    ~List();

    // Modifiers
    void push_front(const int& value);
    void push_back(const int& value);
    void pop_front();
    void pop_back();
    void insert(unsigned int position, const int& value);
    void erase(unsigned int position);
    void clear();

    // Getters
    int& front();
    int& back();
    int& value_at(unsigned int position);
    bool empty() const { return num_elems == 0; }
    unsigned int size() const { return num_elems; }

    // Print function
    void print();

private:
    // Internal struct for list nodes
    struct Node {
        int value;
        Node* next;
        Node* prev;
    };

    // List internals
    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;
};

// Destructor to free memory
List::~List() {
    clear();
}

//Afegr un element al final
void List::push_back(const int& value) {
    Node* new_node = new Node{ value, nullptr, last };
    if (last) {
        last->next = new_node;
    }
    else {
        first = new_node; // List was empty
    }
    last = new_node;
    num_elems++;
}

//Afegr un element al principi
void List::push_front(const int& value) {
    Node* new_node = new Node{ value, first, nullptr };
    if (first) {
        first->prev = new_node;
    }
    else {
        last = new_node; // List was empty
    }
    first = new_node;
    num_elems++;
}

// Insertar un element
void List::insert(unsigned int position, const int& value) {
    if (position > num_elems) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (position == 0) {
        push_front(value);
        return;
    }

    if (position == num_elems) {
        push_back(value);
        return;
    }

    Node* current = first;
    for (unsigned int i = 0; i < position; ++i) {
        current = current->next;
    }

    Node* new_node = new Node{ value, current, current->prev };
    if (current->prev) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
    num_elems++;
}

// Print
void List::print() {
    Node* current = first;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Clear
void List::clear() {
    Node* current = first;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    first = last = nullptr;
    num_elems = 0;
}

int main() {
    List my_list; //objecte de la llista

    my_list.push_back(10);
    cout << "After push_back(10): ";
    my_list.print();

    my_list.push_back(20);
    cout << "After push_back(20): ";
    my_list.print();

    my_list.insert(1, 15);
    cout << "After insert(1, 15): ";
    my_list.print();

    my_list.insert(0, 5); 
    cout << "After insert(0, 5): ";
    my_list.print();

    my_list.insert(4, 25);
    cout << "After insert(4, 25): ";
    my_list.print();
}
