#ifndef UTIL_H
#define UTIL_H

using namespace std;

namespace util
{

    long calcPos(int x, int y, int length)
    {
        return y * length + x;
    }

    int wrap(int kX, int const kLowerBound, int const kUpperBound)
    {
        int range_size = kUpperBound - kLowerBound + 1;

        if (kX < kLowerBound)
            kX += range_size * ((kLowerBound - kX) / range_size + 1);

        return kLowerBound + (kX - kLowerBound) % range_size;
    }
}

#endif // UTIL_H
