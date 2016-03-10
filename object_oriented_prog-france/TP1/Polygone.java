import java.util.Vector;

public class Polygone{
	private Vector<Point> sommets;
	private int nbSommets;
	
	// Tableau de points
	public Polygone(){
		sommets = new Vector<Point>();
		nbSommets = 0;
	}
	
	public Polygone(Polygone p){
		sommets = new Vector<Point>(p.sommets);
		nbSommets = p.nbSommets;
	}
	public void ajouter(Point s){
		sommets.add(s);
		nbSommets++;
	}
	public void translater(int x, int y){
		for(int i=0;i<nbSommets;i++){
			Point p = sommets.get(i);
			p.translate(x,y);
			sommets.set(i,p);
		}
	}
	
	public String toString(){
		String poly = "Polygone: (";
		for(int i=0;i<nbSommets;i++){
			Point p = sommets.get(i);
			poly = poly+p.getAbscisse()+",";
			poly = poly+p.getOrdonnee()+") (";			
		}		
		return poly;
	}
}
