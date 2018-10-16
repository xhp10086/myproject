#ifndef _STUDENT_H
#define _STUDENT_H
struct student
{
	char number[20];
	char name[20];
	char credit[20];
	int  total;
	int  list[20];	
}stu[20];
void stu_add_link(struct student temp);
void stu_update();
void stu_init();
void stu_add();
void stu_move();
void stu_modify();
void stu_search();
void stu_output();
#endif
