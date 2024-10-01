#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void InsertionAtHead(int a, node* &head)
{
    node* m= new node(a);
    m -> next=head;
    head = m;
}

void InsertAtTail(int a, node* &head)
{
    node* o = new node(a);
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next= o;
    
}

void InsertAnywhere(int a, int position, node* &head)
{
    node* x= new node(a);
    
    node* temp=head;
    int current_p=0;
    while (current_p!=position-1)
    {
        temp=temp->next;
        current_p++;
    }

    x->next= temp->next;
    temp->next= x;
    
}

void UpdateAnywhere(int value, int p, node* &head)
{
    node* temp= head;
    int pos=0;
    while(pos!=p)
    {
        temp=temp->next;
        pos++;
    }
    temp->data=value;
}

void display(node* head)
{
    node* temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

void DeleteAtHead(node* &head)
{
    node* temp=head;
    head=head->next;
    free(temp);
}

void DeleteAtTail(node* &head)
{
    node* temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* a= temp->next; //To be deleted
    temp->next=NULL;
    free(a);
    
}

void DeleteAnywhere(int p, node* &head)
{
    node* temp= head;
    int current_p=0;
    while(current_p<p-1)
    {
        temp=temp->next;
        current_p++;
    }
    node* a= temp->next;
    temp->next=temp->next->next;
    free(a);
}

void Search(int a, node* &head)
{
    int x=0;
    node* temp=head;
    while (temp->next!=NULL)
    {
        if (temp->data==a)
        {
            x++;
        }
    }
    cout<<"Element found "<<x<<" times"<<endl;
    
}

int main()
{
    node* head = NULL;
    InsertionAtHead(5, head);
    InsertionAtHead(6, head);
    InsertAtTail(4,head);
    InsertAnywhere(2,1, head);
    UpdateAnywhere(14,1, head);
    DeleteAtHead(head);
    DeleteAtTail(head);
    InsertAnywhere(20,1, head);
    InsertAnywhere(9, 2, head);
    InsertAnywhere(14,2, head);
    DeleteAnywhere(2, head);
    InsertAnywhere(20, 3, head);
    display(head);
    Search(20, head);
    display(head);

    return 0;
}