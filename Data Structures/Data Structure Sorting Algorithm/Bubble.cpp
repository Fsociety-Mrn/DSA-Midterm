#include <iostream>
#include<String>
using namespace std;
struct Node {
	int data;
	struct Node *next;

};

struct Node* head = NULL; //node

void Ascending_sort()
{
	int swapped;

	Node *leftPtr; 
	Node *rightPrt = NULL;
	do
	{
		swapped = 0;
		leftPtr = head;
		while (leftPtr->next != rightPrt)
		{
			if (leftPtr->data > leftPtr->next->data)
			{
				
				int temp = leftPtr->data;
				leftPtr->data = leftPtr->next->data;
				leftPtr->next->data = temp;
				swapped = 1;
			}
			leftPtr = leftPtr->next;
			
		}
	
		rightPrt = leftPtr;

	} while (swapped);
	//Display Output
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
void Descending_sort()
{
	int swapped;

	Node *leftPtr;
	Node *rightPrt = NULL;
	do
	{
		swapped = 0;
		leftPtr = head;
		while (leftPtr->next != rightPrt)
		{
			if (leftPtr->data < leftPtr->next->data)
			{
				
				int temp = leftPtr->data;
				leftPtr->data = leftPtr->next->data;
				leftPtr->next->data = temp;
				swapped = 1;
			}
			leftPtr = leftPtr->next;

		}

		rightPrt = leftPtr;

	} while (swapped);
	//Display Output
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->data << " ";
		ptr = ptr->next;

	}
	cout << endl;
}
void insert(int new_data) {

	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = NULL;
	new_node->next = head;
	head = new_node;
	return;
}
void clear(){
	head = NULL;

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
int main() {
	system("cls");
	enter_input();
	system("cls");
	cout << "BUBBLE SORTING" << endl << endl<<endl;

	cout << "size of the list: "<<size<<endl<<endl;
	cout << "entered value of the list: \n";
	display();
	cout << "\n\nSorted in ascending: "<<endl;
	Ascending_sort();
	cout << "Sorted in descending: "<<endl;
	Descending_sort();
	cout << endl << endl;

	system("pause");
	return main();
	
}
