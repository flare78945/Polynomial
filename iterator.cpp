#include "iterator.h"
#include "polynomial.h"
#include "term.h"

Iterator::Iterator()
{
	container = nullptr;
	position = nullptr;
}

void Iterator::add(int n, int m)
{
	Term* temp = new Term(n, m);
	if (position == nullptr)
	{
		if (container->First == nullptr && container->Last == nullptr)
		{
			container->First = temp;
			container->Last = temp;
			position = container->First;
		}
		else if (container->First == container->Last)
		{
			temp->previous = container->First;
			container->First->next = temp;
			container->Last = temp;
			position = container->Last;
		}
		else
		{
			temp->previous = container->Last;
			container->Last->next = temp;
			container->Last = temp;
			position = container->Last;
		}
	}
	else if (container->First == container->Last)
	{
		temp->previous = container->First;
		container->First->next = temp;
		container->Last = temp;
		position = container->Last;
	}
	else if (position == container->Last)
	{
		temp->previous = container->Last;
		container->Last->next = temp;
		container->Last = temp;
		position = container->Last;
	}
	else
	{
		temp->next = position->next;
		temp->previous = position;
		position->next = temp;
		position = temp->next;
		position->previous = temp;
		position = temp;
	}
}

void Iterator::next()
{
	if (position == nullptr)
	{
		position = container->Last;
	}
	else
	{
		position = position->next;
	}
}

void Iterator::previous()
{
	if (position == nullptr)
	{
		position = container->First;
	}
	else
	{
		position = position->previous;
	}
}

void Iterator::print()
{
	std::cout << get_coef() << "*x^" << get_exp() << std::endl;
}

int Iterator::get_coef() const
{
	return position->coefficient;
}

int Iterator::get_exp() const
{
	return position->exponent;
}

bool Iterator::equals(Iterator * other) const
{
	bool same = false;

	if ((get_coef() == other->get_coef()) && 
			(get_exp() == other->get_exp()))
	{
		same = true;
	}
	else same = false;
	
	return same;
}
