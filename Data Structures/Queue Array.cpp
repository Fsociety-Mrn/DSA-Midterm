#include<iostream>
#include<String>
using namespace std;

string input;

int size = 0, Queue[5], front = -1, rear = -1;
bool isEmpty(){
	return front == -1 && rear == -1;
}
bool isFull(){
	return rear == front;
}
int EnQueue(int x){

	if ((rear + 1)% size == front)
	{
		cout << "Queue Array is Full\n";
		system("Pause");
		return 0;
	}
	else{
		if (isEmpty()){
			front = rear = 0;
	}
		else{
			rear += 1 % size;
		}
		Queue[rear] = x;
	}
}
int DeQueue(){
	if (isEmpty()){
		
		cout << "Queue Array is Empty\n";
		system("Pause");
		return 0;
	}
   else
    {
	   if (isFull())
	   {
		   front = rear = -1;
	   }
	   else{
		   cout << "Element Deque is : " << Queue[front];
		   front = (front + 1) % size;
	   }
    }
	return 0;
}

void display(){
	if (isEmpty()){
		cout << "Queue Array is Empty\n";
	}
	else
	{
		cout << "Queue List: ";
		for (int i = front; i <= rear; i++){
			cout << Queue[i] << " ";
		}
	}
	cout << endl;
}
void array(){
	int ints;
	system("cls");
	display();
	cout << "[1] Enqueue \n";
	cout << "[2] Dequeue \n";
	cout << "[3] Exit \n";
	cin >>input;
	if (input == "1"){
		cout << "Enqueue: ";
		cin >> ints;
		EnQueue(ints);
		return array();
	}
	else if (input == "2"){
		DeQueue();
		return array();
	}
	else if (input == "3"){
		system("exit");
	}
	else{
		return array();
	}
}

int main(){

	try{
		system("cls");
		cout << "Input Queue Size: ";
		cin >> input;
		size = stoi(input);
		Queue[size];
		array();
	}
	catch (exception e){
		cout << "Invalid Input\n";
		system("Pause\n");
		return main();
	}
	system("Pause");
	return 0;
}