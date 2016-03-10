///////////////////////////////////////////////////////
// Olivier ROUX
// MELOG - TP2 	Contenu.java
///////////////////////////////////////////////////////

import java.io.*;
import java.util.*;

// Contenu d'un fichier texte
class Contenu extends LinkedList<String>{	
	// Le nom du fichier texte initial (sans extension)
	protected String nom;
	
	// Constructeur : Afficher le contenu d'un fichier texte
	public Contenu(String texte) throws IOException	{
		nom = texte; 
		// Lecture du fichier texte
		Reader reader = new FileReader(texte+".txt");
		// Prise en compte d'une ligne
		BufferedReader in = new BufferedReader(reader);
		String ligne = in.readLine();
		while (ligne != null)	{
			// traitement de la ligne courante: decouper les mots separes par des delimiteurs
			String delimiteurs = "/0123456789°~^%$£*-_=+|#'.,;:?!() {}[]`<>\"\t\\<>«»";
			StringTokenizer st = new StringTokenizer (ligne, delimiteurs);
			while (st.hasMoreTokens())	{
				String mot = st.nextToken();
				mot=mot.toLowerCase();
				// Traitement du mot courant
				System.out.println(mot);	
				this.add((String)mot);  
            }
			// Lecture de la prochaine ligne 
			ligne = in.readLine();
		}
	}

	// Ecrire tous les mots dans un second fichier texte
	public void ecri() throws IOException	{
		Writer writer = new FileWriter(this.nom+"_modifie.txt");
		writer.write("############\n#\n# Contenu de "+this.nom+".txt :\n#\n#\t"+this.size()+" mots.\n#\n############\n\n");
		
		// Tous les mots de la liste constituee
		for(Object k : this)	{  // this est une LinkedList<String>
			writer.write(k+"\n");
			writer.flush();
		}
		writer.close();
	}
}
