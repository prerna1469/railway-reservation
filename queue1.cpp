#include <iostream>
#define Maxsize 10
using namespace std;
class Passenger
{
    public:
    string name;
    char gender;
    int age;
    string source;
    string destination;
    Passenger()
    {
        name="\0";
        gender='\0';
        age=0;
        source="\0";
        destination="\0";
    }
    void accept();
    void display();
    int cancel(string s);//to check name for canceling tickets
};
void Passenger::accept()//accept passenger details
{
    string str;
    cout<<"\n Enter passenger name : ";
    getline(cin,str);
    getline(cin,name);
    cout<<"\n Enter passenger gender : ";
    cin>>gender;
    cout<<"\n Enter passenger age : ";
    cin>>age;
    cout<<"\n Enter source : ";
    getline(cin,str);
    getline(cin,source);
    cout<<"\n Enter destination : ";
    getline(cin,destination);
}
void Passenger::display()//display passenger details
{
    cout<<"\n Passenger name is : "<<name;
    cout<<"\n Passenger gender is : "<<gender;
    cout<<"\n Passenger age is : "<<age;
    cout<<"\n Source is : "<<source;
    cout<<"\n Destination"<<destination;
}
int Passenger::cancel(string s) //cancels confirmed tickets.
{
	int flag = 0;
	if (s == name) 
	{
		cout << "Booking has been cancelled." << endl;
		flag = 1;
	}
	else
	{
	    flag=0;
	}
	return flag;
}
class Queue
{
    Passenger data[10];
    int front;
    int rear;
public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    int isfull();
    int isempty();
    void enque();
    Passenger deque();
    void displaylist();
};
int Queue::isfull()//check if queue is full
{
    if(rear==Maxsize-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Queue::isempty()//check if queue is empty
{
    if(front==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Queue::enque()//add element to queue
{
    if(isfull()==1)
    {
        cout<<"\n Queue is full";
        cout<<"\n Reservations are closed";
    }
    else
    {
        cout << "You are in the waiting list";
		rear++;
		data[rear].accept(); 
    }
}
Passenger Queue::deque()//remove element from queue
{
    Passenger ob;
    if(isempty()==1)
    {
        cout<<"\n Wating list Queue is empty";
    }
    else
    {
        ob = data[front]; //removed from waiting list
		front++;
		return ob;
    }
}
void Queue::displaylist() //display list of passengers
{
    int i=0;
	if (isempty()==1) 
	{
		cout << "Waiting list is empty ." << endl;
	} 
	else
	{
		for (i = front; i <= rear; i++)
		{
			data[i].display();
		}
	}
}
int main()
{
    Queue q1;//object of queue
	string name1;
	Passenger p;//object of passenger
	Passenger confirm[5];
	int choice=0;
	int n = 0, c = 0,i=0;
	do
	{
	    do
	    {
	        cout<<"\n Menu";
        	cout<<"\n 1.Book ticket";
        	cout<<"\n 2.Display confirmed passenger list";
        	cout<<"\n 3.Display waiting passenger list";
        	cout<<"\n 4.Cancel ticket";
        	cout<<"\n 0.Exit";
        	cout<<"\n Enter choice = ";
        	cin>>choice;
    	}while(choice<0 && choice>4);
    	switch(choice)
    	{
    	    	case 1: 	//book tickets
				if (n < 5) 
            	    		{
        				confirm[n].accept();
        				cout << "Confirmed Reservation.";
        				n++;
        			} 
        			else 
        			{
        				cout << "Reservations are full!";
        				q1.enque();
        			}
        			break;
        	case 2: cout << "Confirmed Reservations list:" ;
        			for ( i= 0; i < 5; i++) {
        				confirm[i].display();//display confirmed list
        			}
        			break;
        	case 3: cout << "Passengers in waiting list : " << endl;
			        q1.displaylist();//display waiting list
			        break;
			case 4: cout << "Enter name to cancel ticket : ";
        			cin >> name1;
        			for ( i = 0; i < 5; i++) {
        				if (confirm[i].cancel(name1) == true)//cancel tickets
        				{
        					c = i;
        					break;
        				}
        			}
        			cout << "\n";
        			p = q1.deque(); //removes from waiting list
        			//adds to confirmed reservation list
        			confirm[c].name = p.name;
        			confirm[c].gender = p.gender;
        			confirm[c].age = p.age;
        			break;
        	case 0: cout<<"\n End of program.Thank you";
    	            break;
    	    default: cout<<"\n Invalid entry,please enter again";
    	            break;
        	
    	}
	}while(choice!=0);
}

/*
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1

 Enter passenger name : prerna

 Enter passenger gender : f

 Enter passenger age : 19

 Enter source : pune

 Enter destination : chennai
Confirmed Reservation.
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1

 Enter passenger name : deepak

 Enter passenger gender : m

 Enter passenger age : 45

 Enter source : pune

 Enter destination : goa
Confirmed Reservation.
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1

 Enter passenger name : hema

 Enter passenger gender : f

 Enter passenger age : 41

 Enter source : pune

 Enter destination : mumbai
Confirmed Reservation.
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1

 Enter passenger name : amruta

 Enter passenger gender : f

 Enter passenger age : 19

 Enter source : pune

 Enter destination : mumbai
Confirmed Reservation.
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1

 Enter passenger name : isha

 Enter passenger gender : f

 Enter passenger age : 19

 Enter source : mumbai

 Enter destination : pune
Confirmed Reservation.
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 1
Reservations are full!You are in the waiting list
 Enter passenger name : ronisha

 Enter passenger gender : f

 Enter passenger age : 19

 Enter source : pune

 Enter destination : tirupati

 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 2
Confirmed Reservations list:
 Passenger name is : prerna
 Passenger gender is : f
 Passenger age is : 19
 Source is : pune
 Destinationchennai
 Passenger name is : deepak
 Passenger gender is : m
 Passenger age is : 45
 Source is : pune
 Destinationgoa
 Passenger name is : hema
 Passenger gender is : f
 Passenger age is : 41
 Source is : pune
 Destinationmumbai
 Passenger name is : amruta
 Passenger gender is : f
 Passenger age is : 19
 Source is : pune
 Destinationmumbai
 Passenger name is : isha
 Passenger gender is : f
 Passenger age is : 19
 Source is : mumbai
 Destinationpune
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 3
Passengers in waiting list : 

 
 Passenger name is : ronisha
 Passenger gender is : f
 Passenger age is : 19
 Source is : pune
 Destinationtirupati
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 4
Enter name to cancel ticket : prerna
Booking has been cancelled.


 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 2
Confirmed Reservations list:
 Passenger name is : ronisha
 Passenger gender is : f
 Passenger age is : 19
 Source is : pune
 Destinationtirupati
 Passenger name is : deepak
 Passenger gender is : m
 Passenger age is : 45
 Source is : pune
 Destinationgoa
 Passenger name is : hema
 Passenger gender is : f
 Passenger age is : 41
 Source is : pune
 Destinationmumbai
 Passenger name is : amruta
 Passenger gender is : f
 Passenger age is : 19
 Source is : pune
 Destinationmumbai
 Passenger name is : isha
 Passenger gender is : f
 Passenger age is : 19
 Source is : mumbai
 Destinationpune
 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 3
Passengers in waiting list : 
Waiting list is empty .

 Menu
 1.Book ticket
 2.Display confirmed passenger list
 3.Display waiting passenger list
 4.Cancel ticket
 0.Exit
 Enter choice = 0

 End of program.Thank you
*/
