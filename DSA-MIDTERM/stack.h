#include <iostream>

class linkstack{
public:
	struct Node {
		int data;
		struct Node *next;

	};

	struct Node* head = NULL; //node

//  push data
	void push(int new_data) {

		Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		new_node->next = head;
		head = new_node;
		return;
	}
	
//  display data	
	void display() {

		struct Node* ptr;
		ptr = head;
		cout << "[";
		while (ptr != NULL) {
			cout << ptr->data << ",";
			ptr = ptr->next;
		}
		cout << "]"<<endl;
	}
	
//	check if empty
	bool empty(){
		struct Node* ptr;
		ptr = head;
		if(ptr == NULL){
			return true;
		}else{
			return false;
		}
	}	
	
//	pop data
	void pop()
	{
		struct Node* temp1 = head;
		head = temp1->next;
		delete(temp1);
		return;
	}
	
//	clear stack
	void clear()
	{ 
	    head = NULL;
		return;
	}

};
