

typedef struct Headmaster{
	int account;
	int PW;
}Headmaster;

typedef struct Teacher{
	char Name;
	char Sex;
	int WNum;
	int PW;
	char States;
}Teacher;

typedef struct Student{
	char Name;
	char Sex;
	char count=0;
	char exist=0;
	char time=0;
	int SNum;
	int PW;
	int CHN;
	int MAT;
	int ENG;
}Student;

Student stu[300];

int main()
{
	return 0;
}
