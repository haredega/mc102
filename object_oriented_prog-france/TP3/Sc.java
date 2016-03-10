// Exemple d'utilisation de la classe Arbre fournie pour le TP n� III
// exemple d'execution : java Sc "(x+3)*(5-(2*x))"
// necessite les fichiers Arbre.java, Clavier.javaGUIHelper.java, JCanvas.java, ManipulationArbre.java, TextInter.java
import java.io.*;
import java.awt.Dimension;


public class Sc{
        
    public static void main(String args[]) throws IOException {
		//utilisation des methodes pour transformer le texte d'une expression en un arbre (avec stockage dans un format intermediaire)
	   ManipulationArbre.generationXMLdepuisTexte(args, "XML.xml");
	   ManipulationArbre.XMLVersArbre("XML.xml").afficherPrefixe();
        System.out.println();
        //Utilisation: java Sc "(x+3)*(5-(2*x))" donne comme resultat:
        // *	+	x	3	-	5	*	2	x	
        
        // R�cuperation d'un objet de la classe Arbre
        Arbre arbre = ManipulationArbre.XMLVersArbre("XML.xml");
        	//arbre.afficherPrefixe();
		//System.out.println();
		/*double x = 2;
		double resultat = arbre.evaluerExpression(x);
		System.out.println(resultat);*/
		
		// Derivees
		Arbre arbred = arbre.deriverExpression();
		arbred.afficherPrefixe();
		double x = 1;
		double resultat = arbred.evaluerExpression(x);
		System.out.println(resultat);
		
		//utilisation de la methode pour afficher l'arbre dans une fenetre.	
		ManipulationArbre.Affiche(arbred);

    }
  }
