#include<bits/stdc++.h>
using namespace std;
class node{
    public: 
        int val;
        node* next;
        node(int val){
            this->val = val;
            this->next = NULL;
        }
        node(int val, node *next){
            this->val = val;
            this->next = next;
        }
};
class LinkedList{
    // Elements:
        // head
        // tail
    // Functions:
        // pushFront(key)    O(1)
        // topFront()    O(1)
        // popFront()    O(1)
        // pushBack(key)    O(n) | O(1)
        // topBack()    O(n) | O(1)
        // popBack()    O(n)
        // find(key)    O(n)
        // erase(key)    O(n)
        // empty()    O(1)
        // addBefore(node, key)    O(n)

    public:
    node *head, *tail;
    LinkedList(){
        head=tail=NULL;
    }
    void pushFront(int key){
        node *tmp=new node(key);
        if(head == NULL){
            head = tail = tmp;
        }else{
            tmp->next=head;
            head=tmp;
        }
    }
    int topFront(){
        return head->val;
    }
    void popFront(){
        if(head->next == NULL){
            cout<<head<<" deleted\n";
            delete head;
            head=tail=NULL;
        }else{
            node *tmp = head;
            head=head->next;
            cout<<tmp->val<<" deleted\n";
            delete tmp;
        }
    }
    void pushBack(int key){
        node *tmp = new node(key);
        if(head == NULL){
            head=tail=tmp;
        }else{
            tail->next=tmp;
            tail=tmp;
            // node *itr=head;
            // while(itr->next!=NULL) itr=itr->next;
            // itr->next=tmp;
        }
    }
    int topBack(){
        return tail->val;
        // node *itr=head;
        // while(itr->next!=NULL) itr=itr->next;
        // return itr->val;
    }
    void popBack(){
        node *itr=head;
        if(head->next==NULL){
            cout<<head->val<<" deleted\n";
            delete head;
            head=tail=NULL;
        }
        while(itr->next->next!=NULL) itr=itr->next;
        tail=itr;
        cout<<itr->next->val<<" deleted\n";
        delete itr->next;
        itr->next=NULL;
    }
    node* find(int key) {
        node *tmp=head;
        while(tmp!=NULL && tmp->val!=key) tmp=tmp->next;
        return tmp;
    }
    void erase(int key) {
        if(head->val == key){
            if(head==tail){
                cout<<head->val<<" deleted\n";
                delete head;
                head=tail=NULL;
            }else{
                node *tmp = head;
                head=head->next;
                cout<<tmp->val<<" deleted\n";
                delete tmp;
            }
        }
        node *itr=head;
        while(itr->next->val!=key && itr->next!=NULL) itr=itr->next;
        node *tmp=itr->next;
        itr=itr->next->next;
        cout<<tmp->val<<" deleted\n";
        delete tmp;
    }
    bool empty() {return head==NULL;}
    void addBefore(node *ref, int key){
        node *tmp=new node(key), *itr=head;
        while(itr->next!=ref) itr=itr->next;
        tmp->next=itr->next;
        itr->next=tmp;
    }
    void addAfter(node *ref, int key){
        node *tmp=new node(key,ref->next);
        ref->next=tmp;
    }
    void print(){
        cout<<"Linked List contents: ";
        node *itr=head;
        while(itr!=NULL){
            cout<<itr->val<<" ";
            itr=itr->next;
        }
        cout<<"\n";
    }
};
void testLinkedList(){
    LinkedList *test=new LinkedList();
    cout<<"Empty Linked List: "<<test->empty()<<"\n";
    test->pushFront(1);
    test->pushFront(2);
    test->pushFront(3);
    cout<<"Empty Linked List: "<<test->empty()<<"\n";
    test->print();
    cout<<"Front of Linked List: "<<test->topFront()<<"\n";
    test->popFront();
    test->print();
    cout<<"Front of Linked List: "<<test->topFront()<<"\n";
    cout<<"Back of Linked List: "<<test->topBack()<<"\n";
    test->pushBack(4);
    test->print();
    cout<<"Back of Linxked List: "<<test->topBack()<<"\n";
    test->popBack();
    test->print();
    cout<<"Back of Linked List: "<<test->topBack()<<"\n";
    test->pushBack(5);
    test->pushBack(6);
    test->pushBack(7);
    node *tmp = test->find(1);
    test->print();
    test->addAfter(tmp,10);
    test->print();
    test->addBefore(tmp,11);
    test->print();
}
int main(){
    testLinkedList();
    return 0;
}
