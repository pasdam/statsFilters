#include "SimpleMovingAverage.hpp"

using pasdam::statsFilters::SimpleMovingAverage;

SimpleMovingAverage::SimpleMovingAverage(int windowSize)
    : mIndex(0)
    , mN(0)
    , mSum(0)
    , mTotalSamples(0)
    , mWindowSize(windowSize)
{
    mWindow = new double[windowSize];
}

SimpleMovingAverage::~SimpleMovingAverage()
{
    delete[] mWindow;
}

double SimpleMovingAverage::filter(double value, long)
{
    if (mN < mWindowSize) {
        mN++;
    } else {
        mSum -= mWindow[mIndex];
    }

    mWindow[mIndex] = value;
    mSum += mWindow[mIndex];
    mIndex = (mIndex + 1) % mWindowSize;
    return mSum / mN;
}

unsigned int SimpleMovingAverage::getModelSamplesCount() const
{
    return mN;
}

unsigned int SimpleMovingAverage::getTotalSamplesCount() const
{
    return mTotalSamples;
}

void SimpleMovingAverage::reset()
{
    mIndex          = 0;
    mN              = 0;
    mSum            = 0;
    mTotalSamples   = 0;
    mWindow[mIndex] = 0;
}
