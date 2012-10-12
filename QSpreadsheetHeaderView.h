/*
*
* This file is part of QSpreadsheetHeaderView,
* an open-source header view widget
*
* Copyright (C) 2012 Morgan Leborgne
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with QSpreadsheetHeaderView. If not, see <http://www.gnu.org/licenses/>.
*
*/
#ifndef QSPREADSHEETHEADERVIEW_H
#define QSPREADSHEETHEADERVIEW_H

#include <QHeaderView>

/*!
    \class QSpreadsheetHeaderView
    \brief The QSpreadsheetHeaderView class is a special QHeaderView that mimic Google Spreadsheet header.
    version 1.0
    \sa QHeaderView
*/
class QSpreadsheetHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    QSpreadsheetHeaderView(Qt::Orientation orientation, QWidget * parent = 0);
protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;

    QRect sectionRect(int logicalIndex) const;
    QRect buttonMenuRect(int logicalIndex) const;
    QRect prevRect(int logicalIndex) const;
    QRect nextRect(int logicalIndex) const;

    void drawMenuButton(QPainter *painter, int logicalIndex, bool enabled) const;
    void drawPrevButton(QPainter *painter, int logicalIndex) const;
    void drawNextButton(QPainter *painter, int logicalIndex) const;
private:

};

#endif /* QSPREADSHEETHEADERVIEW_H */
