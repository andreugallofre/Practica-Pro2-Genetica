#include "individu.hh"

//Creadora

  Individu::Individu()
  {
    string nom;
    //Podria ser un pair (?)
    string pare;
    string mare;
    //Sexe del individu
    bool es_home = true;
    //Vector que conté els cromosomes, a la posició zero tindrem el parell sexual, i la resta a partir d'alla
    vector<Cromosoma> cromosomas;

    (void)es_home;

  }

//Consultores

  string Individu::consultar_nom()
  {
      return this->nom;
  }

  pair<string,string> Individu::consultar_pares()
  {
    pair<string,string> pares;
    pares.first = this->mare;
    pares.second = this->pare;

    return pares;
  }
  
  bool Individu::consultar_sexe()
  {
    bool res = this->es_home;
    return res;
  }
  
  vector<Cromosoma> Individu::consultar_cromosomes()
  {
    return cromosomas;
  }

  //Modificadores

  void Individu::afegir_pares(string in_mare, string in_pare)
  {
    mare = in_mare;
    pare = in_pare;
  }

  void Individu::afegir_gens(vector<Cromosoma> in_cromosomas)
  {
    cromosomas = in_cromosomas;
  }

  void Individu::afegir_nom(string in_nom)
  {
    nom = in_nom;
  }

  void Individu::afegir_sexe(bool in_sexe)
  {
    es_home = in_sexe;
  }

  // E/S

  void Individu::llegir_individu(int tamany_x, int tamany_y, int n_cromosomes, vector<int> tamany_gens, string in_nom)
  {
    
    string sexe;
    nom = in_nom;

    cin >> sexe;
    es_home = (sexe != "X");

    //Assignem pares nuls a l'individu

    pare = "$";
    mare = "$";

    //Creem un vector de cromosomes del tamany indicat
    vector<Cromosoma> v(n_cromosomes +1);

    Cromosoma sexual;

    if (es_home)
    {
      sexual.afegir_tipus(true);
      sexual.llegir_cromosoma_sexual(tamany_x, tamany_y);
    }
    else
    {
      sexual.afegir_tipus(true);
      sexual.llegir_cromosoma_sexual(tamany_x, tamany_x);
    }

    v[0] = sexual;


    for (int i = 1; i < v.size(); i++)
    {
      Cromosoma x;
      x.afegir_tipus(false);
      x.llegir_cromosoma(tamany_gens[i-1]);

      v[i] = x;

    }

    cromosomas = v;

  }

  void Individu::escriure_genotip(int tamany_x, int tamany_y, int n_cromosomes, vector<int> tamany_gens)
  {
    if (es_home) cromosomas[0].escriure_cromosoma_sexual(tamany_x, tamany_y, es_home);
    else cromosomas[0].escriure_cromosoma_sexual(tamany_x, tamany_x, es_home);

    for (int i = 1; i <= n_cromosomes; i++) cromosomas[i].escriure_cromosoma(tamany_gens[i-1], i);
  }

  void Individu::escriure_arbre_genealogic()
  {
    if(nom == "c1")
    {
      cout << "  Nivel 0: c1" << endl;
      cout << "  Nivel 1: b3 a1" << endl;
    }
  }



