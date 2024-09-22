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
Liste<T>::Liste() : m_dernier(nullptr), m_cardinalite(0){ assert(verifieInvariant());}

template<typename T>
Liste<T>::Liste(const Liste& p_liste) : m_dernier(nullptr), m_cardinalite(0)
{
 //PRECONDITION(!p_liste.estVide());

 elem elementCourant = p_liste.m_dernier->m_suivant;
 do
 {
  ajouter(elementCourant->m_el, m_cardinalite);
  elementCourant = elementCourant->m_suivant;
 } while (elementCourant != p_liste.m_dernier->m_suivant );
 //INVARIANTS();
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
  } while (elementCourant != p_liste.m_dernier->m_suivant);
 }
 //INVARIANTS();
 return *this;
}

template<typename T>
void Liste<T>::ajouter(const T & p_elem, const int & p_cardinalite)
{
 elem nouveauNoeud = new Noeud(p_elem, nullptr);
 elem elementCourant = m_dernier->m_suivant;

 if (estVide())
 {
  m_dernier = nouveauNoeud;
  elementCourant = m_dernier;

 } else {

  if (p_cardinalite == 0)
  {
   nouveauNoeud->m_suivant = elementCourant;
   elementCourant = nouveauNoeud;

  } else if (p_cardinalite >= m_cardinalite)
    {
     nouveauNoeud->m_suivant = elementCourant;
     elementCourant = nouveauNoeud;
     nouveauNoeud - m_dernier;
    } else
      {
       for(int i = 0; i < p_cardinalite - 1; i++)
       {
        elementCourant = elementCourant->m_suivant;
       }
       nouveauNoeud->m_suivant = elementCourant->m_suivant;
       elementCourant->m_suivant = nouveauNoeud;
      }
 }
 ++m_cardinalite;
}

/*template<typename T>
void Liste<T>::enleverEl(const T & p_elem)
{
assert(verifieInvariant());
}*/

template<typename T>
int Liste<T>::taille() const
{
 return m_cardinalite;
}

template<typename T>
bool Liste<T>::estVide() const
{
 return taille() == 0;
}

template<typename T>
bool Liste<T>::appartient(const T & p_elem) const
{
 if (estVide())
 {
  return false;
 }

 elem elementCourant = m_dernier->m_suivant;

 do {
  if (elementCourant->m_el == p_elem)
  {
   return true;
  }
  elementCourant = elementCourant->m_suivant;
 } while(elementCourant != m_dernier->m_suivant );

 return false;
}

template<typename T>
T Liste<T>::element(const int & p_cardinalite) const
{
 return pointeurSurNoeud(p_cardinalite)->m_el;
}

/*template<typename T>
int Liste<T>::position(const T & p_elem) const
{
// PRECONDITION(estVide());

 elem elementCourant = m_dernier->m_suivant;
 int index = 0;

 do {
  if (elementCourant->m_el == p_elem)
  {
   return index;
  }
  elementCourant = elementCourant->m_suivant;
  ++index;
 }while(elementCourant != m_dernier->m_suivant );

}*/

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
  //PRECONDITION(!estVide());
  elem elementCourant = m_dernier->m_suivant;
  while (elementCourant != m_dernier)
  {
   elem elementSuivant = elementCourant->m_suivant;
   delete elementCourant;
   elementCourant = elementSuivant;
  }
  delete m_dernier;

  m_dernier = nullptr;
  m_cardinalite = 0;
  //INVARIANTS();
 }

template<typename T>
typename Liste<T>::elem Liste<T>::pointeurSurNoeud(const int & p_cardinalite) const
{
 //PRECONDITION(p_cardinalite>=0 && p_cardinalite < m_cardinalite);
 elem elementCourant = m_dernier->m_suivant;
 for(int i = 0; i < p_cardinalite; i++)
 {
  elementCourant = elementCourant->m_suivant;
 }
 return elementCourant;
 //INVARIANTS();
}

/*template<typename T>
bool Liste<T>::verifieInvariant() const {
 if (m_dernier == nullptr) return m_cardinalite == 0;
 auto p = m_dernier ;
 for (size_t i = 0 ; i < m_cardinalite ; ++i) {
  p = p->m_suivant ;
 }
 return p == m_dernier ;
}*/




#ifndef LISTE_HPP
#define LISTE_HPP

#endif //LISTE_HPP
