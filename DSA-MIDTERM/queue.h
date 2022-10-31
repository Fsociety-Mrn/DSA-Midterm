#include <iostream>

class linkqueue{
public:
	struct Node {
		int data;
		struct Node *next;

	};
	
	int rear = 0, front = 0, asd = 0;
	struct Node* head = NULL; //node

//  push data
	void Enqueue(int new_data) {

		Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		new_node->next = head;
		head = new_node;
		rear++;
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
	void Dequeue()
	{
		int n = rear;
		struct Node* temp1 = head;
		if (n == 1)
		{
			head = temp1->next;

			delete(temp1);

			return;
		}
		for (int i = 0; i < n - 2; i++){
			temp1 = temp1->next;
		}
		struct Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		rear--;
		delete(temp2);
	}
	
//	clear stack
	void clear()
	{ 
	    head = NULL;
		return;
	}

};
