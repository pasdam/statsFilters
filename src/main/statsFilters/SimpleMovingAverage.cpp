#include "SimpleMovingAverage.hpp"

#include <cstring>

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

SimpleMovingAverage::SimpleMovingAverage(const SimpleMovingAverage& other)
    : mIndex(other.mIndex)
    , mN(other.mN)
    , mSum(other.mSum)
    , mTotalSamples(other.mTotalSamples)
    , mWindowSize(other.mWindowSize)
{
    mWindow = new double[other.mWindowSize];
    memcpy(mWindow, other.mWindow, sizeof(double) * other.mWindowSize);
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
