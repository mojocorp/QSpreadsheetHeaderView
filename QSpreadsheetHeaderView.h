#ifndef QSPREADSHEETHEADERVIEW_H
#define QSPREADSHEETHEADERVIEW_H

#include <QHeaderView>

class QSpreadsheetHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    QSpreadsheetHeaderView(Qt::Orientation orientation, QWidget * parent = 0);
};

#endif /* QSPREADSHEETHEADERVIEW_H */
