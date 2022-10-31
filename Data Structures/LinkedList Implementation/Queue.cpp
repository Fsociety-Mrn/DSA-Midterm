#include <iostream>
#include<String>
using namespace std;

struct Node {
	int data;
	struct Node *next;

};
int rear = 0, front = 0, asd = 0;
struct Node* head = NULL; //node

void Enqueue(int new_data) {

	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = NULL;
	new_node->next = head;
	head = new_node;
	rear++;
	return;
}

void display() {

	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;

	}
	return;
}
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

void yeyeye(int size){
	system("cls");
	string a;
	display();
	cout << "\n[1] Enqueue ";
	cout << "\n[2] Dequeue";
	cout << "\n[3] Exit ";
	cout << "\nChoose: ";
	cin >> a;
	if (a == "1") {
		if (asd == size)
		{
			cout << "Queue is Full\n";
			system("pause");
			return yeyeye(size);
		}
		else{
			cin >> a;
			Enqueue(stoi(a));
			asd++;
		}

	}
	else if (a == "2"){
		if (asd <= 0){
			cout << "Queue is Empty\n";
			system("pause");
			return yeyeye(size);
		}
		else{

			Dequeue();
			asd--;
		}

	}
	else if (a == "3"){

		system("exit");
	}
	else{
		cout << "Mali ang iyong ininput\n";
		system("pause");

	}

	return yeyeye(size);
}


int main(){
	string input;
	try{
		system("cls");
		cout << "Input Size: ";
		cin >> input;
		yeyeye(stoi(input));
	}
	catch (exception e)
	{
		cout << "BOBO!\n";
		system("pause");
		return main();
	}
	system("pause");
	return 0;
}