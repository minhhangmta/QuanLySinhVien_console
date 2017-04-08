#include"iostream"
#include"conio.h"
#include"windows.h"
#include"string"
#include"iomanip"
#include"fstream"
using namespace std;


char choice, choice1, choice2;
struct student
{
	int stt;
	string name;
	string id_class;
	string id_student;
	string dateOfBirth;
	string average;
};

struct Birthday
{
	int dd;
	int mm;
	int yy;
};

struct node
{
	student data;
	node *next;
};

struct list
{
	node *head;
	node *tail;
};

node *Creat_node(student st)
{
	node *p = new node;
	p->data = st;
	p->next = NULL;
	return p;
}

void Init(list &l)
{
	l.head = l.tail = NULL;
}
/*
void delLast(list &l) {
node *p, *q;
p = q = l.head;
while (q != l.tail) {
p = q;
q = q->next;
}
p->next = NULL;
delete q;
}*/

void delAtPos(list &l, int n)
{
	node  *temp1=l.head;
	if(n==0)
	{
		l.head = temp1->next;
		free(temp1);
		return;
	}
	else
	{
	int pos=0;
	node* temp2=l.head;
	while(temp1->next!=NULL && pos<=n)
	{
		temp2=temp1;
		temp1=temp1->next;
		pos++;
	}
	temp2->next=temp1->next;
	delete temp1;
	}
}


void Insert_at_last(list &l, node *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void Choice();
void gotoxy(int x, int y);

void WriteFile(student st);
void ReadFile(list &l);
void Display(list &l);

void Print(list &l);
void Insert(list &l);

void viewDel(list &l);

string deleteSpaceAtFirst(string str);
string deleteSpaceAtLast(string str);
string deleteSpaceBetween(string str);
string standardizedName(string str);
string standardizedDOB(string str);
string upperCase(string s);
double change(string x);
void Swap(student &a, student &b);
int checkDOB(Birthday bd1, Birthday bd2);
void SwapArray(student st1[100],student st2[100]);
Birthday splitDOB(string str);

void Select_sort(list &l);
void SS_Name(list &l);
void SS_DOB(list &l);
void SS_StudentID(list &l);
void SS_ClassID(list &l);
void SS_Average(list &l);


void Insert_sort(list &l);
void IS_Name(list &l);
void IS_DOB(list &l);
void IS_StudentID(list &l);
void IS_Average(list &l);
void IS_ClassID(list &l);

void Quick_sort(list &l);
void QS_Name(list &l);
void QS_DOB(list &l);
void QS_StudentID(list &l);
void QS_ClassID(list &l);
void QS_Average(list &l);
void QSbyAverage(student st[] , int l , int r);

void Linear_search(list &l);
void Binary_search(list &l);
void Search(list &l);

void Arrange(list &l);
void Statistic(list &l);

void viewScore(list &l);
void viewNumber(list &l);

void Main_menu();
void Start();