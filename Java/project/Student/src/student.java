import java.util.Random;
public class student {
	private String name,addr,major;
	private int SID;
	private double gpa;
	Random gen = new Random();{
	SID = gen.nextInt(9999999);}

	public student(String n, String add,String maj)
		{name=n; addr=add; major=maj;
		gpa = 4.5*gen.nextDouble();
		}
		
	public String getname(){
		return name;
	}
	public String getaddr(){
		return addr;
	}
	public String getmajor(){
		return major;
	}
	public int getSID(){
		return SID;
	}
	public double getgpa()
{
		return gpa;}
	
	
	public String setname(String n){
		name=n;
		return name;
	}
	public String setaddr(String add){
		addr=add;
		return addr;
	}
	public String setmajor(String maj){
		major=maj;
		return major;
	}
	public int setSID(){
		SID++;
		return SID;
	}
	public double setgpa()
{		
		gpa = 4.5*gen.nextDouble();
		return gpa;}
	
	public String toString(){
		return ("Name:"+name+"\nAddresss:"+addr+"\nMajor:"+major+"\nStudent ID:"+SID+"\nGPA:"+gpa);
	}}
