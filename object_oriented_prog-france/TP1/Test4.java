public class Test4{
	public static void main(String [] args){
		Point alsacienne = new Point(0,50);
		Carre patricia = new Carre(alsacienne,7);
				
		System.out.println(patricia.toString());
		
		Carre richou = new Carre(patricia);	
		System.out.println(richou.toString());
		richou.translater(0,-50);
		System.out.println(richou.toString());		
	}
}
