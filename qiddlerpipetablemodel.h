#ifndef QIDDLERPIPETABLEMODEL_H
#define QIDDLERPIPETABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QSharedPointer>
#include "qiconnectiondata.h"
class QiddlerPipeTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit QiddlerPipeTableModel(QObject *parent = 0);
    ~QiddlerPipeTableModel();
    QMap<int,ConnectionData_ptr > pipesMap;
    QVector<ConnectionData_ptr > pipesVector;

    int rowCount( const QModelIndex & parent ) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
public slots:
    void addItem(ConnectionData_ptr p);
    void removeItems();
    void removeAllItem();

    ConnectionData_ptr getItem(int column);

    void updateItem(ConnectionData_ptr p);

signals:
	//signals emit when connections are added/updated/removed
	void connectionAdded(ConnectionData_ptr p);
	void connectionUpdated(ConnectionData_ptr p);
	void connectionRemoved(ConnectionData_ptr p);

public slots:

private:
    int pipeNumber;
};

#endif // QIDDLERPIPETABLEMODEL_H
