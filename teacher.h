#ifndef CONTACT_H
#define CONTACT_H

#define STU_MAX 300
#define TCH_MAX 50
#define STU_INT_ID 20200701

typedef struct Teacher{
	char Name[20];
	char Sex;
	int WNum;
	char PW[10];
	char States;
	char time;
}Teacher;

typedef struct Student
{
	char Name[20];		
	char Sex;
	int SNum;
	int CHN;
	int MAT;
	int ENG;		
	char PW[10];
	char time;
	char exist;
}Student;


Teacher Tec[TCH_MAX]={"haha",'w',1001,"666",1,0}; //测试使用的初始化数据
Student stu[STU_MAX];

int count_stu = 0;

void anykey_continue(void);

void show_msg(const char* msg,float sec);

void add_stu(void);

void del_stu(void);

void find_name(void);

void find_id(void);

void find_stu(void);

void change_ifo(int i);

void change_ach(int i);

void change_stu(void);

void reset_stu(void);

void input_stu(void);

void show_stu_in(void);

void show_stu_out(void);

void save();

void load();

char menu(void);

void tch_start(void);

//此处.C中有个int main函数
#endif//CONTACT_H
