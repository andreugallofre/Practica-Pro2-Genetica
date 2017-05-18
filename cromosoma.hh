#ifndef CROMOSOMA_HH
#define CROMOSOMA_HH

#include <list>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Cromosoma {
    
private: 
  
  bool tipus; //True => És cromosomoa sexual, False => És cromosoma normal
  pair< vector<bool>,vector<bool> > gens; //Conté el parell de 

public:
  //Constructores
  
  /** @brief Creadora per defecte. 
      \pre <em>Cert</em>
      \post El resultat es un conjunt de cromosomes sense gens
  */
  Cromosoma();
    

  //--------------------------------------------------------------------------------------------------------

  void encreuar_cromosomes(Cromosoma cromo1, Cromosoma cromo2);

  bool encreuar_cromosoma_sexual(Cromosoma mare, Cromosoma pare, int part_comuna_sexual);

  //Modificadores

  /** @brief Modificadora dels gens, n'afegeix el contigunt
      \pre <em>Cert</em>
      \post L'objecte conté els gens
  */
  void afegir_cromosomes(pair< vector<bool>,vector<bool> > gens);

  void afegir_tipus(bool es_sexual);


//--------------------------------------------------------------------------------------------------------

  //Consultores
  
  /** @brief Consultora del numero de cromosomes de l'especie
      \pre <em>Cert</em>
      \post Retorna un pair amb els vectors que contenen les dades genètiques del parell de cromosomes
  */
  pair< vector<bool>,vector<bool> > consultar_valors();

  /** @brief Consultora del tipus de cromosoma
      \pre <em>Cert</em>
      \post Retorna true si es tracata d'un cromosoma sexual
  */
  bool consultar_tipus();

  //--------------------------------------------------------------------------------------------------------
  // Entrada i sortida de dades

  /** @brief Operació de lectura
      \pre Hi han preparats al canal standart totes les dades realcionades amb el cromosoma necesaries
      \post Es genera un objecte de tipus cromosoma amb les dades introduïdes pel canal standart
  */
  void llegir_cromosoma(int tamany);
  void llegir_cromosoma_sexual(int tamany_x, int tamany_y);

  void escriure_cromosoma_sexual(int tamany_x, int tamany_y, bool sexe);
  void escriure_cromosoma(int tamany, int numero);

    
};
#endif
