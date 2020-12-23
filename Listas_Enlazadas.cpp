/*By Eric 22/12/2020 simple linked lists*/

#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct Node{
    int data;       
    Node *next;
};

//function prototypes
Node *createNode(int value);
void insertAtTheBeginning(Node *&list, int value);
void insertAtTheEnd(Node *&list, int value);
int insertAfterBefore();
void insertByPosition(Node *&list, int value, int position);
void removeElementByPostion(Node *&list, int position);
bool searchElement(Node *list, int value);
void printList(Node *list, int count);
void removeElement(Node *&list, int value);
void removeDuplicateElements(Node *&list, int value);
 
int main()
{
    Node *list = NULL;
    int option;
    int value;
    int position;
 
    do {
    	cout<< "\t..::Menu::..\n"<< endl;
    	cout<< "[1] Insert at the beginnig"<< endl;
    	cout<< "[2] Insert at the end"<< endl;
    	cout<< "[3] Insert by position"<< endl;
    	cout<< "[4] Remove by position"<< endl;
    	cout<< "[5] Show list"<< endl;
    	cout<< "[6] Search one element"<< endl;
    	cout<< "[7] Delete element"<< endl;
    	cout<< "[8] Delete duplicate elements"<< endl;
    	cout<< "[9] Quit"<< endl;
 
    	cout<< "\nSelect: ";
        cin>> option;
        
        system("cls");
        switch(option){
            case 1:
                cout<< "Type one number: "; 
				cin>> value;
				
                insertAtTheBeginning(list, value);
            break;

            case 2:
				cout<< "Type one number: "; 
				cin>> value;
				
                insertAtTheEnd(list, value);
            break;
 
            case 3:
                printList(list, 0);
                
                cout<< "\n\nType one number: "; 
				cin>> value;
				
            	cout<< "\n\nChosse one position: ";      
				cin>> position;
				
                insertByPosition(list, value, position);
            break;
            
            case 4:
            	printList(list, 0);
            	
            	cout<< "\n\nChosse one position: ";       
				cin>> position;
				
                removeElementByPostion(list, position);
            break;
 
            case 5:
                cout << "Showing list\n\n";
                printList(list, 0);
            break;
 
            case 6:
                cout<<"Type one number: "; 
				cin>> value;
				
                if (searchElement(list, value)) {
                	cout<< "\nElement: "<< value<< " found"<< endl;
				} else {
					cout<< "\nElement: "<< value<< " no found"<< endl;
				}
            break;
 
            case 7:
            	printList(list, 0);
            	
				cout<< "\n\nType one number: "; 
				cin>> value;
				
                removeElement(list, value);
            break;
 
            case 8:
            	printList(list, 0);
            	
                cout<< "\n\nType one number: "; 
				cin>> value;
				
                removeDuplicateElements(list, value);
            break;
            
            case 9:
                cout<< "\t**Thank you**"<< endl;
            break;
        }
 
        cout<< "\n";
        system("pause");  
		system("cls");
 
    } while(option != 9);
 
   return 0;
}

Node *createNode(int value)
{
	Node *newNode = new Node();
	
	newNode->data  = value;
    newNode->next = NULL;
    
	return newNode;
}
 
void insertAtTheBeginning(Node *&list, int value)
{
    Node *list_aux;
    list_aux = createNode(value);
    list_aux->next = list;         				// just add the list to your new element "new_element-> list"
    list  = list_aux;
    cout<< "\nElement: "<< value<< " has been inserted successfully!"<< endl;
}
 
void insertAtTheEnd(Node *&list, int value)
{
	if (list == NULL) {
		Node *newNode = createNode(value); 
		list = newNode; 						// just add the new element to your list "list-> new_element"
		cout<< "\nElement: "<< value<< " has been inserted successfully!"<< endl;
		return;
	}
    											// if you have more than one element
    insertAtTheEnd(list->next, value); 			// go to the end of the list
}
 
// this function is a reference to decide how to insert
int insertAfterBefore()
{
    int option, flag;
    
    cout<< "\n\t[1] Do you want to do this operation before?"<< endl;
    cout<< "\t[2] Do you want to do this operation after?"<< endl;
 
    cout<< "\n\tSelect: "; 
	cin>> option;
 
    if (option == 1) {
    	flag = -1;	
	} else {
    	flag = 0;	
	}
 
    return flag;
}
 
