public class Test3{
	public static void main(String [] args){
		Point Carquefou= new Point(2,0);
		Rectangle Patrick=new Rectangle(Carquefou,98,12);
				
		System.out.println(Patrick.toString());
		Rectangle Patrickvaarennes=new Rectangle(Patrick);
		System.out.println(Patrickvaarennes.toString());
		Patrickvaarennes.translater(100,2);
		System.out.println(Patrickvaarennes.toString());
	}
}
