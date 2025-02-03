#include <iostream>
using namespace std;
struct SNode {
int data;
SNode *next;
};

class CList {
private:
SNode *head;
public:
CList() { head = new SNode; head->next = NULL; }
void createList(int *value, int n);
void printList();
bool insertNode(int pos, int value);
bool removeNode(int pos);
~CList();
};

void CList::createList(int *value, int n) {
SNode *temp;
while (--n >= 0) {
temp = new SNode;
temp->data = value[n];
temp->next = head->next;
head->next = temp;
}
}

void CList::printList() {
SNode *p = head;
while (p->next != NULL) {
cout << p->next->data << ' ';
p = p->next;
}
cout << endl;
}

bool CList::insertNode(int pos, int value) {
SNode *p = head;
while (p) {
pos--;
if (pos == -1) {
SNode *q = new SNode, *t;
t = p->next;
p->next = q;
q->data = value;
q->next = t;
return true;
}
p = p->next;
}
return false;
}

bool CList::removeNode(int pos) {
SNode *p = head;
while (p != NULL) {
pos--;
if (pos == 0) {
if (p->next == NULL) return false;
SNode *t = p->next;
p->next = t->next;
delete t;
return true;
}
p = p->next;
}
return false;
}

CList::~CList() {
SNode *p;
do {
p = head;
head = p->next;
delete p;
} while (head != NULL);
}
