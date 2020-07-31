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

// 功能函数，任意键返回
void anykey_continue(void);

// 功能函数，显示msg信息sec秒后自动返回
void show_msg(const char* msg,float sec);

// 添加学生
void add_stu(void);

// 删除学生
void del_stu(void);

// 按姓名查找学生并显示个人信息
void find_name(void);

// 按学号查找学生并显示个人信息
void find_id(void);

// 查找学生
void find_stu(void);

// 更改学生基础信息
void change_ifo(int i);

// 更改学生成绩
void change_ach(int i);

// 查找学生更改信息
void change_stu(void);

// 重置学生密码
void reset_stu(void);

// 导入学生成绩
void input_stu(void);

// 显示全部在校学生信息
void show_stu_in(void);

// 显示全部离校学生信息
void show_stu_out(void);

// 存储学生信息到文本文件
void save();

// 从文本文件中导出数据到内存
void load();

// 老师子系统菜单
char menu(void);

// 进入系统
void tch_start(void);

//此处.C中有个int main函数
#endif//CONTACT_H
