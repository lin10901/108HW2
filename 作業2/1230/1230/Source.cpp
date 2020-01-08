#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)
struct  table
{
	char name[4] = { '\0' ,'\0' ,'\0','\0' };
	int number = 0;
	int valid = 0;
	int namevaild=  0;

};

struct  RS
{
	char title[5] = "\0";
	char name1[10] = { '\0' ,'\0' ,'\0' ,'\0' ,'\0' };
	char name2[10]= { '\0' ,'\0' ,'\0' ,'\0' ,'\0' };
	char name3[10] = { '\0' ,'\0' ,'\0' ,'\0' ,'\0' };
	int number1 = 0;
	int number2 = 0;

	int valid = 0;
	int namevaild = 0;
	int number1vaild = 0;
	int number2vaild = 0;

};
int check(char* ch);
int getindex(char* ch);
void Issue(int Rf[ ], struct table  Rat[ ], struct  RS  Add[ ], int count, char *token, int n, int* rsindex, int* ratindex, int entry);
void print(int Rf[5], struct table Rat[5], struct  RS Add[ ], struct  RS Mul[2], int cycle);
int main(void)
{

	FILE *fp;
	errno_t err;
	char StrLine[1024];
	char *token;
	int Rf[5] = {0,2,4,6,8};
	struct  table Rat[5] = { "\0" };
	struct  RS Add[3] = { "\0" };
	struct  RS Mul[3] = { "\0" };
	int cycle = 0;
	if ((err = fopen_s(&fp, "test2.txt", "r")) != 0)
	{
		printf("open file error!!\n");
		system("PAUSE");
		exit(0);
	}
	else 
	{
		while (!feof(fp))
		{
			fgets(StrLine, 1024, fp);  //Åª¨ú¤@¦æ
			printf("input: %s\n", StrLine);
			token = strtok(StrLine, " ,\n,");
			int count = 1,rsindex=-1,ratindex = -1;
			int n = 0;

			while (token != NULL)
			{
				

				if (count == 1)
				{
					n = check(token);

				}
				if (n > 0 && n < 4)
				{

					Issue(Rf, Rat, Add, count, token, n, &rsindex,& ratindex,3);
					if (count == 4)
					{
						cycle++;
						print(Rf, Rat, Add, Mul, cycle);
					}
						
				}
				if (n > 3 && n < 6)
				{

					Issue(Rf, Rat, Mul, count, token, n, &rsindex, &ratindex, 2);
					if (count == 4)
					{
						print(Rf, Rat, Add, Mul,cycle);
						cycle++;
					}
						
				}
				
				 
				
				/*if (count == 2 && n > 0 && n < 4)
				{
					for (int i = 0; i < 3; i++)
					{
						if (Add[i].valid == 0)
						{
							Add[i].valid = 1;
							rsindex = i;
							break;
						}
					}

					ratindex = getindex(token)-1;
					if (Rat[rsindex].valid == 0 && n>0&&n<4)
					{
						char temp[10] = { "\0" };
							if (n == 1||n == 2)
								strcpy(temp,"+");
							if (n == 3)
								strcpy(temp, "-");
						strcpy(Add[rsindex].name1, temp);
						Add[rsindex].namevaild = 1;

					}

				}
				if (count == 3 && n > 0 && n < 4)
				{
					int rfindex = getindex(token);
					if (rfindex == -1)
					{
						strcpy(Add[rsindex].name3, token);
						Add[rsindex].number1vaild = 1;
						//rsindex = -1;
					}

					if (Rat[rfindex - 1].valid == 0 && rsindex!=-1)
					{
						char  temp [10]= "\0";
						sprintf(temp, "%d", Rf[rfindex-1]);
						strcpy(Add[rsindex].name2, temp);
						Add[rsindex].number1vaild = 1;

					}
					else if (Rat[rfindex - 1].valid == 1 && rsindex != -1)
					{
						strcpy(Add[rsindex].name2, Rat[rfindex - 1].name);
					}

				}

				if (count == 4 && n > 0 && n < 4 )
				{
					int rfindex = getindex(token);
					if (rfindex == -1 && rsindex != -1)
					{
						strcpy(Add[rsindex].name3, token);

						Add[rsindex].number2vaild = 1;
						char temp2[10] = "\0";
						char temp1[10] = "\0";
						sprintf(temp2, "%d", rsindex + 1);
						strcpy(temp1, "RS");
						strcat(temp1, temp2);
						strcpy(Rat[ratindex].name, temp1);
						Rat[ratindex].valid = 1;
						rsindex = -1;
					}


					if (Rat[rfindex - 1].valid == 0 && rsindex != -1)
					{
						char t3[10] = "\0";
						char t2[10] = "\0";
						char t1[10] = "\0";
						sprintf(t2, "%d",rsindex+1);
						sprintf(t3, "%d", Rf[rfindex-1]);
						strcpy(t1,"RS");
						strcat(t1, t2);
						strcpy(Rat[ratindex].name, t1);
						Rat[ratindex ].valid = 1;
						strcpy(Add[rsindex].name3, t3);
						Add[rsindex].valid = 1;
						Add[rsindex].number2vaild = 1;
					}
					else if (Rat[rfindex - 1].valid == 1 && rsindex != -1)
					{
						strcpy(Add[rsindex].name3, Rat[rfindex - 1].name);
						rsindex = -1;

					}
					count = 0;
					print(Rf, Rat, Add, Mul);

				}
				 */
				(Rf, Rat, Add, Mul, count, token, n, rsindex, ratindex);
				 //printf(" %s\n", token );
				token = strtok(NULL, ", ");
				count++;
			}
 
		}



	}

		fclose(fp);

		system("PAUSE");

	return 0;
}

