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
Set::Set() : head(new Node{ 0, nullptr }), counter(0) {
    // ADD CODE
}

// Constructor for creating a set from an int
Set::Set(int v) : Set{} {

    insert(v);
   
}


// Constructor: create a set with the elements in V
// V is not sorted and may contain repeated elements
Set::Set(const std::vector<int>& V) : Set{} {
    // 5, 3, 1
    // 4, 3, 4, 20, 15
    for (int i : V) {
        Node* ptr = head;

        while (ptr) {
            if (!ptr->next || ptr->next->value > i) {
                insert(i);
                
                break;
            }
            else if (ptr->next->value < i) {
                ptr = ptr->next;
            }
            else {
                break;
            }
        }
            
    }

}

// copy constructor
Set::Set(const Set& source) : Set() {
    Node* ptr1 = source.head->next;
    Node* ptr2 = head;

    while (ptr1 != nullptr) {
        insert(ptr1->value, ptr2);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    counter = source.counter;
}

// Assignment operator: copy-and-swap idiom
Set& Set::operator=(Set s) {
    std::swap(head, s.head);
    std::swap(counter, s.counter);

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {

    Node* p = head;
    while (p!= nullptr) {
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
    
    Node* element = head->next;

    while (element != nullptr && x != element->value) {
        element = element->next;
        
    }

    if (element == nullptr) {
        return false;
    }
    else return true;

}

bool Set::operator<=(const Set& b) const {
    
    Node* element = head->next;

    while(element != nullptr) {
    
        if (!b.member(element->value)) {
            return false;
        }
        element = element->next;


    }


    return true;  
}

bool Set::operator==(const Set& b) const {


    if(b <= *this && *this <= b) { //^^ the same code
        return true;
    }


    return false;  // delete if needed
}// delete if needed


bool Set::operator!=(const Set& b) const {

    if (b == *this) {
        return false;
    }
    else return true;
}

bool Set::operator<(const Set& b) const {
    if (*this <= b) { // Om ett snitt finns
        if (counter < b.counter) { // men antalet element e färre än det i b, sann delmängd
            return true;
        }
    }

    return false;  // delete if needed
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const {
   
    Set temp;

    Node* ptr1 = head->next;
    Node* ptr2 = b.head->next;

    

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value < ptr2->value) {
            temp.insert(ptr1->value);
            ptr1 = ptr1->next;
        }
        else if (ptr2->value < ptr1->value) {
            temp.insert(ptr2->value);
            ptr2 = ptr2->next;
        }
        else
        {
            temp.insert(ptr1->value);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }



    while (ptr1 != nullptr) {
        temp.insert(ptr1->value);
        ptr1 = ptr1->next;
    }
    while (ptr2 != nullptr) {
        temp.insert(ptr2->value);
        ptr2 = ptr2->next;
    }

    return temp;  // delete if needed
}

// Set intersection
Set Set::operator*(const Set& b) const {
    
    Set temp;

    Node* ptr = head->next;
   


    while (ptr != nullptr /*|| ptr1 != nullptr*/)
    {
        if (b.member(ptr->value) == true)
        {
            temp.insert(ptr->value);
        }
        ptr = ptr->next;

    }

    return temp;  // delete if needed
}

// Set difference
Set Set::operator-(const Set& b) const {
    Set temp;

    Node* ptr = head->next;



    while (ptr != nullptr /*|| ptr1 != nullptr*/)
    {
        if (b.member(ptr->value) == false)
        {
            temp.insert(ptr->value);
        }
        ptr = ptr->next;

    }

    return temp;  // delete if needed
}

// set difference with set {x}
Set Set::operator-(int x) const {
    
    Set temp1;
    temp1.insert(x);

    Set temp2 = operator-(temp1);


    return temp2;  // delete if needed
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Set& theSet) {
    if (theSet.empty()) {
        os << "Set is empty!";
    }
    else {
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

void Set::insert(int value, Node* p) {
    Node* node = new Node{ value, p->next };
    p->next = node;
};

void Set::remove(Node* p) {
    delete p;
    counter--;
}

void Set::insert(int value) {
    Node* ptr = head;

    while ((ptr->next != nullptr) && (ptr->next->value < value)) { //störst längst bak
        ptr = ptr->next;
    }
    if (ptr->next == nullptr || ptr->next->value != value) {
        insert(value, ptr); //sätt in den nya node:n mellan
    }
    counter++;
}