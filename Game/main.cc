#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>
#include <QGraphicsScene>
#include <actors/nysse.hh>
#include <actors/passenger.hh>
#include <actors/stop.hh>
#include <core/location.hh>
#include <core/logic.hh>
#include <errors/gameerror.hh>
#include <errors/initerror.hh>
#include <graphics/simpleactoritem.hh>
#include <graphics/simplemainwindow.hh>
#include <interfaces/iactor.hh>
#include <interfaces/icity.hh>
#include <interfaces/ipassenger.hh>
#include <interfaces/istatistics.hh>
#include <interfaces/istop.hh>
#include <interfaces/ivehicle.hh>
#include <creategame.hh>
#include <doxygeninfo.hh>
#include <offlinereader.hh>



class Manse: public virtual Interface::ICity {
    public:
    int a = 10;
};


int main(int argc, char *argv[])
{
    Manse man;



    QApplication a(argc, argv);
    CourseSide::SimpleMainWindow w;
    w.show();



    Q_INIT_RESOURCE(offlinedata);



    return a.exec();
}
