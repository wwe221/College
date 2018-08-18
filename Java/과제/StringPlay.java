public class StringPlay
{
public static void main (String[] args)
{
String college = new String ("PoDunk College");
String town = "Anytown, USA";
String change1, change2, change3;
int stringLength = college.length();
System.out.println (college + " contains " + stringLength + " characters.");
change1 = college.toUpperCase(); 
change2 = college.replace('O','*');
change3 = college.concat(town);
System.out.println ("The final string is " + change3);
}
}