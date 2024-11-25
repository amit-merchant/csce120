#include <iostream>
#include <sstream>
#include <limits>
using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

class node {
    private:
        int value = 0;
        node *ptr = nullptr;
    public:
        // constructor for node
        node (int arg_val, node *ptr = nullptr) {
            this->value = arg_val;
            this->ptr = ptr;    
        }
        // getters, gets value, gets ptr
        int getvalue () {return this->value;}
        node *getptr () {return this->ptr;}
        // setter
        void setptr (node *ptr) {this->ptr = ptr;}
        void setvalue (int value) {this->value = value;}
        // copy constructor
        node(const node& object) {
            node *exactCopy = new node(object.value, object.ptr);
            this->value = exactCopy->value;
            this->ptr = exactCopy->ptr;    
        }
        // copy assigntment constructor
        node& operator=(const node& object) {
            if (this != &object) {
                delete this;
                node *exactCopy = new node(object.value, object.ptr);
                this->value = exactCopy->value;
                this->ptr = exactCopy->ptr;
            }
            return *this;  
        }
};

class LinkedList {
    private:
        node *headptr;
    public:
        // constructor
        LinkedList () {
            this->headptr = nullptr;
        }
        // destructor
        ~LinkedList () {
            while(this->headptr != nullptr) {
                pop();
            }
        }
        // add a node
        void push (int value) {
            this->headptr = new node(value, this->headptr);            
        }
        // remove node
        int pop () {
            int value_to_remove;
            if (this->headptr != nullptr) {
                node *throwaway = this->headptr;
                value_to_remove = this->headptr->getvalue();
                this->headptr = this->headptr->getptr();
                delete throwaway;
            }
            else {
                    try { throw invalid_argument("Cannot remove elements from empty link list"); } 
                    catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
            }
            return value_to_remove;
        }
        // insert node based on reference value
        void insertNode(int value, int reference_value) {
            node *new_node = new node(value, nullptr);
            node *curNode = headptr;
            bool reference_value_found = false;
            while (curNode != nullptr) {
                // insert node when value of node equals reference_value
                if (curNode->getvalue() == reference_value){
                    new_node->setptr(curNode->getptr());
                    curNode->setptr(new_node);
                    reference_value_found = true;
                    break;
                }
                else {
                    // update curNode in linkedlist traversal based on next node pointer 
                    curNode = curNode->getptr();
                }
            }
            if (!reference_value_found) {
                    try { throw invalid_argument("Trying to add a node at a loctaion that does not exist"); } 
                    catch (std::invalid_argument const& e) { cout << e.what() << endl; }                 
            }
        } // end insertNode
        void deleteNode(int reference_value) {
            node *curNode = headptr;
            bool skipUpdate = false;
            bool reference_value_found = false;
            while(reference_value_found == false) {
                if (curNode == headptr && curNode->getvalue() == reference_value) {
                    node *throwaway = curNode; 
                    headptr = curNode->getptr();
                    reference_value_found = true;
                    delete throwaway;
                    break;
                }
                else if (curNode->getptr()->getvalue() == reference_value) {
                    node *throwaway = curNode->getptr(); 
                    curNode->setptr(curNode->getptr()->getptr());
                    reference_value_found = true;
                    delete throwaway;
                    break;
                }
                else {
                    curNode = curNode->getptr();
                }
                if (curNode->getptr() == nullptr) {
                    try { throw invalid_argument("Cannot remove elements from empty link list"); } 
                    catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
                    break;
                }
            }
            if (!reference_value_found) {
                try { throw invalid_argument("Trying to delete a node at a location that does not exist"); } 
                catch (std::invalid_argument const& e) { cout << e.what() << endl; }                 
            }
        } // end deleteNode
        bool link_list_empty() {
            if (this->headptr == nullptr) {return true;}
            else {return false;}
        }
        void printLinkedList () {
            node *curNode = headptr;
            cout << "          ";
            while (curNode != nullptr) {
                cout << curNode->getvalue() << " -> ";
                curNode = curNode->getptr();
            }
            cout << endl;
            curNode = headptr;
            cout << "          headptr: " << curNode << endl;
            cout << "          ";
            while (curNode != nullptr) {
                cout << curNode->getptr() << " -> ";
                curNode = curNode->getptr();
            }
            cout << endl;
        } // end print
}; // end LL

void get_op(const string& line, string* operation, int* num, int* location) {
    // turn the string into an input stream
    std::istringstream sin(line);
    *num = 100;
    *location = 100;
    sin >> *operation;
    if (*operation == "add" || *operation == "insert") {
        sin >> *num >> *location;
    }
    else if (*operation == "remove" || *operation == "delete") {
        sin >> *location;
    }
    else if (*operation == "push") {
        sin >> *num;
    }
    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *operation = "ignore";
    }
}

int main () {
    LinkedList list;
    string line;
    string operation;
    int num;
    int location;
    getline (cin, line);    
    while (!line.empty()) {
        get_op (line, &operation, &num, &location);
        // cout << operation << num;
        if (operation == "insert" || operation == "add"){
            list.insertNode(num, location);
        }
        else if (operation == "delete" || operation == "remove"){
            list.deleteNode(location);
        }
        else if (operation == "push") {
            list.push(num);
        }
        else if (operation == "pop"){
            list.pop();
        }
        else if (operation == "clear"){
            list.~LinkedList();            
        }
        else if (operation == "print"){
            list.printLinkedList();
        }
        else if (operation == "q" || operation == "quit") {
            break;
        }
        else {
            cout << "operation type undefined, re-enter please" << endl;
        }    
        getline (cin, line);
    }

    // node *sample = new node(99);
    // node *another = new node(100);
    // node *copyOfNode = new node(*sample);
    // cout << sample->getvalue() << " " << another->getvalue() << " " << copyOfNode->getvalue() << endl;
    // copyOfNode = another;
    // cout << copyOfNode->getvalue() << endl;

    return 0;
}
