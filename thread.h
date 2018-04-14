#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
private:
    void run();

public:
    Thread();
};

#endif // THREAD_H
