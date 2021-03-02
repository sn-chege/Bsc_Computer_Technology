import java.util.Random;
import java.text.DecimalFormat;

public class Dice
{
    public static void main(String[] args) {
        RollDice();
    }

    private static void RollDice() {
        DecimalFormat df = new DecimalFormat("#.#");
        int number_of_rolls = 1000;
        int count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0;

        double
                First=0,
                Second=(double)1.0/6.0,
                Third=(double)1.0/3.0,
                Fourth=(double)1.0/2.0,
                Fifth=(double)2.0/3.0,
                Sixth=(double)5.0/6.0;

        for (int index = 0; index < number_of_rolls; index++) {

            double face = Math.random();

            if (face >=First && face < Second)
            {
                count1=count1 +1;
            }else if (face >=Second && face <Third)
            {
                count2++;
            }else if (face >=Third && face <Fourth)
            {
                count3++;
            }else if (face >=Fourth && face <Fifth)
            {
                count4++;
            }else if (face >=Fifth && face <Sixth)
            {
                count5++;
            }else
            {
                count6++;
            }


        }

        double PercFreq1 = count1 *0.1;
        double PercFreq2 = count2 *0.1;
        double PercFreq3 = count3 *0.1;
        double PercFreq4 = count4 *0.1;
        double PercFreq5 = count5*0.1;
        double PercFreq6 = count6*0.1;

        System.out.println("Face\t\tFrequency\tPecentage Frequency");
        System.out.println("1"+"\t\t"+count1+"\t\t\t"+df.format(PercFreq1)+" %");
        System.out.println("2"+"\t\t"+count2+"\t\t\t"+df.format(PercFreq2)+" %");
        System.out.println("3"+"\t\t"+count3+"\t\t\t"+df.format(PercFreq3)+" %");
        System.out.println("4"+"\t\t"+count4+"\t\t\t"+df.format(PercFreq4)+" %");
        System.out.println("5"+"\t\t"+count5+"\t\t\t"+df.format(PercFreq5)+" %");
        System.out.println("6"+"\t\t"+count6+"\t\t\t"+df.format(PercFreq6)+" %");
    }
}
