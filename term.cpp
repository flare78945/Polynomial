#include "term.h"

Term::Term()
{
	coefficient = 0;
	exponent = 0;
	next = nullptr;
	previous = nullptr;
}

Term::Term(int coef, int exp)
{
	coefficient = coef;
	exponent = exp;
	next = nullptr;
	previous = nullptr;
}

bool Term::equals(Term * other) const
{
	bool same = false;

	if ((coefficient == other->coefficient) && 
			(exponent == other->exponent))
	{
		same = true;
	}
	else same = false;
	
	return same;
}
