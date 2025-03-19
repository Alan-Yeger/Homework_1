#include <iostream>

using namespace std;

struct node{
    int value;
    node* next;
    size_t size;
};

bool create_node();

bool push_front(); bool push_back();

bool insert(); bool erase();

void print_list();

int main() {
    return 0;
}