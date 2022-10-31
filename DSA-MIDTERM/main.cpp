#include <iostream>
#include <string>
#include <sstream>

#include "list.h"
#include "stack.h"
#include "queue.h"

using namespace std;


class adtMain{
	
	linklist list; //call linklist class in list.h file
	
	linkstack stack; //call linkstack class in stack.h file
	int insertStack = 0;
	int size = 0;
	
	linkqueue queu;
	int insertQueu = 0;
	int sizeQueu = 0;
	
	public:
// ***************************** ADT MAIN MENU ***************************** //
	int AdtMenu(){
		
		system("cls"); // clear text
	
		string menu="";
		cout<<"******** ADT MAIN MENU ********\n";
		cout<<"1. List"<< endl;
		cout<<"2. Stack"<< endl;
		cout<<"3. Queue"<< endl;
		cout<<"4. Exit"<< endl;
		cout<<"Enter Menu: ";
		cin>>menu;
	
		
		if (menu == "1"){

			enterSizeList(); //list
			
		}else if (menu == "2"){
			
			enterSizeStack();

		}else if (menu == "3"){
			enterSizeQueue();
		
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
	
// ***************************** List ***************************** //
	int enterSizeList(){
		int size = 0;

		system("cls");
		cout<<"------------- List -------------\n";
		cout <<"Enter a size: ";
		if (cin>> size){
//			insertStack = size;
			listMainMenu(size);
		}else{
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<endl;
			cout<<"Invalid Input \n";
			system("pause");
			return enterSizeList();
		}			
	}
	
	//List mainmenu
	void listMainMenu(int size){
				
		string menu="";
		
		system("cls");
		cout<<"------------- List -------------\n";
		cout <<"Enter a size: " <<size<<endl;
		cout<<"1. Insert Data"<< endl;
		cout<<"2. Delete Data"<< endl;
		cout<<"3. Display Data"<< endl;
		cout<<"4. Exit"<< endl;
		cout<<"Enter Menu: ";
		cin>>menu;
	
		
		if (menu == "1"){ //insert Data

			insertDataList(size);
			
		}else if (menu == "2"){ //delete Data
		
			//list.delete(); //delete specific position element in data
			if (list.isEmpty()){ //check if element is empty
				cout<<"Please insert data first before deleting a data \n\n";
				system("pause");
			}else{
				cout<<"------------- delete data -------------\n";
				deleteDatalist();
				return listMainMenu(size);
			}
			

			return listMainMenu(size);
		}else if (menu == "3"){ //display data
			
			list.get(); //diplay all element in a list
			system("pause");
			return listMainMenu(size);
			
		}else if (menu == "4"){ //back to adt main menu
			
			if(!list.isEmpty()){ //check if List is not empty
				list.removeAll(); //to replace all element in position
			}
			
			cout<<"going back to mainmenu......"<< endl;
			system("pause");
			AdtMenu();
			
		}else{
			
			cout<<endl;
			cout<<"Please select one of the options."<< endl;
			system("pause"); //pause screen
	
			return listMainMenu(size);	
			
		}
	}
	
//	insert List
	void insertDataList(int size){
		//note: this function will replace all the inputed data
		
		if(!list.isEmpty()){ //check if List is not empty
			list.removeAll(); //to replace all element in position
		}
		
		int data=0; //data input
		
		cout<<"------------- insert data -------------\n";
		for (int i=0; i<size; i++){

			cout<<"Data: ";
			if(cin>> data){
				
				list.insert(data,1+i);
			}else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid input, please select data again \n\n";
				system("pause");
				listMainMenu(size);
				
			}
		}
		
		listMainMenu(size);
	}
	
	// delete List
	void deleteDatalist(){
		int position=NULL;
		cout<<"Position: ";
		if (cin>>position){
			if(list.removeAt(position)){
				cout<<"Data succesfully remove it\n\n";
				system("pause");
			}else{
				cout<<"Invalid position\n\n";
				deleteDatalist();
			}
			
			
		}else{
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Invalid input\n\n";
			system("pause");
			deleteDatalist();	
		}
	}
	
// ***************************** Stack ***************************** //	

	int enterSizeStack(){
		
		system("cls");
		cout<<"------------- Stack -------------\n";
		cout <<"Enter a size: ";
		if (cin>> size){
			
			insertStack = size;
			
			stackMainMenu(insertStack);
		}else{
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<endl;
			cout<<"Invalid Input \n";
			system("pause");
			return enterSizeStack();
		}			
	}	
	
//stack mainmenu
	void stackMainMenu(int sizes){
				
		string menu="";
		
		system("cls");
		cout<<"------------- Stack -------------\n";
		cout <<"Enter a size: " <<size<<endl;
		cout<<"1. Push in stack"<< endl;
		cout<<"2. Pop from stack"<< endl;
		cout<<"3. Display Stack"<< endl;
		cout<<"4. Exit"<< endl;
		cout<<"Enter Menu: ";
		cin>>menu;
		
		
		
		if (menu == "1"){ //insert Data

			pushDataStack(insertStack);
			
		}else if (menu == "2"){ //delete Data
		
			//list.delete(); //delete specific position element in data
			if (stack.empty()){ //check if element is empty
				cout<<"Nothing to pop please push data \n\n";
				system("pause");
			}else{
				cout<<"------------- push data -------------\n\n";
				insertStack++;
				stack.pop();
				cout<<"please display stack to see changes\n";
				system("pause");
				return stackMainMenu(size);
			}
			

			return listMainMenu(size);
		}else if (menu == "3"){ //display data
			
			stack.display(); //diplay all element in a list
			system("pause");
			return stackMainMenu(size);
			
		}else if (menu == "4"){ //back to adt main menu
			
			if(!stack.empty()){ //check if List is not empty
				stack.clear(); //to replace all element in position
			}
			
			cout<<"going back to mainmenu......"<< endl;
			system("pause");
			AdtMenu();
			
		}else{
			
			cout<<endl;
			cout<<"Please select one of the options."<< endl;
			system("pause"); //pause screen
	
			return stackMainMenu(size);	
			
		}
	}	
	
	
//	stack push data
	void pushDataStack(int size){
		
		int data=0; //data input
		int sizes = size;
		cout<<"------------- push data -------------\n";
		for (int i=sizes; i>0; i--){

			cout<<"Data: ";
			if(cin>> data){
				insertStack--;
				stack.push(data);
			}else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid input, please select data again \n\n";
				system("pause");
				insertStack=size;
				stackMainMenu(size);
				
			}
		}
		
		stackMainMenu(size);
	}
	
// ***************************** Queue ***************************** //		

