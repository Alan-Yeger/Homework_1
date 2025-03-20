#include <iostream>
#include "homework_1.hpp"

using namespace std;

struct node{
    int value;
    node* next;
    size_t size;
};

unique_ptr<list> create_list();
unique_ptr<node> create_node(int val);

bool push_front(); bool push_back();

bool insert(); bool erase();

void print_list();

int main() {
    return 0;
}