#include "Duck.h"
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

    // Test copy constructors and assignment operators
    MallardDuck mDuck1;
    MallardDuck mDuck2 = mDuck1;
    MallardDuck mDuck3;
    mDuck1 = mDuck3;

    RedHeadDuck rDuck1;
    //RedHeadDuck rDuck2 = rDuck1; copy constructor is deleted
    RedHeadDuck rDuck3;
    //rDuck1 = rDuck3; assignment operator is deleted
}