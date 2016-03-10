///////////////////////////////////////////////////////
// Olivier ROUX
// MELOG - TP2  	tp.java
///////////////////////////////////////////////////////

import java.io.*;
import java.util.*;

public class Tp {
	public static void main(String[] argv) throws IOException {
		// Recuperation du nom du fichier a traiter
		String fichier;
        fichier =(argv.length!=0)? argv[0]: "texte";
		// Appel de l'affichage du texte
		Contenu t = new Contenu(fichier);
		// Ecriture du texte modifie dans un second fichier texte
		t.ecri();
	}
}
