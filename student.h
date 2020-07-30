#ifndef STUDENT_H
#define STUDENT_H

//学生界面菜单
static void student_menu(void);

//登录账号
int Login_stu(void);

//首次登录修改密码
//void Dec_PW_stu(void);

//查询成绩
void Query(void);

//修改密码
void Alter_PW_stu(void);

//查看个人信息
void Info(void);

//学生开始界面
void Start_stu(void);
#endif//STUDENT_H
