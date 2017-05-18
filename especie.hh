#ifndef ESPECIE_HH
#define ESPECIE_HH


#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

#include "individu.hh"

using namespace std;

/** @class Especie
    @brief Representa el conjunt de l'espècie que contindrà els individus dins
*/
class Especie {
    
private:

  /*Conjunt on tindrem els individus guardats*/
  map<string, Individu> especie;

  /*Dades en relació a la identitat genètica de l'especie*/
  int no_cromosomes;
  vector<int> tamany_gens;
  pair<int,int> tamany_sexuals;
  int part_comuna_sexuals;
    
public:
  //Constructores
  
  /** @brief Creadora per defecte. 
      \pre <em>Cert</em>
      \post El resultat es una especie sense individus
  */
  Especie();
  /* Pre: Cert */
  /* Post: Es crea un nou objecte de tipus especie*/

  // Destructora: esborra automaticament els objectes locals en sortir
  // d'un ambit de visibilitat
  

//--------------------------------------------------------------------------------------------------------

  //Modificadores

  /** @brief Modificadora del conjunt, n'afegeix un individu
      \pre <em>Cert</em>
      \post El conjunt espècie conté el nou individu
  */
  void afegir(Individu individu);

  /** @brief Consultora del nom
      \pre <em>Cert</em>
      \post Afegeix l'individu fruit de la reproduccio entre els individus indicats al canal standart d'entrada
  */
  pair<string,bool> reproduir_individus(string nom1, string nom2);

  /** @brief Modificadora del tamany dels gens de l'especie
      \pre <em>Cert</em>
      \post Queda determinat el numero de parells de cromosomes de l'especie
  */
  void afegirTamanyGens(vector<int> tamany_gens);

  /** @brief Modificadora del numero de cromosomes de l'especie
      \pre <em>Cert</em>
      \post Queda determinat el numero de parells de cromosomes de l'especie
  */
  void afegirNumeroCromosomes(int no_cromosomes);

  /** @brief Modificadora del numero de cromosomes sexuals de l'especie
      \pre <em>Cert</em>
      \post Queda determinat el tamany dels cromosomes sexuals de l'especie
  */
  void afegirTamanySexuals(pair<int,int> tamany_sexuals);

  /** @brief Modificadora del numero de gens de la part comuna dels cromosomes sexuals
      \pre <em>Cert</em>
      \post Queda determinada la llargada de la part comuna dels cromosomes sexuals de l'especie
  */
  void afegirPartComunaSexuals(int part_comuna_sexuals);

//--------------------------------------------------------------------------------------------------------

  //Consultores

  /** @brief Consultora del numero de cromosomes de l'especie
      \pre <em>Cert</em>
      \post Retorna el numero de cromosomes de l'especie
  */
  int n_cromosomes();

  /** @brief Consulora per determinar si dos individus es poden reproduir entre ells
      \pre Els dos indivudus estàn al conjunt
      \post Retorna false si existeix parentesc d'ascendència o bé son gemrans entre ells
  */
  bool es_possible_reproduccio(Individu ind1, Individu ind2);
 

   /** @brief Consulta si un idividu està al conjunt
      \pre <em>Cert</em>
      \post Retorna cert si existeix un individu amb el nom nom al conjunt, fals en cas contrari
  */
  bool esta_conjunt(string nom);

  /** @brief Consultora del numero d'alels d'un cromosoma x
      \pre 0 => no_cromosoma < N 
      \post etorna el numero d'alèls que conté
  */
  vector<int> consultar_tamany_cromosoma();

  /** @brief Consultora del numero d'alels del cromosoma sexual Y
      \pre <em>Cert</em>
      \post Retorna el numero d'alèls que conté el cromosoma Y
  */
  int tamany_cromosoma_y();

  /** @brief Consultora del numero d'alels del cromosoma sexual X
      \pre <em>Cert</em>
      \post Retorna el numero d'alèls que conté el cromosoma X
  */
  int tamany_cromosoma_x();

  /** @brief Consultora del tamany del la part comuna dels cromosomes sexuals
      \pre <em>Cert</em>
      \post Retorna un int amb el punt on arriba la part comuna dels sexuals
  */
  int consultar_partcomuna_sex();

  /** @brief Donat un nom en format string ens retorna l'objecte individu asociat
      \pre Nom es el nom d'un individu que pertany al conjunt
      \post Retorna l'objecte individu asociat al nom indicat
  */
  Individu get_individu(string nom);
    
  //--------------------------------------------------------------------------------------------------------

  /** @brief Operació de lectura
      \pre Hi han preparats al canal standart totes les dades realcionades amb l'especie necesàries
      \post S'afegeix a l'especie les dades inicials
  */
  void llegir_dades_especie();
  
  /** @brief Operació de lectura
      \pre Hi han preparats al canal standart totes les dades dels primers individus
      \post S'afegeix a l'especie els individus "originals"
  */
  void llegir_poblacio_inicial();

  /** @brief Operació d'escriptura
      \pre Cert
      \post S'imprimeixen al canal stadart de sortida les dades de tots els individus de l'especie
  */
  void escriure();
   
  /** @brief Operació d'escriptura
      \pre Cert
      \post S'imprimeixen al canal stadart de sortida l'arbre genalogic del individu donat completat
  */
  void completar_arbre_genealogic(string nom);

};
#endif
