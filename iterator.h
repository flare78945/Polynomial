#ifndef ITERATOR_H
#define ITERATOR_H

class Polynomial;
class Term;

class Iterator
{
	private:
		Polynomial* container;
		Term* position;
	public:
		/*
		Default Constructor
		*/
		Iterator();
		/*
		Add a new Term to the Polynomial
		@param n, is the coefficient
		@param m is the exponent
		*/
		void add(int n, int m);
		/*
		Moves Iterator to next Term
		*/
		void next();
		/*
		Moves Iterator to previous Term
		*/
		void previous();
		/*
		Print Position
		*/
		void print();
		/*
		Returns coefficient from Term
		*/
		int get_coef() const;
		/*
		Returns exponent from Term
		*/
		int get_exp() const;
		/*
		Compares two Terms;
		*/
		bool equals(Iterator * other) const;
	friend class Polynomial;
};

#endif
