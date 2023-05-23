#include "state.h"
#include "context.h"

/**
 * @brief This test script only implements concrete classes based on the state and
 * context classes. Its purpose is to see the output of each concrete class method
 * only.
 * 
 * To run it:
 * $ source $SDKPATH
 * $ qemu-arm -L $SDKTARGETSYSROOT ./test/unit_tests --gtest_filter=TestStateMachine.CreateConcreteContext
 */

class TestStateB : public IState
{
public:
   TestStateB(std::shared_ptr<IContext> context);

   virtual ~TestStateB() {
      std::cout << "TestStateB deleted!\n";
   }

   IState::Status run() override;

};