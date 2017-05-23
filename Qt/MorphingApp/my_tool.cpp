#include "my_tool.h"

using namespace std;

my_tool::my_tool(QWidget *parent) :
    QLabel(parent)
{

}

my_tool::~my_tool()
{

}

void my_tool::mouseMoveEvent(QMouseEvent *e)
{
    this->x = e->x();
    this->y = e->y();
    emit Sig_pos();
}

void my_tool::mousePressEvent(QMouseEvent *e)
{
    Coord_X.append(x);
    Coord_Y.append(y);
    qDebug() << Coord_X;
    qDebug() << Coord_Y;
    emit Sig_Mouse_Pressed();
    emit Sig_pos();
}

//void my_tool::paintEvent(QPaintEvent *e)
//{
//    for(int i = 1; i <= Coord_X.size(); i ++)
//    {
//        QLabel::paintEvent(e);
//        QPainter painter(this);
//        QPen drawpen(Qt::red);
//        drawpen.setWidth(7);
//        QPoint point;
//        point.setX(Coord_X.value(i));
//        point.setY(Coord_Y.value(i));
//        painter.setPen(drawpen);
//        painter.drawPoint(point);
//        emit Sig_Mouse_Pressed();
//    }
//}
