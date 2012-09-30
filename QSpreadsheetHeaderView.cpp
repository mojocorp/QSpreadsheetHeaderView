#include <QPainter>
#include <QCursor>
#include <QHoverEvent>
#include <QMenu>

#include "QSpreadsheetHeaderView.h"

QSpreadsheetHeaderView::QSpreadsheetHeaderView(Qt::Orientation orientation, QWidget * parent)
    : QHeaderView(orientation, parent)
{
    setAttribute(Qt::WA_Hover, true);
}

void QSpreadsheetHeaderView::mousePressEvent ( QMouseEvent * event )
{
    QHeaderView::mousePressEvent(event);

    int logicalIndex = logicalIndexAt(event->pos());

    if (buttonMenuRect(logicalIndex).contains(event->pos())) {
        QMenu menu(this);
        QAction *hideCol = menu.addAction("Hide column");
        QAction *sortAZ = menu.addAction("Sort sheet A->Z");
        QAction *sortZA = menu.addAction("Sort sheet Z->A");

        QAction *res = menu.exec(mapToGlobal(event->pos()));

        if (res == hideCol) {
            hideSection(logicalIndex);
            update();
        }
        if (res == sortAZ)
            model()->sort(logicalIndex, Qt::AscendingOrder);
        if (res == sortZA)
            model()->sort(logicalIndex, Qt::DescendingOrder);
    }

    if (prevRect(logicalIndex).contains(event->pos())) {
        showSection(logicalIndex - 1);
    }

    if (nextRect(logicalIndex).contains(event->pos())) {
        showSection(logicalIndex + 1);
    }
}

void QSpreadsheetHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();

    QHeaderView::paintSection(painter, rect, logicalIndex);

    painter->restore();

    if (!rect.isValid() || isSortIndicatorShown())
        return;

    if (isSectionHidden(logicalIndex - 1)) {
        drawPrevButton(painter, logicalIndex);
    }

    if (isSectionHidden(logicalIndex + 1)) {
        drawNextButton(painter, logicalIndex);
    }

    QPoint pos = mapFromGlobal(QCursor::pos());
    if (!rect.contains(pos))
        return;

    drawMenuButton(painter, logicalIndex);
}

QRect QSpreadsheetHeaderView::sectionRect(int logicalIndex) const
{
    return QRect(sectionViewportPosition(logicalIndex), 0, sectionSize(logicalIndex), height());
}

QRect QSpreadsheetHeaderView::buttonMenuRect(int logicalIndex) const
{
    QRect sr = sectionRect(logicalIndex);

    return QRect(sr.right() - 5 - 13, sr.center().y() - 6, 13, 13);
}

QRect QSpreadsheetHeaderView::prevRect(int logicalIndex) const
{
    if (isSectionHidden(logicalIndex))
        return QRect();

    QRect sr = sectionRect(logicalIndex);

    return QRect(sr.left() + 1, sr.center().y() - 6, 13, 13);
}

QRect QSpreadsheetHeaderView::nextRect(int logicalIndex) const
{
    if (isSectionHidden(logicalIndex))
        return QRect();

    QRect sr = sectionRect(logicalIndex);

    return QRect(sr.right() - 13, sr.center().y() - 6, 13, 13);
}

void QSpreadsheetHeaderView::drawMenuButton(QPainter *painter, int logicalIndex) const
{
    QRect brect = buttonMenuRect(logicalIndex);

    painter->setPen(QColor(186,186,186));
    painter->setBrush(QColor(246,246,246));
    painter->drawRect(brect.adjusted(0,0,-1,-1));

    painter->setPen(QColor(71,71,71));
    painter->drawLine(brect.left()+3, brect.top()+5, brect.right()-3, brect.top()+5);
    painter->drawLine(brect.left()+4, brect.top()+6, brect.right()-4, brect.top()+6);
    painter->drawLine(brect.left()+5, brect.top()+7, brect.right()-5, brect.top()+7);
    painter->drawPoint(brect.left()+6, brect.top()+8);
}

void QSpreadsheetHeaderView::drawPrevButton(QPainter *painter, int logicalIndex) const
{
    QRect rect = prevRect(logicalIndex);

    painter->setPen(QColor(71,71,71));
    painter->drawLine(rect.left()+1, rect.center().y() - 3, rect.left()+1, rect.center().y() + 3);
    painter->drawLine(rect.left()+2, rect.center().y() - 2, rect.left()+2, rect.center().y() + 2);
    painter->drawLine(rect.left()+3, rect.center().y() - 1, rect.left()+3, rect.center().y() + 1);
    painter->drawLine(rect.left()+4, rect.center().y() - 0, rect.left()+4, rect.center().y() + 0);
}

void QSpreadsheetHeaderView::drawNextButton(QPainter *painter, int logicalIndex) const
{
    QRect rect = nextRect(logicalIndex);

    painter->setPen(QColor(71,71,71));
    painter->drawLine(rect.right()-2, rect.center().y() - 3, rect.right()-2, rect.center().y() + 3);
    painter->drawLine(rect.right()-3, rect.center().y() - 2, rect.right()-3, rect.center().y() + 2);
    painter->drawLine(rect.right()-4, rect.center().y() - 1, rect.right()-4, rect.center().y() + 1);
    painter->drawLine(rect.right()-5, rect.center().y() - 0, rect.right()-5, rect.center().y() + 0);
}
