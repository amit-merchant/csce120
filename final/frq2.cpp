#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node(int data, node* next) : data(data), next(next) {}
};

class linkedlist {
    public:
        node *head;
    public:
        linkedlist() : head(nullptr){}
        //Write these functions
        linkedlist& push_back(int value) {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }            
            node* newNode = new node(value, nullptr);
            temp->next = newNode;
            return *this;
        }
        void add_mirror(node*& head) {
            node* temp = head;
            while (temp->next != nullptr) {
                node* newNode = new node(temp->next->data, head);
                head = newNode;
                temp = temp->next;
            }
        };
        void print() {
            node* currnode = head;
            while (currnode->next != nullptr) {
                cout << currnode->data << " -> ";
                currnode = currnode->next;
            }
            cout << currnode->data << endl;
        }
};

int main() {
    linkedlist ll;
    ll.head = new node(0,nullptr);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    cout << "created original ll: ";
    ll.print();
    ll.add_mirror(ll.head);
    cout << "mirror ll: ";
    ll.print();
}

