public class Point{
	private int abscisse;
	private int ordonnee;
	
	//Constructeur
	public Point (int x, int y){
		abscisse=x;
		ordonnee=y;
	}
	// Constructeur recopie
	public Point (Point p){
		abscisse=p.abscisse;
		ordonnee=p.ordonnee;
	}
	// accesseur ou getter
	public int getAbscisse(){
		return abscisse;
	}
	public int getOrdonnee(){
		return ordonnee;
	}
	//modificateur ou setter
	public void setAbscisse(int x){
		abscisse=x;
	}
	public void setOrdonnee(int y){
		ordonnee=y;
	}
	
	public void translate (int a, int b) {
		abscisse=abscisse+a;
		ordonnee=ordonnee+b;
	}
}
