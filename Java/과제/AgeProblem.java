import java.util.Scanner;
public class AgeProblem
{
public static void main(String args[])
{
int aliceAge = 0;
int bobAge = 0;
Scanner scan = new Scanner(System.in);
System.out.print("What is Bob's current age? ");
bobAge = scan.nextInt();
aliceAge = 3*(bobAge)- 7;
System.out.println("If Bob is " + bobAge + " then Alice must be " + aliceAge +
".");
}}