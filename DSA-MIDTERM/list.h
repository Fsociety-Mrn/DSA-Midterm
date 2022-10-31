#include <iostream>
#include <string>
#include <sstream>
using namespace std;


///CLASS LINKLIST
class linklist  {
	
public:
	struct Node {
		int data;
		struct Node *next;

	};

	struct Node* head = NULL; //node
	
//  insert data at specific position
	void insert(int new_data,int n) {

		Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		//head = new_node;
		if (n == 1)
		{
			new_node->next = head;
			head = new_node;
			return;
		}
		
		Node *temp = head;
		for (int i = 0; i < n - 2; i++)
		{
			temp = temp->next;
			
		}
		new_node->next = temp->next;
		temp->next = new_node;
		
	}
//	display all the element
	void get() {

		struct Node* ptr;
		ptr = head;
		cout << "[";
		while (ptr != NULL) {
			cout << ptr->data;
			cout << ",";
			ptr = ptr->next;
		}
		cout << "]"<<endl;
	}
	
//	check if empty
	bool isEmpty(){
		struct Node* ptr;
		ptr = head;
		if(ptr == NULL){
			return true;
		}else{
			return false;
		}
	}
	
//	remove specific position in linkedList
	bool removeAt(int n)
	{
		struct Node* temp1 = head;
		if (n == 1)
		{
			head = temp1->next;

			delete(temp1);

			return true;
		}
		for (int i = 0; i < n - 2; i++){
			if(temp1->next != NULL){
				temp1 = temp1->next;	
			}
			
		}
		
		if(temp1->next != NULL){
			struct Node* temp2 = temp1->next;
			temp1->next = temp2->next;
			cout<<temp2->data<<endl;
			delete(temp2);
			return true;
		}else{
			return false;
		}
			
	}
	
//	remove all element in linkedList
	void removeAll(){
		struct Node* temp1 = head;
		head = temp1->next = NULL;
		return;		
	}
	
};

