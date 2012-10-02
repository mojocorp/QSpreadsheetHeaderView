## Description
[![Build Status](https://secure.travis-ci.org/mojocorp/QSpreadsheetHeaderView.png)](http://travis-ci.org/mojocorp/QSpreadsheetHeaderView)

The QSpreadsheetHeaderView class is a special header for QTableView that mimic Google Spreadsheet header.

A button with a context menu...
<img src="https://raw.github.com/mojocorp/QSpreadsheetHeaderView/master/screen-capture-1.jpg" >

And buttons/indicators for hidden columns. Clicking on it restore the column visibility.
<img src="https://raw.github.com/mojocorp/QSpreadsheetHeaderView/master/screen-capture-2.jpg" >

## How to use it ?

    QSpreadsheetHeaderView *header = new QSpreadsheetHeaderView(Qt::Horizontal, this);
    
    QTableView *tableView = new QTableView(this);
    tableView->setHorizontalHeader(header);

## Dependency
Qt 4.4.x.

## License

LGPL
