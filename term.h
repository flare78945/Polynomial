#ifndef TERM_H
#define TERM_H

class Iterator;
class Polynomial;

class Term
{
	private:
		int coefficient;
		int exponent;
		Term* next;
		Term* previous;
	public:
		/*
		Default Constructor
		There should be no reason to call it
		*/
		Term();
		/*
		Constructs a Term with
		@param coef = any integer for coefficient
		@param exp = any integer for exponent
		*/
		Term(int coef, int exp);
		/*
		Compares two Terms;
		*/
		bool equals(Term * other) const;

	friend class Iterator;
	friend class Polynomial;
};

#endif
