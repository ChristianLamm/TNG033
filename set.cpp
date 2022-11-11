#include "set.hpp"

// std::size_t is defined in the C++ standard library
// std::size_t is an unsigned integer type that can store the maximum size of any possible object
// sizes are non-negative integers -- i.e. unsigned integer type

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ******************************************************** */

// Default constructor
Set::Set() : head(new Node{0, nullptr}), counter(0) {
    // ADD CODE
}

// Constructor for creating a set from an int
Set::Set(int v) : Set{} {
    
    head->next = (new Node{v, nullptr});
    counter++;
    
}


// Constructor: create a set with the elements in V
// V is not sorted and may contain repeated elements
Set::Set(const std::vector<int>& V) : Set{} {
    // ADD CODE
}

// copy constructor
Set::Set(const Set& source) : Set() {
    // ADD CODE
}

// Assignment operator: copy-and-swap idiom
Set& Set::operator=(Set s) {
    // ADD CODE

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    
    Node* p = head;
    while (p != nullptr) {
        head = p->next;
        remove(p);
        p = head;

    }
    counter = 0;
}


// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE

    return counter;  // delete if needed
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
  
    return counter == 0;  // delete if needed

}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE

    return false;  // delete if needed
}

bool Set::operator<=(const Set& b) const {
    // ADD CODE

    return false;  // delete if needed
}

bool Set::operator==(const Set& b) const {
    // ADD CODE

    return false;  // delete if needed
}

bool Set::operator!=(const Set& b) const {
    // ADD CODE

    return false;  // delete if needed
}

bool Set::operator<(const Set& b) const {
    // ADD CODE

    return false;  // delete if needed
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const {
    // ADD CODE

    return Set{};  // delete if needed
}

// Set intersection
Set Set::operator*(const Set& b) const {
    // ADD CODE

    return Set{};  // delete if needed
}

// Set difference
Set Set::operator-(const Set& b) const {
    // ADD CODE

    return Set{};  // delete if needed
}

// set difference with set {x}
Set Set::operator-(int x) const {
    // ADD CODE

    return Set{};  // delete if needed
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Set& theSet) {
    if (theSet.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* temp = theSet.head->next;
        os << "{ ";

        while (temp != nullptr) {
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

void Set::insert(Node* p, int value) {
    p->next = new Node{ value, p->next};
    ++counter;
};

void Set::remove(Node* p) {
    delete p;
    counter--;
}
