#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"class.h"
#define N 20
#define M 10
int stu_num=4;
extern int class_num;
struct student
{
	char number[N];
	char name[N];
	char credit[N];
	int  total;
	int  list[N];	
}stu[M];
void stu_update();
void stu_output();
void stu_init()
{
	int i,j;
	FILE *fp;
	fp=fopen("student.txt","r+");
	for(i=0;i<stu_num;i++)
	{
	fscanf(fp,"%s%s%s%2d",stu[i].number,stu[i].name,stu[i].credit,&stu[i].total);
		for(j=0;j<stu[i].total;j++)
		{
			fscanf(fp,"%2d",&stu[i].list[j]);
		}
	}
	fclose(fp);
	return ;
}
void stu_add_link(struct student temp)
{
	cla_init();
	int i,j;
	for(i=0;i<temp.total;i++)
	{
		for(j=0;j<class_num;j++)
		{
			if(temp.list[i]==class[j].number)
			{
				class[j].total+=1;
		strcpy(class[j].stu_list[class[j].total-1],temp.number);
			}
		}
	}	
	cla_update();
	cla_output();
}
void stu_add()
{
	int i=0,j;
	stu_num+=1;
	printf("Please input the number of student:\n");
	scanf("%s",stu[stu_num-1].number);
	printf("Please input the name of student:\n");
	scanf("%s",stu[stu_num-1].name);
	printf("Please input the credit of student:\n");
	scanf("%s",stu[stu_num-1].credit);
	printf("Please input the total class student choose:\n");
	scanf("%d",&stu[stu_num-1].total);
 	printf("Please input the list of class of student:\n");
	for(i=0;i<stu[i].total;i++)
	{
		scanf("%d",&stu[stu_num-1].list[i]);
	}
	stu_update();
	stu_output();
	struct student temp=stu[stu_num-1];
	stu_add_link(temp);
	return ;
}
void stu_move_link(struct student tmp)
{
	char str[20];
	cla_init();
	int i,j,k,m,n;
	for(i=0;i<tmp.total;i++)
	{
		for(j=0;j<class_num;j++)
		{
			if(tmp.list[i]==class[j].number)
			{
				for(k=0;k<class[j].total;k++)
				{
					if(strcmp(class[j].stu_list[k],tmp.number)==0)
					{
						n=k;	
						strcpy(class[j].stu_list[k],str);
					}
				}
				//class[j].total-=1;
				if(n!=class[j].total-1)
				{
					for(m=n;m<class[j].total-1;m++)
					{
						strcpy(class[j].stu_list[m],class[j].stu_list[m+1]);
					}
				}
				class[j].total-=1;				
			}
		}
	}
	cla_update();
	cla_output();
}
void stu_move()
{
  int i,j;
  struct student tmp;
  struct student temp;
  char number[N];
  printf("Please input the number of student which you want to delete\n");
  scanf("%s",number);
  for(i=0;i<stu_num;i++)
  {
      if(strcmp(stu[i].number,number)==0)
	  {
		tmp=stu[i];
	  	if(i==(stu_num-1))
		{
			stu[i]=temp;
		}
		else
		{
			for(j=i;j<stu_num-1;j++)
			{
				stu[j]=stu[j+1];
			}
		}
	  }
  }
  stu_num--;
  stu_update();
  stu_output();
  stu_move_link(tmp);
  return ;
}
void stu_modify_link(struct student temp,int sign1,int sign2)
{
	int i,j,k;
	char str[20];
	cla_init();
	for(i=0;i<class[sign1-1].total;i++)
	{
		if(strcmp(class[sign1-1].stu_list[i],temp.number)==0)
		{	
			j=i;	
			strcpy(class[sign1-1].stu_list[i],str);
		}
	}
	if(j!=class[sign1-1].total-1)
	{
		for(k=j;k<class[sign1-1].total-1;k++)
		{
			strcpy(class[sign1-1].stu_list[k],class[sign1-1].stu_list[k+1]);
		}
	}
	class[sign1-1].total-=1;	
	class[sign2-1].total+=1;
	strcpy(class[sign2-1].stu_list[class[sign2-1].total-1],temp.number);
	cla_update();
	cla_output();
}
void stu_modify()
{
	int i,sign,res;
	char number[N];
	char number1[N];
	char name[N];
	char credit[N];
	int  total;
	int  class_number;
	int  new_name;
	struct student temp;
	int  sign1,sign2;
	printf("Please input which student you want to change\n");
	scanf("%s",number);
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(stu[i].number,number)==0)
		{
			res=i;
			break;
		}
	}
	temp=stu[res];
	printf("Please input the information you want to change\n");
	printf("modify number please input 1:\n");
	printf("modify name please input 2:\n");
	printf("modify credit please input 3:\n");
	printf("modify total please input 4:\n");
	printf("modify list please input 5:\n");
	scanf("%d",&sign);
	switch(sign)
	{
		case 1: 
				printf("Please input new number:\n");
				scanf("%s",number1);
				strcpy(stu[i].number,number1);
				break;
		case 2: 
				printf("Please input new name:\n");
				scanf("%s",name);
				strcpy(stu[i].name,name);
				break;
		case 3: 
	            		printf("Please input new credit:\n");
			    	scanf("%s",credit);
			    	strcpy(stu[i].credit,credit);
			    	break;
		case 4:		printf("Please input new total:\n");
				scanf("%d",&total);
				stu[i].total=total;
				break;
		default:
		printf("Please input which class number you want to change\n");
				printf("01 represent yuwen:\n");
				printf("02 represent shuxue:\n");
				printf("03 represent yingyu:\n");
				printf("04 represent wuli:\n");
				printf("05 represent huaxue:\n");
				printf("06 represent shengxu:\n");
				printf("07 represent zhengzhi:\n");
				printf("08 represent lishi:\n");
				printf("09 represent dili:\n");
				scanf("%d",&class_number);
				sign1=class_number;
				for(i=0;i<stu[i].total;i++)
				{
					if(stu[res].list[i]==class_number)
					{
						printf("Find the class number!\n");
						printf("Please input the new class number:\n");
						scanf("%d",&new_name);
						sign2=new_name;
						stu[res].list[i]=new_name;
					}
				}
				if(i>stu[i].total)
				{
			printf("Input class_number error,Dont't have this class\n");
				}
	}
	stu_update();
	stu_output();
	stu_modify_link(temp,sign1,sign2);
	return ;
}
void stu_search()
{
	int i,j;
	int res=-1;
	char number[N];
	printf("Please input the which student you want to look up\n");
	scanf("%s",number);
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(stu[i].number,number)==0)
		{
			res=i;
			break;
		}
	}
