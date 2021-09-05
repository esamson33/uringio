#include "uringio/work.hpp"
#include "uringio/uring_reactor.hpp"

namespace uringio {

  work_t::work_t(uring_reactor* rtor, io_type type)
      :rtor_{rtor}, type_{type}
  {
    rtor->add_work(*this);
  }

}