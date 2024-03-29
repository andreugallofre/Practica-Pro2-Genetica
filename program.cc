#include <iostream>
#include <string>
#include <map>

#include "especie.hh"
#include "individu.hh"

using namespace std;

int main() 
{

	string command = "";

	Especie especie;

	especie.llegir_dades_especie(); //Guardem les dades principals de l'especie
	especie.llegir_poblacio_inicial(); //Introduim al conjunt les dades de la població inicial

	cin >> command;

	while(command != "acabar")
	{
		if (command == "anadir_individuo")
		{
			string nom;
			cin >> nom;

			cout << "anadir_individuo " << nom << endl;
			if(not especie.esta_conjunt(nom)){
				Individu ind1;
				ind1.llegir_individu(especie.tamany_cromosoma_y(), especie.tamany_cromosoma_x(), especie.n_cromosomes(), especie.consultar_tamany_cromosoma(), nom);
				especie.afegir(ind1);
				
			}
			else cout << "  error" << endl;

			cin >> command;
		}

		else if (command == "escribir_poblacion")
		{
			cout << "escribir_poblacion" << endl;
			especie.escriure();

			cin >> command;
		}

		else if (command == "reproduccion_sexual")
		{
			string nom1, nom2, nom3;
			cin >> nom1 >> nom2 >> nom3;
			especie.reproduir_individus(nom1, nom2, nom3);

			cin >> command;
		}

		else if (command == "escribir_genotipo")
		{
			string nom;
			cin >> nom;

			cout << "escribir_genotipo " << nom << endl;
			
			if (especie.esta_conjunt(nom)){
				Individu ind1;
				ind1 = especie.get_individu(nom);
				ind1.escriure_genotip(especie.tamany_cromosoma_y(), especie.tamany_cromosoma_x(), especie.n_cromosomes(), especie.consultar_tamany_cromosoma());
			}  
			//Obtenim l'individu a partir d'un nom i n'imprimim el genotip
			else cout << "  error" << endl;

			cin >> command;
		}

		else if (command == "escribir_arbol_genealogico")
		{
			string nom;
			cin >> nom;

			cout << "escribir_arbol_genealogico " << nom << endl;
			if(especie.esta_conjunt(nom)){
				especie.escriure_arbre_genealogic(nom);
			}
			else cout << "  error" << endl;

			cin >> command;
		}
		
		else if (command == "completar_arbol_genealogico")
		{
			string nom;
			cin >> nom;
			cout << "completar_arbol_genealogico " << nom << endl;
			command = especie.completar_arbre_genealogic(nom);
		}
		else cin >> command;
		
	}

	cout << "acabar" << endl;
}