public class Operation <T> extends Arbre <T>{
    // Constructeurs
    public Operation(T val) {
        super(val);
    }
    public Operation(T val, Arbre<T> g, Arbre<T> d) {
        super(val, g, d);
    }	
	
    public void afficherExpression() {
	if (filsGauche.feuille() && filsDroit.feuille()){
		System.out.print(filsGauche.valeur()+"\t"+valeur+"\t"+filsDroit.valeur());
	}else{
		((Operation <T>)filsGauche).afficherExpression();
		((Operation <T>)filsDroit).afficherExpression();
	}
    }	
}
