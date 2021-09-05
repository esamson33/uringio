#pragma once

#include <mutex>
#include <queue>
#include <uringio/work.hpp>

namespace uringio {

  class uring_reactor
  {
  public:

    // default constructor
    uring_reactor() = default;

    // run reactor loop
    void run();

  private:
    void add_work(work_t const& work)
    {
      queue_.push(work);
    }

    void schedule_work(work_t const& w) { }

    friend class work_t;

  private:
    std::queue<work_t> queue_;
    std::mutex work_mutex_;
  };

} // uringio
