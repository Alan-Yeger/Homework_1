#include <iostream>
#include <memory>

using namespace std;

struct node{
    node* next;
    int value;
};

struct list {
    node* head;
    node* tail;
    size_t size;
};

unique_ptr<list> create_list() {
    
    unique_ptr<list> lista = make_unique<list>();
    

    lista->head = nullptr;
    lista->tail = nullptr;
    lista->size = 0;

    return lista;
}


unique_ptr<node> create_node(int val) {
    unique_ptr<node> nodo = make_unique<node>();
    nodo->value = val;

    return nodo;
}

bool push_front(list* lista, void* val) {

} 

bool push_back(list* lista, void* val) {

}

bool insert(list* lista, int pos, void* val) {

} 

bool erase(list* lista, int pos) {
    lista->size --;
}

void print_list(list) {

}