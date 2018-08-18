import java.util.Random;
import java.util.Scanner;
public class RandomNumbers
{
public static void main (String[] args)
{
	Random generator = new Random();
	Scanner scan=new Scanner(System.in);
	int dice1,dice2;
	int a1, a2, a3, b1, b2, b3, sum1, sum2;
	double aver1,aver2;
	System.out.println("How many sides does die 1 have?");
	dice1=scan.nextInt();
	System.out.println("How many sides does die 2 have?");
	dice2=scan.nextInt();
	a1= generator.nextInt(dice1)+1;
	b1= generator.nextInt(dice2)+1;
	a2= generator.nextInt(dice1)+1;
	b2= generator.nextInt(dice2)+1;
	a3= generator.nextInt(dice1)+1;
	b3= generator.nextInt(dice2)+1;
	aver1=(float)(a1+a2+a3)/3;
	aver2=(float)(b1+b2+b3)/3;
	sum1=a1+a2+a3;
	sum2=b1+b2+b3;
	System.out.println("Dice 1 first roll ="+a1);
	System.out.println("Dice 2 first roll ="+b1);
	
	System.out.println("Dice 1 second roll ="+a2);
	System.out.println("Dice 2 second roll ="+b2);
	
	System.out.println("Dice 1 third roll ="+a3);
	System.out.println("Dice 2 third roll ="+b3);
System.out.println("Die 1 rolled a total of "+sum1 +" and rolled " +aver1 + " on average.");
System.out.println("Die 2 rolled a total of "+sum2 +" and rolled " +aver2 + " on average.");
	
}}