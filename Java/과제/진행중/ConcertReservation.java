import java.util.Scanner;
public class ConcertReservation {
	private int numb = 0;
	private String name[],sit[];
	private int in;
	public ConcertReservation(int inn){
		in=inn;
		/*int i=0;	
		Scanner scan= new Scanner(System.in);
		in = scan.nextInt();
		while(i==0){
			switch(in){
			case 1:
				Reserv();
				break;
			case 2:
				search();
				break;
			case 3:
				break;
			case 4:
				return;
			}
		}*/
	}
	public void Reserv(){
		int inin;	
		Scanner scan2= new Scanner(System.in);
		inin = scan2.nextInt();
		
		System.out.println("S(1) A(2) B(3):");
		switch(inin){
			case 1:
				sit[numb]="S";
				break;
			case 2:
				sit[numb]="A";
				break;
			case 3:
				sit[numb]="B";
				break;
			default:
				System.out.println("올바른 입력이 아닙니다");}
		System.out.println("이름:");
		name[numb] = scan2.next();numb++;
		System.out.println("예약번호는"+numb+"번 입니다.");}
	public void search(){
		String in2;
		Scanner scan2= new Scanner(System.in);
		in2=scan2.next();
		switch(in2){
		case"***":
			System.out.println("예약번호\t이름\t좌석");
			for(int i=0;i<numb;i++){
				System.out.println((i+1)+"\t"+name[i]+"\t"+sit[i]);
			}
		default:
			System.out.println("올바른 입력이 아닙니다");
		}
		
	}
}
