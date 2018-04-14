#include "thread.h"
#include <QDebug>

Thread::Thread()
{

}

void Thread::run(){
    QMessageLogger(__FILE__, __LINE__, 0).debug() << "From worker thread:" << currentThreadId();
}
