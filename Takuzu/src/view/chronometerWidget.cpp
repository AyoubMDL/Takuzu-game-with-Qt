#include "view/chronometerWidget.hpp"

#include <QTime>

ChronometerWidget::ChronometerWidget(QWidget*&){
    setReadOnly(true);
    setAlignment(Qt::AlignCenter);
    connect(_timer, SIGNAL(timeout()), this,SLOT(updateChrono()));

    setText(QTime(0, 0).toString(format));
    t.restart();
    _timer->start(1000);
}


void ChronometerWidget::updateChrono(){
    setText( QTime(0,0).addMSecs(t.elapsed()).toString(format));
}
