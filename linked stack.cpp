#include<iostream>
#include<process.h>

using namespace std;

class Stack;

class Node
{
   int data;
   Node *link;
   public:
     Node()
       {
           data=-1;
           link=NULL;
       }
     Node(int d, Node* l=NULL)
       {
           data=d;
           link=l;
       } 
     friend class Stack;
};

class Stack
{
    Node *top;
    public:
      Stack()
        {
            top=NULL;
        }
      bool isEmpty();
      void push(int);
      int pop();
      void display();
};

void Stack::display()
{
    if(isEmpty())
      {
          cout<<"\nStack underflow!";
          return;
      }
    Node *temp=top;
    while(temp!=NULL)
     {
         cout<<temp->data<<"->";
         temp=temp->link;
     }
    cout<<"NULL";
}

bool Stack::isEmpty()
{
    return top==NULL;
}

int Stack::pop()
{
    if(isEmpty())
      {
          cout<<"\nStack Underflow!";
          exit(-1);
      }
    Node *temp=top;
    int data=temp->data;
    top=top->link;
    delete temp;
    return data;
}

void Stack::push(int data)
{
   Node *newnode=new Node(data,top);
   top=newnode;
}

int main()
{
    int ch,data;
    Stack S;
    while(true)
     {
         cout<<"\n1.Push element to stack: ";
         cout<<"\n2.Pop element from stack: ";
         cout<<"\n3.Display stack from top: ";
         cout<<"\n4.Exit";
         cout<<"\n\nEnter your choice no : ";
         cin>>ch;
         switch(ch)
          {
              case 1:
                 cout<<"\nEnter data to push into stack: ";
                 cin>>data;
                 S.push(data);
                 cout<<"\nElement added";
                 break;
              
              case 2:
                data=S.pop();
                cout<<"\nData deleted : "<<data;
                break;
            
              case 3:
                 S.display();
                 break;
            
              case 4:
                 cout<<"\nManual exit!";
                 exit(0);
            
              default:
                 cout<<"\nInvalid value!";
          }
     }
}