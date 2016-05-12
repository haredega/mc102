DROP DATABASE IF EXISTS Lycee;
CREATE DATABASE Lycee;
USE Lycee;

CREATE TABLE Personne (
Personne_id int NOT NULL AUTO_INCREMENT PRIMARY KEY,
Personne_Nom VARCHAR(50),
Personne_Prenom VARCHAR(50),
Personne_Adresse VARCHAR(50),
Personne_Sexe char,
Personne_Tel VARCHAR(15),
Personne_Mail VARCHAR(50),
Personne_Signature BLOB,
CHECK (Personne_Sexe in ('M','F'))
);

CREATE TABLE Eleve (
Personne_id INT NOT NULL PRIMARY KEY,
Eleve_Redoublant int DEFAULT 0,
Eleve_DateArrivee DATE,
Eleve_DatePartie DATE,
Eleve_Commentaire TEXT,
Groupe_id int REFERENCES Groupe(Groupe_id),
Eleve_MotPasseNet int,
FOREIGN KEY (Personne_id) REFERENCES Personne(Personne_id)
        ON UPDATE CASCADE ON DELETE CASCADE
);


CREATE TABLE Enseignant(
Personne_id INT NOT NULL PRIMARY KEY,
Enseignant_Specialite VARCHAR(50),
Enseignant_DateArrivee DATE,
Enseignant_DatePartie DATE,
Enseignant_Commentaire TEXT,
Enseignant_MotPasseNet int,
FOREIGN KEY (Personne_id) REFERENCES Personne(Personne_id)
        ON UPDATE CASCADE ON DELETE CASCADE
);


CREATE TABLE Cours(
Cours_id int NOT NULL PRIMARY KEY,
Cours_Nom VARCHAR(50),
Cours_Commentaire TEXT,
Personne_id int NOT NULL REFERENCES Enseignant(Personne_id),
Groupe_id int REFERENCES Groupe(Groupe_id)
);


CREATE TABLE Notes(
Note_id int PRIMARY KEY,
Note int,
Notes_Commentaire TEXT,
Notes_DateMisAJour DATE,
Notes_DateEpreuve DATE,
Cours_id int REFERENCES Cours(Cours_id),
Personne_id int NOT NULL REFERENCES Eleve(Personne_id),
Trimestre_id VARCHAR(20) NOT NULL REFERENCES Trimestre(Trimestre_id)
);


CREATE TABLE Annee(
Annee_Scolaire VARCHAR(50),
Annee_Courante int,
Personne_id int REFERENCES Personne(Personne_id),
Annee_Logo BLOB,
PRIMARY KEY(Annee_Scolaire, Annee_Courante)
);


CREATE TABLE Filiere(
Filiere_type VARCHAR(50) PRIMARY KEY,
Filiere_Description TEXT
);


CREATE TABLE Parents(
Parents_Personne_id INT NOT NULL PRIMARY KEY,
Parents_Eleve_Personne_id int NOT NULL REFERENCES personne(Personne_id),
FOREIGN KEY (Parents_Personne_id) REFERENCES personne(Personne_id)
        ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Groupe(
Groupe_id int AUTO_INCREMENT PRIMARY KEY,
Groupe_Numero int,
Filiere_type VARCHAR(50) REFERENCES Filiere(Filiere_type),
Annee_Scolaire VARCHAR(50) REFERENCES Annee(Annee_Scolaire),
Annee_Courante int REFERENCES Annee(Annee_Courante),
ProfesseurPrincipal_Personne_id int REFERENCES personne(Personne_id)
);

CREATE TABLE Trimestre(
Trimestre_id VARCHAR(20) NOT NULL PRIMARY KEY,
Trimestre_Debut DATE,
Trimestre_Fin DATE,
Trimestre_DateBulletin DATE
);

CREATE TABLE avisprofesseurprincipal(
Avis_id int NOT NULL AUTO_INCREMENT PRIMARY KEY,
AvisPP TEXT,
Eleve_Personne_id int REFERENCES eleve(Personne_id),
ProfesseurPrincipal_Personne_id int REFERENCES groupe(Personne_id),
Trimestre_id varchar(10) REFERENCES trimestre(Trimestre_id)
);


/*Jeu d'essais*/

INSERT INTO filiere (Filiere_type)
    VALUES ('S'),('ES'),('L'),('STI');


INSERT INTO groupe (Groupe_Numero, Filiere_type, Annee_Scolaire, Annee_Courante, ProfesseurPrincipal_Personne_id)
    VALUES (1, NULL, 'seconde', 20122013, NULL),
    (2, NULL, 'seconde', 20122013, NULL),
    (3, NULL, 'seconde', 20122013, NULL),
    (4, NULL, 'seconde', 20122013, NULL),
    (5, NULL, 'seconde', 20122013, NULL),
    (6, NULL, 'seconde', 20122013, NULL),
    (1, 'S', 'premiere', 20122013, NULL),
    (2, 'S', 'premiere', 20122013, NULL),
    (3, 'S', 'premiere', 20122013, NULL),
    (1, 'ES', 'premiere', 20122013, NULL),
    (2, 'ES', 'premiere', 20122013, NULL),
    (3, 'ES', 'premiere', 20122013, NULL),
    (1, 'L', 'premiere', 20122013, NULL),
    (2, 'L', 'premiere', 20122013, NULL),
    (3, 'L', 'premiere', 20122013, NULL),
    (1, 'STI', 'premiere', 20122013, NULL),
    (2, 'STI', 'premiere', 20122013, NULL),
    (3, 'STI', 'premiere', 20122013, NULL);
    
INSERT INTO personne (Personne_id, Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES (1, 'Eherra', 'Erwan', 'M');

INSERT INTO eleve (Personne_id, Eleve_Redoublant, Eleve_DateArrivee, Groupe_id)
    VALUES (1, 0, '2013-06-21', 6);

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Kupinho', 'Gayxta', 'M');

INSERT INTO eleve (Personne_id, Eleve_Redoublant, Eleve_DateArrivee, Groupe_id)
    SELECT MAX(Personne_id), 0, '2013-06-24', 6 
    FROM personne
    ;

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Avatarcia', 'Heitor', 'M');

INSERT INTO eleve (Personne_id, Eleve_Redoublant, Eleve_DateArrivee, Groupe_id)
    SELECT MAX(Personne_id), 1, '2013-06-24', 4 
    FROM personne
    ;

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Michaud', 'Melle', 'F');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Français', '2010-06-24' 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Henrillin', 'Patricia', 'F');

INSERT INTO eleve (Personne_id, Eleve_Redoublant, Eleve_DateArrivee, Groupe_id)
    SELECT MAX(Personne_id), 0, '2012-08-21', 8 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Aubert', 'M', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Mathématiques', '2002-07-22' 
    FROM personne
    ;

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Parker', 'M', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Histoire Géographie', '2005-07-18' 
    FROM personne
    ;

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Eisenberg', 'M', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'TechScience', '2005-07-18' 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Gontzmann', 'Mme', 'F');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Allemand', '2009-07-19' 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Pablo', 'M', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Arts Plastiques', '2011-07-26' 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Murphy', 'M', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Ed physique et sportive', '2010-07-20' 
    FROM personne
    ;
    
INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Hautbois', 'Mme', 'F');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Education musicale', '2010-07-21' 
    FROM personne
    ;


INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe)
    VALUES ('Trummer', 'Mme', 'M');

