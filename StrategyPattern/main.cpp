#include "RedheadDuck.h"
#include "MallardDuck.h"
#include "RubberDuck.h"
#include "FlyBehavior.h"

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

    delete rubberDuck->flyBehavior;
    // Stategy can be easily changed in run time with the help of strategy pattern 
    rubberDuck->flyBehavior = new FlyWithRocket();
    rubberDuck->performFly();

    mallardDuck->display();
    mallardDuck->performFly();
    mallardDuck->performQuack();

    delete redHeadDuck;
    delete rubberDuck;
    delete mallardDuck;
}