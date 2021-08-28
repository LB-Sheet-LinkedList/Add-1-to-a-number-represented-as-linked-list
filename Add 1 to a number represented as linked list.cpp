class Solution
{
    public:
    
    Node* reverse(Node *head)
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL; 
		Node *next = NULL;
 
        while (current != NULL) 
		{
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        //basically we need  to handle 3 cases
        /*
        4 5 5 raha to sidha 1 add karke bahar
        4 5 9 raha to 1 add karo next me jaao ad agar vo 9 nahi hai to 1 add karke bahar
        9 9 9 raha to sabko 0 0 karo and 1 0 0 bnao last me ek 0 bnao bcoz aise ad karna easy hai
        */
        
        head=reverse(head);
        
        Node *cur=head;  //iterator bnaya
        
        while(cur!=NULL)
        {
            //ek ek place value ko handle karte chalo
            
            //9 9 9 wala case pehle lete hai
            if(cur->next==NULL && cur->data==9)
            {
                cur->data=1; 
                
                //nayi 0 wali node bnayi and usko last me laga diya
                Node *temp=new Node(0);
                
                temp->next=head;
                head=temp;            //temp ko naya head bnao ab
                cur=cur->next;
            }
            else if(cur->data==9)
            {
                cur->data=0;
                cur=cur->next;
            }
            else if(cur->data<9)
            {
                cur->data=cur->data+1;
                cur=cur->next;
                break;  //aage ke digit ka kaam nhi hai
            }
        }
        
        head=reverse(head);
        return head;
        
    }
};
