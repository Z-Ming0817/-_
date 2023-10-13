
#include <stdio.h>
#include <stdlib.h>
int correct_input(int change);
int judge(int year, int month, int n);
void the_date();
void menu();
void menu2();

int main()
{
	int change = 0;
	int change2 = 0;
	do
	{
	end:	
		menu();
		printf("Please choose:");
//		scanf("%d",&change);
		
		change=correct_input(change);
		switch (change)
		{
		case 1:
			do
			{
				menu2();
				printf("Please choose:");
//				scanf("%d",&change2);
                 change2=correct_input(change2);	
				system("cls");
				switch (change2)
				{	
				case 1:
					the_date();
					break;
				case 2:
					goto end;
					break;
				default:
					printf("Please input again\n");
				}
				
			} while (change2);
			
			break;
		case 2:
			printf("Exit.\n");
			exit (0);
		default:
			printf("Please input again:\n");
		}
		system("cls");
	}while(change2);
	
	return 0;
}

void menu()//菜单一
{
	printf("-----------------------------\n");
	printf("********** 1.Apply **********\n");
	printf("********** 2.Exit  **********\n");
	printf("-----------------------------\n");
}

void menu2()//菜单二
{
	printf("------------------------------\n");
	printf("******** 1.Check date ********\n");
	printf("********** 2.Return  **********\n");
	printf("------------------------------\n");
}

void the_date()//日历
{
	int day = 0;
	int year = 0;
	int month = 0;
	int  ord_year_month[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leap_year_month[13] = { 0, 31,29,31,30,31,30,31,31,30,31,30,31 };
	int* p_ord = ord_year_month; 
	int* p_leap = leap_year_month;
	int num = 0;
	printf("-------------------------------------\n");
	printf("Please enter the year,month,and day:\n");
	while ((scanf("%d %d %d", &year, &month,&day)) != EOF)//判断输入成功与否
	{
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		{
			num = *(p_leap + month);
		}
		else
		{
			num = *(p_ord + month);
		}
		//判断这个月的一号属于星期几
		int one = judge(year, month, 1);
		printf("------------ --CALENDER-- --------------\n");
		
		long long int arr[5][7] = { 0 };//创造日历表5*7(最大表)
		printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun  \n");
			int i = 0;
			int j = 0;
			int num2 = 0;
			for (i = 0; i < 1; i++)
			{
				for (j = 0; j < 7; j++)//填充第一行
				{
					int a = 0;
					int b = 1;
					while (a < 7)
					{
						if (a < one - 1)
						{
							arr[0][a] = '      ';
						}
						if (a >= one-1)
						{
							arr[0][a] = b++;	
						}
						a++;
					}
					num2 = b;
				}
			}
			//打印月份的第一行
			for (i = 0; i < 1; i++)
			{
				for (j = 0; j < 7; j++)
				{
					if (arr[i][j] == '      ')
					{
						printf(" %3c ",arr[i][j]);//输入格式
					}
					else
					{
						if(arr[i][j]==day)
						{						
						printf(" *%2d ",arr[i][j]);
					    }
					    else
					    {
					    	printf(" %3d ",arr[i][j]);
						}
					}
				}
			}
			printf("\n");
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 7; j ++)
				{
					if (num2 <= num)
					{
						arr[i][j] = num2++;
						
					}
				}
			}
			//打印月份的后四行
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 7; j++)
				{
					if (arr[i][j] != 0)
					{
						if(arr[i][j]==day)
						{						
						printf(" *%2d ",arr[i][j]);
					    }
					    else
					    {						
						printf(" %3d ",arr[i][j]);
					    }
					}
				}
				printf("\n");
			}
			printf("---------- ---------------- ------------\n");
 
	}
 
}

int judge(int year, int month, int day)//菜勒公式（已掌握）判断今天是星期几
{
	if (month == 1 || month == 2)
	{
		year -= 1;//将次年一月当做当年十三月
		month += 12;//例如：2003.1->2002.13
	}
	int c = year / 100;//例如：2013->20(自动取整)
	int y = year - c * 100;//例如2023->23
	int d = day;
	int m = month;
	int w = (y + y / 4 + c / 4 + -2 * c + 13 * (m + 1) / 5 + d - 1);//已简化
	while (w < 0)
	{
		w += 7;
	}
	w %= 7;
	if (month > 12)
	{
		year += 1;
		month -= 12;
	}
	if (0 == w)
	{
		w = 7;
	}
	return w;
}

int correct_input(int change)//输入合法检验
{   int k=1;
    int d=change;
	int b,ret;
    char c;
   do
    { 
    if(k>1)
   {
	printf("\n input again:");
   }    
     k+=1;
     ret = scanf("%d", &d);
     c = getchar();
    fflush(stdin); 
    }while ((ret!=1)||(c!='\n'));    
 return d;
}