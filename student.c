#include <string.h>
#include "student.h"
#include <getch.h>

int Rank;
float AVG;
int SUM;
float Score_max;
float Score_min;
int cnt = 0;

//学生界面
static void student_menu(void)
{
	printf("进入学生子系统……\n");
	printf("1.查询成绩\n");
	printf("2.修改密码\n");
	printf("3.查看个人信息\n");
	printf("4.返回上一级\n");
	printf("————————————————");
}

//登录账号
int Login_stu(void)
{
	//文件中查找是否有匹配的学号
	char stu_num[20]={};
	char stu_pw[20]={};
	printf("请输入学号：\n");
	fgets(stu_num,20,stdin);
	if(stu_num[0] == '\0')
	{
		printf("学号不能为空！\n");
		return -1;
	}
 	printf("请输入密码：");
	fgets(stu_pw,20,stdin);
	printf("\n");
	for(int i=0;i<300;i++)
	{
		if(strcmp(stu_num,stu[i].SNum)==0)
		{
			if(stu[i].time==3)
			{
				printf("此学号已被锁定，请找教师解锁。\n");
				return -1;
			}
			if(stu[i].exist==1)
			{
				printf("此学生已退学。\n");
				return -1;
			}
			if(strcmp(stu_pw,stu[i].PW)==0)
			{
				return i;//?
			}
			else
			{
				stu[i].time++;
				printf("密码错误\n");
				return -1;
			}
		}
	}
	printf("不存在此学生\n");
	return -1;
}

//首次登录修改密码
/*void Dec_PW_stu(void)
{
	与修改密码合并，加一个状态判断是不是首次登陆
}*/

//查询成绩
void Query(void)
{
	printf("成绩查询\n");
	printf("语文：%d，数学：%d，英语%d：\n",stu[cnt].CHN,stu[cnt].MAT,stu[cnt].ENG);//cnt??
	SUM=stu[cnt].CHN+stu[cnt].MAT+stu[cnt].ENG;
	AVG=SUM/3;
	Score_max=(stu[cnt].CHN>stu[cnt].MAT?stu[cnt].CHN:stu[cnt].MAT)>stu[cnt].ENG?(stu[cnt].CHN>stu[cnt].MAT?stu[cnt].CHN:stu[cnt].MAT):stu[cnt].ENG;
	Sorce_min=(stu[cnt].CHN<stu[cnt].MAT?stu[cnt].CHN:stu[cnt].MAT)<stu[cnt].ENG?(stu[cnt].CHN<stu[cnt].MAT?stu[cnt].CHN:stu[cnt].MAT):stu[cnt].ENG;
	printf("平均分：%hd,最高分：%hd，最低分：%hd\n",AVG,Score_max,Score_min);
}

//修改密码
void Alter_PW_stu(void)
{
	char old_stu_pw[20]={};
	char new_stu_pw[20]={};
	char new_stu_pw2[20]={};
	printf("请输入原密码：");
	fgets(old_stu_pw,20,stdin);
	printf("\n");
	printf("请输入新密码：");
	fgets(new_stu_pw,20,stdin);
	printf("\n");
	printf("请再次输入新密码：");
	fgets(new_stu_pw2,20,stdin);
	printf("\n");
	if(strcmp(old_stu_pw,stu[cnt].PW)==0)
	{
		if(strcmp(new_stu_pw,new_stu_pw2)==0)
		{
			printf("修改密码成功\n");
			if(stu[cnt].count==0)
			{
				stu[cnt].count=1;
			}
			strcpy(stu[cnt].PW,new_stu_pw);
		}
		else
		{
			printf("两次密码不一致\n");
		}
	}
	else
	{
		printf("原密码错误\n");
	}
}

//查看个人信息
void Info(void)
{
	printf("个人信息\n");
	printf("姓名：%c，性别：%c，学号：%d\n",stu[cnt].Name,stu[cnt].Sex,stu[cnt].Snum);
}

//学生开始界面
void Start_stu(void)
{
	cnt = Login_stu();
	if(-1 == temp)
	{
		printf("登录失败！\n");
		return;
	}
	while(true)
	{
		if(stu[cnt].num==0)
		{Alter_PW_stu();}
		else
		{
			student_menu();
			switch(getch())
			{
				case '1':Query();break;
				case '2':Alter_PW_stu();break;
				case '3':Info();break;
				case '4':return;
			}
		}
	}
}
