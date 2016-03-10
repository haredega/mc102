public class Test2{
	public static void main(String [] args){
		Polygone philippe = new Polygone();
		Point p1 = new Point(12,4);
		Point p2 = new Point(7,2);
		Point p3 = new Point(3,9);

		philippe.ajouter(p1);
		philippe.ajouter(p2);
		philippe.ajouter(p3);

		System.out.println(philippe.toString());

		Point p4 = new Point(9,3);
		philippe.ajouter(p4);		
		
		System.out.println(philippe.toString());
		
		philippe.translater(10,10);
		
		System.out.println(philippe.toString());
		
		Polygone louis = new Polygone(philippe);
		
		System.out.println(louis.toString());
	}
}
