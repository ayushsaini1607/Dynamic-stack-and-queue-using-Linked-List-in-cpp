#include<iostream>
#include<process.h>

using namespace std;

class Queue;

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
     friend class Queue;
};

class Queue
{
    Node *front,*rear;
    public:
      Queue()
        {
            front=NULL;
            rear=NULL;
        }
      bool isEmpty();
      void enqueue(int);
      int dequeue();
      void display();
};

bool Queue::isEmpty()
{
    return front==NULL;
}

void Queue::display()
{
   if(isEmpty())
    {
        cout<<"\nQueue Underflow!";
        return;  
    }
    Node *temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<"NULL";
}

int Queue::dequeue()
{
    if(isEmpty())
     {
         cout<<"\nQueue Underflow!";
         exit(-1);
     }
    int data;
    if(front==rear)
      {
          data=front->data;
          delete front;
          front=NULL;
          rear=NULL;
          return data;
      }
    data=front->data;
    Node *temp=front;
    front=front->link;
    delete temp;
    return data;
}

void Queue::enqueue(int data)
{
    Node *newnode=new Node(data);
    if(isEmpty())
     {
        front=newnode;
        rear=newnode;
        return;
     }
    rear->link=newnode;
    rear=newnode;
}

int main()
{
    int data,ch;
    Queue Q;
    while(true)
     {
         cout<<"\n1.Add data to queue";
         cout<<"\n2.Delete data from queue";
         cout<<"\n3.Display queue";
         cout<<"\n4.Exit";
         cout<<"\n\nEnter your choice no : ";
         cin>>ch;
         switch(ch)
          {
              case 1:
                 cout<<"\nEnter data to add to queue: ";
                 cin>>data;
                 Q.enqueue(data);
                 cout<<"\nElement added";
                 break;
              
              case 2:
                data=Q.dequeue();
                cout<<"\nData deleted : "<<data;
                break;
            
              case 3:
                 Q.display();
                 break;
            
              case 4:
                 cout<<"\nManual exit!";
                 exit(0);
            
              default:
                 cout<<"\nInvalid value!";
          }
     }
}