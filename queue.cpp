#include <iostream>

using namespace std;

int queue1[100];
int n=100, Front = -1, Rear = -1;

void isEmpty(){
    if(Rear ==-1 || Front ==-1 ){
        cout<<"Queue is Empty"<<endl;
    }
    else
        cout<<"Queue is Not Empty!"<<endl;
}

void isFull(){
    if(Rear==n-1){
    cout<<"Queue is Full"<<endl;
    }
    else
        cout<<"Queue is Not Full!"<<endl;
}


void peek(){
    if(Front==-1 && Rear==-1){
        cout<<"There is no element inside the queue to display"<<endl;
    }
    else
         cout<<"The element at the front node is: "<<queue1[Front]<<endl;
}


void enqueue(){
    int element;
    if (Rear == n-1){
        cout<<"Overflow Error"<<endl;
    }
    else
    if (Front==-1){
        Front=0;
    }
     cout<<"Enter the element for insertion: ";
     cin>>element;
     Rear++;
     queue1[Rear]=element;
}



void dequeue(){
    if (Front ==-1 && Rear==-1){
        cout<<"Underflow Error";
    }

    else if(Front == Rear){
        cout<<"The deleted element from the queue is:"<<queue1[Front]<<endl;
        Front = Rear =-1;
    }
    else
        cout<<"The deleted element from the queue is:"<<queue1[Front]<<endl;
    Front++;

}


void display(){
    if(Front==-1){
        cout<<"Queue is Empty!"<<endl;
    }
    else
        cout<<"Queue elements are:"<<endl;

    for(int i =Front; i <= Rear; i++)
        cout<<queue1[i]<<"\n";
        cout<<endl;
}

int main()
{
   int choice;
	do
	{
		system("cls");
		system("Color 0E");
		cout << '\n';
		cout << " # # # # # # # # # # # # # # # # # # # # #  # \n";
		cout << " #                                          # \n";
		cout << " #                 MAIN MENU                # \n";
		cout << " #                                          # \n";
		cout << " # |1|  INSERT                              # \n";
		cout << " # |2|  DELETE                              # \n";
		cout << " # |3|  DISPLAY                             # \n";
		cout << " # |4|  DISPLAY FRONT W/O DELETION          # \n";
		cout << " # |5|  DISPLAY IF THE QUEUE IS NOT FULL    # \n";
		cout << " # |6|  DISPLAY IF THE QUEUE IS EMPTY OR NOT# \n";
		cout << " # |7|  EXIT                                # \n";
		cout << " #                                          # \n";
		cout << " # # # # # # # # # # # # # # # # # # # # #  # \n";
		cout << "       -----Choose A Program Letter----: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			system("cls");
            enqueue();
			system("pause");
			break;

		case 2:

			system("cls");
            dequeue();
			system("pause");
			break;

		case 3:
			system("cls");
            display();
			system("pause");
			break;

        {

			case 4:
				system("cls");
                peek();
				system("pause");
				break;
        }
        {

			case 5:
				system("cls");
				isFull();
				system("pause");
				break;
        }
         {

			case 6:

				system("cls");
				isEmpty();
				system("pause");
				break;
        }
		}
	} while (choice != 7);
}
