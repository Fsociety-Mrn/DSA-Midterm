// C++ implementation of the approach SELECTION
#include <iostream> 
using namespace std;

// Linked List Node 
struct Node {
	int data;
	Node* next;
};

struct Node* head = NULL; //Node

void insert(int new_data) {
	Node* new_Node = new Node;
	new_Node->data = new_data;
	new_Node->next = NULL;
	new_Node->next = head;
	head = new_Node;
	return;

}

void ascending_sort()
{
	Node* temp = head;

	// Traverse the List 
	while (temp) {
		Node* min = temp;
		Node* r = temp->next;

		// Traverse the unsorted sublist 
		while (r) {
			if (min->data > r->data)
				min = r;

			r = r->next;
		}

		// Swap Data 
		int x = temp->data;
		temp->data = min->data;
		min->data = x;
		temp = temp->next;
	}
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->data << " ";
		ptr = ptr->next;


	}
}

void descending_sort()
{
	Node* temp = head;

	// Traverse the List 
	while (temp) {
		Node* min = temp;
		Node* r = temp->next;

		// Traverse the unsorted sublist 
		while (r) {
			if (min->data < r->data)
				min = r;

			r = r->next;
		}

		// Swap Data 
		int x = temp->data;
		temp->data = min->data;
		min->data = x;
		temp = temp->next;
	}
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->data << " ";
		ptr = ptr->next;


	}
}

void display() {

	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->data << " ";
		ptr = ptr->next;


	}

}
int size = 0;
void enter_input(){
	int value = 0;
	cout << "enter size of the list: ";
	cin >> size;
	cout << endl << endl;
	for (int i = 0; i < size; i++){
		cout << "Enter value of the List: ";
		cin >> value;
		insert(value);
	}
}
int main()
{
	
	system("cls");
	enter_input();
	system("cls");
	cout << "SELECTION SORTING" << endl << endl << endl;

	cout << "size of the list: " << size << endl << endl;
	cout << "entered value of the list: \n";
	display();
	cout << "\n\nSorted in ascending: " << endl;
	ascending_sort();
	cout << "\nSorted in descending: " << endl;
	descending_sort();
	cout << endl << endl;

	system("pause");
	return main();
}
