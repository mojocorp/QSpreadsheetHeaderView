## Description

[![Build Status](https://secure.travis-ci.org/mojocorp/QSpreadsheetHeaderView.png)](http://travis-ci.org/mojocorp/QSpreadsheetHeaderView)

The QSpreadsheetHeaderView class is a special QHeaderView that mimic Google Spreadsheet header.

It means:
* A button with a context menu to hide/sort colums.
* Indicators for hidden columns. Clicking on it restore the column visibility.

<img src="https://raw.github.com/mojocorp/QSpreadsheetHeaderView/master/screen-capture.png" >

## How to use it ?

    QSpreadsheetHeaderView *header = new QSpreadsheetHeaderView(Qt::Horizontal, this);
    
    QTableView *tableView = new QTableView(this);
    tableView->setHorizontalHeader(header);

## Dependency
Qt 4.4.x.

## License

LGPL
