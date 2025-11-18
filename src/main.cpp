#include <fmt/format.h>
#include <fmt/ranges.h>

#include <unifex/on.hpp>
#include <unifex/single_thread_context.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/task.hpp>
#include <vector>

auto expected = std::vector<int>{1, 2, 3, 4, 5};

int main() {
  auto ctx1 = unifex::single_thread_context{};
  auto ctx2 = unifex::single_thread_context{};

  auto f1 = [&]() -> unifex::task<decltype(expected)> {
    co_await unifex::schedule(ctx1.get_scheduler());
    co_return expected;
  };

  auto f2 = [&]() -> unifex::task<decltype(expected)> {
    co_return co_await f1();
  };

  auto result = unifex::sync_wait(unifex::on(ctx2.get_scheduler(), f2()));
  if (!result.has_value()) {
    throw "result has no value";
  }

  if (result.value() == expected) {
    fmt::println("expected:{}", expected);
    fmt::println("result.value():{}", result.value());
    fmt::println("ok");
  } else {
    throw "result is not as expected";
  }
}
