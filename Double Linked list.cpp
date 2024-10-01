#include<iostream>
using namespace std;

class node
{
public:
        int data;
        node* previous;
        node* next;

        node(int val)
        {
            data=val;
            previous=NULL;
            next=NULL;
        }
};

class dll
{
    public:
            node* head;
            node* tail;

            dll()
            {
                head=NULL;
                tail=NULL;
            }

            void InsertAtStart(int val)
            {
                node* n = new node(val);
                if (head==NULL)
        
                {
                    head = n;
                    tail = n;
                }

                n->next=head;
                head->previous= n;
                head = n;  
            }

            void InsertAtEnd(int val)
            {
                node* n= new node(val);
                if (tail==NULL)
                {
                    head= n;
                    tail= n;
                }

                tail->next=n;
                n->previous = tail;
                tail= n;
                
            }
 
            void InsertAnywhere(int val, int p)
            {
                node* n= new node(val);
                int current_p=0;
                node* temp= head;
                while (current_p<p-1)
                {
                    temp=temp->next;
                    current_p++;
                }

                n->next=temp->next;
                temp->next=n;
                n->previous=temp;
                n->next->previous=n;  
            }

            void display()
            {
                node* temp = head;
                cout<<"NULL<-";
                while (temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->next;
                }
                cout<<"->NULL";
                cout<<endl;
            }

            void DeletingAtStart()
            {
                node* temp=head;
                head=head->next;
                head->next->previous=NULL;
                free(temp);
            }

            void DeletingAtEnd()
            {
                node*temp= tail;
                tail->previous->next=NULL;
                tail=tail->previous;
                free(temp);
            }

            void DeletingAnywhere(int p)
            {
                int current_p=0;
                node* temp= head;
                while (current_p<p)
                {
                    temp=temp->next;
                    current_p++;
                }
                node* n= temp;
                temp->previous->next=temp->next;
                temp->next->previous=temp->previous;
                free(n);
            }

            void update(int val, int p)
            {
                node* temp=head;
                int current_p=0;
                while (current_p<p)
                {
                    temp=temp->next;
                    current_p++;
                }
                temp->data=val;
            }

            void search(int val)
            {
                int c=0;
                node* temp=head;
                while (temp!=NULL)
                {
                    if (temp->data==val)
                    {
                        c++;
                    }
                    temp=temp->next;
                }
                cout<<"Found "<<val<<", "<<c<<" times.";
            }
};

int main()
{
    node* new_node= new node(5);
    dll l1;
    l1.head= new_node;
    l1.tail= new_node;

    l1.InsertAtStart(1);
    l1.InsertAtStart(2);
    l1.InsertAtStart(3);
    l1.InsertAtStart(4);
    l1.InsertAtStart(5);
    l1.InsertAtStart(6);
    l1.InsertAtEnd(0);
    l1.display();
    l1.InsertAnywhere(13,2);
    l1.display();
    l1.DeletingAtStart();
    l1.display();
    l1.DeletingAtEnd();
    l1.display();
    l1.DeletingAnywhere(3);
    l1.display();
    l1.update(6,1);
    l1.display();
    l1.search(5);
    return 0;
}
