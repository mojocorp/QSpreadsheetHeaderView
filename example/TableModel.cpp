#include "TableModel.h"

static const char *header[] = {"REVIEW_DATE","AUTHOR","ISBN","DISCOUNTED_PRICE"};

typedef struct {
    QString date;
    QString author;
    int isbn;
    float price;
} Row;

static Row rows[] = {
{"1985/01/21","Douglas Adams",345391802,5.95f},
{"1990/01/12","Douglas Hofstadter",465026567,9.95f},
{"1998/07/15","Timothy ""The Parser"" Campbell",968411304,18.99f},
{"1999/12/03","Richard Friedman",60630353,5.95f},
{"2001/09/19","Karen Armstrong",345384563,9.95f},
{"2002/06/23","David Jones",198504691,9.95f},
{"2002/06/23","Julian Jaynes",618057072,12.50f},
{"2003/09/30","Scott Adams",740721909,4.95f},
{"2004/10/04","Benjamin Radcliff",804818088,4.95f},
{"2004/10/04","Randel Helms",879755725,4.50f}};

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 10;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= 10 || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch(index.column()) {
        case 0: return rows[index.row()].date;
        case 1: return rows[index.row()].author;
        case 2: return rows[index.row()].isbn;
        case 3: return rows[index.row()].price;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        return header[section];
    } else {
        return section+1;
    }
    return QVariant();
}

void TableModel::swapRows(int r1, int r2)
{
    qSwap(rows[r1].date, rows[r2].date);
    qSwap(rows[r1].author, rows[r2].author);
    qSwap(rows[r1].isbn, rows[r2].isbn);
    qSwap(rows[r1].price, rows[r2].price);
}

bool TableModel::lessThan(int column, int r1, int r2)
{
    switch(column) {
    case 0: return rows[r1].date <= rows[r2].date;
    case 1: return rows[r1].author <= rows[r2].author;
    case 2: return rows[r1].isbn <= rows[r2].isbn;
    case 3: return rows[r1].price <= rows[r2].price;
    }
    return false;
}

void TableModel::sort(int column, Qt::SortOrder order)
{
    emit layoutAboutToBeChanged();

    // gnomesort
    for ( int i = 1; i < rowCount(); ) {
        if ( order == Qt::AscendingOrder ? lessThan(column, i-1, i) : lessThan(column, i, i-1)) {
            ++i;
        } else {
            swapRows(i-1, i);
            --i;
            if ( i == 0 ) {
                i = 1;
            }
        }
    }
    emit layoutChanged();
}
