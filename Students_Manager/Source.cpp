#include"Header.h"
using namespace std;

int main()
{
	Start();
	system("PAUSE");
	return 0;
}

void WriteFile(student st)
{
	fstream f;
	f.open("data.txt", ios::app);
	f<<endl;
	f << st.id_student << endl;
	f << st.id_class << endl;
	f << st.name << endl;
	f << st.dateOfBirth << endl;
	f << st.average;
	f.close();
}

void ReadFile(list& l)
{
	fstream f;
	student st;
	f.open("data.txt", ios::in);
	if (f==NULL)	//if(!f)
	{
		cout << "No Entries Found....."<<endl;
	}
	else
	{
		st.stt=0;
		while (!f.eof())
		{
			getline(f, st.id_student);
			getline(f, st.id_class);
			getline(f, st.name);
			getline(f, st.dateOfBirth);
			getline(f, st.average);
			st.stt++;
			node *p = Creat_node(st);
			Insert_at_last(l, p);
		}
	}
}

void Choice()
{
	cout << "\n\n  Do you want to exit program? (Y/N) =>  \a";
	choice=_getch();
	switch(choice)
	{
	case 'y':
		exit(0);
	case 'Y':
		exit(0);
	case 'N':
		Main_menu();
		break;
	case 'n':
		Main_menu();
		break;
	}
}

void gotoxy(int x, int y)
{
	COORD ord;
	ord.X = x;
	ord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}
void Start()
{
	Sleep(800);
	gotoxy(43, 15);
	cout << "STUDENT INFORMATION SYSTEM\n";
	Sleep(600);
	system("color 7c");
	gotoxy(43, 17);
	Sleep(100);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(200);
	cout << "\xDB\xDB\xDB\xDB";
	Sleep(100);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(100);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(50);
	system("color 17");
	Main_menu();
}

void Main_menu()
{
	list l;
	Init(l);
	ReadFile(l);
	do
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t    MAIN MENU \n";
		cout << "\t\t\t\t\t_______________________________\n\n";
		cout << "\n\t\t\t\t\t1.Add Student \n";
		cout << "\n\t\t\t\t\t2.Delete Student \n";
		cout << "\n\t\t\t\t\t3.Display All List\n";
		cout << "\n\t\t\t\t\t4.Arrange\n";
		cout << "\n\t\t\t\t\t5.Find A Student\n";
		cout << "\n\t\t\t\t\t6.Statistic\n";
		cout << "\n\t\t\t\t\t7.Exit\n";
		cout << "\n\t\t\t\t\t=>Choose Number : ";
		choice1=_getch();
		switch (choice1)
		{
		case '1':
			system("cls");
			Insert(l);
			break;
		case '2':
			system("cls");
			viewDel(l);
			break;
		case '3':
			system("cls");
			Display(l);
			break;
		case '4':
			system("cls");
			Arrange(l);
			break;
		case '5':
			system("cls");
			Search(l);
			break;
		case '6':
			system("cls");
			Statistic(l);
			break;
		case '7':
			exit(0);
			break;
		default:
			break;
		}
		cout << "\n\n  *Press ENTER KEY To <continue>";
		cout << "\n\n  *Press ESC KEY To <exit>";
		choice2=_getch();
		system("cls");
		if (choice2 == 27)
		{
			exit(0);
		}
		else
		{
			Main_menu();
		}
	} while (choice2 == 13);
}

void Print(list &l)
{
	node *p = l.head;
	gotoxy(40, 1);
	cout << "\tDISPLAY STUDENT \n";
	cout << "\t______________________________________________________________________________________________";
	cout << "\n";
	cout << "\t______________________________________________________________________________________________\n\n";
	//
	cout << "\t" << char(218);
	for (int i = 0; i < 87; i++) {
		cout << char(196);
		if (i == 4 || i == 17 || i == 33 || i == 58 || i == 75) cout << char(194);
	}
	cout << char(191) << endl;
	//
	//cout << "\n";
	//cout << "\t+-----+-----------+-------+---------------------------+---------------+--------+" << endl;
	//cout << "\t| STT |    ID     | CLASS |        FULL NAME          | DATE OF BIRTH | SCORE  |" << endl;
	//cout << "\t+-----+-----------+-------+---------------------------+---------------+--------+" << endl;

	//
	cout << "\t" << char(179); cout << " STT ";
	cout << char(179) << "    ID" << setw(7) << "";
	cout << char(179) << "   CLASS" << setw(8) << "";
	cout << char(179) << " FULL NAME" << setw(15) << "";
	cout << char(179) << " DATE OF BIRTH   ";
	cout << char(179) << "   SCORE   " << char(179) << endl;
	//

	//
	int stt=1;
	while (p!=NULL)
	{
		//
		cout << "\t" << char(195);
		for (int i = 0; i < 87; i++) {
			cout << char(196);
			if (i == 4 || i == 17 || i == 33 || i == 58 || i == 75)cout << char(197);
		}
		cout << char(180) << endl;
		//
		cout << "\t" << char(179) << setw(3) << stt << "  " << char(179) << " " << p->data.id_student
			<< setw(13 - p->data.id_student.length()) << char(179) << " " << p->data.id_class
			<< setw(16 - p->data.id_class.length()) << char(179) << " " << p->data.name;
		cout << setw(25 - p->data.name.length()) << char(179) << " " << p->data.dateOfBirth
			<< setw(17 - p->data.dateOfBirth.length()) << char(179) << " ";
		double mark = atof(p->data.average.c_str());
		cout << setiosflags(ios::showpoint)
			<< setprecision(3) << mark << setw(7) << char(179) << endl;
		//cout << "\t+-----+-----------+-------+---------------------------+---------------+--------+" << endl;
		p = p->next;
		stt++;
	}
	//
	cout << "\t" << char(192);
	for (int i = 0; i < 87; i++) {
		cout << char(196);
		if (i == 4 || i == 17 || i == 33 || i == 58 || i == 75)cout << char(193);
	}
	cout << char(217);
	cout << "\n\t______________________________________________________________________________________________";
	cout << "\n";
	cout << "\t______________________________________________________________________________________________\n";

	//cout << "\t================================================================================";
}

