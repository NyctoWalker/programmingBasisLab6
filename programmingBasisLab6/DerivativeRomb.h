#include "Romb.h"

class NewRomb : public Romb
{
private:
    Point prevA, prevB, prevC, prevD;
    Point middle;
    double axis_angle = 0;
public:
    void NewCreateRomb();
    void Reset();
    void NewPrintRomb();
    void TurnPoint(Point &TURN, const double angle);
    void TurnRomb();
};