#include<stdio.h>
#include<time.h>
char name[30];
int amount=1000,diposit_amount,account_no,count=0;
void menu();
void deposit();
void with_draw();
void transfer_money();
void account_details();
void transaction_details();
int main()
{
	FILE *ptr=fopen("account.txt","w");
	FILE *fp=fopen("account2.txt","w");
	int ch;
    printf("WELCOME TO YOUR BANK\n");
	printf("enter your name:");
	gets(name);
	fprintf(ptr,"\nname:%s\n",name);
	fprintf(fp,"AMOUNT TRANSFERED");
	printf("please enter your account number:");
	scanf("%d",&account_no);
	fprintf(ptr,"\naccount no:%d\n",account_no);
	fclose(ptr);
	while(1)
	{
		
	menu();
	printf("ENTER YOUR CHOICE :");
	scanf("%d",&ch);
    if(ch==6)
    {
    	break;
	}

	switch(ch)
		{
			case 1:
				deposit();
				break;
			case 2:
				with_draw();
				break;
			case 3:
			    transfer_money();
				break;
			case 4:
				account_details();
				break;
			case 5:
				transaction_details();
				break;
			case 6:
			    break;	
	        default:
	        	printf("please enter right choice");
				break;				 	
			    
}}
	return 0;
}
void menu()
{   


	printf("\nplease select an option\n\n");
	printf("1.DEPOSIT MONEY\n2.WITH DRAW MONEY\n3.TRANSFER MONEY\n4.ACCOUNT DETAILS\n5.TRANSACTION DETAILS\n6.EXIT\n\n");

	
}
void deposit()
{    
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("account.txt","a");
	printf("enter the amount you want to deposit :");
	scanf("%d",&diposit_amount);
	amount+=diposit_amount;
	printf("money deposited\n");
	printf("\ncurrent balence=%d\n",amount);
	fprintf(ptr,"\n%d rupees has been deposited in your account\n",diposit_amount);
	fprintf(ptr,"\nCurrent balance is %d\n",amount);
	fprintf(ptr,"\nThe date and time of the transaction is\t%s\n",ctime(&tm));
	count++;
}
void with_draw()
{
	int with_draw;
	time_t tm;
	time(&tm);
	FILE *ptr=fopen("account.txt","a");
	printf("\nenter the amount you want to with draw\n");
	scanf("%d",&with_draw);
	if(with_draw>amount)
	{
		printf("/nINSUFFICIENT BALANCE\n");
	}
	else
	{
		amount-=with_draw;
		printf("\nWITHDRAW SUCESSFUL\n");
		printf("current balance is  :%d",amount);
		fprintf(ptr,"\nrupees:%d has been withdrawn from your account\n",with_draw);
		fprintf(ptr,"\nyour current balance is :%d\n",amount);
		fprintf(ptr,"\nThe date and time of the transation is\t%s\n",ctime(&tm));
		count++;
	}
	fclose(ptr);
}
void transfer_money()
{
	int acc1,acc2,transfer_amount;
	time_t tm;
	time(&tm);
	FILE *ptr=fopen("account.txt","a");
	FILE *fp=fopen("account2.txt","a");
	printf("\nenter account no in which you have to transfer :\n");
	scanf("%d",&acc2);
	printf("\nenter the amount you want to transfer\n");
	scanf("%d",&transfer_amount);
	if(transfer_amount>amount)
	{
		printf("\nINSUFFICIENT BALANCE\n");
		
	}
	else
	{
		amount-=transfer_amount;
		printf("\nMoney Transferred\n");
        printf("Current balance : %d\n", amount);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", transfer_amount, acc2);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        fprintf(fp, "\nRs%d had been transferred to your account from the account : %d\n", transfer_amount, account_no);
        fprintf(fp, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    fclose(fp);
   
	}
	

void account_details()
{
    printf("\nACCOUNT DETAILS\n");
    

    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", account_no);
    printf("Total balance = %d\n ", amount);
    printf("\n%d transactions have been made from your account \n", count);
}
void transaction_details()
{
	char c;
	FILE *ptr=fopen("account.txt","r");
	c=fgetc(ptr);
	if(c==EOF)
	{
		printf("\ntransaction details:\n");
		printf("\nNO RECENT TRANSACTION\n");
	}
	else
	{
		printf("transaction details");
		printf("\n%d transactions have been made from your account with account no:%d",count,account_no);
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(ptr);
			
		}
	}
	
}
    

