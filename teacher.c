#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getch.h>
#include "teacher.h"
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


void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("任意键继续...");
	getch();
}

void show_msg(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}



void add_stu(void)
{	
	if(count_stu > STU_MAX)
	{
		show_msg("系统正在升级，请稍候!\n",3);
		return;
	}

	int i = 0;
	while(stu[i].Sex) i++;

	printf("请输入姓名 性别:");
	scanf("%s %c",stu[i].Name,&stu[i].Sex);
	stu[i].SNum=STU_INT_ID + count_stu;
	strcpy(stu[i].PW,"111");
	stu[i].exist=1;
	stu[i].time=0;

	count_stu++;

	show_msg("添加学生成功!\n",3);

	anykey_continue();
}

void del_stu(void)
{
	int key1=0,key2=0;
	printf("请输入要删除的学生学号:");
	scanf("%d",&key1);
	printf("再次输入确定要删除的学生学号：");
	scanf("%d",&key2);
	for(int i=0; i<STU_MAX; i++)
	{
		if(key1 == stu[i].SNum && key2 == stu[i].SNum)
		{
			stu[i].exist = 2;
			show_msg("删除学生成功！\n",3);
			return;
		}
	}

	show_msg("学生不存在，请检查输入的学生学号\n",3);
}

void find_name(void)
{
	char key[20] = {};
	printf("请输入要查询的姓名：");
	gets(key);

	for(int i=0; i<STU_MAX; i++)
	{
		if(stu[i].exist && strstr(stu[i].Name,key))
		{
			printf("%s %s %d %s\n",stu[i].Name,'w'==stu[i].Sex?"女":"男",stu[i].SNum,1==stu[i].exist?"在校":"离校");
			anykey_continue();
			return;
		
		}
	}
	show_msg("学生不存在，请检查输入的学生姓名\n",3);
	
}

void find_id(void)
{
	int key = 0;
	printf("请输入要查询的学号：");
	scanf("%d",&key);

	for(int i=0; i<STU_MAX; i++)
	{
		if(stu[i].exist && stu[i].SNum == key)
		{
			printf("%s %s %d %s\n",stu[i].Name,'w'==stu[i].Sex?"女":"男",stu[i].SNum,1==stu[i].exist?"在校":"离校");
			anykey_continue();
			return;
		
		}
	}
	show_msg("学生不存在，请检查输入的学生学号\n",3);
}

void find_stu(void)
{
	system("clear");
	puts("***请选择查找方法***");
	puts("1、姓名查找");
	puts("2、学号查找");
	puts("3、退出查找");
	puts("-------------------");
	printf("请选择方法:");
	char cmd = getch();
	printf("%c\n",cmd);

	switch(cmd)
	{
		case '1': find_name(); break;
		case '2': find_id(); break;
		case '3': return;
	}
	
}

void change_ifo(int i)
{
	printf("请输入姓名 性别:");
	scanf("%s %c",stu[i].Name,&stu[i].Sex);
	show_msg("修改成功\n",3);
}
void change_ach(int i)
{
	printf("请输入语文成绩：");
	scanf("%d",&stu[i].CHN);
	printf("请输入数学成绩：");
	scanf("%d",&stu[i].MAT);
	printf("请输入英语成绩：");
	scanf("%d",&stu[i].ENG);
	show_msg("修改成功\n",3);
}

void change_stu(void)
{
	int key = 0;
	printf("请输入要修改信息的学生学号：");
	scanf("%d",&key);

	for(int i=0; i<STU_MAX; i++)
	{
		if(stu[i].SNum == key)
		{
			for(;;)
			{
				system("clear");
				printf("已查询到该学生信息为：姓名 %s   性别 %s   学号 %d   语文 %d   数学 %d   英语 %d\n",stu[i].Name,'w'==stu[i].Sex?"女":"男",stu[i].SNum,stu[i].CHN,stu[i].MAT,stu[i].ENG);
				puts("***请选择要修改的信息***");
				puts("1、学生基础信息");
				puts("2、学生成绩");
				puts("3、退出修改");
				puts("-------------------");
				printf("请选择:");
				char cmm = getch();
				printf("%c\n",cmm);

				switch(cmm)
				{
					case '1': change_ifo(i); break;
					case '2': change_ach(i); break;	
					case '3': return;
				}
			}
		}
	}

	

	
	show_msg("学生不存在，请检查输入的学生学号\n",3);
}
void reset_stu(void)
{
	int key = 0;
	printf("请输入需要重置密码的学生学号：");
	scanf("%d",&key);

	for(int i=0; i<STU_MAX; i++)
	{
		if(stu[i].SNum == key)
		{
			stu[i].time=0;
		}
	}
}
void input_stu(void)
{
	int key = 0;
	printf("请输入要录入成绩的学生的学号：");
	scanf("%d",&key);

	for(int i=0; i<STU_MAX; i++)
	{
		if(stu[i].exist && stu[i].SNum == key)
		{
			printf("请输入语文成绩：");
			scanf("%d",&stu[i].CHN);
			printf("请输入数学成绩：");
			scanf("%d",&stu[i].MAT);
			printf("请输入英语成绩：");
			scanf("%d",&stu[i].ENG);
			anykey_continue();
			return;
		
		}
	}
	show_msg("学生不存在，请检查输入的学生学号\n",3);
}

