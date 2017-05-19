#ifndef INDIVIDU_HH
#define INDIVIDU_HH


#include <list> //Pendent de definir (?)
#include <vector>
#include <iostream>
#include <string>
#include <utility>

#include "cromosoma.hh"

using namespace std;

/** @class Individu
    @brief Representa un individu de l'especie amb atributs nom, pare, mare, sexe i els 
    seus cromosomes
*/
class Individu {
    
private:
  //Nom del individu
  string nom;
  
  //Podria ser un pair (?)
  string pare;
  string mare;
  
  //Sexe del individu
  bool es_home;

  //Vector que conté els cromosomes, a la posició zero tindrem el parell sexual, i la resta a partir d'alla
  vector<Cromosoma> cromosomas;
    
public:
  //Constructores

  /** @brief Creadora per defecte. 
      \pre <em>Cert</em>
      \post El resultat es un individu amb pares nuls, conjunt de gens buit i sexe home
  */
  Individu();  

  /** @brief Creadora per defecte. 
      \pre No existeix un individu amb el nom triat al conjunt
      \post el resultat es un individu amb nom = this.nom i la resta de camps nuls
  */
  Individu(string nom);

  /** @brief Creadora per defecte. 
      \pre Pare i mare existeixen com a individus, la llista de cromosomes conté un parell de cromosomes sexuals
      \post El resultat es un individu amb nom, pare, mare i cromosomes
  */
  Individu(string nom, string pare, string mare, vector<Cromosoma> cromosomas);
  
  /** @brief Creadora per defecte. 
      \pre No existeix un individu amb el nom triat al conjunt, i el llistat de cromosomes conté un parell de cromosomes sexuals
      \post el resultat es un individu amb nom, pare, mare i cromosomes
  */  
  Individu(string nom, list<Cromosoma> cromosomas);

  // Destructora: esborra automaticament els objectes locals en sortir
  // d'un ambit de visibilitat


  //--------------------------------------------------------------------------------------------------------

  //Consultores

  /** @brief Consultora del nom
      \pre <em>Cert</em>
      \post retorna el nom del paràmetre implicit
  */
  string consultar_nom();

  /** @brief Consultora del nom
      \pre <em>Cert</em>
      \post Retorna un pair amb el nom del pare al first i el nom de la mare al second del paràmetre implicit
  */
  pair<string,string> consultar_pares();
  
  /** @brief Consultora del nom
      \pre <em>Cert</em>
      \post Retorna un booleà, conté true si es home, false si es dona 
  */
  bool consultar_sexe();
  
  /** @brief Consultora del nom
      \pre <em>Cert</em>
      \post Retorna una llista amb els cromosomoes sexuals a la primera posició i després la resta 
  */
  vector<Cromosoma> consultar_cromosomes();

  //--------------------------------------------------------------------------------------------------------

  //Modificadores

  void afegir_pares(string mare, string pare);

  void afegir_gens(vector<Cromosoma> cromosomas);

  void afegir_nom(string nom);

  void afegir_sexe(bool sexe);

  //Entrada_Sortida
  /** @brief Operació de lectura
      \pre Hi han preparats al canal standart totes les dades realcionades amb l'indiviud necesàries
      \post Es genera un objecte de tipus individu amb les dades introduïdes pel canal standart
  */
  void llegir_individu(int tamany_x, int tamany_y, int no_cromosomes, vector<int> tamany_sexuals, string nom);

  /** @brief Operació d'escriptura
      \pre Cert
      \post S'imprimeixen al canal stadart de sortida les dades de l'individu
  */
  void escriure_genotip(int tamany_x, int tamany_y, int n_cromosomes, vector<int> tamany_gens);
    
};
#endif
