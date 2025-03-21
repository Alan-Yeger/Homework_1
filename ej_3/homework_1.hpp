#include <iostream>
#include <memory>

using namespace std;

//Nuestros nodos tienen un smart_pointer al siguiente en la lista y un valor
struct node{
    shared_ptr<node> next;
    int value;
};

//Nuestra lista tiene un head, tail y un size
struct list {
    shared_ptr<node> head;
    shared_ptr<node> tail;
    size_t size;
};

shared_ptr<list> create_list() {
    //Creamos un smart_pointer para la lista
    shared_ptr<list> lista = make_shared<list>();
    //Inicializamoms sus valores
    lista->head = nullptr;
    lista->tail = nullptr;
    lista->size = 0;

    return lista;
}


shared_ptr<node> create_node(int val) {
    //Creamos un nodo y lo inicializamos con su val
    shared_ptr<node> nodo = make_shared<node>();
    nodo->next = nullptr;
    nodo->value = val;

    return nodo;
}

void push_front(shared_ptr<list> lista, int val) {
    //Creamos el nodo
    shared_ptr<node> new_node = create_node(val);
    //Lo ubicamos al principio de la lista
    new_node->next = lista->head;
    //Renombramos el head por el nuevo nodo
    lista->head = new_node;
    //Si la lista estaba vacía, también es el tail
    if(!lista->tail) lista->tail = new_node;
    //Incrementamos el size
    lista->size ++;
} 

void push_back(shared_ptr<list> lista, int val) {
    //Creamos el nodo
    shared_ptr<node> new_node = create_node(val);
    //Si la lista estaba vacía, es el nuevo head y tail
    if(!lista->tail) lista->head = lista->tail = new_node;
    else { //Sino pasa a ser el tail y el tail anterior lo tiene como next a new_node
        lista->tail->next = new_node;
        lista->tail = new_node;
    }
    //Incrementamos el size
    lista->size ++;
}

bool insert(shared_ptr<list> lista, int pos, int val) {
    //No aceptamos posiciones negativas
    if (pos < 0) {
        cout << "Posición inválida";
        return false;
    } //Buscamos el previo al lugar de inserción y reacomodamos los punteros
    //Insertar al principio es hacer push_front
    else if (pos == 0) {
        push_front(lista, val);
        return true;
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
    else { //Si nos pasamos lo insertamoms al final
        cout << "Posición excede rango. Se insertó al final \n";
        push_back(lista, val);
        return true;
    }
    //Incrementamos el size
    lista->size ++;
    return true;
}


bool erase(shared_ptr<list> lista, int pos) {
    //No aceptamos posiciones negativas
    if (pos < 0 || !lista->head) {
        cout << "Posición inválida";
        return false;
    }//Si nos pasamos, reemplazamos pos por la última posición válida para borrar del final
    if (pos >= lista->size) {
        cout << "Posición excede rango. Se eliminó del final\n";
        pos = lista->size - 1;
    }
    //Si borramos del principio cambiamos el head por el siguiente
    if (pos == 0) {
        lista->head = lista->head->next;
        if (!lista->head) lista->tail = nullptr;
    } else { //Sino buscamos el previo al eliminado y reacomodamos punteros
        shared_ptr<node> to_erase_prev = lista->head;
        
        for (int i = 0; i < pos - 1; ++i) {
            to_erase_prev = to_erase_prev->next;
        }

        shared_ptr<node> to_erase = to_erase_prev->next;
        //Si es el último el anterior ahora pasa a nullptr
        if (!to_erase->next) to_erase_prev->next = nullptr; 
        
        else to_erase_prev->next = to_erase->next;
    }
    //Decrementamos el size
    lista->size --;
    return true;
}

void print_list(shared_ptr<list> lista) {
    //Si está vacía no hacemos nada
    if (!lista->head) return;
    //Recorremos la lista y la vamos printeando
    shared_ptr<node> curr = lista->head;
    cout << curr->value;
    curr = curr -> next;
    while(curr) {
        cout << " -> " << curr->value;
        curr = curr->next;
    }
    cout << "\n";
}