void insertByPosition(Node *&list, int value, int position)
{
    Node *list_aux1, *list_aux2;
    list_aux1 = createNode(value); 					// create node
    int where = insertAfterBefore(); 				// decide before or after 
 
    if (position == 1 && where == -1) { 			// case: the first position and insert before 
        cout<< "\nyou can not insert before"<< endl;
        return;
    } else {
        list_aux2 = list;
 
        for (int i = 1; list_aux2 != NULL; i++) { 	// iterate the whole list
            if (i == position+where) { 				// find position and decide to insert before or after
                list_aux1->next = list_aux2->next;
                list_aux2->next = list_aux1;       	//merge
                cout<< "\nElement: "<< value<< " has been inserted successfully!"<< endl;
				return;
            }
            list_aux2 = list_aux2->next; 			// change to the next position
        }
    }
    cout<< "\n\tError...out of range..!"<< endl;
}

void removeElementByPostion(Node *&list, int position)
{
    Node *list_aux1, *list_aux2;
    int where = insertAfterBefore();
    int number = 0;
 
    if (position == 1 && where == -1) { 					// case: the first position and remove before 
        cout<< "\nYou can not remove before"<< endl;
        return;
    } else {
    	list_aux1 = list;
    	
    	if (where == 0) { 									// if you want to remove after where+1
    		where = 1;
		}
    	
    	for (int i = 1; list_aux1 != NULL; i++) { 			// iterate the whole list
            if(i == position+where) {  						// find position and decide how to remove before or after
                if (list_aux1==list) {  					// remove item from first position
                    number = list->data;
					list = list->next;
                } else {
                	number = list_aux2->next->data;
                    list_aux2->next = list_aux1->next; 		// merge	
                }
 
 				cout<< "\nElement: "<< number<< " has been removed"<< endl; 
                delete(list_aux1); 							// remove other item
                return;
            }
            list_aux2 = list_aux1; 							// this is a reference
            list_aux1 = list_aux1->next;  					// change to the next position
        }
    }
    cout<< "\n\tError...out of range..!"<< endl;
}
 
bool searchElement(Node *list, int value)
{
    if (list == NULL) {
    	return false;										// empty list
	}
	
	if (value != list->data) {
		return searchElement(list->next, value);			// keep searching
	} else {
		return true;										// element or item found
	}
}
 
void printList(Node *list, int count)
{
	if (list == NULL) {
		if (count == 0) {
			cout<< "\n\t**empty list**"<< endl;
		} else {
			cout<< "NULL"<< endl;
		}
		return;
	}
    
	cout<< "[ "<< count+1 <<" | " <<list->data << " ]"<< "  ->  ";
    printList(list->next, count+1);
}
 
 
void removeElement(Node *&list, int value)
{
    Node *list_aux1, *list_aux2;
    list_aux1 = list;
    
	while (list_aux1 != NULL) {
    	if (list_aux1->data == value) {
            if (list_aux1 == list) {
        	   list = list->next;								// remove item from first position
            } else {
                list_aux2->next = list_aux1->next;				// merge
            }
 
            delete(list_aux1);									// remove other items
            cout<< "\nNumber: "<< value<< " removed"<< endl;
            return;
        }
        list_aux2 = list_aux1;									// this a reference
        list_aux1 = list_aux1->next;							//change the next position
    }
        
    cout<< "\nNumber: "<< value<< " no found"<< endl;
}
 
void removeDuplicateElements(Node *&list, int value)
{
    Node *list_aux1, *list_aux2;
    list_aux1 = list;
    list_aux2 = list;
    int count = 0;
 
    while (list_aux1 != NULL) {
        if (list_aux1->data == value) {
        	if (count == 0) {  									// exclude one number
        		count++;
        		list_aux2 = list_aux1;
            	list_aux1 = list_aux1->next;
        		continue;
			}
			
            list_aux2->next = list_aux1->next;
            delete(list_aux1);									// and remove the others
            list_aux1 = list_aux2->next;						// update
        	count++;
		} else {
            list_aux2 = list_aux1;
            list_aux1 = list_aux1->next;						// change to the next position
        }
    }
    
    if (count == 0) {
    	cout<<"\n\nElement "<< value<< " no found..!"<< endl;
	} else if (count > 1) {
    	cout<<"\n\nThe elements have been deleted..!"<< endl;
	} else {
		cout<<"\n\nEverything is ok..!"<< endl;
	}
}