if(res!=-1)
{
  printf("The information of student you want to look up is following\n");
  printf("Number      Name            Credit  Total Class_list            \n");
  printf("----------------------------------------------------------------\n");
 printf("%-11s%-15s%-7s%-6d",stu[res].number,stu[res].name,
	stu[res].credit,stu[res].total);
	for(j=0;j<stu[res].total;j++)
	{
		printf("%2d",stu[res].list[j]);
	}
	printf("\n");
	printf("\n");
}
else
printf("Dont't have this student!\n"); 
}
void stu_output()
{
   int i,j;
   printf("Total students' information is following\n");
   printf("Number      Name            Credit  Total Class_list            \n");
   printf("----------------------------------------------------------\n");
   for(i=0;i<stu_num;i++)
   {
printf("%-11s %-15s %-7s %-6d",stu[i].number,stu[i].name,stu[i].credit,stu[i].total);
		for(j=0;j<stu[i].total;j++)
		{
			printf("%2d",stu[i].list[j]);
		}
		printf("\n");
	}
}
void stu_update()
{
	int i,j;
	FILE *fp;
	fp=fopen("student.txt","w+");
	for(i=0;i<stu_num;i++)
	{
fprintf(fp,"%-11s%-13s%-5s%-6d",stu[i].number,stu[i].name,stu[i].credit,stu[i].total);
		for(j=0;j<stu[i].total;j++)
		{
			 fprintf(fp,"%-2d",stu[i].list[j]);
		}
//		printf("\n");
		fprintf(fp,"\n");
	}
	fclose(fp);
	return ;
}