int checkName(string s)
{
	int count=1;
	for(int i=0;i<s.size();i++)
	{
		if (s[i]==48||s[i]==49||s[i]==50||s[i]==51||s[i]==52||s[i]==53||s[i]==54||s[i]==55||s[i]==56||s[i]==57)
		{
			count =0;
			break;
		}
	}
	return count;
}

bool checkDate(string s)//doi ngay sinh tu string ve d,m,y roi kiem tra tung ngay thang nam.
{
	Birthday bd= splitDOB(s);
	if (bd.yy<1900||bd.yy>2016) return false;
	if (bd.mm < 1 || bd.mm>12) return false;
	switch (bd.mm)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (bd.dd < 1 || bd.dd>31)
		{
			return false;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (bd.dd < 1 || bd.dd>30)
		{
			return false;
		}
		break;
	case 2:
		if (bd.yy % 4 == 0)
		{
			if (bd.dd < 1 || bd.dd>29)
			{
				return false;
			}
			break;
		}
		else
		{
			if (bd.dd < 1 || bd.dd>28)
			{
				return false;
			}
			break;
		}
	}
	return true;
}

void Insert(list &l)
{
	gotoxy(45, 1); cout << "   ADD STUDENT ";
	gotoxy(45, 2); cout << " _______________\n";
	cout << "\n";
	student st;

	//ID
	gotoxy(0,5);cout << "\n #Student Id (8 numbers) : ";
	fflush(stdin);
	getline(cin, st.id_student);
	while ((st.id_student).size()!=8 || change(st.id_student)==0)
	{	
		gotoxy(27,6);cout <<"                                                                     ";
		fflush(stdin);
		gotoxy(27,6);getline(cin, st.id_student);
	}


	//Class
	cout << "\n #Enter The Class : ";
	getline(cin, st.id_class);
	st.id_class=upperCase(st.id_class);


	//Name
	cout << "\n #Enter The Name : ";
	getline(cin, st.name);
	st.name=standardizedName(st.name);
	while (checkName(st.name)==0)
	{	
		gotoxy(19,10);cout <<"                                                                     ";
		fflush(stdin);
		gotoxy(19,10);getline(cin, st.name);
	}	


	//Date of birth
	cout << "\n #Enter The Date Of Birth (dd/mm/yyyy) : ";
	getline(cin, st.dateOfBirth);
	st.dateOfBirth=standardizedDOB(st.dateOfBirth);
	while (checkDate(st.dateOfBirth)==false)
	{	
		gotoxy(41,12);cout <<"                                                                      ";
		fflush(stdin);
		gotoxy(41,12);getline(cin,  st.dateOfBirth);
	}

	//Average
	cout << "\n #Enter The Point Average : ";
	getline(cin, st.average);
	while (change(st.average)<0||change(st.average)>4||change(st.average)==0) 
	{	
		gotoxy(28,14);cout <<"                                                                      ";
		fflush(stdin);
		gotoxy(28,14);getline(cin, st.average);
	}

	WriteFile(st);

	cout << "\n  Your List Has Been SuccessFully Inserted!\n \a";
	cout << "\n  Do You Want To Add Another Student ? (Y/N) ? =>  ";
	choice=_getch();
	switch (choice)
	{
	case 'y':
		system("cls");
		Insert(l);
		break;
	case 'Y':
		system("cls");
		Insert(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void Display(list &l)
{
	system("cls");
	Print(l);
	Choice();
}

string deleteSpaceAtFirst(string str)
{
	int n=str.length();
	for(int i=0;i<str.length();i++)
	{
		if (str[0]==' ')
			str.erase(0,1);
	}
	return str;
}
string deleteSpaceAtLast(string str)
{
	int n=str.length();
	for(int i=n-1;i>=0;i--)
	{
		if (str[i]==' ')
		{
			str.erase(i,1);
		}
		else
			break;
	}
	return str;
}

string deleteSpaceBetween(string str)
{
	while(!str.empty())
	{
		if(str.find("  ")>str.size())
			break;
		else
			str.erase(str.find("  "),1);
	}
	return str;
}

string standardizedName(string str)
{
	str=deleteSpaceBetween(str);
	str=deleteSpaceAtFirst(str);
	str=deleteSpaceAtLast(str);
	int n = str.length();
	str[0] = toupper(str[0]);
	for (int i = 1;i < n;i++) {
		if (str[i] != ' ')
			str[i] = tolower(str[i]);
		else 
		{
			str[i + 1] = toupper(str[i + 1]);
			i += 2;
		}
	}
	return str;
}


string ReverseName(string str) {//dao nguoc ten HangNguyenThiMinh
	//	str=standardizedName(str);
	string resultStr, s;
	//chuyen ten len dau 
	for (int i = str.length() - 1; i >= 0; i--){
		if (str[i] == ' ')
			break;
		resultStr = str.substr(i);
		s = str.substr(0, i - 1);
		resultStr += s;
	}
	int n = resultStr.length();
	//xoa tat ca khoang trang
	for (int j = 0; j < n - 1; j++){
		if (resultStr[j] == ' ')
			resultStr = resultStr.erase(j,1);
	}
	return resultStr;
}

string upperCase(string s)//Viet Hoa
{
	int n = s.length();
	for (int i = 0;i < n;i++) {
		s[i] = toupper(s[i]);
	}
	return s;
}


Birthday splitDOB(string str)//Tach ngay thang nam
{
	Birthday bd;
	bd.dd = change(str.substr(0,2));
	bd.mm=change(str.substr(3,2));
	bd.yy=change(str.substr(6,4));
	return bd;
}
//Nhap du lieu:
//chuan hoa ngay sinh thanh dd/mm/yyyy: doc du lieu, dua ve dang chuan hoa.
//check ngay sinh. kiem tra day, month, year xem hop le chua: 
//+doi ngay sinh tu string ve dl so dd,mm,yy. kiem tra dung chua
//+neu ko dung thi nhap lai
//Sap xep ngay sinh:
//+tach ngay thang nam roi so sanh. tra ve gia tri 1 hoac 0.
//

string splitStr(string str)// tach chuoi ngay sinh: 11/10/1996 thanh 10111996 va chuyen thanh 19961110
{
	return str.substr(6,4)+str.substr(3,2)+str.substr(0,2)+str.substr(0,2);
}


string standardizedDOB(string str)
{
	//Dang chuan --/--/----
	//Duyet tu dau toi cuoi. Neu truoc ki tu '/' or '.' or '-' ma co 1 ki tu thi them so 0 vao truoc. vd: 1 => 01
	string s,tg;
	for(int i=0;i<str.length();i++)
	{
		tg=str.substr(0,str.find("/")+1);
		str=str.erase(0,str.find("/")+1);
		if(tg.size()==2)
			s+='0'+tg;
		else
			s+=tg;
	}
	s+=str;
	return s;
}

int checkDOB(Birthday bd1, Birthday bd2)
{
	//1: nguoi 1 lon tuoi hon nguoi 2
	//0: nguoi 1 nho tuoi hon nguoi 2
	if (bd1.yy==bd2.yy)
	{
		if (bd1.mm==bd2.mm)
		{
			if (bd1.dd<=bd2.dd)
				return 1;
			else return 0;
		}
		else if (bd1.mm<bd2.mm)
			return 1;
		else return 0;
	}
	else if (bd1.yy<bd2.yy) 
		return 1;
	else return 0;
}

double change(string x)
{
	return atof(x.c_str());
}

void Swap(student &a, student &b)
{
	student tg = a;
	a = b;
	b = tg;
}

void Select_sort(list &l)
{
	gotoxy(45, 1); cout << " SELECT THE KEY TO SORT" << endl;
	gotoxy(45, 2); cout << "________________________" << endl;
	cout << "\n 1. Name " << endl;
	cout << "\n 2. ID Student " << endl;
	cout << "\n 3. ID Class " << endl;
	cout << "\n 4. Point Average" << endl;
	cout << "\n 5. Date Of Birth" << endl;
	cout << "\n 6. Back" << endl;
	cout << "\n Enter A Number Which You Select: ";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		system("cls");
		{
			SS_Name(l);
		}
		break;
	case '2':
		system("cls");
		{
			SS_StudentID(l);
		}
		break;
	case '3':
		system("cls");
		{
			SS_ClassID(l);
		}
		break;
	case '4':
		system("cls");
		{
			SS_Average(l);
		}
		break;
	case '5':
		system("cls");
		{
			SS_DOB(l);
		}
		break;
	case '6':
		system("cls");
		Arrange(l);
		break;
	default: break;
	}
	cout << "\n\n  Do you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Select_sort(l);
		break;
	case 'Y':
		system("cls");
		Select_sort(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void SS_Average(list &l)
{
	node* t1,*t2;
	for (t1 = l.head; t1 != l.tail; t1 = t1->next) {
		node* min = t1;
		for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
			if (min->data.average.compare(t2->data.average) > 0) min = t2;
		}
		if(min!=t1)
			Swap(t1->data, min->data);
	}
	Print(l);
}

void SS_Name(list &l)
{
	node* t1, *t2;
	for (t1 = l.head; t1 != l.tail; t1 = t1->next) {
		node* min = t1;
		for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
			if (ReverseName(min->data.name).compare(ReverseName(t2->data.name)) > 0) min = t2;
		}
		if(min!=t1)
			Swap(t1->data, min->data);
	}
	Print(l);
}

void SS_ClassID(list &l)
{
	node* t1, *t2;
	for (t1 = l.head; t1!= l.tail; t1 = t1->next) {
		node* min = t1;
		for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
			if (min->data.id_class.compare(t2->data.id_class) > 0) min = t2;
		}
		if(min!=t1)
			Swap(t1->data, min->data);
	}
	Print(l);
}

void SS_StudentID(list &l)
{
	node* t1, *t2;
	for (t1 = l.head; t1!= l.tail; t1 = t1->next) {
		node* min = t1;
		for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
			if (min->data.id_student.compare(t2->data.id_student) > 0) min = t2;
		}
		if(min!=t1)
			Swap(t1->data, min->data);
	}
	Print(l);
}


