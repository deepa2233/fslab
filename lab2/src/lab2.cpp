//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;
class student
{

	string usn,name;
	int sem;
 public :
	void read();
	void write();
	void pack();
	void unpack();
	int search(string);
	void display();
};
fstream fp;
string key;
void student::read(void)
{
	cout<<"enter usn name ansd sem;"<<endl;
			cin>>usn;
			cin>>name;
			cin>>sem;
}
void student::pack(void)
{
	student s;
	string buffer;
	string ss;
	stringstream out;
	out<<sem;
	ss=out.str();
	buffer=usn+'|'+name+'|'+ss;
	buffer.resize(100,'$');
	s.write();


}
void student::unpack(void)
{
   int i=0;
	string buffer;

	fp.open("file1.txt",ios::in);

    while(buffer[i]!='|')
    {
    	usn+=buffer[i++];
    }
    i++;
    while(buffer[i]!='|')
        {
        	name+=buffer[i++];
        }
    i++;
    while(buffer[i]!='$')
        {
        	sem+=buffer[i++];
        }

	fp.close();
}
int student::search(string )
{student s;
	int pos;
	int flag=0;
	string buffer;
	fp.open("file1.txt",ios::in);
	while(!fp.eof())
	{
		getline(fp,buffer);
		pos=fp.tellp();
		s.unpack();}
		if(s.usn==key)
		{
			flag=1;
		cout<<"succesfull";
		}

		if(flag==0)
		{
				cout<<"unsucces";
		}

		return pos;


}
void student::write(void)
{
	string buffer;
		fp.open("file1.txt",ios::out|ios::app);
				fp<<buffer;
		fp.close();
}

int main() {

	int choice;
	student s;
	cout << "1.read data 2.search" << endl;
		cout<<"enter   gfhgf   ur choice"<<endl;

	cin>>choice;

	switch(choice)
	{
	case 1:

		s.read();
	fp.open("file1.txt",ios::out);
		if(!fp)
			cout<<"not opened"<<endl;
		s.pack();
		s.write();
		fp.close();
			break;
	case 2:cout<<"enter key to be searched"<<endl;
	       cin>>key;
	       s.search(key);


	       break;
	default:exit(0);

	}
	return 0;
}
