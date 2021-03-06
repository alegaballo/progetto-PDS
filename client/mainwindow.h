#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "clientprotocol.h"
#include "serverlistmodel.h"
#include "connection.h"
#include "applist.h"

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTcpSocket>
#include <QTimer>
#include <QMessageBox>
#include <QVector>

#include <memory>

namespace Ui { class MainWindow; }
namespace msgs {
    class AppList;
    class KeystrokeRequest;
    class Response;
}
class QModelIndex;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    virtual void closeEvent(QCloseEvent *) override;

signals:
    void connectionAdded(Connection*);

private slots:
    void sendKeystroke();
    void showResponse(Connection *conn, const msgs::KeystrokeRequest&,
                      const msgs::Response&);
    void addConnection();
    void removeConnection();
    void reconnectSelected();
    void connSelectionChanged();
    void appSelectionChanged();

private:
    void updatePendingReqMsg();

    std::unique_ptr<Ui::MainWindow> ui_;
    QVector<Connection*> connections_;
    QSortFilterProxyModel proxyModel_;  
    ServerListModel serverListModel_;
    AppList appListModel_;
    QMessageBox msgBox_;
};

#endif // MAINWINDOW_H
