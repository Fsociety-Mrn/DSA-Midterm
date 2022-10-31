#include <iostream>
#include<String>
using namespace std;

///CLASS LINKLIST
class linklist{
public:
	struct Node {
		int data;
		struct Node *next;

	};

	struct Node* head = NULL; //node

	void push(int new_data) {

		Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		new_node->next = head;
		head = new_node;
		return;
	}
	void display() {

		struct Node* ptr;
		ptr = head;
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	void pop()
	{
		struct Node* temp1 = head;
		head = temp1->next;
			delete(temp1);
			return;
	}
	void clear()
	{ 
	     head = NULL;
		return;
	}

};

////CLASS TAKBO INHERIT FROM LINKLIST
class takbo :public linklist{
public:
	int size = 0;
	void insrt_elmnt(){
		try{
			if (size != 10){
				size++;
				int frst_elmnt;
				cout << "\nEnter Element: ";
				cin >> frst_elmnt;
				push(frst_elmnt);
				run();
				
			}
			else{
				cout << "Stack Overflow pare" << endl;
				system("pause");
				run();
			}
		}
		catch (exception e){
			cout << "Number Lang kapatid";
			system("pause");
			return insrt_elmnt();
		}


	}
	void ask() {
		for (int i = 0; i < 35; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	void display_linklist(){
		if (size != 0){
			ask();
			cout << "Linklist: ";
			display();
			cout << endl;
			ask();
		}
	}

	void run()
	{
		string chces;
		system("cls");
		display_linklist();
		cout << "[1] Push element\n";
		cout << "[2] Pop element\n";
		cout << "[3] Clear Element\n";
		cout << "[4] exit\n";
		cout << "Enter Menu: ";
		cin >> chces;

		if (chces == "1")
		{
			insrt_elmnt();
		}
		else if (chces == "2"){
			if (size != 0)
			{
				size--;
				pop();
			}
			else{
				cout << "Stack underflow" << endl;
				system("pause");
			}
			return run();
		}
		else if (chces == "3")
		{
			size = 0;
			clear();
			return run();
		}
		else if (chces == "4")
		{
			
			system("exit");
		}
		else{
			cout << "Wrong Input!" << endl;
			system("pause");
			system("cls");
			return run();
		}
	}
	void input(){
		
		//size = 10;
	}
	
};

///main function
int main() {
	takbo tak;
	tak.input();
	tak.run();
}
