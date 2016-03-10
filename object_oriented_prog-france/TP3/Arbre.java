class Arbre <T>{
    protected T valeur;
    protected Arbre<T> filsGauche, filsDroit;

    public T valeur() {
        return valeur;
    }
    public boolean existeFilsGauche() {
        return filsGauche != null;
    }
    public boolean existeFilsDroit() {
        return filsDroit != null;
    }
    public Arbre<T> filsGauche() {
        return filsGauche;
    }
    public Arbre<T> filsDroit() {
        return filsDroit;
    }
    public void affecterValeur(T c) {
        valeur = c;
    }
    public void affecterFilsGauche(Arbre<T> g) {
        filsGauche = g;
    }
    public void affecterFilsDroit(Arbre<T> d) {
        filsDroit = d;
    }
    public boolean feuille() {
        return (filsDroit==null && filsGauche==null);
    }
    public int hauteur() {
        int g = existeFilsGauche() ? filsGauche.hauteur() : 0;
        int d = existeFilsDroit() ? filsDroit.hauteur() : 0;
        return 1 + Math.max(g, d);
    }
    // Constructeurs
    public Arbre(T val) {
        valeur = val;
        filsGauche = filsDroit = null;
    }
    public Arbre(T val, Arbre<T> g, Arbre<T> d) {
        valeur = val;
        filsGauche = g; filsDroit = d;
    }
    // Affichage
    public void afficherPrefixe() {
        System.out.print(valeur+"\t");
        if (existeFilsGauche()) filsGauche.afficherPrefixe();
        if (existeFilsDroit())	filsDroit.afficherPrefixe();
    }
    public void afficherInfixe() {
        if (existeFilsGauche()) filsGauche.afficherInfixe();
        System.out.print(valeur+"\t");
        if (existeFilsDroit())filsDroit.afficherInfixe();
    }
    public void afficherPostfixe() {
        if (existeFilsGauche()) filsGauche.afficherPostfixe();
        if (existeFilsDroit())filsDroit.afficherPostfixe();
        System.out.print(valeur+"\t");
    }
    
    // Methodes du TP
    public double evaluerExpression(double x) {
    	// Traitement des cas: Feuille 
    	if (this.feuille()){
    		if(valeur.toString().charAt(0) == 'x'){
    			return x;
    		}
    		return Double.parseDouble(this.valeur.toString());
    	// Traitement des cas: Noeud    	
    	}else{
		switch (valeur.toString().charAt(0)){
			case '+': return (filsGauche.evaluerExpression(x)+filsDroit.evaluerExpression(x));
			case '-': return (filsGauche.evaluerExpression(x)-filsDroit.evaluerExpression(x));
			case '*': return (filsGauche.evaluerExpression(x)*filsDroit.evaluerExpression(x));
			case '/': return (filsGauche.evaluerExpression(x)/filsDroit.evaluerExpression(x));
			case '^': return (Math.pow(filsGauche.evaluerExpression(x),filsDroit.evaluerExpression(x)));				
			default: return 0;				
		}
	}
    }
    
    
    public Arbre deriverExpression(){
	    // Traitement des cas: Feuille 
	    if (this.feuille()){
	    	    if(valeur.toString().charAt(0) == 'x'){
	    	    	    return new Arbre(1);    
	    	    }else{
	    	    	    return new Arbre(0);
	    	    }
	    }else{
	    	    switch (valeur.toString().charAt(0)){
			case '+': return new Arbre(this.valeur, filsGauche.deriverExpression(), filsDroit.deriverExpression());
			case '-': return new Arbre(this.valeur, filsGauche.deriverExpression(), filsDroit.deriverExpression());
			// Le plus compliqué
			case '^': Arbre puissance = new Arbre("-",filsDroit,new Arbre(1));
				  Arbre pow = new Arbre("^",new Arbre("x"),puissance);
				  return new Arbre("*", filsDroit, pow);
			case '*': Arbre foisg = new Arbre("*",filsDroit,filsGauche.deriverExpression());
				  Arbre foisd = new Arbre("*",filsGauche,filsDroit.deriverExpression());
				  return new Arbre("+",foisg,foisd);
			case '/': Arbre bas = new Arbre("^",filsDroit,new Arbre(2));
				  Arbre foisgg = new Arbre("*",filsGauche.deriverExpression(),filsDroit);
				  Arbre foisdd = new Arbre("*",filsDroit.deriverExpression(),filsGauche);
				  Arbre haut = new Arbre("-",foisgg,foisdd);
				  return new Arbre("/",haut,bas);				  
			default: return new Arbre(0);
		    }	    	    
	    }
    }

}
