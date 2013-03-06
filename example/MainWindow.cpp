#include <QApplication>
#include <QTableView>

#include "MainWindow.h"
#include "TableModel.h"
#include "QSpreadsheetHeaderView.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}

MainWindow::MainWindow()
{
    QSpreadsheetHeaderView *hv = new QSpreadsheetHeaderView(Qt::Horizontal, this);
    hv->setClickable(true);
    hv->setHighlightSections(true);
    TableModel *model = new TableModel(this);
    QTableView *tv = new QTableView(this);
    tv->setModel(model);
    tv->setHorizontalHeader(hv);

    setCentralWidget(tv);
}
