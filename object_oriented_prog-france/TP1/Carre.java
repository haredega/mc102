public class Carre{
	private Point origine;
	private int longueur;
	
	//Constructeur
	public Carre (Point p ,int l){
		origine = p;
		longueur=l;
	}
	// Constructeur recopie
	public Carre (Carre c){
		origine = c.origine;
		longueur = c.longueur;
	}
	public void translater(int a, int b) {
		origine.translate(a,b);
	}
	
	public String toString(){
		return "Carré: Origine ("+origine.getAbscisse()+","+origine.getOrdonnee()+"), Longueur ("+longueur+")";
	}
}