void SS_DOB(list &l)
{
	node* t1, *t2;
	for (t1 = l.head; t1!= l.tail; t1 = t1->next) {
		node* min = t1;
		for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
			if (checkDOB(splitDOB(min->data.dateOfBirth),splitDOB(t2->data.dateOfBirth))==1) 
				min = t2;
		}
		if(min!=t1)
			Swap(t1->data, min->data);
	}
	Print(l);
}


void Quick_sort(list &l)
{
	gotoxy(45, 1); cout << " SELECT THE KEY TO SORT" << endl;
	gotoxy(45, 2); cout << "________________________" << endl;
	cout << "\n 1. Name " << endl;
	cout << "\n 2. ID Student " << endl;
	cout << "\n 3. ID Class " << endl;
	cout << "\n 4. Point Average" << endl;
	cout << "\n 5. Date Of Birth" << endl;
	cout << "\n 6. Back" << endl;
	cout << "\n Enter A Number Which You Select: ";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		system("cls");
		{
			QS_Name(l);
		}
		break;
	case '2':
		system("cls");
		{
			QS_StudentID(l);
		}
		break;
	case '3':
		system("cls");
		{
			QS_ClassID(l);
		}
		break;
	case '4':
		system("cls");
		{
			QS_Average(l);
		}
		break;
	case '5':
		system("cls");
		{
			QS_DOB(l);
		}
		break;
	case '6':
		system("cls");
		Arrange(l);
		break;
	default: break;
	}
	cout << "\nDo you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Quick_sort(l);
		break;
	case 'Y':
		system("cls");
		Quick_sort(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void QSbyName(student st[] , int l , int r)
{
	int i = l ; int j = r;
	student k = st[l];
	do
	{
		while (ReverseName(st[i].name).compare(ReverseName(k.name)) < 0 && i < r) i++;
		while (ReverseName(st[j].name).compare(ReverseName(k.name)) > 0 && j > l) j--;
		if ( i <= j)
		{ 
			Swap(st[i] , st[j]);
			i++ ; j--;
		}
	}while(i<=j);
	if (i < r) QSbyName(st,i,r);
	if( j > l) QSbyName(st,l,j);
}

void QS_Name(list &l)
{
	student st[50];
	int dem = 0;
	node *p = l.head;
	int i = 0;	
	while (p != NULL)
	{
		st[i] = p->data;
		i++;
		p = p->next;
	}

	QSbyName(st,0,i-1);
	list l_rel;
	Init(l_rel);
	for (int j = 0 ; j < i ; j++)
	{
		node *p = Creat_node(st[j]);
		Insert_at_last(l_rel,p);
	}
	Print(l_rel);
}

void QSbyDOB(student st[] , int l , int r)
{

	int i = l ; int j = r;
	student k = st[l];
	do
	{
		while (checkDOB(splitDOB(st[i].dateOfBirth),splitDOB(k.dateOfBirth))==0 && i < r) i++;
		while (checkDOB(splitDOB(st[j].dateOfBirth),splitDOB(k.dateOfBirth))==1 && j > l) j--;
		if ( i <= j)
		{ 
			Swap(st[i] , st[j]);
			i++ ; j--;
		}
	}while(i <= j);

	if (i < r) QSbyDOB(st,i,r);
	if( j > l) QSbyDOB(st,l,j);

}

void QS_DOB(list &l)
{
	student st[50];
	int dem = 0;
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p->data;
		i++;
		p = p->next;
	}

	QSbyDOB(st, 0, i - 1);
	list l_rel;
	Init(l_rel);
	for (int j = 0; j < i; j++)
	{
		node *p = Creat_node(st[j]);
		Insert_at_last(l_rel, p);
	}
	Print(l_rel);
}


