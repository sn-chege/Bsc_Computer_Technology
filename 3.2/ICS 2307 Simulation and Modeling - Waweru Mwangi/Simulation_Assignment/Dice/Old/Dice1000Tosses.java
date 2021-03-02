import java.lang.reflect.Array;
import java.util.Random;
    // return ;
public class Dice1000Tosses {

    public static void main(String [] args){
        
        int max, min, counter, num_of_throws;
        max = 6;
        min = 1;
        num_of_throws = 1000;

        int  DiceOutcomes [] = new int[num_of_throws];
        int  OutcomeStats [] = new int[max+1];

        //loop that generates random outcomes of a dice, stores them in array
        System.out.println("\n=======================================================\nDiplaying All Dice Values obtained after "+num_of_throws+" throws \n=======================================================");

        for(counter = 0; counter < num_of_throws; counter++){
            //Dice throw
            float lower = 0.6f;
            float upper = 6.0f;

            Random rand = new Random();
            //generate a value within bounds
            float value = rand.nextFloat() * (upper - lower) + lower;
            //convert float to int by rounding
            int side = Math.round(value);


            DiceOutcomes[counter] = side;
           
            if (counter % 20 == 0){
                //Group output in lines each containing 20 values only
                System.out.println("");
            }
            System.out.print(DiceOutcomes[counter] +"  ");
        }

        //Nested loop to count number of times one side of the dice (counter) appears as a value in the OutcomeStats Array
        for (counter = 1; counter < 7; counter++ ){
            int counter1 ;
            int dice_entry_tally = 0; //Number of times a value appears

            for(counter1 = 0 ; counter1 < num_of_throws ; counter1++ ){
               if(DiceOutcomes[counter1] == counter){
                   ++dice_entry_tally;
               }
            }
            OutcomeStats[counter] = dice_entry_tally;
        }
        System.out.println("\n==================================================");
        System.out.println("-----Diplaying Dice Output after "+num_of_throws+" Throws -----");
        System.out.println("==================================================");

        System.out.println("Dice Face \t|| Frequency \t|| Percentage ");

        for (counter = 1; counter < OutcomeStats.length; counter++){
            System.out.print("Side "+counter+"\t\t||  "+OutcomeStats[counter]+"\t\t||  ");
            double percent = (OutcomeStats[counter])/10.0;
            //instead of value/1000 * 100, use /10
            System.out.print(percent+"%\n");
        }   
         System.out.println("======================END==========================");
         
    }
}
