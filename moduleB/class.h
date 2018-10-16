#ifndef _CLASS_H
#define _CLASS_H
struct Class
{
	int  number;
	char name[20];
	char attribute[20];
	char credit[20];
	int  time;
	int  total;
	int  limit;
	char stu_list[20][20];
}class[20];
void cla_update();
void cla_init();
void cla_add();
void cla_move();
void cla_modify();
void cla_search();
void cla_output();
#endif
