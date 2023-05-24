#include <iostream>
#include <memory>
#include <vector>

#include "state.h"
#include "context.h"
#include "test_context.h"
#include "test_state_a.h"

int main() {

   std::shared_ptr<IContext> context(new TestContext());

   context->start(make_state<TestStateA>(context));

   std::vector<int> v = {0, 1, 2, 3, 4, 5};
   for (auto i : v) {
      std::cout << " running index: " << i << std::endl;
      context->run();
   }

   return 0;
}