
public class studentdriver {
	public static void main(String[] args){
		student std = new student("Jason Snyder", "124 Streetrd.","Computer Science");
		System.out.println(std.toString()+"\n\n");
		std.setname("Dan Stern");
		std.setaddr("54 Queens Blvd");
		std.setmajor("Undeclard");
		std.setSID();
		std.setgpa();
		System.out.println(std.toString()+"\n\n");
		std.setname("Dave Scott");
		std.setaddr("19 Phillies Ln");
		std.setmajor("Russian History  ");
		std.setSID();
		std.setgpa();
		System.out.println(std.toString()+"\n\n");
		std.setname("Jason Snyder");
		std.setaddr(" 16 Kristen Dr.");
		std.setmajor("Computer Science  ");
		std.setSID();
		std.setgpa();
		System.out.println(std.toString()+"\n\n");
		std.setname("Dan Stern ");
		std.setaddr("54 Queens Blvd.");
		std.setmajor("Philosopy");
		std.setSID();
		std.setgpa();
		System.out.println(std.toString()+"\n\n");
		}
}
