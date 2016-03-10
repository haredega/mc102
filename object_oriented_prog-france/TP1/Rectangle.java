public class Rectangle{
	private Point origine;
	private int largeur;
	private int hauteur;
	
	//Constructeur
	public Rectangle (Point p ,int l, int h){
		origine = p;
		largeur=l;
		hauteur=h;
	}
	// Constructeur recopie
	public Rectangle (Rectangle r){
		origine = r.origine;
		largeur = r.largeur;
		hauteur = r.hauteur;
	}
	public void translater(int a, int b) {
		origine.translate(a,b);
	}
	
	public String toString(){
		return "rectangle: Origine ("+origine.getAbscisse()+","+origine.getOrdonnee()+"), Largeur ("+largeur+"), Hauteur ("+hauteur+")";
	}
}
