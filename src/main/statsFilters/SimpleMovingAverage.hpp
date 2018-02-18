#ifndef __SIMPLE_MOVING_AVERAGE_HPP_
#define __SIMPLE_MOVING_AVERAGE_HPP_

#include "Filter.hpp"

namespace pasdam {
namespace statsFilters {

class SimpleMovingAverage: public Filter
{
public:
    explicit SimpleMovingAverage(int windowSize = 10);
    explicit SimpleMovingAverage(const SimpleMovingAverage& other);
    virtual ~SimpleMovingAverage();

    virtual double       filter(double value, long timestamp) override;
    virtual unsigned int getModelSamplesCount() const override;
    virtual unsigned int getTotalSamplesCount() const override;
    virtual void         reset() override;

private:
    unsigned int mIndex;
    unsigned int mN;
    double       mSum;
    unsigned int mTotalSamples;
    double*      mWindow;
    unsigned int mWindowSize;
};

} // namespace statsFilters
} // namespace pasdam
#endif // __SIMPLE_MOVING_AVERAGE_HPP_
