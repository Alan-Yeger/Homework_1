#include <iostream>
#include "homework_1.hpp"

using namespace std;

/*
En este ejercicio codeamos las funciones básicas de una lista enlazada, con la particularidad de que los punteros son todos smart pointers.
Como no me pedían performance ni nada parecido decidí usar shared_pointers ya que me facilitó algunas funciones (por ej cuando tengo head y tail 
apuntando al mismo elemento). 
*/

shared_ptr<list> create_list();
shared_ptr<node> create_node(int val);

void push_front(shared_ptr<list> lista, int val); void push_back(shared_ptr<list> lista, int val);

bool insert(shared_ptr<list> lista, int pos, int val); bool erase(shared_ptr<list> lista, int pos);

void print_list(shared_ptr<list> lista);

int main() {
    //Tests para mostrar la funcionalidad de la lista
    shared_ptr<list> lista = create_list();
    push_back(lista, 3);
    print_list(lista);
    push_front(lista, 1);
    print_list(lista);
    insert(lista, 1, 2);
    print_list(lista);
    insert(lista, 54, 4);
    print_list(lista);
    erase(lista, 57);
    print_list(lista);

    return 0;
}