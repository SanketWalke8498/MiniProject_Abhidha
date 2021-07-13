/**
 * @file food.c
 * @author Abhidha Choudhari (choudhariabhidha@gamil.com)
 * @brief A main progarm
 * @version 0.1
 * @date 2021-07-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "food.h"  /**
 * @brief - Header guard
 * 
 */
/**
 * @brief - Declaring  Functions 
 * 
 */

void showMenu(); 
int takeOrder();
int displayOrder();
int refreshOrderlist();
char menu[5][20] = {"Pizza","Pasta","Burger","Noodles","Sandwich"};
int stock[5]={100,100,100,100,100};
int prices[5]={150,100,100,80,70};
char order[10][20]={"0"}; /**
 * @brief char declared
 * 
 */
int totalPrice;
int flag;
int j=0;
/**
 * @brief various integer variables are declared
 * 
 * @return int 
 */
int main() 
{ char name[50];
    char email[50];
    printf("\nEnter your name\n");
    scanf("%4s", name);
    printf("Enter your email\n");
    scanf("%4s", email);  
    printf("Your name -  %s    \n", name);           
    printf("Your email -    %s   \n", email);
    while(1)
    {   
        int option;
        char order[10][20]={"0"};
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
/**
 * @brief showMenu function declared
 * 
 */
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
/**
 * @brief takeOrder decared
 * 
 * @return int 
 */
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
        scanf("%4s",quantity);
        totalPrice += prices[input-1] * atoi(quantity);
        strcpy(order[j],menu[input-1]);
        j++;
        strcpy(order[j],quantity);
        j++;
        printf("item = %s, quantity = %s\n",order[j-2],order[j-1]);
        printf("Enter -1 to cancel order or 0 to get bill\n");
        
        stock[input-1] = stock[input-1] - atoi(quantity);
        takeOrder(); /**
         * @brief takeOrder called
         * 
         */
    }
}