INSERT INTO enseignant (Personne_id, Enseignant_Specialite, Enseignant_DateArrivee)
    SELECT MAX(Personne_id), 'Français', '2011-07-20' 
    FROM personne
    ;



SELECT personne.Personne_id, Personne_Nom, Personne_Prenom, Personne_Sexe, Eleve_Redoublant, Eleve_DateArrivee, Groupe_id
from personne
join eleve
on personne.Personne_id=eleve.Personne_id;

SELECT personne.Personne_id, Personne_Nom, Personne_Prenom, Personne_Sexe, Enseignant_Specialite, Enseignant_DateArrivee
from personne
join enseignant
on personne.Personne_id=enseignant.Personne_id;

UPDATE groupe
SET ProfesseurPrincipal_Personne_id=(SELECT Personne_id
FROM personne
WHERE Personne_Nom='Parker' AND Personne_Prenom='M')
WHERE Groupe_id=6;

SELECT Groupe_Numero, Filiere_type, Annee_Scolaire, Annee_Courante, ProfesseurPrincipal_Personne_id, Personne_Nom, Personne_Prenom
from groupe
join personne
on groupe.ProfesseurPrincipal_Personne_id=personne.Personne_id;

/*
SELECT Groupe_Numero, Filiere_type, Annee_Scolaire, Annee_Courante, ProfesseurPrincipal_Personne_id
from groupe;
*/

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe, Personne_Adresse)
    VALUES ('Eherra', 'Hervé', 'M','12 Boulevard Saint Guillaume - 29810 Ploumoguer');

INSERT INTO parents (Parents_Personne_id, Parents_Eleve_Personne_id)
    SELECT
    (SELECT MAX(personne.Personne_id) FROM personne),
    (SELECT Personne_id FROM personne
    WHERE Personne_Nom='Eherra' AND Personne_Prenom='Erwan');

INSERT INTO personne (Personne_Nom, Personne_Prenom, Personne_Sexe, Personne_Adresse)
    VALUES ('Eherra', 'Mme', 'M','12 Boulevard Saint Guillaume - 29810 Ploumoguer');

INSERT INTO parents (Parents_Personne_id, Parents_Eleve_Personne_id)
    SELECT
    (SELECT MAX(personne.Personne_id) FROM personne),
    (SELECT Personne_id FROM personne
    WHERE Personne_Nom='Eherra' AND Personne_Prenom='Erwan');

SELECT FILS.Personne_Nom, FILS.Personne_Prenom, FILS.Personne_Sexe , PAR.Personne_Nom, PAR.Personne_Prenom, PAR.Personne_Sexe
FROM parents
JOIN personne PAR ON (PAR.Personne_id = parents.Parents_Personne_id)
JOIN personne FILS ON (FILS.Personne_id = parents.Parents_Eleve_Personne_id)
ORDER BY FILS.Personne_Nom ASC;



INSERT INTO Annee (Annee_Logo) VALUES(LOAD_FILE('D:/Temp/logo.gif'));

