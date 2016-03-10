public class Test{
	public static void main(String [] args){
		Point p = new Point(0,0);
	
		//Affichage
		System.out.println(p.getAbscisse());
		System.out.println(p.getOrdonnee());

		//Créer p1
		Point p1 = new Point(12,3);
		//Affichage
		System.out.println(p1.getAbscisse());
		System.out.println(p1.getOrdonnee());

		
		//Créer p2
		Point p2 = new Point(p1);
		
		//Affichage
		System.out.println(p2.getAbscisse());
		System.out.println(p2.getOrdonnee());

		p2.setAbscisse(7);
		p2.setOrdonnee(4);

		//Affichage
		System.out.println(p2.getAbscisse());
		System.out.println(p2.getOrdonnee());	

		p2.translate(3,3);
		
		//Affichage
		System.out.println(p2.getAbscisse());
		System.out.println(p2.getOrdonnee());
	
		
	}	
}