void QSbyAverage(student st[] , int l , int r)
{

	int i = l ; int j = r;
	student k = st[l];
	do
	{
		while (st[i].average.compare(k.average) < 0 && i < r) i++;
		while (st[j].average.compare(k.average) > 0 && j > l) j--;
		if ( i <= j)
		{ 
			Swap(st[i] , st[j]);
			i++ ; j--;
		}
	}while(i<=j);
	if (i < r) QSbyAverage(st,i,r);
	if( j > l) QSbyAverage(st,l,j);
}


void QS_Average(list &l)
{
	//dua dslk vao mang
	student st[50];
	int dem = 0;
	node *p = l.head;
	int i = 0;	
	while (p != NULL)
	{
		st[i] = p->data;
		i++;
		p = p->next;
	}
	//sap xep mang
	QSbyAverage(st,0,i-1);
	//dua mang vao lai danh sach
	list l_rel;
	Init(l_rel);
	for (int j = 0 ; j < i ; j++)
	{
		node *p = Creat_node(st[j]);
		Insert_at_last(l_rel,p);
	}
	Print(l_rel);
}

void QSbyClass(student st[] , int l , int r)
{

	int i = l ; int j = r;
	student k = st[l];
	do
	{
		while (st[i].id_class.compare(k.id_class) < 0 && i < r ) i++;
		while (st[j].id_class.compare(k.id_class) > 0 && j > l ) j--;
		if ( i <= j)
		{ 
			Swap(st[i] , st[j]);
			i++ ; j--;
		}
	} while(i<=j);
	if (i < r) QSbyClass(st,i,r);
	if( j > l) QSbyClass(st,l,j);
}

void QS_ClassID(list &l)
{
	student st[50];
	int dem = 0;
	node *p = l.head;
	int i = 0;	
	while (p != NULL)
	{
		st[i] = p->data;
		i++;
		p = p->next;
	}

	QSbyClass(st,0,i-1);
	list l_rel;
	Init(l_rel);
	for (int j = 0 ; j < i ; j++)
	{
		node *p = Creat_node(st[j]);
		Insert_at_last(l_rel,p);
	}
	Print(l_rel);
}

void QSbyID(student st[] , int l , int r)
{

	int i = l ; int j = r;
	student k = st[l];
	do
	{
		while (st[i].id_student.compare(k.id_student) < 0 && i < r ) i++;
		while (st[j].id_student.compare(k.id_student) > 0 && j > l ) j--;
		if ( i <= j)
		{ 
			Swap(st[i] , st[j]);
			i++ ; j--;
		}
	}while(i<=j);
	if (i < r) QSbyID(st,i,r);
	if( j > l) QSbyID(st,l,j);
}


void QS_StudentID(list &l)
{
	student st[50];
	int dem = 0;
	node *p = l.head;
	int i = 0;	
	while (p != NULL)
	{
		st[i] = p->data;
		i++;
		p = p->next;
	}

	QSbyID(st,0,i-1);
	list l_rel;
	Init(l_rel);
	for (int j = 0 ; j < i ; j++)
	{
		node *p = Creat_node(st[j]);
		Insert_at_last(l_rel,p);
	}
	Print(l_rel);
}