	int enterSizeQueue(){
		
//		int insertQueu = 0;
//		int sizeQueu = 0;
		
		system("cls");
		cout<<"------------- Queue -------------\n";
		cout <<"Enter a size: ";
		if (cin>> sizeQueu){
			
			insertQueu = sizeQueu;
			
			queueMainMenu();
		}else{
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<endl;
			cout<<"Invalid Input \n";
			system("pause");
			return enterSizeQueue();
		}			
	}
	
	
	//stack mainmenu
	void queueMainMenu(){
				
		string menu="";
		
		system("cls");
		cout<<"------------- Queue -------------\n";
		cout <<"Enter a size: " <<sizeQueu<<endl;
		cout<<"1. Enqueue"<< endl;
		cout<<"2. Dequeue"<< endl;
		cout<<"3. Display Queue"<< endl;
		cout<<"4. Exit"<< endl;
		cout<<"Enter Menu: ";
		cin>>menu;
		
		
		
		if (menu == "1"){ //insert Data

			enqueueDataQue(insertQueu);
			
		}else if (menu == "2"){ //delete Data
		
			//list.delete(); //delete specific position element in data
			if (queu.empty()){ //check if element is empty
				cout<<"Nothing to dequeue please enqueue data \n\n";
				system("pause");
			}else{
				cout<<"------------- dequeue data -------------\n\n";
				insertQueu++;
				queu.Dequeue();
				cout<<"please display queue to see changes\n";
				system("pause");
				return queueMainMenu();
			}
			

			return listMainMenu(size);
		}else if (menu == "3"){ //display data
			
			queu.display(); //diplay all element in a list
			system("pause");
			return queueMainMenu();
			
		}else if (menu == "4"){ //back to adt main menu
			
			if(!queu.empty()){ //check if List is not empty
				queu.clear(); //to replace all element in position
			}
			
			cout<<"going back to mainmenu......"<< endl;
			system("pause");
			AdtMenu();
			
		}else{
			
			cout<<endl;
			cout<<"Please select one of the options."<< endl;
			system("pause"); //pause screen
	
			return queueMainMenu();	
			
		}
	}	
	
	
//	enqueue  data
	void enqueueDataQue(int size){
		
		int data=0; //data input
		int sizes = size;
		cout<<"------------- queue data -------------\n";
		for (int i=sizes; i>0; i--){

			cout<<"Data: ";
			if(cin>> data){
				insertQueu--;
				cout<<size<<endl;
				queu.Enqueue(data);
			}else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Invalid input, please select data again \n\n";
				system("pause");
				insertQueu=size;
				queueMainMenu();
				
			}
		}
		
		queueMainMenu();
	}	

};



int main() {
	adtMain().AdtMenu(); // call the main class
}





















