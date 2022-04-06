/*
* File: main.cpp
* Description: Write a class Polynomial that stores a polynomial as a linked list of terms. A term contains the coefficient and the power of x. Supply member functions to add, multiply, and print polynomials. Supply a constructor that makes a polynomial from a single term. Then compute p(x) x p(x).
* Author: Minhquang Phillip Tran
* Date: March 22, 2022
* Email: phillip_tran_98@yahoo.com
*/

#include <iostream>

#include "iterator.h"
#include "polynomial.h"
#include "term.h"

int main() 
{
	Polynomial* alpha = new Polynomial(new Term(4,5));
	Iterator* pos = new Iterator();

	pos = alpha->begin();
	
	pos->add(5, 6);
	pos->add(4, 5);
	pos->add(6, 7);
	pos->add(7, 3);
	pos->add(-2, 3);

	pos->previous();

	pos->add(2, 4);

	pos->next();

	pos = alpha->erase(pos);

	pos->add(2, 4);

	pos->add(2, 0);

	alpha->combine();
	
	alpha->print();

	alpha = alpha->multiply(alpha);
	
	alpha->print();

	delete pos;

	alpha->free();
	
	delete alpha;
}
