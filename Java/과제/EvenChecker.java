import java.util.Scanner;
public class EvenChecker{
public static void main (String[] args)
{	int i;
	int number,per;
	Scanner scan = new Scanner (System.in);
	System.out.print ("¦���� �Է��Ͻʽÿ�.");
	
	number = scan.nextInt();
	while(number!=0)
	{if (number%2==0)
		break;
	else System.out.println("Ȧ���Դϴ� �ٽ��Է����ּ���");
		number = scan.nextInt();	}	
	
	

}}