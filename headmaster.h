#ifndef HEADMASTER_H
#define HEADMASTER_H

//登录账号
void Login_head(void);

//首次登录修改密码
void Dec_PW_head(void);

//添加教师
void Add_tea(void);

//删除教师
void Delete_tea(void);

//重置密码
void Reset(int);

//显示教师状态
void Show_states_tea(int);

//解锁教师账号
void Unlock_tea(void);

//显示界面
int show_view_head(void);


#endif//HEADMASTER_H
