#ifndef QSPREADSHEETHEADERVIEW_H
#define QSPREADSHEETHEADERVIEW_H

#include <QHeaderView>

class QSpreadsheetHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    QSpreadsheetHeaderView(Qt::Orientation orientation, QWidget * parent = 0);
protected:
    void mousePressEvent ( QMouseEvent * event );
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;

    QRect sectionRect(int logicalIndex) const;
    QRect buttonMenuRect(int logicalIndex) const;
    QRect prevRect(int logicalIndex) const;
    QRect nextRect(int logicalIndex) const;

    void drawMenuButton(QPainter *painter, int logicalIndex) const;
    void drawPrevButton(QPainter *painter, int logicalIndex) const;
    void drawNextButton(QPainter *painter, int logicalIndex) const;
private:

};

#endif /* QSPREADSHEETHEADERVIEW_H */
