#include<stdlib.h>
#include<stdio.h>
#include "headmaster.h"
#include<getch.h>


//登录账号
int PW=888888;

void Login_head(void)
{
	char* str;
	int num=0;
	printf("请输入用户名");
	gets(str);
	printf("请输入管理员密码");
	scanf("%d",&num);
	if(num == PW && PW == 888888)
	{
		 Dec_PW_head();
	}
	
	if(num==PW && PW != 888888)
	{
		 show_view_head();
	}

	
}

//显示界面
int show_view_head(void)
{
	system("clear");
	puts("1、重置管理员密码");
	puts("2、重置教师密码");
	puts("3、添加教师");
	puts("4、删除教师");
	puts("5、显示所有在职教师");
	puts("6、显示所有离职教师");
	puts("7、退出学生成绩管理系统");
	printf("请输入指令:");
	char cmd=getch();
    switch(cmd)
	{
		case '1':Reset(1)   ;break;//重置管理员密码
		case '2':Reset(0)   ;break;//重置教师密码
		case '3':Add_tea()   ;break;
		case '4':Delete_tea()   ;break;
		case '5':Show_states_tea(1)   ;break;//显示在职教师
		case '6':Show_states_tea(0)   ;break;//显示离职教师
		case '7': return 0;
	}
}


//首次登录修改密码
	void Dec_PW_head(void)
	{
		int newnum=0;
		printf("请输入新密码");
		scanf("%d",&newnum);
		PW=newnum;
		Login_head();
	}

//添加教师
void Add_tea(void)
{
       
	int i=0;
	while(Tec.Sex[i]) i++;
	printf("请输入姓名 性别 工号");
	scanf("%s %c %s",&Tec[i].name,&Tec[i].sex,&Tec[i].WNum);
	printf("添加教师成功");
}	

//删除教师
void Delete_tea(void)
{
	int i=0;
	char key[20] = {};
	printf("请输入要删除的教师姓名");
	scanf("%s",key);
	
	{
		if(0 == strcmp(key,Tec[i].Name))
			{
				printf("删除教师成功");
				Tec[i].sex = 0;
				Tec[i].Stats=0;
			}
	}

}

//重置密码
void Reset(int s)
{
	int num=s;
	if(1==num)
	{
		PW=888888;
		printf("重置管理员密码成功！");
	}
	if(0 == num)
	{
	printf("请输入教师工号：");
	char* Cteacher_id[20]={};
	gets(Cteacher_id[20]);
	char Cteacher_pw[20] = "888888";
	int i=0;
	while(Tec[i].Sex)
	{
		if(strcmp(Tec[i].Name,Cteacher_id)==0)
		{
			strcpy(Tec[i].PW,Cteacher_pw); 
			printf("重置成功！\n");
			break;
			}
			i++;
			}
		
	}
}

//显示教师状态
void Show_states_tea(int s)
{
	int num=s;
	if(1==num)//显示在职教师
	{
		int i=0;
		while(Tec.Stats)
		{
			printf("%s %c %s",Tec[i].Name,Tec[i].sex,Tec[i].WNum);
			i++;
	}
	}
	if(0==num)//显示离职教师
	{
		int i=0;
		while(0==Tec.states)
		{
			printf("%s %c %d",Tec[i].Name,Tec[i].sex,Tec[i].WNum);
			i++;
		}
	}
}


