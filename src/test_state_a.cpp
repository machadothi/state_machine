#include "test_state_a.h"
#include "test_state_b.h"

TestStateA::TestStateA(std::shared_ptr<IContext> context) :
   IState(context, "test_a") {
      std::cout << "TestStateA Created!\n";
}

// -----------------------------------------------------------------------------

IState::Status TestStateA::run() {
   static unsigned value = 10;

   std::cout << "\nState A running, value: " << --value << std::endl;

   std::cout << "\nState A stoped. Transitioning to B." << std::endl;
   
   m_context->transition_to(make_state<TestStateB>(m_context));

   return Status::SUCCESS;
}