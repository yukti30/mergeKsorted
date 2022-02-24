// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* h1 , Node* h2){
        Node* head = new Node(-1);
        Node* temp = head;
        Node* ch1 = h1;
        Node* ch2 = h2;
        while(ch1 != NULL && ch2 != NULL){
            if(ch1->data <= ch2->data){
                Node* newnode = new Node(ch1->data);
                temp->next = newnode;
                temp = newnode;
                ch1 = ch1->next;
            }
            else{
                Node* newnode = new Node(ch2->data);
                temp->next = newnode;
                temp = newnode;
                ch2 = ch2->next;
            }
            
        }
        while(ch1 != NULL){
            Node* newnode = new Node(ch1->data);
                temp->next = newnode;
                temp = newnode;
                ch1 = ch1->next;
        }
        
        while(ch2 != NULL ){
            Node* newnode = new Node(ch2->data);
                temp->next = newnode;
                temp = newnode;
                ch2 = ch2->next;
        }
        
        return head->next;
    }
    
    
    Node * mergeKLists(Node *arr[], int K)
    {
           
           for(int i = 1 ; i < K ; i++){
               arr[0] = merge(arr[0] , arr[i]);
           }
           
           return arr[0];
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends