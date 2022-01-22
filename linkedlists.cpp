#include <iostream>
#include "hutils.cpp"

using namespace std;

struct slistNode {
    int data;
    struct slistNode* next;
};

class listNode{
    public:
    int data;
    listNode* next;
    // Default constructor
    listNode(){
        data = 0;
        next = NULL;
    }
     // Parameterised Constructor
    listNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

class linkList{
    listNode* head;
    public:

    linkList(){
        head = NULL;
    }
    int len();
    void insertNode(int);
    void printList();
    void deleteNode(int);
    void beginsert(int);
};

int linkList::len(){
    listNode* current = head;
    int pos = 0;
    while(current != NULL){
        current = current->next;
        pos++;
    }
    return pos;
}

void linkList::beginsert(int dat){
    listNode* in = new listNode(dat);
    
}

void linkList::deleteNode(int nOffset){
    listNode* current = head, * temp = NULL;
    
    if(current == NULL){
        printf("\nEmpty list");
        return;
    }
    
    if(nOffset == 0){
        head = head->next;
        return;
    }

    int llen = 0;

    while(current!=NULL and llen<nOffset){
        temp = current;
        current=current->next;
        llen ++;
    }
    if(current==NULL){
        if(llen == nOffset){
            temp->next = NULL;
            return;
        }else{
            printf("\nIndex too high");
        }

    }
    if(llen == nOffset){
        temp->next = current->next;
    }
}
void linkList::printList(){
    listNode* current = head;
    if(current == NULL){
        printf("\nEmpty list");
        return;
    }
    int item = 0;
    while(current!=NULL){
        printf("\nItem no. %d = %d",item,current->data);
        current = current->next;
        item ++;
    }
};

void linkList::insertNode(int dat){
    listNode* nnode = new listNode(dat);
    if(head == NULL){
        head = nnode;
        return;
    }
    
    listNode* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    
    current->next = nnode;
}

int main(){
    // slistNode node1;
    // cout << "Enter node1 data: ";
	// cin >> node1.data;
    // printf("%d",node1.data);
    linkList tlist = linkList();
    for(int i=0;i<7;i++){
        tlist.insertNode(i*2);
    }
    tlist.printList();
    tlist.deleteNode(0);
    tlist.printList();
}