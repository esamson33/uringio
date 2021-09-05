#include <uringio/uring_reactor.hpp>

int main()
{
  uringio::uring_reactor rtor;
  uringio::work_t w(&rtor);
  rtor.run();
  return 0;
}