//SAP XEP SU DUNG THUAT TOAN INSERT 
void Insert_sort(list &l)
{
	gotoxy(45, 1); cout << " SELECT THE KEY TO SORT" << endl;
	gotoxy(45, 2); cout << "________________________" << endl;
	cout << "\n 1. Name " << endl;
	cout << "\n 2. ID Student " << endl;
	cout << "\n 3. ID Class " << endl;
	cout << "\n 4. Point Average" << endl;
	cout << "\n 5. Date Of Birth" << endl;
	cout << "\n 6. Back" << endl;
	cout << "\n Enter A Number Which You Select: ";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		system("cls");
		{
			IS_Name(l);
		}
		break;
	case '2':
		system("cls");
		{
			IS_StudentID(l);
		}
		break;
	case '3':
		system("cls");
		{
			IS_ClassID(l);
		}
		break;
	case '4':
		system("cls");
		{
			IS_Average(l);
		}
		break;
	case '5':
		system("cls");
		{
			IS_DOB(l);
		}
		break;
	case '6':
		system("cls");
		Arrange(l);
		break;
	default: break;
	}
	cout << "\nDo you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Insert_sort(l);
		break;
	case 'Y':
		system("cls");
		Insert_sort(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void IS_Name(list &l)
{
	node *t1,*t2;
	for (t1=l.head;t1!=l.tail;t1=t1->next)
	{
		for (t2=t1->next;t2!=NULL;t2=t2->next)
			if (ReverseName(t1->data.name).compare(ReverseName(t2->data.name))>0)
				Swap(t1->data,t2->data);
	}
	Print(l);
}
void IS_DOB(list &l)
{
	node *t1,*t2;
	for (t1=l.head;t1!=l.tail;t1=t1->next)
	{
		for (t2=t1->next;t2!=NULL;t2=t2->next)
			if (checkDOB(splitDOB(t1->data.dateOfBirth),splitDOB(t2->data.dateOfBirth))==1)
				Swap(t1->data,t2->data);
	}
	Print(l);
}

void IS_StudentID(list &l)
{
	node *t1,*t2;
	for (t1=l.head;t1!=l.tail;t1=t1->next)
	{
		for (t2=t1->next;t2!=NULL;t2=t2->next)
			if (t1->data.id_student.compare(t2->data.id_student)>0)
				Swap(t1->data,t2->data);
	}
	Print(l);
}

void IS_ClassID(list &l)
{
	node *t1,*t2;
	for (t1=l.head;t1!=l.tail;t1=t1->next)
	{
		for (t2=t1->next;t2!=NULL;t2=t2->next)
			if (t1->data.id_class.compare(t2->data.id_class)>0)
				Swap(t1->data,t2->data);
	}
	Print(l);
}

void IS_Average(list &l)
{
	node *t1,*t2;
	for (t1=l.head;t1!=l.tail;t1=t1->next)
	{
		for (t2=t1->next;t2!=NULL;t2=t2->next)
			if (t1->data.average.compare(t2->data.average)>0)
				Swap(t1->data,t2->data);
	}
	Print(l);
}


void Arrange(list &l)
{
	gotoxy(45, 1); cout << " SELECT THE ALGORITHM TO SORT" << endl;
	gotoxy(45, 2); cout << "______________________________" << endl;
	cout << "\n 1. Select Sort" << endl;
	cout << "\n 2. Quick Sort" << endl;
	cout << "\n 3. Insertion Sort" << endl;
	cout << "\n 4. Back" << endl;
	cout << "\n Enter A Number Which You Select: ";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		system("cls");
		Select_sort(l);
		break;
	case '2':
		system("cls");
		Quick_sort(l);
		break;
	case '3':
		system("cls");
		Insert_sort(l);
		break;
	case '4':
		system("cls");
		Main_menu();
		break;
	default: break;
	}
}


void Search(list &l)
{
	gotoxy(43, 1); cout << "SELECT THE ALGORITHM TO SEARCH" << endl;
	gotoxy(43, 2); cout << "______________________________" << endl;
	cout << "\n 1. Linear Search" << endl;
	cout << "\n 2. Binary Search" << endl;
	cout << "\n 3. Back" << endl;
	cout << "\n Enter a number which you select: ";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		system("cls");
		Linear_search(l);
		break;
	case '2':
		system("cls");
		Binary_search(l);
		break;
	case '3':
		system("cls");
		Main_menu();
		break;
	default: break;
	}
}

int SearchKey(string st , string key )   
{
	size_t found = st.find(key);
	if (found != string::npos)
		return 1;
	else return 0;
}

void Linear_search(list &l)
{
	system("cls");
	node *p=l.head;
	string key;
	list newlist;
	Init(newlist);
	node *temp;
	int count=0;
	student st[50];
	int i=0;
	gotoxy(45, 1); cout << " SELECT THE KEY TO SEARCH " << endl;
	gotoxy(45, 2); cout << "__________________________" << endl;
	cout << "\n 1. Name " << endl;
	cout << "\n 2. ID Student " << endl;
	cout << "\n 3. ID Class " << endl;
	cout << "\n 4. Point Average" << endl;
	cout << "\n 5. Date Of Birth" << endl;
	cout << "\n 6. Back" << endl;
	cout << "\n Enter A Number Which You Select:";
	choice1=_getch();
	switch (choice1)
	{
	case '1':
		{
			system("cls");
			gotoxy(35,2);cout<<"Enter the name which you want to search: ";
			cin>>key;
			while(p!=NULL)
			{
				st[i]=p->data;	
				if ( SearchKey(p->data.name,key) == 1 )
				{
					temp=Creat_node(st[i]);
					Insert_at_last(newlist,temp);
					count++;
					i++;
				}
				p = p -> next;
			}
			if ( count!=0)
				Print(newlist);
			else
			{
				gotoxy(45,4);cout<<"Not found!!!"<<endl;
			}
		}
		break;
	case '2':
		{
			system("cls");
			gotoxy(35,2);cout<<"Enter the ID of student which you want to search: ";
			cin>>key;
			while(p!=NULL)
			{
				st[i]=p->data;	
				if ( SearchKey(p->data.id_student,key) == 1 )
				{
					temp=Creat_node(st[i]);
					Insert_at_last(newlist,temp);
					count++;
					i++;
				}
				p = p -> next;
			}
			if ( count!=0)
				Print(newlist);
			else
			{
				gotoxy(35,4);
				cout<<"Not found!!!"<<endl;
			}
		}
		break;
	case '3':
		{
			system("cls");
			gotoxy(35,2);cout<<"Enter the class ID which you want to search: ";
			cin>>key;
			while(p!=NULL)
			{
				st[i]=p->data;	
				if ( SearchKey(p->data.id_class,key) == 1 )
				{
					temp=Creat_node(st[i]);
					Insert_at_last(newlist,temp);
					count++;
					i++;
				}
				p = p -> next;
			}
			if ( count!=0)
				Print(newlist);
			else
			{
				gotoxy(35,4);
				cout<<"Not found!!!"<<endl;
			}
		}
		break;
	case '4':
		{
			system("cls");
			gotoxy(35,2);cout<<"Enter the average which you want to search: ";
			cin>>key;
			while(p!=NULL)
			{
				st[i]=p->data;	
				if ( SearchKey(p->data.average,key) == 1 )
				{
					temp=Creat_node(st[i]);
					Insert_at_last(newlist,temp);
					count++;
					i++;
				}
				p = p -> next;
			}
			if ( count!=0)
				Print(newlist);
			else
			{
				gotoxy(35,4);
				cout<<"Not found!!!"<<endl;
			}
		}
		break;
	case '5':
		{
			system("cls");
			gotoxy(25,2);cout<<"Enter the date of birth student which you want to search: ";
			cin>>key;
			while(p!=NULL)
			{
				st[i]=p->data;	
				if ( SearchKey(p->data.dateOfBirth,key) == 1 )
				{
					temp=Creat_node(st[i]);
					Insert_at_last(newlist,temp);
					count++;
					i++;
				}
				p = p -> next;
			}
			if ( count!=0)
				Print(newlist);
			else
			{
				gotoxy(35,4);
				cout<<"Not found!!!"<<endl;
			}
		}
		break;
	case '6':
		system("cls");
		Search(l);
		break;
	default: break;
	}
	cout << "\n\n  Do you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Linear_search(l);
		break;
	case 'Y':
		system("cls");
		Linear_search(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}



int BS_name(student st[], int left, int right, string x)
{
	//ham tim nhi phan tra ve gia tri tim thay mid
	//sap xep nhanh roi tim kiem

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (SearchKey(st[mid].name,x)==1) 
		return mid;
	if (x.compare(st[mid].name)<0) 
		return BS_name(st,left,mid-1,x);
	if (x.compare(st[mid].name)>0) 
		return BS_name(st,mid+1,right,x);
}
void ViewName(list &l)
{
	student st[50];
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p ->data;
		i++;
		p = p->next;
	}
	QSbyName(st,0,i-1);
	list l_rel;
	Init(l_rel);
	gotoxy(35,2);cout<<"Enter the name which you want to search: ";
	string key;
	fflush(stdin);
	getline(cin,key);
	int x = BS_name(st,0,i-1,key);
	if (x != -1)
	{
		node *p2 = Creat_node(st[BS_name(st,0,i-1,key)]);
		Insert_at_last(l_rel,p2);
		Print(l_rel);
	}
	else
	{
		//system("CLS");
		gotoxy(35,4);cout<<"Not found!!!"<<endl;
	}
}

