#include "test_context.h"

TestContext::TestContext()
{
   std::cout << "TestContext created!" << std::endl;
}

void TestContext::start(IState_ptr &&state)
{
   transition_to(std::move(state));
}

void TestContext::stop()
{
   this->m_state.reset();
}
/**
 * The Context allows changing the State object at runtime.
 */
void TestContext::transition_to(IState_ptr &&state)
{
   std::cout << "Context: Transition to " << state->name() << ".\n";

   this->m_state = std::move(state);
}
/**
 * The Context delegates part of its behavior to the current State object.
 */

IContext::Status TestContext::run()
{
   static unsigned attempt = 5;

   switch(m_state->run())
   {
      case IState::Status::SUCCESS:
         std::cout << "State " << this->m_state->name() 
         << " ran successfully\n";
         return Status::RUNNING;

      case IState::Status::RUNNING:
         std::cout << "State " << this->m_state->name() 
         << " running\n";
         return Status::RUNNING;
      
      case IState::Status::FINISHED:
         std::cout << "Modem recovered successfully!\n";
         return Status::SUCCESS;

      case IState::Status::ERROR:
      case IState::Status::TIMEOUT:
         --attempt;

         if(!attempt)
         {
            return Status::FATAL_ERROR;
         }
         
         return Status::ERROR;
   }

   return Status::ERROR;
}
