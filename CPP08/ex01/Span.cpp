#include "Span.hpp"

Span::Span(void)
{
	this->_limit = 1;
}

Span::Span(unsigned int i)
{
	if (i > (unsigned int)std::numeric_limits<int>::max())
		throw OutOfRangeException();
	this->_limit = i;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span(void)
{

}

Span& Span::operator = (const Span& other)
{
	if (this == &other)
		return (*this);
	
	this->_span = other._span;
	this->_limit = other._limit;

	return (*this);
}

void Span::addNumber(int num)
{
	if (this->_span.size() != this->_limit)
		this->_span.push_back(num);
	else
		throw NoSpaceException();
}

int Span::shortestSpan(void)
{
	int a;
	int b;
	int sspan;

	if (this->_span.size() == 0 || this->_span.size() == 1)
		throw NoSpanException();

	a = _span[0];
	b = _span[1];
	(a >= b) ? (sspan = a - b) : (sspan = b - a);
	for (size_t i = 0; i < this->_span.size(); i++)
	{
		a = _span[i];
		for (size_t j =  i + 1; j < this->_span.size(); j++)
		{
			b = _span[j];
			int currentSpan = getSpan(a, b);
			if (currentSpan < sspan)
				sspan = currentSpan;
		}
	}
	return (sspan);
}

int Span::longestSpan(void)
{
	int a;
	int b;
	int lspan;
	if (this->_span.size() == 0 || this->_span.size() == 1)
		throw NoSpanException();

	a = _span[0];
	b = _span[1];
	(a >= b) ? (lspan = a - b) : (lspan = b - a);
	for (size_t i = 0; i < this->_span.size() - 1; i++)
	{
		a = _span[i];
		for (size_t j =  i + 1; j < this->_span.size(); j++)
		{
			b = _span[j];
			int currentSpan = getSpan(a, b);
			if (currentSpan > lspan)
				lspan = currentSpan;
		}
	}
	return (lspan);
}

void Span::insert(unsigned int n, std::vector<int>::iterator start, std::vector<int>::iterator end) // inserts numbers from a range of iterator
{
	if (n > _limit - _span.size())
		throw BadInsertException();
	
	_span.insert(_span.end(), start, end);
}

void Span::print(void)
{
	for (size_t i = 0; i < _span.size(); i++)
	{
		std::cout << "Index " << i << ": " << _span[i] << std::endl;
	}
}

size_t Span::size(void) const
{
	return (this->_span.size());
}