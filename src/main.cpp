#include <iostream>
#include <unifex/on.hpp>
#include <unifex/single_thread_context.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/task.hpp>

constexpr int expected = 42;

int main() {
  auto ctx1 = unifex::single_thread_context{};
  auto ctx2 = unifex::single_thread_context{};

  auto f1 = [&]() -> unifex::task<int> {
    co_await unifex::schedule(ctx1.get_scheduler());
    co_return expected;
  };

  auto f2 = [&]() -> unifex::task<int> { co_return co_await f1(); };

  auto result = unifex::sync_wait(unifex::on(ctx2.get_scheduler(), f2()));
  if (!result.has_value()) {
    throw "result has no value";
  }
  if (result.value() == expected) {
    std::cout << "as expected" << std::endl;
  } else {
    throw "result is not as expected";
  }
}
