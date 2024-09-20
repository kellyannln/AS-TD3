/**
* \file Liste.h
 * \brief Classe définissant le type abstrait Liste.
 * \author Kelly-Ann Lareau-Naud
 * \date septembre 2024
 *
 * Implémentation dans une liste simplement chaînée circulaire.
 */

#include "Liste.h"
#include "ContratException.h"
using namespace lab03;

template<typename T>
Liste<T>::Liste() : m_dernier(nullptr), m_cardinalite(0){}

template<typename T>
Liste<T>::Liste(const Liste& p_liste) : m_dernier(nullptr), m_cardinalite(0)
{
 PRECONDITION(!p_liste.estVide());

 elem elementCourant = p_liste.m_dernier->m_suivant;
 do
 {
  ajouter(elementCourant->m_el, m_cardinalite);
  elementCourant = elementCourant->m_suivant;
 } while (elementCourant != p_liste.m_dernier->suivant );

 INVARIANTS();
}

template<typename T>
Liste<T>::~Liste()
{
 detruire();
}

template<typename T>
const Liste<T> & Liste<T>::operator =(const Liste<T> & p_liste)
{
 if (this != &p_liste)
 {
  detruire();
  elem elementCourant = p_liste.m_dernier->m_suivant;
  do
  {
   ajouter(elementCourant->m_el, m_cardinalite);
   elementCourant = elementCourant->m_suivant;
  } while (elementCourant != p_liste.m_dernier->suivant);
 }
 INVARIANTS();
 return *this;
}

template<typename T>
void Liste<T>::ajouter(const T & p_elem, const int & p_cardinalite)
{
 elem nouveauNoeud = new Noeud(p_elem, p_cardinalite);
 elem elementCourant = m_dernier->m_suivant;

 if (p_cardinalite == 0)
 {
  nouveauNoeud->m_suivant = elementCourant;
  m_dernier->m_suivant = nouveauNoeud;
 }
}

/*template<typename T>
void Liste<T>::copier(elem) {
 do
 {
  ajouter(elementCourant->m_el, m_cardinalite);
  elementCourant = elementCourant->m_suivant;
 } while (elementCourant != p_liste.m_dernier );
}*/


template<typename T>
void Liste<T>::detruire()
 {
  PRECONDITION(!estVide());
  elem elementCourant = m_dernier->m_suivant;
  while (elementCourant != m_dernier)
  {
   elem elementSuivant = elementCourant->suivant;
   delete elementCourant;
   elementCourant = elementSuivant;
  }
  delete m_dernier;

  m_dernier = nullptr;
  m_cardinalite = 0;

  INVARIANTS();
 }




#ifndef LISTE_HPP
#define LISTE_HPP

#endif //LISTE_HPP
