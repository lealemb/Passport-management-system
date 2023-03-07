#include<iostream>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<string>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

// 3 structures here
	struct Address {
		char zone[50];
		char kk[50];
		int woreda;
		int h_no;
	};
	struct Bdate{
		int date, month, year;
	};
	
	struct people {
		char name[20];
		char last_name[20];
		int age;
		char birth_place[30];
		Bdate bdate;
		Address address;
		int pass_no;
		char nationality[30];
		char sex;
		
	};
	
//function prototypes here
void intro();
void Rigister(char* fn,people p[],int &max);
void display(char*fn);
void search(char*fn);
void deleteperson(char* fn);
void edit(char* fn);
void Exit(int &e);
void size(char *fn);
//Main Menu
int main(int argc, char** argv) {
    intro();
    system("cls");
    system("Color 07");

	int max,c,exit=0;
	char want;
	want = 'y';
	people p[100];
	char*fn="passport_r.txt";
	while ( want=='y'|| want=='Y'){
	cout<< "|============MAIN MENU============|"<<endl;
	cout<< "1. register people\n";
	cout<< "2. Display the information of all registered people\n";
	cout<< "3. Search person by passport_no \n";
	cout<< "4. Delete person by passport_no \n";
	cout<< "5. Edit person by passport_no \n";
	cout<< "6. Display the total number of people registered \n"; 
	cout<< "7. close the program \n";
	cout<< "Enter your choice:  ";
	cin>>c;
	switch (c){
	case 1: 
	Rigister(fn,p,max);
	break;
	case 2:{
		display(fn);
		break;
	}
	case 3:{
		search(fn);
		break;
	}
	case 4:{
		deleteperson(fn);
		break;
	}
	case 5:{
		edit(fn);
		break;
	}
	case 6:
		size(fn);
		break;
	case 7:
		Exit(exit);
		break;
}
	if(exit==1)
want='n';
	system ("pause");
	system ("cls");

}


	return 0;
}
// just introduction
void intro(){
	system ("cls");
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n    |-- ADDIS ABABA UNIVERSITY --|";
    cout<<"\n  |-- COLLEGE OF NATURAL SCIENCE --|";
    cout<<"\n       |-- COMPUTER SCIENCE--|";
	cout<<"\n  |-- PASSPORT RIGISTERATION SYSTEM --|";
	cout<<"\n\nName                               ID\n";
	cout<<"\n1.Lealem Birhanu               NSE/8335/14"<<endl;
	cout<<"2.Musse Sisay                  NSE/4465/14"<<endl;
	cout<<"3.Eyerus Getawa                NSE/1783/14"<<endl;
	cout<<"4.Hamza Hassen                 NSE/1750/14 "<<endl;
	cout<<"5.Tewodros Belay               NSE/8750/14"<<endl;
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"<<endl<<endl;
	cout<< "   ****************************************************/!"<< endl<<endl;
	cout<< "   WELCOME TO THIS  NEW  PASSPORT RIGISTERATION SYSTEM!"<<endl;
	cout<< "   WE  ARE  HAPPY TO SERVE YOU!\n   READ THE GUIDE IF YOU GET ANY ERRORS!"<< endl<<endl;
	cout<< "   ******************************************************/!"<< endl<<endl;
	cout<< "    ### press any key to get started!"<< endl;

	cin.get();
}
//this function rigister new customers
void Rigister(char* fn,people p[],int &max) {
	system ("cls");
		ofstream out("passport_r.txt", ios::binary| ios::app);
		if(out.is_open()){
		
		int max=1000;
		
		people  p[max];
		for(int i=0; i<1; i++){
			cout<<"Enter the information of person "<<i+1<<endl;
			cout<<"Enter first name: ";
			cin>>p[i].name;
			cout<<"Enter last name: ";
			cin>>p[i].last_name;
			cout<<"Enter birth year(NUMBER ONLY): ";
			cin>>p[i].bdate.year;
			while (p[i].bdate.year<1900 || p[i].bdate.year>2023){
			cout<<"please enter a correct format!\n";
			cout<<"Enter birth year(NUMBER ONLY): ";

			cin>>p[i].bdate.year;}
			cout<<"Enter birth month(NUMBER ONLY): ";
			cin>>p[i].bdate.month;
			while(p[i].bdate.month<1 || p[i].bdate.month> 12){
			cout<<"please enter a correct format!\n";
			cout<<"Enter birth month(NUMBER ONLY): ";
			cin>>p[i].bdate.month;
			}
			cout<<"Enter birth date: ";
			cin>>p[i].bdate.date;
			while(p[i].bdate.date<1 || p[i].bdate.date> 30){
			cout<<"please enter a correct format!\n";
			cout<<"Enter birth date(NUMBER ONLY): ";
			cin>>p[i].bdate.date;}
			cout<<"Enter birth place: ";
			cin>>p[i].birth_place;
			cout<<"Enter sex(Male(M)\\ Female(F)): ";
			cin>>p[i].sex;
			cout<<"Enter age: ";
			cin>>p[i].age;
			cout<<"Enter Nationality: ";
			cin>>p[i].nationality;
			cout<<"Enter zone: ";
			cin>>p[i].address.zone;
			cout<<"Enter kefle ketema: ";
			cin>>p[i].address.kk;
			cout<<"Enter woreda: ";
			cin>>p[i].address.woreda;
			cout<<"Enter house no: ";
			cin>>p[i].address.h_no;
			cout<<"passport number: ";
			cin>>p[i].pass_no;
			out.write((char*)&p[i], sizeof p[i]);
			out.close();
		
			}
		cout<<"Cumstomer Registered  Sucessfully"<<endl;
		cout << "  ----PRESS ANY KEY TO CONTINUE!----  " << endl;	}
		else
		cout<<"Unable to open the file. \n";} 
	//display a rigister