void show_stu_in(void)
{
	printf("姓名   学号   性别   语文   数学   英语   密码\n");
	for(int i=0;i<STU_MAX;i++)
	{
		if(1==stu[i].exist)
		{
			printf("%s %d %-5s %-5d %-5d %-5d %s\n",stu[i].Name,stu[i].SNum,'w'==stu[i].Sex?"女":"男",stu[i].CHN,stu[i].MAT,stu[i].ENG,stu[i].PW);
		}
	}
	anykey_continue();
}

void show_stu_out(void)
{
	printf("姓名   学号   性别   语文   数学   英语   密码\n");
	for(int i=0;i<STU_MAX;i++)
	{
		if(2==stu[i].exist)
		{
			printf("%s %d %-5s %-5d %-5d %-5d %s\n",stu[i].Name,stu[i].SNum,'w'==stu[i].Sex?"女":"男",stu[i].CHN,stu[i].MAT,stu[i].ENG,stu[i].PW);
		}
	}
	anykey_continue();
}



void save()
{
	printf("进入了\n");
            FILE* frp = fopen("test.txt","w");
            if(NULL == frp)
            {
                perror("fopen");
                return;
            }
            for(int i=0;i<count_stu;i++)
            {
                fwrite(&stu[i],sizeof(Student),1,frp);
            }
            anykey_continue();
			fclose(frp);
}
void load()
{
    FILE* fwp = fopen("test.txt","r");
    if(NULL==fwp)
    {
        perror("fopen");
        return;
    }
    for(int i=0;i<100;i++)
    {
        if(fread(&stu[i],sizeof(struct Student),1,fwp))
		{count_stu++;}
	}
    fclose(fwp);
}

char menu(void)
{
	system("clear");
	puts("***欢迎进入教师子系统***");
	puts("1、添加学生");
	puts("2、删除学生");
	puts("3、查询学生信息");
	puts("4、修改学生信息");
	puts("5、重置学生密码");
	puts("6、录入学生成绩");
	puts("7、显示所有在校学生信息");
	puts("8、显示所有离校学生信息");
	puts("9、退出通讯录");
	puts("-------------------");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}

void tch_start(void)
{	
	load();
	for(;;)
	{
		switch(menu())
		{
			case '1': add_stu(); break;
			case '2': del_stu(); break;
			case '3': find_stu(); break;
			case '4': change_stu(); break;
			case '5': reset_stu(); break;
			case '6': input_stu(); break;
			case '7': show_stu_in(); break;
			case '8': show_stu_out(); break;
			case '9': return;
			case 's': save(); break;
		}
	}
}

int main() //我自己测试用了int main 整合时候修改
{
	char login_pw[10];
	int login_id=0;
	printf("请输入工号：");
	scanf("%d",&login_id);
	printf("请输入密码：");
	scanf("%s",login_pw);
	
	for(int i = 0; i<TCH_MAX;i++)
	{
		if(login_id == Tec[i].WNum)
		{
			if(3==Tec[i].time)
			{
				show_msg("此帐号已锁定，返回登陆界面。\n",3);
			}
			
			if(2==Tec[i].States)
			{
				show_msg("该教师已离职，返回登陆界面。\n",3);
			}
			
			if(strcmp(login_pw,Tec[i].PW))
			{
				Tec[i].time++;
				show_msg("密码输入错误，返回登陆界面。\n",3);
			}

			
		}
	}
	

	tch_start();
	
	show_msg("没有此帐号，返回登陆界面。\n",3);
	return 0; //试用，转入正是程序内 去掉0.

}
