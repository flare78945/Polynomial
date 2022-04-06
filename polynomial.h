#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Iterator;
class Term;

class Polynomial
{
	private:
		Term* First;
		Term* Last;
		/*
		Sorts the Polynomial by greatest
		power to least power
		Currently unimplemented
		*/
		//void sort();
	public:
		/*
		Create a Polynomial
		*/
		Polynomial();
		/*
		Create a Polynomial with given Term
		@param a is assigned to First
		*/
		Polynomial(Term* a);
		/*
		Create a Polynomial with given Terms
		@param a is assigned to First
		@param b is assigned to Last
		*/
		Polynomial(Term* a, Term* b);
		/*
		Goes through the Polynomial
		and combines like terms
		*/
		void combine();
		/*
		Returns the Polynomial's size
		*/
		int size();
		/*
		Multiply the Polynomial by
		@param p
		*/
		Polynomial * multiply(Polynomial* p);
		/*
		Print the Polynomial
		*/
		void print();
		/*
		Delete the Polynomial
		*/
		void free();
		/*
		Removes the Term at
		@param pos
		*/
		Iterator * erase(Iterator* pos);
		/*
		Returns an Iterator pointing at First
		*/
		Iterator * begin();
		/*
		Returns an Iterator pointing at Last
		*/
		Iterator end();

	friend class Iterator;
};

#endif