int check(char* ch)
{
	int n = 0;
	if (strcmp(ch, "ADD") == 0)
		n = 1;
	if (strcmp(ch, "ADDI") == 0)
		n = 2;
	if (strcmp(ch, "SUB") == 0)
		n = 3;
	if (strcmp(ch, "MUL") == 0)
		n = 4;
	if (strcmp(ch, "DIV") == 0)
		n = 5;
	 

	return n;
}
int getindex(char* ch)
{
	char t = ch[0];

	if (t == 'F')
	{
		int i = 0;
		i = ch[1] - '0';
		return i;
	}
 

	return -1;

}

void print(int Rf[5], struct table Rat[5], struct  RS Add[3], struct  RS Mul[2],int cycle)
{
	printf("\nRf:\n");
	for (int i = 0; i < 5; i++)
		printf("F%d %d\n",i+1,Rf[i]);
	printf("\nRat:\n");


	for (int i = 0; i < 5; i++)
	{
		printf("F%d  %s\n", i + 1, Rat[i].name);

	}
	
	printf("\nRS Add:\n");
	for (int i = 0; i < 3; i++)
	{	
		printf("RS%d  %s| %s | %s\n",i+1, Add[i].name1, Add[i].name2, Add[i].name3);	
	}
		

	printf("\nMul:\n");
	for (int i = 0; i < 2; i++)
		printf("RS%d  %s| %s | %s\n", i + 4, Mul[i].name1, Mul[i].name2, Mul[i].name3);

	printf("\n");

	printf("cycle:%d\n", cycle);


}
void Issue(int Rf[ ], struct table Rat[ ], struct  RS Add[ ], int count, char *token, int n, int* rsindex, int* ratindex,int entry)
{

	if (count == 2 )
	{
		for (int i = 0; i < entry; i++)
		{
			if (Add[i].valid == 0)
			{
				*rsindex = i;
				break;
			}
		}

		*ratindex = getindex(token) - 1;
		if (Add[*rsindex].valid == 0 )
		{
			char temp[10] = { "\0" };
			if (n == 1 || n == 2)
				strcpy(temp, "+");
			if (n == 3)
				strcpy(temp, "-");
			if (n == 4)
				strcpy(temp, "*");
			if (n == 5)
				strcpy(temp, "\\");
			strcpy(Add[*rsindex].name1, temp);
			Add[*rsindex].namevaild = 1;
			Add[*rsindex].valid = 1;

		}

	}
	if (count == 3 )
	{
		int rfindex = getindex(token);
		if (rfindex == -1)
		{
			token = strtok(token, "\n");
			strcpy(Add[*rsindex].name3, token);
			Add[*rsindex].number1vaild = 1;
		}

		if (Rat[rfindex - 1].valid == 0 && *rsindex != -1)
		{
			char  temp[10] = "\0";
			sprintf(temp, "%d", Rf[rfindex - 1]);
			strcpy(Add[*rsindex].name2, temp);
			Add[*rsindex].number1vaild = 1;

		}
		else if (Rat[rfindex - 1].valid == 1 && *rsindex != -1)
		{
			strcpy(Add[*rsindex].name2, Rat[rfindex - 1].name);
		}

	}

	if (count == 4 )
	{
		int rfindex = getindex(token);
		if (rfindex == -1 && *rsindex != -1)
		{
			token = strtok(token, "\n");
			strcpy(Add[*rsindex].name3, token);

			Add[*rsindex].number2vaild = 1;
			char temp2[10] = "\0";
			char temp1[10] = "\0";
			int x = 0;
			if (n > 3)
				x = 3;

			sprintf(temp2, "%d", *rsindex + 1+x);
			strcpy(temp1, "RS");
			strcat(temp1, temp2);
			strcpy(Rat[*ratindex].name, temp1);
			Rat[*ratindex].valid = 1;
			*rsindex = -1;
		}


		if (Rat[rfindex - 1].valid == 0 && *rsindex != -1)
		{
			char t3[10] = "\0";
			char t2[10] = "\0";
			char t1[10] = "\0";
			int x=0;
			if (n > 3)
				x = 3;
			sprintf(t2, "%d", *rsindex + 1+x);
			sprintf(t3, "%d", Rf[rfindex - 1]);
			strcpy(t1, "RS");
			strcat(t1, t2);
			strcpy(Rat[*ratindex].name, t1);
			Rat[*ratindex].valid = 1;
			strcpy(Add[*rsindex].name3, t3);
			Add[*rsindex].valid = 1;
			Add[*rsindex].number2vaild = 1;
		}
		else if (Rat[rfindex - 1].valid == 1 && *rsindex != -1)
		{
			strcpy(Add[*rsindex].name3, Rat[rfindex - 1].name);
			*rsindex = -1;

		}
		count = 0;
		
	}



}