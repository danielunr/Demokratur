#ifndef POSITION_H
#define POSITION_H


class position
{
private:
    int x;
    int y;
public:
    position();
    ~position();
    position(int x, int y);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    bool equal(position pos);
};

#endif // POSITION_H
