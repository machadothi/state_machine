#include "test_state_b.h"
#include "test_state_a.h"


TestStateB::TestStateB(std::shared_ptr<IContext> context) :
   IState(context, "test_b") {
      std::cout << "TestStateB Created!\n";
}

// -----------------------------------------------------------------------------

IState::Status TestStateB::run() {
   static unsigned value = 10;

   std::cout << "\nState B running, value: " << --value << std::endl;

   std::cout << "\nState B stoped. Transitioning to A." << std::endl;

   m_context->transition_to(make_state<TestStateA>(m_context));

   return Status::SUCCESS;
}