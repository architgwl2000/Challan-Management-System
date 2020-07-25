#include<bits/stdc++.h>
#include<fstream>
#define max 10

using namespace std;


class ChallanType 
{
public:

    int reciept_number;
string PersonName;
string date;
int value[10];
string type = {"RTO"};
int x, menu2[10];
    double amount[10];
    string ChallanName[10]={"Without Helmet","Without Driving Licence(DL)","Over Speeding","Red Light Jumping","Drunk and Drive","Using Cell-Phone",
"Overloading","Without Seat Belt","Without Insurance","Without Number Plate"};
double Challan[10] = {1000,5000,1500,2000,3000,2500,4000,1200,2200,1800};
double total;
   

void take_order();
void order_list(); 
void exit();  
int receipt_return();
ChallanType();//constuctor

};
// ###################################################
void write_account();
void display_sp();

// ###################################################
void write_account()
{
ChallanType ch;
ofstream outFile;
outFile.open("challan.txt",ios::out|ios::app);
ch.take_order();
outFile.write((char *)(&ch), sizeof(ChallanType));
outFile.close();
}
void display_sp()
{
ChallanType ch;
bool flag=false;
ifstream inFile;
inFile.open("challan.txt",ios::in);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
return;
}
int num2;
cout<<" Enter the Reciept Number To Print The Reciept\n";
cin>>num2;
cout<<"\nBALANCE DETAILS\n";

    while(inFile.read((char *)(&ch), sizeof(ChallanType)))
{
if(ch.receipt_return()==num2)
{
ch.order_list();
flag=true;
}
}
inFile.close();
if(flag==false)
cout<<"\n\nChallan Receipt does not exist";
}


// ###################################################
 ChallanType::ChallanType ()
{
for(int i=0;i<10;i++)
amount[i]=0;
}
int ChallanType::receipt_return()
{
return reciept_number;
}
void ChallanType::take_order() 
{
system("clear");
int i;
    int choice, price,None;

cout <<"\nChallan Details\n";
cout <<"_____________________________________ \n\n";


cout <<"**************************************************************************\n";
cout<<"CHALLAN ID"<<"\tAUTHORIZATION"<<"   \t\tCHALLAN NAME"<<"           FINE(RS)"<<endl;
cout <<"**************************************************************************\n";
                cout<<"001"<<"\t"<<"\tRTO"<<"\t\t"<<"    Without Helmet"<<" RS. 1000"<<endl;
                cout<<"002"<<"\t"<<"\tRTO"<<"\t\t"<<"    Without Driving Licence(DL)"<<" RS. 5000"<<endl;
                cout<<"003"<<"\t"<<"\tRTO"<<"\t\t"<<"    Over Speeding"<<" RS. 1500"<<endl;
                cout<<"004"<<"\t"<<"\tRTO"<<"\t\t"<<"    Red Light Jumping"<<" RS. 2000"<<endl;
                cout<<"005"<<"\t"<<"\tRTO"<<"\t\t"<<"    Drunk and Drive"<<" RS. 3000"<<endl;
                cout<<"006"<<"\t"<<"\tRTO"<<"\t\t"<<"    Using Cell-Phone"<<" RS. 2500"<<endl;
                cout<<"007"<<"\t"<<"\tRTO"<<"\t\t"<<"    Overloading"<<" RS. 4000"<<endl;
                cout<<"008"<<"\t"<<"\tRTO"<<"\t\t"<<"    Without Seat Belt "<<" RS. 1200"<<endl;//1353fn
                cout<<"009"<<"\t"<<"\tRTO"<<"\t\t"<<"    Without Insurance"<<" RS. 2200"<<endl;
                cout<<"010"<<"\t"<<"\tRTO"<<"\t\t"<<"    Without Number Plate"<<" RS. 1800"<<endl;
                cout<<" "<<endl;
   
cout << "Challan Number: ";
    cin >>reciept_number;
cout<< "Enter Person Name: ";
cin>> PersonName;
cout<<"Enter Date (dd/mm/yyyy): ";
cin>>date;
cout << "How many Challans Imposed: \n"<< endl;

cout << "  " ;
cin >> x;
for (i=0; i<x; i++)
{

cout << "Please enter Challan ID : "<<endl;
cin>> menu2[i];
        cout<< "Challan Name: " <<ChallanName[menu2[i]-1]<<endl;
        cout << "Are you sure, Challan to be Imposed(YES=1/No=0)?";
        cin >> value[i];
        amount[i] = value[i] * Challan[menu2[i]-1];
        cout << "The Fine You have to pay is: " << amount[i]<<" RS."<<endl;
        system("PAUSE");
                     
}
cout<<"==========================================================================="<<endl;
    cout << "Challan Imposed Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Fine"<<endl;
    cout<<"==========================================================================="<<endl;
system ("PAUSE");
system("clear");
}

void ChallanType::order_list() 
{
int i, num, num2;
bool found; 
system("clear");

found = true;
cout<<"\n";
cout<<"==========================================================================="<<endl;
cout <<"\t\tHere is the Challan list\n";
cout<<"==========================================================================="<<endl;


        if (found) /
        {
cout <<"Reciept Number : "<<reciept_number;
cout <<"\n";
cout<<"Person Name: "<<PersonName<<endl;

cout<<"Order Date : "<<date<<endl;

cout<<"_____________________________________________________________________________"<<endl;

cout << "===============================================================================" << endl;
cout << "|  AUTHORIZATION |     Challan Name    |   Imposed   |   Total Fine |" << endl;
cout << "=======++==================++================++===============++===============" << endl;
for (i=0;i<x;i++)
{
cout << type <<"  \t\t";
cout<<ChallanName[menu2[i]-1]<<"\t\t\t  ";
cout<<value[i] <<"\t\t";
cout<< amount[i]<<" RS."<<endl;
cout<<"_________________________________________________________________________________"<<endl;
}

total = amount[0]+amount[1]+amount[2]+amount[3]+amount[4]+amount[5]+amount[6]+amount[7]
+amount[8]+amount[9];
cout<<"Total Fine is : "<<total;
cout<<"\n";
cout << "Type the exact Fine You need to pay: ";
        cin >> num;
        cout<<"@"<<num<<endl;

        if(total==num)
        {
        cout<<"Amount Correct"<<endl;
        }
        else
        {
        cout<<"Amount Incorrect"<<endl;
        system("PAUSE");
        getchar();
        return;
        }
cout <<"\n";
cout <<"\n";
cout<<"Payment Done\nThank You\n";
cout <<"\n_______________________________________________________________________________\n";
}


} 
int main()
{

system("COLOR 0"); 
ChallanType Challan;
int menu;
do
{
system("clear");
cout<<"\t\t\t    Challan Management System\n";
cout<<"\t\t==================================================\n\n";
cout<<"\t\t--------------------------------------------------\n";
cout<<"\t\t||\t1. Take new Challan order \t\t ||\n";
cout<<"\t\t||\t2. Print the Reciept and Make Payment \t ||\n";
cout<<"\t\t||\t3. Exit\t\t\t\t\t ||\n";
cout<<"\t\t--------------------------------------------------\n";
cout<<"Enter choice: ";

cin>>menu;

switch (menu)
{
case 1:
{
write_account(); 
break;
} 

case 2:
{
display_sp(); 
system("PAUSE");
break;
} 
        case 3:
{
exit(1); 

break;
} 


default:
{
cout<<"You enter invalid input\nre-enter the input\n"<<endl;
break;
}
}while(menu!=6);

cout<<"thank you"<<endl;
system ("PAUSE");
return 0;
}

	
