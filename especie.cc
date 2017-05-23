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

void Especie::completar_arbre_helper(Individu individuo, list<string> &arbre) {

 	arbre.push_back(individuo.consultar_pares().first);
 
 	if (esta_conjunt(individuo.consultar_pares().first)) completar_arbre_helper(get_individu(individuo.consultar_pares().first), arbre);
 		
 	arbre.push_back(individuo.consultar_pares().second);
 	if (esta_conjunt(individuo.consultar_pares().second)) completar_arbre_helper(get_individu(individuo.consultar_pares().second), arbre);

}


pair<bool,string> Especie::completar_arbre_i(list<string> &x, list<string> &arbre, list<string> &final, string nom)
{

	string part_arbre;
	pair<bool, string> res(true,"");
	

	cin >> part_arbre;

	while (part_arbre != "escribir_poblacion" && part_arbre != "completar_arbol_genealogico" && part_arbre != "escribir_arbol_genealogico" && part_arbre != "escribir_genotipo" && part_arbre != "reproduccion_sexual" && part_arbre != "anadir_individuo" && part_arbre != "acabar")
	{
		x.push_back(part_arbre);
		cin >> part_arbre;
	}

	cerr << "Command " << part_arbre << endl;

	res.second = part_arbre;

	completar_arbre_helper(get_individu(nom), arbre);

	list<string>::iterator it = x.begin();
	list<string>::iterator it2 = arbre.begin();
	list<string>::iterator aux = arbre.end();

	cerr << "  arbre entrat:"<< endl << "   ";
	for(auto i : x) cerr << " " << i;
	cerr << endl;

	cerr << " arbre individu:" << endl << " ";
	cerr << "  ";
	for(auto i : arbre) cerr << " " << i;
	cerr << endl;
 	
	bool condition = false;

	while(it != x.end() && it2 != arbre.end())
	{
		cerr << "iter while " << endl;
		if((*it) == (*it2)){
			cerr << "it = it2" << endl;
			if(aux != it2){
				final.push_back(*it2);
				it++;
				it2++;
				condition = false;
			}
			else{
				cerr << "Error auxiliar" << endl;
				res.first = false;
				return res;
			}

		} 
		else if ((*it) == "$"){
			cerr << "it = $" << endl;
			aux = it2;
			condition = true;
			while(it != x.end() && (*it) == "$") it++;
			if(it == x.end())
			{
				while(it2 != arbre.end()){
					cerr << "Arbre2 not end" << endl;
					if((*it2) != "$"){
						final.push_back("*" + (*it2) + "*");
						it2++;
					}
					else{
						final.push_back((*it2));
						it2++;
					}
				}
			}
		}
		else if (it2 != arbre.end() && condition)
		{
			cerr << "it2 not end i condicio" << endl;
			if((*it2) != "$"){
				final.push_back("*" + (*it2) + "*");
				it2++;
			}
			else{
				final.push_back((*it2));
				it2++;
			}
		}
		else if((*it) != "$" && (*it2) == "$")
		{
			cerr << "Error $ i != $" << endl;
			res.first = false;
			return res;
		}
		else{
			cerr << "Altres errors" << endl;
			res.first = false;
			return res;
		} 
	}

	if((it != x.end() && it2 == arbre.end()) || (it2 != arbre.end() && it == x.end()))
	{
		res.first = false;
		return res;
	}

	return res;

}

string Especie::completar_arbre_genealogic(string nom)
{
	string command, part_arbre = "";
	Individu ind1;
	list<string> x, arbre, final;
	
	if(not esta_conjunt(nom))
	{
		cout << "  no es arbol parcial" << endl;
	}
	else{
		x.push_back(nom);
		arbre.push_back(nom);

		pair<bool,string> test = completar_arbre_i(x, arbre, final, nom);

		if(test.first){
			cout << " ";
			for(auto i : final) cout << " " << i;
			cout << endl;
			command	= test.second;
		}
		else{
			command	= test.second;
			cout << "  no es arbol parcial" << endl;
		}
	}

	return command;
	}


void Especie::escriure_arbre(map<int, list<Individu>> arbre)
{
	for(auto elem : arbre)
	{
		list<Individu> individus = elem.second;

		cout << "  Nivel " << elem.first << ":";
		for (auto v : individus){
        	cout << " " << v.consultar_nom();
		}
		
		cout << endl; 
	}
}

  void Especie::escriure_arbre_genealogic(string nom)
  {
	Individu ind1;
	int count = 0;
	map<int, list<Individu>> arbre;

	ind1 = get_individu(nom); 
	esprint(ind1, count, arbre);

	escriure_arbre(arbre);

  }


void Especie::esprint(Individu individuo , int count , map<int, list<Individu>> &arbre) {
 	
 	list<Individu> nivel = arbre[count];

 	nivel.push_back(individuo);

 	arbre[count] = nivel;

 	if (individuo.consultar_pares().first != "$" && individuo.consultar_pares().second != "$")
 	{
 		count++;
 		esprint(get_individu(individuo.consultar_pares().first), count, arbre);
 		esprint(get_individu(individuo.consultar_pares().second), count, arbre);
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

bool Especie::es_antecesor(string nom, Individu ind){
	list<string> x;

	completar_arbre_helper(ind, x);

	for(auto i : x) if (i == nom) return true;

	return false;
}

bool Especie::es_possible_reproduccio(Individu ind1, Individu ind2)
{
		bool res = true;

		//Pares dels individus
		pair<string,string> pares_ind1, pares_ind2;
		
		//Nom dels individus
		string nom_ind1 = ind1.consultar_nom();
		string nom_ind2 = ind2.consultar_nom();

		//Agafem els noms dels pares
		pares_ind1 = ind1.consultar_pares();
		pares_ind2 = ind2.consultar_pares();

		//Comprovem que el sexe dels pares sigui correcte
		if (ind1.consultar_sexe() == true || ind2.consultar_sexe() == false)
		{
			cerr << "Fallo per sexe" << " MARE:" << nom_ind1 << " PARE:" << nom_ind2 <<endl;
			res = false;
		}
		//Mirem que els pares no sigun buits
		else if(pares_ind1.first != "$" && pares_ind2.first != "$"){
			if (pares_ind1.first == pares_ind2.first){
				cerr << "Mare 1 = Mare 2 " << pares_ind1.first << " " << pares_ind2.first << endl;
				res = false;
			}
			if (pares_ind1.second == pares_ind2.second){
				cerr << " Pare 1 = Pare 2 " << pares_ind1.second << " " << pares_ind2.second << endl;
				res = false;
			}
		}
		else if(es_antecesor(nom_ind2, ind1) || es_antecesor(nom_ind1, ind2))
		{
			cerr << "Fallada per antecesor" << endl;
			res = false;
		}
		if(not res) cout << "  no es posible reproduccion" << endl;

		return res;
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

void Especie::reproduir_individus(string nom1, string nom2, string nom3)
{

	Individu mare, pare;

	Individu fill;

	cout << "reproduccion_sexual " << nom1 << " " << nom2 << " " << nom3 << endl;

	if(not esta_conjunt(nom1)) cout << "  error" << endl;
	else if (not esta_conjunt(nom2)) cout << "  error" << endl;
	else if(esta_conjunt(nom3)) cout << "  error" << endl;
	else{
		mare = get_individu(nom1);
		pare = get_individu(nom2);

		if (es_possible_reproduccio(mare, pare))
		{

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
	}
	
	
}


