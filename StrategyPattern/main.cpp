#include "RedheadDuck.h"
#include "MallardDuck.h"
#include "RubberDuck.h"

int main()
{
    Duck* redHeadDuck = new RedHeadDuck();
    Duck* rubberDuck = new RubberDuck();
    Duck* mallardDuck = new MallardDuck();

    redHeadDuck->display();
    redHeadDuck->performFly();
    redHeadDuck->performQuack();

    rubberDuck->display();
    rubberDuck->performFly();
    rubberDuck->performQuack();

    mallardDuck->display();
    mallardDuck->performFly();
    mallardDuck->performQuack();

    delete redHeadDuck;
    delete rubberDuck;
    delete mallardDuck;
}