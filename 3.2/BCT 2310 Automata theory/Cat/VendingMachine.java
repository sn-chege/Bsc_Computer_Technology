import java.util.Scanner;

public class VendingMachine {
	
	public static int total_amount_entered = 0;
	
	Scanner myscanner = new Scanner(System.in);

	public static void main(String[]args){
		boolean input_status = true;//True when the user has to keep inserting coins, false once the user is done inserting coins 

		while(input_status==true ){
			input_status = InsertCoin();
		}

		  //Ask person how many drinks they want
		  int balance = total_amount_entered % 50 ;
		  int num_drinks = (total_amount_entered - (balance) ) /50 ;
	  
		  //give drinks
		  System.out.println("Machine releases %d drinks "+num_drinks+"\n");
		  //give change
		  System.out.println("Balance is: "+balance+"\n");  

	}

	private boolean InsertCoin(){
			
			//Returns true if user is required to insert another coin else false if user is done inserting coins
			int inserted_coin_value;
			
			String input;
			
			System.out.println("\nINSERT A COIN: \n");
			
			System.out.println("\n---(Type X if you are done inserting Coins)---\n");
			
			input = myscanner.nextLine(); 
			
			//printf("Value: %s\n", input);
			 
			if(input == 'x'|| input =='X' ){
				//Check if the user has entered a minimum of 50
				
				if(total_amount_entered >= 50){
					//printf("------------Please take Your Drink---------------");
					//Give Balance, or request for more drinks 
					return false;
				}else{
					System.out.println("\nNOTE: To buy a drink, you must insert a minimum of 50/- \n");
					return true;
				}
				
			}else{
				//Convert input into int
				inserted_coin_value=Integer.parseInt(input);
				
				//Test if coin is valid
				if(inserted_coin_value == 10 || inserted_coin_value==20 || inserted_coin_value == 40){
					
					total_amount_entered = total_amount_entered + inserted_coin_value;
					
				}else{
				  //  printf("\n--------------------------------------------\n");
				  //  printf("\nYour %d shilling coin has been rejected\n",inserted_coin_value); 
				  System.out.println("\nPlease enter a 10, 20 or 40 shilling coin\n"); 
				 //   printf("\n--------------------------------------------\n"); 
					
				}
				
				return true;
			}
			
		}
}