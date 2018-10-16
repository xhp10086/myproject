#include<stdio.h>
#include<student.h>
#include<class.h>
int main()
{
	int sign=1,func;
	printf("----------Welcome to the course selection system!----------\n");
	printf("\n");
	printf("---[1]:Enter Student information management system\n");
	printf("---[2]:Enter Course selection information management system\n");
	printf("---[3]:Sign out system\n");
	while(sign)
	{
		printf("Please input which system you want to enter\n");	
		scanf("%d",&func);
		if(func==1)
		{
			stu_init();
			int sign_stu=1;
			int number;
			while(1)
			{
				printf("Now you have four functions to choose:\n");
   				printf("----------------------------------------------------------\n");
   				printf("******** First:  add one student's information    ********\n");
   				printf("******** Second: move one student's information   ********\n");
  			 	printf("******** Third:  modify one student's information ********\n");
  			 	printf("******** Four:   search one student's information ********\n");
   		 		printf("******** Five:   exit this work                   ********\n");
   				printf("----------------------------------------------------------\n");
   				printf("Please input number decide which function you to choose\n");
   				scanf("%d",&number);
   				switch(number)
   				{
					case 1:stu_add();break;
					case 2:stu_move();break;
					case 3:stu_modify();break;
					case 4:stu_search();break;
					case 5:sign_stu=0;break;
					default:printf("Input error!\n");
					printf("Please input number again\n");
					printf("\n");
   				}
   				if(sign_stu==0) break;
			}
		}
		else if(func==2)
		{
			cla_init();
			int sign_class=1;
			int num;
			while(1)
			{
				printf("Now you have four functions to choose:\n");
  			 	printf("----------------------------------------------------------\n");
   				printf("******** First:  add one class's information      ********\n");
  			 	printf("******** Second: move one class's information     ********\n");
  			 	printf("******** Third:  modify one class's information   ********\n");
  			 	printf("******** Four:   search one class's information   ********\n");
  			 	printf("******** Five:   exit this work                   ********\n");
   				printf("----------------------------------------------------------\n");
   				printf("Please input number decide which function you to choose\n");
   				scanf("%d",&num);
   				switch(num)
   				{
					case 1:cla_add();break;
					case 2:cla_move();break;
					case 3:cla_modify();break;
					case 4:cla_search();break;
					case 5:sign_class=0;break;
					default:printf("Input error!\n");
					printf("Please input number again\n");
					printf("\n");
   				}		
   				if(sign_class==0) break;
			}
		}
		else if(func==3)
		{
			printf("Sign out successed!\n");
			sign=0;
		}
		else
		{
			printf("input error,please input again!\n");
			printf("\n");
		}
	}
}

