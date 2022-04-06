#include "iterator.h"
#include "polynomial.h"
#include "term.h"

Polynomial::Polynomial()
{
	First = nullptr;
	Last = nullptr;
}

Polynomial::Polynomial(Term* a)
{
	First = a;
	Last = a;
}

Polynomial::Polynomial(Term* a, Term* b)
{
	First = a;
	Last = b;
	First->next = Last;
	Last->previous = First;
}

void Polynomial::combine()
{
	Iterator* combiner = new Iterator();
	combiner->container = this;
	combiner->position = combiner->container->First;
	Iterator* to_check = new Iterator();
	to_check->container = this;
	to_check->position = to_check->container->First;
	while (to_check->position != nullptr)
	{
		while (combiner->position != nullptr)
		{
			combiner->next();
			if (combiner->position == nullptr)
			{
				break;
			}
			if (to_check->get_exp() == combiner->get_exp())
			{
				to_check->position->coefficient += combiner->get_coef();
				combiner = this->erase(combiner);
			}
		}
		to_check->next();
		combiner->position = to_check->position;
	}
}

int Polynomial::size()
{
	int count = 0;
	Iterator* temp = new Iterator();
	temp->container = this;
	temp->position = temp->container->First;
	while (temp->position != nullptr)
	{
		count++;
		temp->next();
	}
	return count;
}

Polynomial * Polynomial::multiply(Polynomial* p)
{
	Iterator* current = new Iterator();
	current->container = this;
	current->container->combine();
	current->position = current->container->First;
	Iterator* to_multiply = new Iterator();
	to_multiply->container = p;
	to_multiply->container->combine();
	to_multiply->position = to_multiply->container->First;

	Polynomial * temp = new Polynomial();
	Iterator * hold = new Iterator();
	hold->container = temp;
	
	while (current->position != nullptr)
	{
		int coef = current->get_coef();
		int exp = current->get_exp();
		while (to_multiply->position != nullptr)
		{
			int coef_prod = coef * to_multiply->get_coef();
			int exp_prod = exp + to_multiply->get_exp();
			hold->add(coef_prod, exp_prod);
			to_multiply->next();
		}
		to_multiply->position = to_multiply->container->First;
		current->next();
	}
	this->free();
	temp->combine();
	return temp;
}

void Polynomial::print()
{
	Iterator* temp = new Iterator();
	temp->container = this;
	temp->position = temp->container->First;
	while (temp->position != nullptr)
	{
		if (temp->position == temp->container->First)
		{
			if (temp->get_coef() > 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << temp->get_coef() << "*x^" << temp->get_exp() << " ";
				}
				else
				{
					std::cout << temp->get_coef() << " ";
				}
			}
			else if (temp->get_coef() < 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << temp->get_coef() << "*x^" << temp->get_exp() << " ";
				}
				else
				{
					std::cout << temp->get_coef() << " ";
				}
			}
			temp->next();
			continue;
		}
		
		if (temp->position->next != nullptr)
		{
			if (temp->get_coef() > 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << " + " << temp->get_coef() << "*x^" << temp->get_exp() << " ";
				}
				else
				{
					std::cout << temp->get_coef() << " ";
				}
			}
			else if (temp->get_coef() < 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << " " << temp->get_coef() << "*x^" << temp->get_exp() << " ";
				}
				else
				{
					std::cout << temp->get_coef() << " ";
				}
			}
		}
			
		else
		{
			if (temp->get_coef() > 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << " + " << temp->get_coef() << "*x^" << temp->get_exp() << std::endl;
				}
				else
				{
					std::cout << " + " << temp->get_coef() << std::endl;
				}
			}
			else if (temp->get_coef() < 0)
			{
				if (temp->get_exp() != 0)
				{
					std::cout << " " << temp->get_coef() << "*x^" << temp->get_exp() << std::endl;
				}
				else
				{
					std::cout << " " << temp->get_coef() << std::endl;
				}
			}
		}
		
		temp->next();
	}
}

void Polynomial::free()
{
	Term* to_delete = First;
	while(to_delete != nullptr)
	{
		Term* next_to_delete = to_delete->next;
		delete to_delete;
		to_delete = next_to_delete;
	}
}

Iterator * Polynomial::erase(Iterator* pos)
{
	Iterator* temp = pos;
	Term* to_delete = pos->position;

	if (to_delete->previous != nullptr)
	{
		if (to_delete->next != nullptr)
		{
			to_delete->previous->next = to_delete->next;
			to_delete->next->previous = to_delete->previous;
			temp->position = pos->position->previous;
		}
		else
		{
			to_delete->previous->next = nullptr;
			temp->position = pos->position->previous;
			temp->container->Last = temp->position;
		}
	}
	else
	{
		temp->position = pos->position->next;
		temp->position->previous = nullptr;
		temp->container->First = temp->position;
	}
	
	delete to_delete;
	
	return temp;
}

Iterator * Polynomial::begin()
{
	Iterator* location = new Iterator();
	if (First != nullptr)
	{
		location->position = First;
	}
	else
	{
		location->position = nullptr;
	}
	location->container = this;
	return location;
}

Iterator Polynomial::end()
{
	Iterator location;
	location.position = nullptr;
	location.container = this;
	return location;
}
