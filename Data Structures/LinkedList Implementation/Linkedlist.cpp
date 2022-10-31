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

	void insert(int new_data, int n) {

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
	void display() {

		struct Node* ptr;
		ptr = head;
		cout << "[";
		while (ptr != NULL) {
			cout << ptr->data;
			cout << ",";
			ptr = ptr->next;
		}
		cout << "]";
	}
	void Delete(int n)
	{
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
		delete(temp2);
	}

};

////CLASS TAKBO INHERIT FROM LINKLIST
class takbo :public linklist{
public:

	void insrt_elmnt(){
		try{
			int frst_elmnt, scnd_elmnt;
			cout << "\nEnter Element: ";
			cin >> frst_elmnt;
			cout << "\nEnter Position:";
			cin >> scnd_elmnt;

			insert(frst_elmnt, scnd_elmnt);
			run();
		}
		catch (exception e){
			cout << "Number Lang kapatid";
			system("pause");
			return insrt_elmnt();
		}


	}
	void dlt_elmnt()
	{
		try{
			int dlt_pare;
			cout << "\nEnter Position: ";
			cin >> dlt_pare;
			Delete(dlt_pare);
			run();

		}
		catch (exception e){
			cout << "Number Lang kapatid";
			system("pause");
			return insrt_elmnt();
		}
	}
	void run()
	{

		string chces;
		system("cls");
		display();
		cout << "\n[1] Insert element in nth position\n";
		cout << "[2] Delete element in nth position\n";
		cout << "[3] exit\n";
		cout << "Enter Menu: ";
		cin >> chces;

		if (chces == "1")
		{
			insrt_elmnt();
		}
		else if (chces == "2"){
			dlt_elmnt();
		}
		else if (chces == "3")
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
	void insertdisp(){
		insert(1, 1);
		insert(2, 1);
		insert(3, 1);
		insert(4, 1);
		insert(5, 1);
		insert(6, 1);
	}
};

///main function
int main() {
	takbo tak;
	tak.insertdisp();
	tak.run();
}
