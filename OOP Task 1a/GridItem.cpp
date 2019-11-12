#include "GridItem.h"

GridItem::GridItem(char symbol) : symbol(symbol)
{
}

char GridItem::getSymbol() const
{
	return symbol;
}