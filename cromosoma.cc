#include "cromosoma.hh"

Cromosoma::Cromosoma()
{
  bool tipus = false; //True => És cromosomoa sexual, False => És cromosoma normal
  pair< vector<bool>,vector<bool> > gens; //Conté el parell de 

  (void)tipus;
}

void Cromosoma::encreuar_cromosomes(Cromosoma cromo1, Cromosoma cromo2)
{

  //Variables necessàries

  int mare, pare, tall;

  //Guardem els vectors dels cromosomes que ens donen, i creem un de nou que serà el resultat
  //d'encreuarlos

  pair< vector<bool>,vector<bool> > a = cromo1.consultar_valors();
  pair< vector<bool>,vector<bool> > b = cromo2.consultar_valors();

  pair< vector<bool>,vector<bool> > c;

  //vectors de boleans auxiliars

  vector<bool> v_mare;
  vector<bool> v_pare;

  //agafem les dades necessàries

  cin >> mare >> pare >> tall;

  //Seleccionem el cromosoma que toca de cada parell

  if(mare) v_mare = a.second;
  else v_mare = a.first;

  if(pare) v_pare = b.second;
  else v_pare = b.first;

  vector<bool> aux1(v_mare.size());
  vector<bool> aux2(v_pare.size());

  //Encreuem com ens indiqui el punt de tall

  for(int i=0; i< tall;i++)
  {
    aux1[i] = v_mare[i];
    aux2[i] = v_pare[i];
  } 
  for (int i=tall; i< v_pare.size() ; i++)
  {
    aux1[i] = v_pare[i];
    aux2[i] = v_mare[i];
  }

  //Afegim les dades al cromosoma que encreuem i retornem

  c.first = aux1;
  c.second = aux2;

  gens = c;
}

bool Cromosoma::encreuar_cromosoma_sexual(Cromosoma mare, Cromosoma pare, int part_comuna_sexuals)
{
  int bmare, bpare, tall;
  bool sexe = false;

  //Guardem els vectors dels cromosomes que ens donen, i creem un de nou que serà el resultat
  //d'encreuarlos

  pair< vector<bool>,vector<bool> > a = mare.consultar_valors();
  pair< vector<bool>,vector<bool> > b = pare.consultar_valors();

  pair< vector<bool>,vector<bool> > c;

  //vectors de boleans auxiliars

  vector<bool> v_mare;
  vector<bool> v_pare;

  //agafem les dades necessàries

  cin >> bmare >> bpare >> tall;

  //Seleccionem el cromosoma que toca de cada parell

  if(bmare) v_mare = a.second;
  else v_mare = a.first;

  if(bpare){
    v_pare = b.second;
    sexe = true;
  } 
  else v_pare = b.first;
 
  vector<bool> aux1(v_mare.size());
  vector<bool> aux2(v_pare.size());

  //Part que manté al inici

  for(int i=0; i< tall;i++)
  {
    aux1[i] = v_mare[i];
    aux2[i] = v_pare[i];
  } 
  
  //Part encreuada

  for (int i=tall; i < part_comuna_sexuals; i++)
  {
    aux1[i] = v_pare[i];
    aux2[i] = v_mare[i];
  }
  
  //Part que manté final

  for (int i = part_comuna_sexuals; i < v_mare.size(); i++)
  {
    aux1[i] = v_mare[i];
  }
  for (int i = part_comuna_sexuals; i < v_pare.size(); i++)
  {
    aux2[i] = v_pare[i];
  }

  c.first = aux1;
  c.second = aux2;

  gens = c;
  tipus = true;

  return sexe;
}

void Cromosoma::afegir_cromosomes(pair< vector<bool>,vector<bool> > gens)
{
  this->gens = gens;
}

pair< vector<bool>,vector<bool> > Cromosoma::consultar_valors()
{
  return gens;
}

bool Cromosoma::consultar_tipus()
{
  return tipus;
}

void Cromosoma::afegir_tipus(bool es_sexual)
{
  this->tipus = es_sexual;
}

//Llegeix els alèls dels cromosomes sexuals d'un individu
void Cromosoma::llegir_cromosoma_sexual(int tamany1, int tamany2)
{

  vector<bool> a(tamany1);
  vector<bool> b(tamany2);


  for (int i = 0; i < tamany1; i++)
  {
    int x;
    cin >> x;

    a[i] = x;

   /* cout << "gen a[i] " << i << " " << x;
    cout << endl;*/
  } 

  for (int i = 0; i < tamany2; i++)
  {
    int x;
    cin >> x;
    b[i] = x;

    /*cout << "gen b[i] " << i << " " << x;
    cout << endl;*/
  }

  gens.first = a;
  gens.second = b;

}

void Cromosoma::llegir_cromosoma(int tamany_cromosoma)
{

  vector<bool> a(tamany_cromosoma);
  vector<bool> b(tamany_cromosoma);

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < tamany_cromosoma; j++)
    {
      int x;
      cin >> x; 
      if (i == 0) a[j] = x;
      else b[j] = x;
    }
  }

  gens.first = a;
  gens.second = b;
}

void Cromosoma::escriure_cromosoma(int tamany_cromosoma, int num)
{
  cout << "  " << num << ".1:";
  for (int i=0; i<tamany_cromosoma; i++) cout << " " << gens.first[i];
  cout << endl;
  cout << "  " << num << ".2:";
  for (int i=0; i<tamany_cromosoma; i++) cout << " " << gens.second[i];
  cout << endl;

}

void Cromosoma::escriure_cromosoma_sexual(int tamany1, int tamany2, bool sexe)
{
  if (sexe)
  {
    cout << "  X:";
    for (int i = 0; i < tamany1; i++) cout << " " << gens.first[i];
    cout << endl;
    
    cout << "  Y:";
    for (int i = 0; i < tamany2; i++) cout << " " << gens.second[i];
    cout << endl;
  }
  else 
  {
    cout << "  X:";
    for (int i = 0; i < tamany2; i++) cout << " " << gens.first[i];
    cout << endl;
    
    cout << "  X:";
    for (int i = 0; i < tamany2; i++) cout << " " << gens.second[i];
    cout << endl;
  }

}