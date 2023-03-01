#include "llrec.h"
#include <iostream>

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	//takes in head linked list 
	//smaller creates LL from the smaller values from the pivot point
	//larger creates LL from the larger values from the pivot point
	//decide whether to use head or tail recursion
	
	//Node* Ltail = larger;
	//Node* Stail = smaller;
	//have to swithc the pointers so dont lose rest of list
	
	if(head == nullptr){ 
  	larger = nullptr; //if head is null sets everything to null
		
		smaller = nullptr;
  } 

	
	
	else{
  	if( pivot>= head->val){
			//Node* htemp = head->next;
			
			llpivot(head->next, smaller, larger, pivot);
			
			
			head->next = smaller;
			
			
			smaller = head;
		} 

		
		else{ 
			//Node* htemp = head->next;
			llpivot(head->next, smaller, larger, pivot);
			
			
			head->next = larger;
			
			larger = head;
		
		}
	
	}
	

	head = nullptr; //sets head to null on final run

	
	/*Node* Ltail = larger;
	Node* Stail = smaller;

	if (head != nullptr) {
        if (head->val > pivot) {
            if (Ltail == nullptr) {
                Ltail = head;
                larger = head;
            } else {
                Ltail->next = head;
                Ltail = Ltail->next;
            }
        } else if (head->val < pivot) {
            if (Stail == nullptr) {
                Stail = head;
                smaller = head;
            } else {
                Stail->next = head;
                Stail = Stail->next;
            }
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;

        llpivot(head, Stail, Ltail, pivot);
    }*/

	




}

/*int main(){
	Node* head = new Node;
	Node* smaller = new Node;
	Node* larger = new Node;
	head->next->val = 2;
	head->next->next->val = 4;
	head->next->next->next->val = 8;
	head->next->next->next->next->val = 3;

	llpivot(head, )

	Node* LPtemp = larger;
	Node* SPtemp = smaller;
	while(LPtemp -> next != NULL){
		cout<<LPtemp->next->val<<endl;
		LPtemp = LPtemp->next;
	}

	while(SPtemp -> next != NULL){
		cout<<SPtemp->next->val<<endl;
		SPtemp = SPtemp->next;
	}

	return 0;

}*/


