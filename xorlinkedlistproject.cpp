
#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;



class Node
{
	public:
	int data;
	Node* npx;
};
Node *head = NULL,*tail=NULL;
/* returns XORed value of the node addresses */
Node* XOR (Node *a, Node *b)
{
	return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
void inserti()
{

     Node *temp;
     temp = new Node();
     cout<<"enter the data : ";

     cin>>temp->data;

     temp->npx = XOR(tail,NULL);
     if(head==NULL){
        head=temp;
     }

     if(tail != NULL)
     {
             Node *next=XOR(tail->npx,0);
             tail->npx =XOR(next,temp);
     }
     tail = temp;


}


void display ()
{
	Node *curr = head;
	Node *prev = NULL;
	Node *next;

	cout << "Following are the nodes of Linked List: \n";

	while (curr != NULL)
	{
		// print current node
		cout<<curr->data<<" ";

		// get address of next node: curr->npx is
		// next^prev, so curr->npx^prev will be
		// next^prev^prev which is next
		next = XOR (prev, curr->npx);

		// update prev and curr for next iteration
		prev = curr;
		curr = next;
	}
}
int sizee()
    {
          Node *curr = head;
	      Node *prev = NULL;
	       Node *next;

        int countt = 0;

        while(curr!= NULL)
        {
            countt++;
          next = XOR (prev, curr->npx);
		prev = curr;
		curr = next;


        }
        return countt;
    }
        bool contains(int data)
    {
        Node *temp = head;

        while (temp != NULL){
            if(temp->data == data){
               return true;
            }
            temp = temp->npx;
        }
        return false;
    }

    void isEmpty()
    {
        Node *temp = head;
        if( (temp) == NULL )
        {
            cout<< "TRUE"<<endl ;

        }
        else
        {
            cout<< "FALSE"<<endl ;

        }
    }

int get(int position)
    {

	Node *prev = NULL;
	Node *next;
        Node* current = head;

        int count = 0;
        while (current != NULL)
        {
            if (count == position)
                cout<<((current->data))<<endl;
            count++;
            next = XOR (prev, current->npx);
		prev = current;
		current = next;

        }
    }


void reverseDisplay()
{
     Node *temp = head;
     Node *prev = NULL;
     Node *next;
     if(head == NULL)
     {
	cout<<"List empty ";
        return;
     }
     while(temp != NULL)
     {
                next = XOR(temp->npx,prev);
                prev = temp;
                temp = next;
     }
     next=temp;
     temp = prev;
     prev = NULL;
     while(temp != NULL)
     {
             cout<<temp->data<<" ";

                next = XOR(temp->npx,prev);
                prev = temp;
                temp = next;
     }


     cout<<"\n";
}
void searchi()
{
     Node *temp = head;
     Node *prev = NULL;
     Node *next;

     int n;
     cout<<"enter data to be searched : ";
     cin>>n;
     while(temp != NULL )
     {

          if(temp->data == n){
	       cout<<"found\n",temp->data;
               return;
           }
                next = XOR(temp->npx,prev);
                prev = temp;
                temp = next;
     }
     cout<<"data not found!!!\n";
     cout<<"\n";
}
Node* deletenode(Node *head)
{
     Node *temp = head;
     Node *prev = NULL;
     Node *next;
     int data;
     if(head == NULL)
     {
             cout<<"empty list !!!";
             return head;
     }
     cout<<"enter the item to be deleted : ";
     cin>>data;

     while(temp != NULL )
     {
                if(temp->data == data)
                   break;
                next = XOR(temp->npx,prev);
                prev = temp;
                temp = next;
     }
     if(temp  == NULL){
	  cout<<"data not found!!!";
          return head;
     }
     else{
        cout<<" deleted !!",temp->data;
    }

     next = XOR(temp->npx,prev);
     if(next== NULL && temp == head)
     {
               head = NULL;
               return head;
     }
     else if(next == NULL){
              prev->npx = XOR(XOR(prev->npx,temp),next);
              free(temp);
              return head;
     }
     else if(temp == head)
     {
             next->npx = XOR(XOR(temp,next->npx),NULL);
             head = next;
             free(temp);
             return head;
     }

     next->npx = XOR(XOR(temp,next->npx),prev);
     prev->npx = XOR(XOR(prev->npx,temp),next);
     free(temp);
     return head;
     display();
}

int main()
{

    int done = 0,ch,data,position;
    cout<<"------MENU DRIVEN PROGRAM----\n";
    while(!done)
    {
                cout<<"\n1)Insert\n2)Delete\n3)search\n4)Display\n5)Reverse display\n6)size\n7)contains\n8)getthevalue\n9)isEmpty\n10)exit\n";
                cout<<"enter your choice : ";
                cin>>ch;
     		switch(ch)
    		 {
                          case 1:

                            inserti();
                               break;
                          case 2:
                               head= deletenode(head);
                               break;
                          case 3:
                               searchi();
                               break;
                          case 4:
                               display();
                               break;

			  case 5: reverseDisplay();
                               break;
                               case 6:
                                   cout <<sizee() << "\n";

                               break;
                               case 7:
                                    cout<< "Enter data : "<<endl;
                                cin>>data;
                        if(contains(data)) cout << "TRUE\n";
                      else cout << "FALSE\n";
                               break;
                               case 8: cout<< "Enter position : "<<endl;

                           cin>>position;
                              get(position);
                               break;

                               case 9:
                                    isEmpty();

                               break;
                          default:
                                  done = 1;
     		}
    }


    	return 0;
}




