#pragma once

namespace uringio {

  class uring_reactor;

  class work_t
  {
  public:
    enum class io_type
    {
      none, accept, read, write
    };

    work_t(uring_reactor* rtor, io_type = io_type::none);

    io_type const& type() const
    {
      return type_;
    }

  private:
    uring_reactor* rtor_;
    const io_type type_;
  };

} // uringio
