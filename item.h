#ifndef ITEM_H
#define ITEM_H

#include <QObject>

enum class ItemType
{
    INPUT,
    OUTPUT,
    NOT_SET
};

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item( QObject *parent = nullptr );



    int getId() const;
    void setId( const int &value );

    long getAmount_in_cents() const;
    void setAmount_in_cents( const long &value );

    ItemType getType() const;
    void setType( const ItemType &value );

signals:

private:
    int id;
    long amount_in_cents;
    ItemType type;
};

#endif // ITEM_H
