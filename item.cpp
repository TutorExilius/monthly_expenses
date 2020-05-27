#include "item.h"

Item::Item( QObject *parent )
: QObject{ parent }
, amount_in_cents{ 0 }
, type{ ItemType::NOT_SET }
{
}

int Item::getId() const
{
    return this->id;
}

void Item::setId( const int &value )
{
    this->id = value;
}

long Item::getAmount_in_cents() const
{
    return this->amount_in_cents;
}

void Item::setAmount_in_cents( const long &value)
{
    this->amount_in_cents = value;
}

ItemType Item::getType() const
{
    return this->type;
}

void Item::setType( const ItemType &value )
{
    this->type = value;
}
