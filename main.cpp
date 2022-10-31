#include <iostream>
#include <string>
#include <sstream>
using namespace std;


///CLASS LINKLIST
class linklist{
private:
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
		cout << "]";
	}
	void remove(int n)
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
	
	
	
public:
	int sizeList = 0;
	
	int listMenu(){
		string size = "";
		try{
			system("cls");
			cout<<"------------- List -------------\n";
			cout <<"Enter a size: ";
			cin>> size;
			
			sizeList = (int) size;
		}catch(const exception& ex){
			cout<<"asd";
		}
	}
};


// main menu
int AdtMenu(){
		
	system("cls"); // clear text
	
	string menu="";
	
	cout<<"1. List"<< endl;
	cout<<"2. Stack"<< endl;
	cout<<"3. Queue"<< endl;
	cout<<"4. Exit"<< endl;
	cout<<"Enter Menu: ";
	cin>>menu;
	
		
	if (menu == "1"){
		linklist().listMenu();

	}else if (menu == "2"){
		cout<<"2. Stack"<< endl;
		system("pause");

		return AdtMenu();
	}else if (menu == "3"){
		cout<<"3. Queue"<< endl;
		system("pause");
		
		return AdtMenu();
	}else if (menu == "4"){
		cout<<"Exiting the program......"<< endl;
		return 0;
	}else{
		cout<<endl;
		cout<<"Please select one of the options."<< endl;
		system("pause"); //pause screen
	
		return AdtMenu();	
	}
}

int main() {
	AdtMenu();
}