int BS_average(student st[], int left, int right, string x)
{
	//ham tim nhi phan tra ve gia tri tim thay mid
	//sap xep nhanh roi tim kiem

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (SearchKey(st[mid].average,x)==1) 
		return mid;
	if (x.compare(st[mid].average)<0) 
		return BS_average(st,left,mid-1,x);
	if (x.compare(st[mid].average)>0) 
		return BS_average(st,mid+1,right,x);
}
void ViewAverage(list &l)
{
	student st[50];
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p ->data;
		i++;
		p = p->next;
	}
	QSbyAverage(st,0,i-1);
	list l_rel;
	Init(l_rel);
	gotoxy(35,2);cout<<"Enter the average which you want to search: ";
	string key;
	fflush(stdin);
	getline(cin,key);
	int x = BS_average(st,0,i-1,key);
	if (x != -1)
	{
		node *p2 = Creat_node(st[BS_average(st,0,i-1,key)]);
		Insert_at_last(l_rel,p2);
		Print(l_rel);
	}
	else
	{
		gotoxy(35,4);cout<<"Not found!!!"<<endl;
	}
}

int BS_DOB(student st[], int left, int right, string x)
{
	//ham tim nhi phan tra ve gia tri tim thay mid
	//sap xep nhanh roi tim kiem

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (SearchKey(st[mid].dateOfBirth,x)==1) 
		return mid;
	if (x.compare(st[mid].dateOfBirth)<0) 
		return BS_DOB(st,left,mid-1,x);
	if (x.compare(st[mid].dateOfBirth)>0) 
		return BS_DOB(st,mid+1,right,x);
}
void ViewDOB(list &l)
{
	student st[50];
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p ->data;
		i++;
		p = p->next;
	}
	QSbyDOB(st,0,i-1);
	list l_rel;
	Init(l_rel);
	gotoxy(25,2);cout<<"Enter the date of birth student which you want to search: ";
	string key;
	fflush(stdin);
	getline(cin,key);
	int x = BS_DOB(st,0,i-1,key);
	if (x != -1)
	{
		node *p2 = Creat_node(st[BS_DOB(st,0,i-1,key)]);
		Insert_at_last(l_rel,p2);
		Print(l_rel);
	}
	else
	{
		gotoxy(35,4);cout<<"Not found!!!"<<endl;
	}
}

int BS_Class(student st[], int left, int right, string x)
{
	//ham tim nhi phan tra ve gia tri tim thay mid
	//sap xep nhanh roi tim kiem

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (SearchKey(st[mid].id_class,x)==1) 
		return mid;
	if (x.compare(st[mid].id_class)<0) 
		return BS_Class(st,left,mid-1,x);
	if (x.compare(st[mid].id_class)>0) 
		return BS_Class(st,mid+1,right,x);
}
void ViewClass(list &l)
{
	student st[50];
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p ->data;
		i++;
		p = p->next;
	}
	QSbyClass(st,0,i-1);
	list l_rel;
	Init(l_rel);
	gotoxy(35,2);cout<<"Enter the class ID which you want to search: ";
	string key;
	fflush(stdin);
	getline(cin,key);
	int x = BS_Class(st,0,i-1,key);
	if (x != -1)
	{
		node *p2 = Creat_node(st[BS_Class(st,0,i-1,key)]);
		Insert_at_last(l_rel,p2);
		Print(l_rel);
	}
	else
	{
		gotoxy(35,4);cout<<"Not found!!!"<<endl;
	}
}

int BS_ID(student st[], int left, int right, string x)
{
	//ham tim nhi phan tra ve gia tri tim thay mid
	//sap xep nhanh roi tim kiem

	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (SearchKey(st[mid].id_student,x)==1) 
		return mid;
	if (x.compare(st[mid].id_student)<0) 
		return BS_ID(st,left,mid-1,x);
	if (x.compare(st[mid].id_student)>0) 
		return BS_ID(st,mid+1,right,x);
}
void ViewID(list &l)
{
	student st[50];
	node *p = l.head;
	int i = 0;
	while (p != NULL)
	{
		st[i] = p ->data;
		i++;
		p = p->next;
	}
	QSbyID(st,0,i-1);
	list l_rel;
	Init(l_rel);
	gotoxy(35,2);cout<<"Enter the ID of student which you want to search: ";
	string key;
	fflush(stdin);
	getline(cin,key);
	int x = BS_ID(st,0,i-1,key);
	if (x != -1)
	{
		node *p2 = Creat_node(st[BS_ID(st,0,i-1,key)]);
		Insert_at_last(l_rel,p2);
		Print(l_rel);
	}
	else
	{
		gotoxy(35,4);cout<<"Not found!!!"<<endl;
	}
}