void display(char*fn){
		system ("cls");
		people p;
		int count=1;
		ifstream in(fn,ios::binary);
		if (in.is_open()){
			in.read((char*)&p, sizeof (p));
				while (!in.eof()){
		cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
		    cout<<"Roll_no: "<<count<<endl;
			cout<<"First Name:        "<<p.name<<endl;
			cout<<"Last Name:         "<<p.last_name<<endl;
			cout<<"Age:               "<<p.age<<endl;
			cout<<"Birth Date:        "<<p.bdate.date<<"\\"<<p.bdate.month<<"\\"<<p.bdate.year<<endl;
			cout<<"Nationality:       "<<p.nationality<<endl;
			cout<<"zone:              "<<p.address.zone<<endl;
			cout<<"Kifle ketma:       "<<p.address.kk<<endl;
			cout<<"House no:          "<<p.address.h_no <<endl;
			cout<<"passport no:       "<<p.pass_no<<endl;
		cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;	
	in.read((char*)&p, sizeof (p));
			count++;}
		in.close();
	}
	else 
	cout<<"unable to open the file.\n";}
//search a rigister	
void search(char*fn){
	system ("cls");
		int p_no;
		people p;
		ifstream in(fn, ios::binary);
		if(in.is_open()){
			cout<<"Enter passport number:  ";
			cin>>p_no;
			in.read((char*)&p, sizeof (p));
			while(!in.eof()){
				if (p_no==p.pass_no){
					
			cout<<"The perseon is found\n\n";
			cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
			cout<<"First Name:        "<<p.name<<endl;
			cout<<"Last Name:         "<<p.last_name<<endl;
			cout<<"Age:               "<<p.age<<endl;
			cout<<"Birth Date:        "<<p.bdate.date<<"\\"<<p.bdate.month<<"\\"<<p.bdate.year<<endl;
			cout<<"Nationality:       "<<p.nationality<<endl;
			cout<<"zone:              "<<p.address.zone<<endl;
			cout<<"Kifle ketma:       "<<p.address.kk<<endl;
			cout<<"House no:          "<<p.address.h_no <<endl;
			cout<<"passport no:       "<<p.pass_no<<endl;
		cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;	
				in.close();
				return;}
				in.read((char*)&p, sizeof (p));	}
			cout<<"Not found\n";
			in.close();}
		else
		cout<<"Unable to open file\n";}
//delete a rigister
void deleteperson(char* fn){
	system ("cls");
	char* temp="temporaryFile.dat";
	ofstream out(temp,ios::binary);
	ifstream in(fn,ios::binary);
	int p_no;
	people p;
	in.read((char*)&p,sizeof(p));
	int count=0;
	cout<<"Enter passport number: ";
	cin>>p_no;
	  while(!in.eof()){
	  	 if(p_no!=p.pass_no){
	  	 	out.write((char*)&p,sizeof(p)); }
		   
		   if(p_no==p.pass_no)
		     count=1;
		in.read((char*)&p,sizeof(p));}
	  in.close();
	  out.close();
	  remove(fn);
	  rename(temp,fn);
	
	if(count==1)
	   cout<<"sucessfully deleted.\n";
	else
	    cout<<"Unknown passport_no\n";}
