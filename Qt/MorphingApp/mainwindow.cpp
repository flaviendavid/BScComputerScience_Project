#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_tool.h"

using namespace std;

//Global flag
int flagCurrentPix = 0;

//Global vectors
QVector<int> PixA_x;
QVector<int> PixA_y;
QVector<int> PixB_x;
QVector<int> PixB_y;

//Global picture
QString Image_A = ":/img/img/jolie.jpg";
QString Image_B= ":/img/img/pitt.jpg";

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Default picture
    QPixmap pix1(":/img/img/jolie.jpg");
    ui->label_pic1->setPixmap(pix1);
    QPixmap pix2(":/img/img/pitt.jpg");
    ui->label_pic2->setPixmap(pix2);

    //Connections established Signal-Slot
    //From :\my_tool\Sig_Pos to :\mainwindow\Slot_Mouse_Current_Position
    connect(ui->label_pic1, SIGNAL(Sig_pos()),
            this,SLOT(Slot_Mouse_Current_Position()));
    connect(ui->label_pic2, SIGNAL(Sig_pos()),
            this,SLOT(Slot_Mouse_Current_Position2()));
    //From :\my_tools\. to :\mainwindow\.
    connect(ui->label_pic1, SIGNAL(Sig_Mouse_Pressed()),
            this,SLOT(Slot_Mouse_Pressed()));
    connect(ui->label_pic2, SIGNAL(Sig_Mouse_Pressed()),
            this,SLOT(Slot_Mouse_Pressed()));

    //Instruction in Status bar
    ui->statusBar->showMessage("Do your matching point at each time, e.g a point on the left picture and a point on the right and so on");

}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadImageButton_clicked()
{
    //Code to open the picture through a browser
    QFileDialog dialog (this);
    dialog.setNameFilter(tr("Images (*.png *.jpg *TIFF)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open images"), "/Users", tr("Images File (*.png *.bmp *.jpg *TIFF)"));

    //Select picture
    if (!fileName.isEmpty())
    {
        QImage image (fileName);
        ui->label_pic1->setPixmap(QPixmap::fromImage(image));
        ui->label_pic1->setScaledContents(false);
        ui->label_pic1->adjustSize();
    }
   //Extra feature to play with label
   //ui->label_pic1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
   //ui->label_pic1->hasScaledContents();
   //ui->label_pic1->keepScaledRatio
   //QImage::scaled(const QSize &size, Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio) const
}

void MainWindow::on_loadImageButton2_clicked()
{
    //Code to open the picture through a browser
    QFileDialog dialog (this);
    dialog.setNameFilter(tr("Images (*.png *.jpg *TIFF)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open images"), "/Users", tr("Images File (*.png *.bmp *.jpg *TIFF)"));

    //Select picture
    if (!fileName.isEmpty())
    {
        QImage image (fileName);
        ui->label_pic2->setPixmap(QPixmap::fromImage(image));
        ui->label_pic2->setScaledContents(true);
        ui->label_pic2->adjustSize();
    }
    //Extra feature to play with label
    //ui->label_pic2->hasScaledContents();
    //ui->label_pic2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

void MainWindow::on_saveImageButton_clicked()
{
    QFileDialog dialog (this);
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save images"), "/Users/Flavien/Desktop/BScComputerScience_Project/lib", tr("Images File (*.png *.jpg *TIFF)"));
}

void MainWindow::Slot_Mouse_Pressed()
{

    if(flagCurrentPix == 1 && PixA_x.size() <= PixB_x.size())
    {
        ui->label_event->setText("Mousse Pressed 1!");
        PixA_x.append(ui->label_pic1->x);
        qDebug() << PixA_x;
        PixA_y.append(ui->label_pic1->y);
        qDebug() << PixA_y;
        const auto meanA_x = std::accumulate(PixA_x.begin(), PixA_x.end(), .0) / PixA_x.size();
        qDebug() << "MeanA_x:" << meanA_x;
        const auto meanA_y = std::accumulate(PixA_y.begin(), PixA_y.end(), .0) / PixA_y.size();
        qDebug() << "MeanA_y:" << meanA_y;

////attempt to draw a point at each click
//        int i =1;

//        QPainter painter(this);
//        QPen drawpen(Qt::red);
//        drawpen.setWidth(7);
//        QPoint point;
//        point.setX(PixA_x.value(i));
//        point.setY(PixA_y.value(i));
//        painter.setPen(drawpen);
//        painter.drawPoint(point);
    }
    else if(flagCurrentPix == 2 && PixB_x.size() <= PixA_x.size())
    {
        ui->label_event->setText("Mousse Pressed 2!");
        PixB_x.append(ui->label_pic2->x);
        qDebug() << PixB_x;
        PixB_y.append(ui->label_pic2->y);
        qDebug() << PixB_y;
        auto meanB_x = std::accumulate(PixB_x.begin(), PixB_x.end(), .0) / PixA_x.size();
        qDebug() << "MeanB_x:" << meanB_x;
        auto meanB_y = std::accumulate(PixB_y.begin(), PixB_y.end(), .0) / PixB_y.size();
        qDebug() << "MeanB_y:" << meanB_y;

////attempt to draw a point at each click
//        int i = 1;
//        paintEvent(pix2);
//        QPainter painter(this);
//        QPen drawpen(Qt::blue);
//        drawpen.setWidth(7);
//        QPoint point;
//        point.setX(PixB_x.value(i));
//        point.setY(PixB_y.value(i));
//        painter.setPen(drawpen);
//        painter.drawPoint(point);
    }

    flagCurrentPix=0;
}

void MainWindow::Slot_Mouse_Current_Position()
{
    flagCurrentPix = 1;
    ui->label->setText(QString("X = %1, Y = %2").arg(ui->label_pic1->x).arg(ui->label_pic1->y));
}

void MainWindow::Slot_Mouse_Current_Position2()
{
    flagCurrentPix = 2;
    ui->label->setText(QString("X = %1, Y = %2").arg(ui->label_pic2->x).arg(ui->label_pic2->y));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QImage bot(Image_A);
    QImage top(Image_B);

    //format conversion for alpha channel
    bot = bot.convertToFormat(QImage::Format_ARGB32);
    top = top.convertToFormat(QImage::Format_ARGB32);

    int w = bot.width()-((bot.width()-top.width())*value/99);
    int h = bot.height()-((bot.height()-top.height())*value/99);

    int shiftX = (meanB_x-meanA_x)/ui->label_pic1->width();
    int shiftY = (meanB_y-meanA_y)/ui->label_pic1->height();

    int shiftA_x = shiftX*top.width()*value/99;
    int shiftA_y = shiftY*top.height()*value/99;

    int shiftB_x = shiftX*bot.width()*(1-value/99);
    int shiftB_y = shiftY*bot.height()*(1-value/99);

    QPixmap combined(w, h);
    QPainter p(&combined);
    float opacity = value/99.0;
    p.setOpacity(1-opacity);
    p.drawImage(QPoint(shiftA_x, shiftA_y), bot);
    p.setOpacity(opacity);
    p.drawImage(QPoint(shiftB_x,shiftB_y), top);

    int wa = ui->label_picMixed->width();
    int ha = ui->label_picMixed->height();
    ui->label_picMixed->setPixmap(combined.scaled(wa,ha,Qt::KeepAspectRatio));

    p.end();
}
