#ifndef TIMER_API_HPP
#define TIMER_API_HPP

#include <Arduino.h>

/**
 * @class TimerAPI
 * @brief A simple timer class for measuring elapsed time intervals.
 *
 * The TimerAPI class allows you to create and manage timers to measure elapsed
 * time intervals. It can be useful in various Arduino projects and other
 * embedded systems applications.
 */
class TimerAPI {
public:
  /**
   * @brief Constructor for the TimerAPI class.
   *
   * @param interval The time interval (in milliseconds) for the timer.
   * @param autoReset If true, the timer automatically resets after each
   * interval. If false, you need to manually reset the timer using the reset()
   * method.
   */
  TimerAPI(unsigned long interval, bool start = true, bool autoReset = true);

  /**
   * @brief Start the timer.
   *
   * This method starts the timer. If the timer is already running, this method
   * does nothing.
   */
  void start();

  /**
   * @brief Stop the timer.
   *
   * This method stops the timer.
   */
  void stop();

  /**
   * @brief Reset the timer to its initial state.
   *
   * If auto-reset is disabled, you can use this method to manually reset the
   * timer.
   */
  void reset();

  /**
   * @brief Set the time interval for the timer.
   *
   * @param interval The new time interval (in milliseconds) for the timer.
   */
  void set_interval(unsigned long interval);

  /**
   * @brief Set whether the timer should automatically reset after each
   * interval.
   *
   * @param autoReset If true, the timer will auto-reset; if false, manual reset
   * is required.
   */
  void set_auto_reset(bool autoReset);

  /**
   * @brief Check if the timer has elapsed the specified interval.
   *
   * @return True if the timer has elapsed, false otherwise.
   */
  bool has_elapsed();

private:
  unsigned long interval_; //!< The time interval for the timer.
  bool auto_reset_;        //!< Flag to indicate if the timer should auto-reset.
  unsigned long target_time_; //!< The target time for the timer.
};

#endif // !TIMER_API_HPP
