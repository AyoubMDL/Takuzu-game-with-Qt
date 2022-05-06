#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <QLineEdit>
#include <QElapsedTimer>
#include <QTimer>


class ChronometerWidget : public QLineEdit
{
    Q_OBJECT

public:
    ChronometerWidget(QWidget*&);

public slots:
    void updateChrono();

private:
    QTimer * _timer = new QTimer;
    QElapsedTimer t;
    const QString format = "mm:ss";
};

#endif // CHRONOMETER_H
