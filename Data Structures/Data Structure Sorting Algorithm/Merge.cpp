#include <iostream>
using namespace std;
struct Node
{
	int value;
	struct Node *next, *prev;
};
struct Node *head = NULL;
struct Node *split(struct Node *head);
int size, d, data;

// Function to merge two linked lists
struct Node *merge(struct Node *first, struct Node *second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (first->value < second->value) {
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}


// Function to do merge sort
struct Node *mergeSort(struct Node *head)
{
	if (!head || !head->next)
		return head;

	struct Node *second = split(head);
	// Recur for left and right halves
	head = mergeSort(head);
	second = mergeSort(second);

	// Merge the two sorted halves
	return merge(head, second);
}
void insert(int new_data) {

	Node* new_node = new Node;
	new_node->value = new_data;
	new_node->next = NULL;
	new_node->next = head;
	head = new_node;
	return;
}

/* Function to insert a new node at the
beginning of doubly linked list
*/
void insert(struct Node **head, int n)
{

	struct Node *temp;

	if (n >= 1)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		cout << "Enter value of the List: ";
		cin >> data;
		temp->value = data;
		temp->next = temp->prev = NULL;
		if (!(*head))
			(*head) = temp;
		else {
			temp->next = *head;
			(*head)->prev = temp;
			(*head) = temp;
		}
		for (int i = 2; i <= n; i++)
		{
			//lagayan ng node
			temp = (struct Node *)malloc(sizeof(struct Node));
			cout << "Enter value of the List: ";
			cin >> data;

			temp->value = data;
			temp->next = temp;
			temp->prev = NULL;
			if (!(*head))
				(*head) = temp;
			else {
				temp->next = *head;
				(*head)->prev = temp;
				(*head) = temp;
			}
		}
	}
}

void enteredvalue() {

	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {

		cout << ptr->value << " ";
		ptr = ptr->next;


	}

}
/* Function to print a doubly linked list in
both forward and backward directions
*/

void display()
{
	struct Node *temp = head;
	cout << "\nSorted in ascending: "<<endl;
	while (head) {
		cout << head->value << " ";
		temp = head;
		head = head->next;
	}

	cout << "\n\nSorted in descending: "<<endl;
	while (temp) {
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}


// Split the list to half
struct Node *split(struct Node *head)
{
	struct Node *fast = head, *slow = head;

	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	struct Node *temp = slow->next;
	slow->next = NULL;
	return temp;
}


// Driver program
int main(void) {

	cout << "MERGE SORTING" << endl << endl;
	cout << "enter size of the list: ";
	cin >> size;
	insert(&head, size);
	cout << " ";
	cout << endl;
	system("cls");
	cout << "MERGE SORTING" << endl << endl;
	cout << "enter size of the list: " << size << endl << endl;
	cout << "Enter value of the List: "<<endl;
	enteredvalue();

	head = mergeSort(head);
	display();
	cout << endl << endl;
	system("pause");
	return 0;
}