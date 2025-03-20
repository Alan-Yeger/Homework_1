#include "tp2.h"
#include <stdlib.h>
#include <stdbool.h>

struct node;
typedef struct node node_t;

struct node {
    void* value;
    node_t* next;
    node_t* prev;
};

struct list {
    node_t* head;
    node_t* tail;
    size_t size;
};

struct list_iter {
    list_t* list;
    node_t* curr;
};

list_t *list_new(){
    list_t* nueva_lista = malloc(sizeof(list_t));
    if(nueva_lista == NULL) return NULL;

    nueva_lista->head = NULL;
    nueva_lista->tail = NULL;
    nueva_lista->size = 0;
    return nueva_lista;
}

size_t list_length(const list_t *list){
    return list->size;
}

bool list_is_empty(const list_t *list){
    return (list->size == 0);
}

bool list_insert_head(list_t *list, void *value){
    node_t* nuevo_nodo = malloc(sizeof(node_t));
    if(nuevo_nodo == NULL) return false;

    nuevo_nodo->value = value;
    nuevo_nodo->prev = NULL;
    nuevo_nodo->next = list->head;

    list->head = nuevo_nodo;
    
    if(list->head->next) list->head->next->prev = nuevo_nodo;
    else list->tail = list->head;
    list->size ++;
    return true;
}

bool list_insert_tail(list_t *list, void *value){
    node_t* nuevo_nodo = malloc(sizeof(node_t));
    if(nuevo_nodo == NULL) return false;

    nuevo_nodo->value = value;
    nuevo_nodo->prev = list->tail;
    nuevo_nodo->next = NULL;

    list->tail = nuevo_nodo;
    
    if(list->tail->prev) list->tail->prev->next = nuevo_nodo;
    else list->head = list->tail;
    list->size ++;
    return true;
}

void *list_peek_head(const list_t *list){
    if(list_is_empty(list)) return NULL;
    return list->head->value;
}

void *list_peek_tail(const list_t *list){
    if(list_is_empty(list)) return NULL;
    return list->tail->value;
}

void *list_pop_head(list_t *list){
    if(list_is_empty(list)) return NULL;
    node_t* old_head = list->head;
    void* old_value = NULL;

    if(old_head) {
        old_value = old_head->value;
        list->head = old_head->next;
    }

    if(list->head) list->head->prev = NULL;
    if(list->tail == old_head) list->tail = NULL;

    list->size--;
    free(old_head);
    old_head = NULL;
    return old_value;
}

void *list_pop_tail(list_t *list){
    if(list_is_empty(list)) return NULL;
    node_t* old_tail = list->tail;
    void* old_value = NULL;
    
    if(old_tail) {
        old_value = old_tail->value;
        list->tail = old_tail->prev;
    }

    if(list->tail) list->tail->next = NULL;
    if(list->head == old_tail) list->head = NULL;

    list->size--;
    free(old_tail);
    old_tail = NULL;
    return old_value;
}

void list_destroy(list_t *list, void destroy_value(void *)){
    while(!list_is_empty(list)) {
        void* old_value = list_pop_head(list);
        if(destroy_value) destroy_value(old_value);
    }
    free(list);
    list = NULL;
    return;
}

list_iter_t *list_iter_create_head(list_t *list){
    list_iter_t* nuevo_iter = malloc(sizeof(list_iter_t));
    if(nuevo_iter == NULL) return false;

    nuevo_iter->list = list;
    nuevo_iter->curr = list->head;
    return nuevo_iter;
}

list_iter_t *list_iter_create_tail(list_t *list){
    list_iter_t* nuevo_iter = malloc(sizeof(list_iter_t));
    if(nuevo_iter == NULL) return false;

    nuevo_iter->list = list;
    nuevo_iter->curr = list->tail;
    return nuevo_iter;
}

bool list_iter_forward(list_iter_t *iter){
    if(list_iter_at_last(iter)) return false;
    iter->curr = iter->curr->next;
    return true;
}

bool list_iter_backward(list_iter_t *iter){
    if(list_iter_at_first(iter)) return false;
    iter->curr = iter->curr->prev;
    return true;
}

void *list_iter_peek_current(const list_iter_t *iter){
    if(list_is_empty(iter->list)) return NULL;
    return iter->curr->value;
}

bool list_iter_at_last(const list_iter_t *iter){
    if(list_is_empty(iter->list) || !iter->curr->next) return true;
    return false;
}

bool list_iter_at_first(const list_iter_t *iter){
    if(list_is_empty(iter->list) || !iter->curr->prev) return true;
    return false;
}

void list_iter_destroy(list_iter_t *iter){
    free(iter);
    iter = NULL;
    return;
}

bool list_iter_insert_after(list_iter_t *iter, void *value){
    if(list_iter_at_last(iter)) {
        list_insert_tail(iter->list, value);
        if(!iter->curr) iter->curr = iter->list->tail;
    }

    else {
        node_t* nuevo_nodo = malloc(sizeof(node_t));
        if(nuevo_nodo == NULL) return false;

        nuevo_nodo->value = value;
        nuevo_nodo->next = iter->curr->next;
        nuevo_nodo->prev = iter->curr;

        iter->curr->next->prev = nuevo_nodo;
        iter->curr->next = nuevo_nodo;
        iter->list->size++;
    }
    return true;
}

bool list_iter_insert_before(list_iter_t *iter, void *value){
    if(list_iter_at_first(iter)) {
        list_insert_head(iter->list, value);
    }
    else {
        node_t* nuevo_nodo = malloc(sizeof(node_t));
        if(nuevo_nodo == NULL) return false;

        nuevo_nodo->value = value;
        nuevo_nodo->next = iter->curr;
        nuevo_nodo->prev = iter->curr->prev;
        
        iter->curr->prev->next = nuevo_nodo;
        iter->curr->prev = nuevo_nodo;
        iter->list->size++;
    }
    return true;
}

void *list_iter_delete(list_iter_t *iter){
    if(list_is_empty(iter->list)) return NULL;
    void* valor_eliminado;

    if(list_iter_at_last(iter)) {
        valor_eliminado = list_pop_tail(iter->list);
        iter->curr = iter->list->tail;
    }

    else if(list_iter_at_first(iter)) {
        valor_eliminado = list_pop_head(iter->list);
        iter->curr = iter->list->head;
    }

    else {
        valor_eliminado = iter->curr->value;
        iter->curr->prev->next = iter->curr->next;
        iter->curr->next->prev = iter->curr->prev;
        node_t* nodo_a_eliminar = iter->curr;
        list_iter_forward(iter);
        free(nodo_a_eliminar);
        nodo_a_eliminar = NULL;
        iter->list->size--;
    }
    return valor_eliminado;
}