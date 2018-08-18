import java.util.Scanner;
import java.util.Random;

public class Rock
{
public static void main(String[] args)
{
	String person;
	String personPlay; //User's play -- "R", "P", or "S"
	String computerPlay; //Computer's play -- "R", "P", or "S"
	int computerInt; 

	
	Scanner scan = new Scanner(System.in);
	Random generator = new Random();
	
	person=scan.next();
	personPlay=person.toUpperCase();
	computerInt=generator.nextInt(3);
	

	switch(computerInt){	
		case 1:	
		computerPlay="R";
		break;
		case 2:
		computerPlay="P";
			break;
		default:
		computerPlay="S";}
	
	System.out.println(computerPlay);

	if (personPlay.equals(computerPlay))
		System.out.println("It's a tie!");

	else if (personPlay.equals("R"))
		if (computerPlay.equals("S"))
		System.out.println("Rock crushes scissors. You win!!");
		else 	
		System.out.println("Paper beats Rock.You lose...");

	else if (personPlay.equals("S"))
		if (computerPlay.equals("P"))
		System.out.println("Scissor beats paper.You Win!!");
		else
		
		System.out.println("Rock beats Scissors.You lose...");

	else if (personPlay.equals("P"))
		if (computerPlay.equals("S"))
		System.out.println("Scissor beats paper.You lose...");
		else 
		
		System.out.println("Paper beats Rock.You Win!!");
}}