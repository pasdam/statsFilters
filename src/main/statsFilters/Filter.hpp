#ifndef __FILTER_HPP_
#define __FILTER_HPP_

namespace pasdam {
namespace statsFilters {

/**
 * @brief The Filter class interface implemented by classes that filter a samples series
 */
class Filter
{
public:
    virtual ~Filter() {}

    /**
     * @brief filter adds the sample to the serie and returns the filtered value
     * @param value sample to filter
     * @param timestamp
     * @return the filtered value
     */
    virtual double filter(double value, long timestamp) = 0;

    /**
     * @brief getModelSamplesCount returns the number of samples used by the model to filter new ones
     * @return the number of samples used by the model
     */
    virtual unsigned int getModelSamplesCount() const = 0;

    /**
     * @brief getTotalSamplesCount returns the total number of samples added
     * @return the number of samples added
     */
    virtual unsigned int getTotalSamplesCount() const = 0;

    /**
     * @brief reset resets the state of the filter
     */
    virtual void reset() = 0;
};

} // namespace statsFilters
} // namespace pasdam
#endif // __FILTER_HPP_
