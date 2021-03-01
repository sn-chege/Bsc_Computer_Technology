#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int total_amount_entered = 0;

bool InsertCoin(){
    
    //Returns true if user is required to insert another coin else false if user is done inserting coins
    int inserted_coin_value;
    
    char input[2];
    
    printf("\nINSERT 10, 20 or 40 shilling coin: ");
    scanf("%s",input);

    //Convert input into int
    inserted_coin_value = atoi(input);//*input - '0';
    
    //Test if coin is valid
    if(inserted_coin_value == 10 || inserted_coin_value==20 || inserted_coin_value == 40){
        
        total_amount_entered = total_amount_entered + inserted_coin_value;
        
    }else{
        //  printf("\n--------------------------------------------\n");
        //  printf("\nYour %d shilling coin has been rejected\n",inserted_coin_value); 
        printf("\nPlease enter a 10, 20 or 40 shilling coin\n"); 
        //   printf("\n--------------------------------------------\n"); 
        
    }

    printf("\nAre you done inserting coins? (Type Y for Yes, N for No): ");

    scanf("%s",input);

    if(*input == 'y'|| *input =='Y' ){
        
        //Check if the user has entered a minimum of 50
        if(total_amount_entered>=50){
            //printf("------------Please take Your Drink---------------");
            //Give Balance, or request for more drinks 
            return false;
        }else{
            printf("\nNOTE: To buy a drink, you must insert a minimum of 50/- \n");
            return true;
        }
        
    }else{
        
        
        return true;
    }
    
}

int main()
{
    printf("\n************WELCOME**************");

    //True when the user has to keep inserting coins, false once the user is done inserting coins 
    bool input_status = true;

    while(input_status){
        input_status = InsertCoin();
        //  printf("\nTotal amount Inserted: %d\n",total_amount_entered);
    }
    
    printf("\nTotal amount Inserted: %d\n",total_amount_entered);
    //Ask person how many drinks they want
    int balance = total_amount_entered % 50 ;
    int num_drinks = (total_amount_entered - (balance) ) /50 ;

    //give drinks
    printf("Number of Drinks released: %d\n", num_drinks);
    //give change
    printf("Your Balance is: %d\n",balance);  

    return 0;
}