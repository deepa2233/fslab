1 //============================================================================ 
2 // Name        : lab3.cpp 
3 // Author      : deepa 
4 // Version     : 
5 // Copyright   : Your copyright notice 
6 // Description : Variable length records 
7 //============================================================================ 
8 #include <iostream> 
9 #include<string> 
10 #include<fstream> 
11 #include<sstream> 
12 using namespace std; 
13 class student 
14 { 
15 	string usn,name,branch,sem,buffer; 
16 public: 
17 	void read(); 
18 	void pack(); 
19 	void unpack(); 
20 	void write(); 
21 	int search(string); 
22 	void modify(string); 
23 }; 
24 void student::read() 
25 { 
26 	cout<<"Enter the name"<<endl; 
27 	cin>>name; 
28 	cout<<"Enter the usn"<<endl; 
29 	cin>>usn; 
30 	cout<<"Enter the branch"<<endl; 
31 	cin>>branch; 
32 	cout<<"Enter the semester"<<endl; 
33 	cin>>sem; 
34 } 
35 void student::pack() 
36 { 
37 	string temp; 
38 	int i; 
39 	temp.erase(); 
40 	buffer.erase(); 
41 	temp+=usn+'|'+name+'|'+branch+'|'+sem+'$'; 
42 	buffer+=temp; 
43 	cout<<buffer<<endl; 
44 } 
45 void student::write() 
46 { 
47 	fstream f1; 
48 	f1.open("Data.txt",ios::out|ios::app); 
49 	f1<<buffer; 
50 	f1<<endl; 
51 	f1.close(); 
52 } 
53 int student::search(string key) 
54 { 
55 	fstream f1; 
56 	int pos; 
57 	buffer.erase(); 
58 	f1.open("Data.txt",ios::in); 
59 	while(!f1.eof()) 
60 	{ 
61 		getline(f1,buffer); 
62 		pos=f1.tellp(); 
63 		unpack(); 
64 		if(usn==key) 
65 		{ 
66 			cout<<"found the record"<<endl; 
67 			f1.close(); 
68 			return pos; 
69 		} 
70 
 
71 	} 
72 	return 0; 
73 } 
74 void student::unpack() 
75 { 
76 	int i=0; 
77 	usn.erase(); 
78 	while(buffer[i]!='|') 
79 		usn+=buffer[i++]; 
80 	i++; 
81 	name.erase(); 
82 	while(buffer[i]!='|') 
83 		name+=buffer[i++]; 
84 	i++; 
85 	branch.erase(); 
86 	while(buffer[i]!='|') 
87 		branch+=buffer[i++]; 
88 	i++; 
89 	sem.erase(); 
90 	while(buffer[i]!='$') 
91 		sem+=buffer[i++]; 
92 	i++; 
93 } 
94 void student::modify(string key) 
95 { 
96 	int ch,pos; 
97 	fstream f1; 
98 	pos=search(key); 
99 	if(pos<1)return; 
100 	cout<<"Record modified at position :"<<pos<<endl; 
101 	cout<<"Enter choice for modification :"<<endl; 
102 	cout<<"1.USN"<<endl<<"2.NAME"<<endl<<"3.BRANCH"<<endl<<"4.SEMESTER"<<endl; 
103 	cout<<"Enter your choice: "; 
104 	cin>>ch; 
105 	switch(ch) 
106 	{ 
107 	case 1: 
108 		cout<<"Enter the USN : "<<endl; 
109 		cin>>usn; 
110 		cout<<endl; 
111 		break; 
112 	case 2: 
113 		cout<<"Enter the name "<<endl; 
114 		cin>>name; 
115 		cout<<endl; 
116 		break; 
117 	case 3: 
118 		cout<<"Enter the branch "<<endl; 
119 		cin>>branch; 
120 		cout<<endl; 
121 		break; 
122 	case 4: 
123 		cout<<"Enter the sem"<<endl; 
124 		cin>>sem; 
125 		break; 
126 	default: 
127 		cout<<"Enter a valid choice"<<endl; 
128 	} 
129 	pack(); 
130 	pos=pos-(buffer.size()+1); 
131 	f1.open("Data.txt"); 
132 	f1.seekp(pos,ios::beg); 
133 	f1<<buffer; 
134 	f1<<endl; 
135 	f1.close(); 
136 } 
137 int main() 
138 { 
139 	int choice,i; 
140 	string key; 
141 	student s; 
142 	while(1) 
143 	{ 
144 		cout    <<"1.INSERT"<<endl 
145 				<<"2.SEARCH"<<endl 
146 				<<"3.MODIFY"<<endl; 
147 		cout<<"Enter your choice"; 
148 		cin>>choice; 
149 		switch(choice) 
150 		{ 
151 		case 1: 
152 			s.read(); 
153 			s.pack(); 
154 			s.write(); 
155 			break; 
156 		case 2: 
157 
 
158 			cout<<"Enter the key ; "<<endl; 
159 			cin>>key; 
160 			i= s.search(key); 
161 			if(i!=0) 
162 				cout<<"Found at "<<i-101; 
163 			else 
164 				cout<<"Not found"; 
165 			break; 
166 		case 3: 
167 			cout<<"Enter key "<<endl; 
168 			cin>>key; 
169 			s.modify(key); 
170 			break; 
171 
 
172 		default:return 0; 
173 		} 
174 	} 
175 	return 0; 
176 } 



