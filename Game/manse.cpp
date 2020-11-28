#include "manse.h"

Manse::Manse()
{
    gamestarted_ = false;
}

void Manse::setBackground(QImage& basicbackground, QImage& bigbackground)
{
    Q_UNUSED(basicbackground)
    Q_UNUSED(bigbackground)

    //Currently test implementation in main, implementation here probably later
}

void Manse::setClock(QTime clock)
{
    time_ = clock;
}

void Manse::startGame()
{
    gamestarted_ = true;
}

bool Manse::isGameOver() const
{
    if (prog_ >= 0) {
        return false;
    }
    else {
        return true;
    }
}

void Manse::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}

void Manse::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    //this was the only way we figured out to seperate passengers from buses here
    if (stops_.size() == 0) {
        actors_.push_back(newactor);
    }
}

void Manse::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void Manse::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    //This does not ever seem to be called
    actor->isRemoved();
}

bool Manse::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for (auto a : actors_) {
        if (a == actor) {
            return true;
        }
    }
    return false;
}

void Manse::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_UNUSED(actor)
}

std::vector<std::shared_ptr<Interface::IActor> > Manse::getNearbyActors(Interface::Location loc) const
{

    std::vector<std::shared_ptr<Interface::IActor> > close;

    for (auto a : actors_) {

        int nx = a->giveLocation().giveX();
        int ny = a->giveLocation().giveY();
        Interface::Location b;

        b.setXY(nx + X_MOD, Y_MOD - ny);

        if (b.isClose(loc, RANGE)) {
            close.push_back(a);
        }
    }
    return close;
}

std::vector<std::shared_ptr<Interface::IActor> > Manse::getActors()
{
    return actors_;
}

void Manse::addPlayer(std::shared_ptr<Player> player)
{
    player_ = player;
}

std::shared_ptr<Player> Manse::getPlayer()
{
    return player_;
}

void Manse::addEnemy(std::shared_ptr<Chaser> enemy)
{
    enemy_ = enemy;
}

std::shared_ptr<Chaser> Manse::getEnemy()
{
    return enemy_;
}

std::vector<std::shared_ptr<Interface::IStop> > Manse::getStops()
{
    return stops_;
}

void Manse::getProg(int progress)
{
    prog_ = progress;
}
