#include <uringio/uring_reactor.hpp>

namespace uringio {

  void uring_reactor::run()
  {
    while (!queue_.empty()) {
      if (queue_.front().type()==work_t::io_type::none) {
        auto w = queue_.front();
        queue_.pop();
        queue_.push(w);
      }
      else {
        // do something with the work
        std::unique_lock lock(work_mutex_);
        // dequeue and schedule work
        auto w = queue_.front();
        schedule_work(w);
        queue_.pop();
      }
    }
  }

} // uringio