//edit a rigister	    
void edit(char* fn){
	system ("cls");
	char* temp="temporaryFile.dat";
	ofstream out(temp,ios::binary);
	ifstream in(fn,ios::binary);
	int p_no,choise;
	people p;
	int count=0,i=1;
	cout<<"Enter passport number: ";
	cin>>p_no;
	
	in.read((char*)&p,sizeof(p));
	  while(!in.eof()){
	  	 if(p_no!=p.pass_no){
	  	 	out.write((char*)&p,sizeof(p));}
		   
if(p_no==p.pass_no){
		     count=1;
cout<<"Select the type of person\'s data you want to edit\n";
	cout<<"1. Name(first & Last)\n";
	cout<<"2. Birth Date\n";
	cout<<"3. Birth Place\n";
	cout<<"4. Age\n";
	cout<<"5. Sex\n";
	cout<<"6. Nationality\n";
	cout<<"7. Address\n";
	cout<<"8. passport_no\n";
	cout<<"9. Over All Edition\n";
	cin>>choise;
	switch(choise){
	   case 1:{
	      cout<<"Enter new first_name: ";
			cin>>p.name;
			cout<<"Enter new last_name: ";
			cin>>p.last_name;
         break;}
      case 2:{
         cout<<"Enter new birth year: ";
			cin>>p.bdate.year;
			cout<<"Enter new birth month: ";
			cin>>p.bdate.month;
			cout<<"Enter new birth date: ";
			cin>>p.bdate.date;
         break;}
      case 3:{
			cout<<"Enter new birth place: ";
			cin>>p.birth_place;
            break;}
      case 4:{
			cout<<"Enter new age: ";
			cin>>p.age;
         break;}
      case 5:{
			cout<<"Enter new sex((M)for male\\ (F) for Female): ";
			cin>>p.sex;
         break;}
      case 6:{
			cout<<"Enter new Nationality: ";
			cin>>p.nationality;
         break;}
      case 7:{
			cout<<"Enter new zone: ";
			cin>>p.address.zone;
			cout<<"Enter new kefle ketema: ";
			cin>>p.address.kk;
			cout<<"Enter new woreda: ";
			cin>>p.address.woreda;
			cout<<"Enter new house no: ";
			cin>>p.address.h_no;
         break;}
      case 8:{
			cout<<"Enter new passport number: ";
			cin>>p.pass_no;
         break;}
      case 9:{
		     cout<<"Edit the info of person "<<i<<endl;
			cout<<"Enter new first_name: ";
			cin>>p.name;
			cout<<"Enter new last_name: ";
			cin>>p.last_name;
			cout<<"Enter new birth year: ";
			cin>>p.bdate.year;
			cout<<"Enter new birth month: ";
			cin>>p.bdate.month;
			cout<<"Enter new birth date: ";
			cin>>p.bdate.date;
			cout<<"Enter new birth place: ";
			cin>>p.birth_place;
			cout<<"Enter new sex((M)for male\\ (F) for Female): ";
			cin>>p.sex;
			cout<<"Enter new age: ";
			cin>>p.age;
			cout<<"Enter new Nationality: ";
			cin>>p.nationality;
			cout<<"Enter new zone: ";
			cin>>p.address.zone;
			cout<<"Enter new kefle ketema: ";
			cin>>p.address.kk;
			cout<<"Enter new woreda: ";
			cin>>p.address.woreda;
			cout<<"Enter new house no: ";
			cin>>p.address.h_no;
			cout<<"Enter new passport number: ";
			cin>>p.pass_no;
         break;}}
			out.write((char*)&p, sizeof p); }
		in.read((char*)&p,sizeof(p));
		i++;}
	  in.close();
	  out.close();
	  remove(fn);
	  rename(temp,fn);
	
	if(count==1)
	   cout<<"sucessfully edited\n";
	else
	    cout<<"Unknown passport_no\n";}
//exit from the program
void Exit(int &e){
		system ("cls");
		char c2;
		cout<<"Are you sure?(yes(Y)\no(N)): ";
		cin>>c2;
		if(c2=='y'|| c2=='Y'){
			e++;
		}
	 
	return; } 
//	total size of registered people
void size(char *fn){
		system ("cls");
		ifstream in(fn,ios::binary);
		if(in.is_open()){
			int nom=0;
			int nof=0;
			people p;
			in.read((char*)&p,sizeof(p));
			while(!in.eof()){
			if(p.sex=='m'|| p.sex=='M' ){
				nom++;}
			else if(p.sex=='f'||p.sex=='F'){
				nof++;}
				in.read((char*)&p,sizeof(p));}
				cout<<"Male: "<<nom<<endl;
				cout<<"Female: "<<nof<<endl;
				cout<<"Total: "<<nom+nof<<endl;
		}
		else 
		cout<<"unable to open the file.\n";
	}  
	    
		

