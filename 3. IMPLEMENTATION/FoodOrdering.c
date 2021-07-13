#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showMenu();
int takeOrder();
int displayOrder();
void refreshOrderlist();
char menu[5][20] = {"Pizza","Pasta","Burger","Noodles","Sandwich"};
int stock[5]={100,100,100,100,100};
int prices[5]={150,100,100,80,70};
char order[10][20]={""};
int totalPrice=0;
int flag;
int j=0;

void main()
{ char name[20];
        char email[20];
    printf("\nEnter your name\n");
    scanf("%4s", name);
    printf("Enter your email\n");
    scanf("%4s", email);  
    printf("Your name -  %s    \n", name);           
    printf("Your email -    %s   \n", email);
    while(1)
    {   
        int option;
       
        printf("\n **** CENTRAL PERK **** \n");
        printf("\n A WARM WELCOME \n");
        printf("\n1. Show Menu\n");
        printf("2. Order Directly\n");
        scanf("%d",&option);
        if(option==1){
            showMenu();
            printf("What would you like to have..? give number code of food <space> Quantity   ");
            int y = takeOrder();
            if(y!=1){
                int x = displayOrder();
            }
        }
        else{
            printf("What would you like to have..? give number code of food <space> Quantity   ");
            int y = takeOrder();
            if(y!=1){
                int x = displayOrder();
            }
        }
        refreshOrderlist();
        printf("\nPress 0 to exit system or 1 for next order");
        scanf("%d",&flag);
        if(flag == 0){
            break;
        }
    }
}
void showMenu(){
    printf("----------------------------------------------------\n");
    printf("| No. |Name      |Price |Stock|\n");
    printf("----------------------------------------------------\n");
    printf("|  1. |%s     |%d   |%d  |\n",menu[0],prices[0],stock[0]);
    printf("----------------------------------------------------\n");
    printf("|  2. |%s     |%d   |%d  |\n",menu[1],prices[1],stock[1]);
    printf("----------------------------------------------------\n");
    printf("|  3. |%s    |%d   |%d  |\n",menu[2],prices[2],stock[2]);
    printf("----------------------------------------------------\n");
    printf("|  4. |%s   |%d    |%d  |\n",menu[3],prices[3],stock[3]);
    printf("----------------------------------------------------\n");
    printf("|  5. |%s  |%d    |%d  |\n",menu[4],prices[4],stock[4]);
    printf("----------------------------------------------------\n");
}
int takeOrder(){
    int input;
    char quantity[20];
    scanf("%d",&input);
    if(input==-1){
        refreshOrderlist();
        printf("Order Cancelled");
        return 1;
    }
    if(input==0){
        return 0;
    }
    else
    {
        scanf("%1s",quantity);
        totalPrice += prices[input-1] * atoi(quantity);
        strcpy(order[j],menu[input-1]);
        j++;
        strcpy(order[j],quantity);
        j++;
        printf("item = %s, quantity = %s\n",order[j-2],order[j-1]);
        printf("Enter -1 to cancel order or 0 to get bill\n");
        
        stock[input-1] = stock[input-1] - atoi(quantity);
        takeOrder();
    }
}
int displayOrder(){
    int i=0;
    printf("\n     Your Final Order     \n");
    while(strlen(order[i])!=0){
        printf("item = %s, quantity = %s\n",order[i],order[i+1]);
        i = i+2;
    }
    printf("Total Price = %d",totalPrice);
    printf("\n\n\nThank you for visiting our restaurant");
    return 0;
}
void refreshOrderlist(){
    int i=0;
    while(strlen(order[i])!=0){
        strcpy(order[i],"xyz");
        i++;
    }
    j = 0;
    totalPrice = 0;
}
