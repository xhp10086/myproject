#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#define N 20
#define M 6
int class_num=9;
extern int stu_num;
struct Class
{
	int  number;
	char name[N];
	char attribute[N];
	char credit[N];
	int  time;
	int  total;
	int  limit;
	char stu_list[N][N];
}class[N];
void cla_output();
void cla_update()
{
	int i,j,total;
	FILE *fp;
	fp=fopen("class.txt","w+");
	for(i=0;i<class_num;i++)
	{
		fprintf(fp,"%-7d%-10s%-10s%-7s%-5d%-6d%-6d",class[i].number,
		class[i].name,class[i].attribute,class[i].credit,class[i].time,
		class[i].total,class[i].limit);
		total=class[i].total;
		for(j=0;j<total;j++)
		{
			fprintf(fp,"%-11s",class[i].stu_list[j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return ;	
}
void cla_init()
{
	int i,j,total;
	FILE *fp;
	fp=fopen("class.txt","r+");
	for(i=0;i<class_num;i++)
	{
		fscanf(fp,"%7d%s%s%s%5d%6d%6d",&class[i].number,class[i].name,
			class[i].attribute,class[i].credit,&class[i].time,
				&class[i].total,&class[i].limit);
		total=class[i].total;
		if(total!=0)
		{
			for(j=0;j<total;j++)
			{
				fscanf(fp,"%s",class[i].stu_list[j]);
			}
		}
	}
	cla_output();
	fclose(fp);
	return ;
}
void cla_output()
{
	int i,j,total;
    printf("Total class' information is following\n");
printf("Number Name      Attribute Credit Time Total Limit Stu_list\n");
printf("--------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<class_num;i++)
	{
		printf("%-7d%-10s%-10s%-7s%-5d%-6d%-6d",class[i].number,
		class[i].name,class[i].attribute,class[i].credit,class[i].time,
		class[i].total,class[i].limit);
		total=class[i].total;
		for(j=0;j<total;j++)
		{
			printf("%-11s",class[i].stu_list[j]);
		}
		printf("\n");
	}
	return ;
}
void cla_add_link(struct Class temp)
{
	stu_init();
	int i,j;
	for(i=0;i<temp.total;i++)
	{
		for(j=0;j<stu_num;j++)
		{
			if(strcmp(temp.stu_list[i],stu[j].number)==0)
			{
				stu[j].total+=1;
				stu[j].list[stu[j].total-1]=temp.number;
			}
		}
	}	
	stu_update();
	stu_output();
}
void cla_add()
{
	int j,total;
	struct Class temp;
	class_num++;
	printf("Please input the number of class:\n");
	scanf("%d",&class[class_num-1].number);
	printf("Please input the name of class:\n");
	scanf("%s",class[class_num-1].name);
	printf("Please input the attribute of class:\n");
	scanf("%s",class[class_num-1].attribute);
	printf("Please input the credit of class:\n");
	scanf("%s",class[class_num-1].credit);
	printf("Please input the time of class:\n");
	scanf("%d",&class[class_num-1].time);
	printf("Please input the total people of class:\n");
	scanf("%d",&class[class_num-1].total);
	printf("Please input the limit of class:\n");
	scanf("%d",&class[class_num-1].limit);
	printf("Please input the student list which choose this class:\n");
	total=class[class_num-1].total;
	if(total!=0)
	{
		for(j=0;j<total;j++)
		{
			scanf("%s",class[class_num-1].stu_list[j]);
		}
	}
	cla_output();
	cla_update();
	temp=class[class_num-1];
	cla_add_link(temp);
	return ;
}
void cla_move_link(struct Class temp)
{
	stu_init();
	int tem;
	int i,j,k,m;
	for(i=0;i<temp.total;i++)//temp.total is the number of student who choose this class
	{
		//printf("%d\n",temp.total);
		for(j=0;j<stu_num;j++)//stu_num is the number of student
		{
			if(strcmp(temp.stu_list[i],stu[j].number)==0) //number is true
			{
				for(k=0;k<stu[j].total;k++)//stu[j].total is the number of class student choose it
				{
					if(stu[j].list[k]==temp.number)
					{		
						for(m=k;m<stu[j].total-m;m++)
						{
							stu[j].list[k+1]=stu[j].list[k+1];
						}
						break;
					}
				}
				stu[j].total-=1;
				break;
			}
		}
	}
	stu_update();
	stu_output();
}
void cla_move()
{
	int i,j;
	struct Class temp;
	char name[N];
	printf("Please input the name of class which you want to delete\n");
	scanf("%s",name);
	for(i=0;i<class_num;i++)
	{
		if(strcmp(class[i].name,name)==0)
		{
			temp=class[i];
			if(i==(class_num-1))
			{
				class[i]=temp;
			}
			else
			{
				for(j=i;j<class_num-1;j++)
				{
					class[j]=class[j+1];
				}
			}
			break;
		}
	}	  
	class_num--;
	cla_update();
  	cla_output();
  	cla_move_link(temp);
	return ;
}
void cla_modify_link(struct Class temp,char *sign1,char*sign2)
{
	int i,j,k,res1,res2; 
	stu_init();
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(stu[i].name,sign1)==0)
		{
			for(j=0;j<stu[i].total;j++)
			{
				if(stu[i].list[j]==temp.number)
				{
					res1=j;
					break;
				}
			}
			break;
		}
	}
	if(res1!=stu[i].total-1)
	{
		for(j=res1;j<stu[i].total-1;j++)
		{
			stu[i].list[j+1]=stu[i].list[j+1];
		}
	}
	else 
	stu[i].list[res1]=k;
	printf("hello,world! %d\n",i);
	stu[i-stu_num].total=stu[i-stu_num].total-1;
	for(i=0;i<stu_num;i++)
	{
		if(strcmp(stu[i].name,sign2)==0)
		{	
			res2=i;
			break;
		}
	}
	stu[res2].total+=1;
	stu[res2].list[stu[res2].total-1]=temp.number;
	stu_update();
	stu_output();	
}
void cla_modify()
{
	int  number;
	char name[N];
	char attribute[N];
	char credit[N];
	int  time;
	int  total;
	int  limit;
	int  i,sign,res;
	char new_number[N];char sign1[N];
	char stu_number[N];char sign2[N];
	struct Class temp;
	printf("Please input which class you want to change\n");
	scanf("%s",name);
	for(i=0;i<class_num;i++)
	{
		if(strcmp(class[i].name,name)==0)
		{
			res=i;
			break;
		}
	}
	//printf("%d\n",res);
	printf("Please input the information you want to change\n");
	printf("modify number please input 1:\n");
	printf("modify name please input 2:\n");
	printf("modify attribute please input 3:\n");
	printf("modify credit please input 4:\n");
	printf("modify time please input 5:\n");
	printf("modify total please input 6:\n");
	printf("modify limit please input 7:\n");
	printf("modify stu_list please input 8:\n");
	scanf("%d",&sign);
	switch(sign)
	{
		case 1: 
				printf("Please input new number:\n");
				scanf("%d",&number);
				class[i].number=number;
				break;
		case 2: 
				printf("Please input new name:\n");
				scanf("%s",name);
				strcpy(class[i].name,name);
				break;
		case 3:
				printf("Please input new attribute:\n");
				scanf("%s",attribute);
				strcpy(class[i].attribute,attribute);
				break;
		case 4: 
	            		printf("Please input new credit:\n");
			    	scanf("%s",credit);
			    	strcpy(class[i].credit,credit);
			    	break;
		case 5: 
	            		printf("Please input new time:\n");
			    	scanf("%d",&time);
			    	class[i].time=time;
			    	break;
		case 6:		
				printf("Please input new total:\n");
				scanf("%d",&total);
				class[i].total=total;
				break;
		case 7:		
				printf("Please input new limit:\n");
				scanf("%d",&limit);
				class[i].limit=limit;
				break;
		default:
				cla_output();
		printf("Please input which student number you want to change\n");
				scanf("%s",stu_number);
				strcpy(sign1,stu_number);
				for(i=0;i<class[i].total;i++)
				{
					if(strcmp(class[res].stu_list[i],stu_number)==0)
					{
						temp=class[res];
						printf("Find the student!\n");
						printf("Please input the new stu_number:\n");
						scanf("%s",new_number);
						strcpy(sign2,new_number);
						strcpy(class[res].stu_list[i],new_number);
					}
				}
				if(i>class[i].total)
				{
			printf("Input stu_number error,Dont't have this student\n");
				}
	}
	cla_update();
	cla_output();
	cla_modify_link(temp,sign1,sign2);
	return ;
}
void cla_search()
{
	int i,j,total;
	int res=-1;
	char name[N];
	printf("Please input the which class you want to look up\n");
	scanf("%s",name);
	for(i=0;i<class_num;i++)
	{
		if(strcmp(class[i].name,name)==0)
		{
			res=i;
			break;
		}
	}
	printf("The information of class you want to look up is following\n");
	printf("Number Name      Attribute Credit Time Total Limit Stu_list\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	if(res!=-1)
	{
		printf("%-7d%-10s%-10s%-7s%-5d%-6d%-6d",class[res].number,
				class[res].name,class[res].attribute,class[res].credit,class[res].time,
				class[res].total,class[res].limit);
		total=class[res].total;
    	for(j=0;j<total;j++)
		{
			printf("%-11s",class[res].stu_list[j]);
		}
		printf("\n");
	}
	else
	{
		printf("Don't have this class!\n");
	}
}


