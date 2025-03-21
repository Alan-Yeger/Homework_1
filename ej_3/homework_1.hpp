#include <iostream>
#include <memory>

using namespace std;

struct node{
    shared_ptr<node> next;
    int value;
};

struct list {
    shared_ptr<node> head;
    shared_ptr<node> tail;
    size_t size;
};

shared_ptr<list> create_list() {
    
    shared_ptr<list> lista = make_shared<list>();
    

    lista->head = nullptr;
    lista->tail = nullptr;
    lista->size = 0;

    return lista;
}


shared_ptr<node> create_node(int val) {
    shared_ptr<node> nodo = make_shared<node>();
    nodo->next = nullptr;
    nodo->value = val;

    return nodo;
}

void push_front(shared_ptr<list> lista, int val) {
    shared_ptr<node> new_node = create_node(val);
    new_node->next = lista->head;
    lista->head = new_node;
    if(!lista->tail) lista->tail = new_node;

    lista->size ++;
} 

void push_back(shared_ptr<list> lista, int val) {
    shared_ptr<node> new_node = create_node(val);
    
    if(!lista->tail) lista->head = lista->tail = new_node;
    else { 
        lista->tail->next = new_node;
        lista->tail = new_node;
    }
    lista->size ++;
}

bool insert(shared_ptr<list> lista, int pos, int val) {
    if (pos < 0) {
        cout << "Posición inválida";
        return false;
    }
    else if (pos <= lista->size) {
        shared_ptr<node> new_node = create_node(val);
        shared_ptr<node> prev = lista->head;
        while(--pos) {
            prev = prev->next;
        }
        if (prev) {
            new_node->next = prev->next;
            prev->next = new_node;
        }
    }
    else {
        cout << "Posición excede rango. Se insertó al final \n";
        push_back(lista, val);
        return true;
    }
    
    lista->size ++;
    return true;
}


bool erase(shared_ptr<list> lista, int pos) {
    if (pos < 0) {
        cout << "Posición inválida";
        return false;
    }
    if (pos >= lista->size) {
        cout << "Posición excede rango. Se eliminó del final\n";
        pos = lista->size - 1;
    }

    if (pos == 0) {
        lista->head = lista->head->next;
    } else {
        shared_ptr<node> to_erase_prev = lista->head;
        
        for (int i = 0; i < pos - 1; ++i) {
            to_erase_prev = to_erase_prev->next;
        }

        shared_ptr<node> to_erase = to_erase_prev->next;
        
        if (!to_erase->next) to_erase_prev->next = nullptr; 
        
        else to_erase_prev->next = to_erase->next;
    }
    lista->size --;
    return true;
}

void print_list(shared_ptr<list> lista) {
    if (!lista->head) return;

    shared_ptr<node> curr = lista->head;
    cout << curr->value;
    curr = curr -> next;
    while(curr) {
        cout << " -> " << curr->value;
        curr = curr->next;
    }
    cout << "\n";
}