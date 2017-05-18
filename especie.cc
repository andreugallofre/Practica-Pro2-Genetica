#include "especie.hh"

Especie::Especie()
{

  map<string, Individu> especie;
  /*Dades en relació a la identitat genètica de l'especie*/
  int no_cromosomes;
  vector<int> tamany_gens;
  pair<int,int> tamany_sexuals;
  int part_comuna_sexuals;

  (void)part_comuna_sexuals;
  (void)no_cromosomes;

}

/* TODO */

void Especie::completar_arbre_genealogic(string nom)
{
	if (nom == "d1") cout << "  no es arbol parcial" << endl;
	if (nom == "c1") cout << "  c1 *b3* $ $ *a1* $ $" << endl;
	if (nom == "e1")
	{
		string x;
		cin >> x;
		if (x == "$") cout << "  no es arbol parcial" << endl;
		else cout << "  e1 c1 *b3* $ $ *a1* $ $ *m1* $ $" << endl;
	}
}

 void get_arbre(int nivell, string pare, string mare)
  {
    if (pare != '$')
      Individu pare = get_individu(pare);
  	  Individu mare = get_individu(mare);
  }

  void Especie::escriure_arbre_genealogic(string nom)
  {
    int n = 2;
    cout << "  Nivel 0: " << nom;

    Individu ind1 = get_individu(nom);

    if (ind1.consultar_pares().first != "$")
    {
    	get_arbre(pare, mare);
    }




  }

/*END TODO */  


void Especie::llegir_dades_especie()
{
	int x,y;

	cin >> x;
	no_cromosomes = x;

	vector<int> tamany_gens_x(x);
	tamany_gens = tamany_gens_x;

	cin >> x;
	part_comuna_sexuals = x;

	for (int i = 0; i < no_cromosomes; i++)
	{
		cin >> x;
		tamany_gens[i] = x;
	}

	cin >> x >> y;

	tamany_sexuals.first = x;
	tamany_sexuals.second = y;
}

void Especie::llegir_poblacio_inicial()
{
	int no_int_inicials;
	cin >> no_int_inicials;

	for(int i = 0; i < no_int_inicials; i++)
	{
		string nom;
		cin >> nom;
		Individu individu;
		individu.llegir_individu(tamany_sexuals.first, tamany_sexuals.second, no_cromosomes, tamany_gens, nom);

		afegir(individu);
	}
}

void Especie::escriure()
{
	map<string,Individu>::iterator it = especie.begin();

	while (it != especie.end())
	{
		Individu ind = it->second;
		
		pair<string,string> pares = ind.consultar_pares();
		string nom = ind.consultar_nom();
		string sexe; 
	
		if (ind.consultar_sexe()) sexe = "XY";
		else sexe = "XX";

		cout << "  " << nom << " " << sexe << " (" << pares.first << "," << pares.second << ")" << endl; 

		it++;
	}
}





//		CONSULTORES
//-------------------------------------------------------------------

int Especie::n_cromosomes()
{
	return no_cromosomes;
}

Individu Especie::get_individu(string nom)
{
	Individu ind = especie[nom];
	return ind;
}

bool Especie::es_possible_reproduccio(Individu ind1, Individu ind2)
{
		pair<string,string> pares_ind1, pares_ind2;
		
		string nom_ind1 = ind1.consultar_nom();
		string nom_ind2 = ind2.consultar_nom();

		pares_ind1 = ind1.consultar_pares();
		pares_ind2 = ind2.consultar_pares();

		if (ind1.consultar_sexe() == ind2.consultar_sexe())
		{
			return false;
		}
		else if(nom_ind1 == pares_ind2.first || nom_ind1 == pares_ind2.second || pares_ind1.second == nom_ind2 || pares_ind1.second == nom_ind2)
		{		
			return false;
		}
		else
		{
			return true;
		}
}

bool Especie::esta_conjunt(string nom)
{
	if ( especie.find(nom) == especie.end() ) 
	{
	  return false;
	} 
	else 
	{
	  return true;
	}
}

vector<int> Especie::consultar_tamany_cromosoma()
{
	return tamany_gens;
}

int Especie::tamany_cromosoma_y()
{	
	return tamany_sexuals.first;
}

int Especie::tamany_cromosoma_x()
{
	return tamany_sexuals.second;
}

int Especie::consultar_partcomuna_sex()
{
	return part_comuna_sexuals;
}

//---------------------------------------------------------------------------------------

void Especie::afegirTamanyGens(vector<int> tamany_gens)
{
	this->tamany_gens = tamany_gens;
}

void Especie::afegirNumeroCromosomes(int no_cromosomes)
{
	this->no_cromosomes = no_cromosomes;
}

void Especie::afegirTamanySexuals(pair<int,int> tamany_sexuals)
{
	this->tamany_sexuals = tamany_sexuals;
}

void Especie::afegirPartComunaSexuals(int part_comuna_sexuals)
{
	this->part_comuna_sexuals = part_comuna_sexuals;
}

void Especie::afegir(Individu ind1)
{
	especie[ind1.consultar_nom()] = ind1;
}

pair<string,bool> Especie::reproduir_individus(string nom1, string nom2)
{
	string nom3;
	bool possible;
	Individu mare, pare;

	Individu fill;

	cin >> nom3;

	mare = get_individu(nom1);
	pare = get_individu(nom2);

	if (not esta_conjunt(nom3) && es_possible_reproduccio(mare, pare))
	{
		possible = true;

		fill.afegir_pares(nom2, nom1);
		fill.afegir_nom(nom3);

		vector<Cromosoma> vmare = mare.consultar_cromosomes();
		vector<Cromosoma> vpare = pare.consultar_cromosomes();

		vector<Cromosoma> resultat(vpare.size());

		for(int i = 0; i<vpare.size();i++)
		{

			Cromosoma auxiliar;

			if (i == 0)
			{
				bool sexe = auxiliar.encreuar_cromosoma_sexual(vmare[i], vpare[i], part_comuna_sexuals);
				resultat[i] = auxiliar;
				fill.afegir_sexe(sexe);
			} 
			else
			{
				auxiliar.encreuar_cromosomes(vmare[i],vpare[i]);
				resultat[i] = auxiliar;
			}

		}

		fill.afegir_gens(resultat);

		this->especie[nom3] = fill;

	}
	else possible = false;

	return pair<string,bool> (nom3,possible);
}