void Binary_search(list &l)
{
	system("cls");
	node *p=l.head;
	string key;
	list newlist;
	Init(newlist);
	node *temp;
	int count=0;
	student st[50];
	int i=0;
	gotoxy(45, 1); cout << " SELECT THE KEY TO SEARCH " << endl;
	gotoxy(45, 2); cout << "__________________________" << endl;
	cout << "\n 1. Name " << endl;
	cout << "\n 2. ID Student " << endl;
	cout << "\n 3. ID Class " << endl;
	cout << "\n 4. Point Average" << endl;
	cout << "\n 5. Date Of Birth" << endl;
	cout << "\n 6. Back" << endl;
	cout << "\n Enter A Number Which You Select:";
	choice1=_getch();
	switch (choice1)
	{
	case '1' :
		{
			system("cls"); 
			ViewName(l) ; 
			break;
		}
	case '2':
		{
			system("cls"); 
			ViewID(l) ; 
			break;
		}
	case '3':
		{
			system("cls"); 
			ViewClass(l) ; 
			break;
		}
	case '4':
		{
			system("cls"); 
			ViewAverage(l) ; 
			break;
		}
	case '5':
		{
			system("cls"); 
			ViewDOB(l) ; 
			break;
		}
	case '6':
		system("cls");
		Search(l);
		break;
	default: break;
	}
	cout << "\n\n  Do you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Binary_search(l);
		break;
	case 'Y':
		system("cls");
		Binary_search(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void Statistic(list &l)     //Thong Ke
{
	system("CLS");
	gotoxy(45,1); cout<<" STATISTICAL TABLES ";
	gotoxy(45,2); cout<<"____________________"<<endl;
	cout<<"\n 1. Statistics on number of students"<<endl;
	cout<<"\n 2. Statistics on student scores "<<endl;
	cout<<"\n 3. Back" << endl;
	choice1=_getch();
	switch(choice1)
	{
	case '1':
		viewNumber(l);
		Choice();
		break;
	case '2':
		viewScore(l);
		Choice();
		break;
	case '3':
		system("cls");
		Main_menu();
		break;
	default: break;
	}
}

void viewNumber(list &l)
{
	node *p = l.head;
	int line=12;
	int count;
	gotoxy(40,1);cout<<"  STATISTICS ON NUMBER OF STUDENTS  "<<endl;
	gotoxy(40,2);cout<<"____________________________________"<<endl;
	cout<<"\n\n\n\n";
	cout<<"\n";               

	//goc tren trai
	gotoxy(25,9);cout<<char(218);
	//ke ngang
	for(int i=26;i<=66;i++)  
	{
		if (i==46)
			cout<<char(194);//ke tren giua
		else 
			cout<<char(196);
	}
	//goc tren phai
	gotoxy(66,9);cout<<char(191);
	//ke doc dau ben trai
	gotoxy(25,10);cout<<char(179);
	//ke doc giua
	for(int i=46;i<=66;)
	{
		gotoxy(i,10);cout<<char(179);
		i+=20;
	}

	gotoxy(34,10); cout<<"CLASS ";
	gotoxy(55,10);cout<<"SUM ";

	//goc ngoai trai
	gotoxy(25,11);cout<<char(195);
	//ke ngang giua
	for(int i=26;i<=66;i++)  //ke ngang
	{
		if (i==46)
			cout<<char(197);
		else
			cout<<char(196);
	}
	//goc ngoai phai
	gotoxy(66,11);cout<<char(180);

	while(p!=NULL)
	{
		node* temp=l.head; //dung node* temp kiem tra tu dau den vi tri cua p
		while(temp!=p && p!=NULL) //kiem tra den khi temp = p
		{
			if(temp->data.id_class == p->data.id_class) //neu p.class da xuat hien trong khoan tu l.head den p thi tang p len va duyet lai temp. temp=l.head
			{
				p=p->next;
				temp=l.head;
			}
			else temp=temp->next;	//khong thi tang temp len de kiem tra tiep
		}
		// dem so sinh vien trong lop
		count=1;
		if(p!=NULL)
		{
			node *q=p;
			for(q=q->next;q!=NULL;q=q->next)
			{
				if(q->data.id_class == p->data.id_class)
				{
					count++;
				}
			}

			gotoxy(25,line);cout<<char(179);
			for(int i=46;i<=66;)
			{
				gotoxy(i,line);cout<<char(179);
				i+=20;
			}
			gotoxy(34,line); cout<<p->data.id_class;
			gotoxy(55,line);cout<<count;

			//goc ngoai trai
			gotoxy(25,line+1);cout<<char(195);
			//ke ngang giua
			for(int i=26;i<=66;i++)  //ke ngang
			{
				if (i==46)
					cout<<char(197);
				/*else if(i==27||i==45||i==63||i==81||i==99)
				cout<<char(197);*/
				else
					cout<<char(196);
			}
			//goc ngoai phai
			gotoxy(66,line+1);cout<<char(180);
			line+=2;
			p = p->next;
		}
	}
	gotoxy(25,line-1);cout<<char(192);
	for(int i=46;i<=66;)  //ke lai dong cuoi
	{
		gotoxy(i,line-1);cout<<char(193);
		i+=20;
	}
	gotoxy(66,line-1);cout<<char(217);
	//Choice
	cout << "\n\n  Do you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Statistic(l);
		break;
	case 'Y':
		system("cls");
		Statistic(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}
float phanTram(float a,int b)
{
	a=a*100/b;
	//12.345  12.345*100  1234.5 doi sang nguyen 1234 roi chia 100 -> 12.34
	return (float)((int)(a*100))/100;
	//fixed<< setprecision(2)
}

void viewScore(list &l)
{
	gotoxy(40,1);cout<<"   STATISTICS ON STUDENT SCORES  "<<endl;
	gotoxy(40,2);cout<<"__________________________________"<<endl;
	cout<<"\n\n\n\n";
	cout<<"\n";      
	double sc[5];
	double pt[5];
	node *p=l.head;
	int line=12;
	//goc tren trai
	gotoxy(3,9);cout<<char(218);
	for(int i=4;i<=108;i++)  //ke ngang
	{
		if (i==18||i==36||i==54||i==72||i==90)
			cout<<char(194);
		else 
			cout<<char(196);
	}
	//ke tren giua
	gotoxy(108,9);cout<<char(191);
	//goc tren phai
	gotoxy(3,10);cout<<char(179);
	//ke doc giua
	for(int i=18;i<=108;)
	{
		gotoxy(i,10);cout<<char(179);
		i+=18;
	}

	gotoxy(8,10); cout<<"TEN LOP ";
	gotoxy(24,10);cout<<"XUAT SAC";
	gotoxy(44,10);cout<<"GIOI ";
	gotoxy(62,10);cout<<"KHA ";
	gotoxy(77,10);cout<<"TRUNG BINH";
	gotoxy(98,10);cout<<"YEU";

	//goc ngoai trai
	gotoxy(3,11);cout<<char(195);
	//ke ngang giua
	for(int i=4;i<=108;i++)  //ke ngang
	{
		if (i==18||i==36||i==54||i==72||i==90)
			cout<<char(197);
		else if(i==27||i==45||i==63||i==81||i==99)
			cout<<char(194);
		else
			cout<<char(196);
	}
	//goc ngoai phai
	gotoxy(108,11);cout<<char(180);


	while(p!=NULL)
		//for(int i=1;i<=dem;i++)
	{
		int count=1;
		node *temp=l.head;
		while(temp != p && p != NULL)
		{
			if (temp->data.id_class==p->data.id_class)
			{
				p=p->next;
				temp=l.head;
			}
			else
				temp=temp->next;
		}
		node *q=p;
		sc[0]=sc[1]=sc[2]=sc[3]=sc[4]=0;
		if (p!=NULL)
		{
			if(change(p->data.average)>=3.6 && change(p->data.id_class)<=4.0)
				sc[0]++;
			if(change(p->data.average)<3.6 && change(p->data.average)>=3.2)
				sc[1]++;
			if(change(p->data.average)<3.2 && change(p->data.average) >=2.3)
				sc[2]++;
			if(change(p->data.average)<2.3 && change(p->data.average) >=1.5)
				sc[3]++;
			if (change(p->data.average) <1.5)
				sc[4]++;
			for(q=q->next;q!=NULL;q=q->next)
			{
				if(p->data.id_class==q->data.id_class)
				{
					if(change(q->data.average)>=3.6 && change(q->data.id_class)<=4.0)
						sc[0]++;
					else if(change(q->data.average)<3.6 && change(q->data.average)>=3.2)
						sc[1]++;
					else if(change(q->data.average)<3.2 && change(q->data.average) >=2.3)
						sc[2]++;
					else if(change(q->data.average)<2.3 && change(q->data.average) >=1.5)
						sc[3]++;
					else if (change(q->data.average) <1.5)
						sc[4]++;
					count++;
				}
			}

			gotoxy(3,line);cout<<char(179);
			for(int i=18;i<=108;)
			{
				gotoxy(i,line);cout<<char(179);
				i+=9;
			}
			gotoxy(5,line); cout<<p->data.id_class;
			gotoxy(22,line);cout<<sc[0];
			gotoxy(29,line);cout<<phanTram(sc[0],count)<<" %";
			gotoxy(40,line);cout<<sc[1];
			gotoxy(47,line);cout<<phanTram(sc[1],count)<<" %";
			gotoxy(58,line);cout<<sc[2];
			gotoxy(65,line);cout<<phanTram(sc[2],count)<<" %";
			gotoxy(76,line);cout<<sc[3];
			gotoxy(83,line);cout<<phanTram(sc[3],count)<<" %";
			gotoxy(94,line);cout<<sc[4];
			gotoxy(101,line);cout<<phanTram(sc[4],count)<<" %";

			//goc ngoai trai
			gotoxy(3,line+1);cout<<char(195);
			//ke ngang giua
			for(int i=4;i<=108;i++)  //ke ngang
			{
				if (i==18||i==36||i==54||i==72||i==90)
					cout<<char(197);
				else if(i==27||i==45||i==63||i==81||i==99)
					cout<<char(197);
				else
					cout<<char(196);
			}
			//goc ngoai phai
			gotoxy(108,line+1);cout<<char(180);
			line+=2;
			p = p->next;
		}
	}
	gotoxy(3,line-1);cout<<char(192);
	for(int i=18;i<=108;)  //ke lai dong cuoi
	{
		gotoxy(i,line-1);cout<<char(193);
		i+=9;
	}
	gotoxy(108,line-1);cout<<char(217);

	//Choice
	cout << "\n\n  Do you want to back (Y/N)? =>  \a";
	choice2=_getch();
	switch (choice2)
	{
	case 'y':
		system("cls");
		Statistic(l);
		break;
	case 'Y':
		system("cls");
		Statistic(l);
		break;
	case 'n':
		Sleep(1000);
		Choice();
		break;
	case 'N':
		Sleep(1000);
		Choice();
		break;
	default: break;
	}
}

void writeF(list &l)
{
	fstream f;
	f.open("data.txt", ios::out);
	node* temp=l.head;
	int pos=0;
	while(temp!=NULL)
	{
		if(pos!=0)
			f<<endl;
		f << temp->data.id_student << endl;
		f << temp->data.id_class << endl;
		f << temp->data.name << endl;
		f << temp->data.dateOfBirth << endl;
		f << temp->data.average;
		pos++;
		temp=temp->next;
	}
	f.close();
}

void viewDel(list &l)
{
	int n;
	cout<<"  Enter the STT of student: ";
	cin>>n;
	while (n<=0)
	{	
		gotoxy(28,0);cout <<"                                                                     ";
		fflush(stdin);
		gotoxy(28,0);cin>>n;
	}
	delAtPos(l,n-1);
	cout<<"  Deleted!";
	Print(l);
	// ghi ca danh sach
	writeF(l);
}

