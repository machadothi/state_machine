#include "state.h"
#include "context.h"

class TestContext : public IContext 
{
public:
   TestContext();

   virtual ~TestContext() {
      std::cout << "TestContext deleted!\n";
   }

   void start(IState_ptr &&state) override;

   void stop() override;
   
   /**
    * The Context allows changing the State object at runtime.
    */
   void transition_to(IState_ptr &&state) override;
   /**
    * The Context delegates part of its behavior to the current State object.
    */

   IContext::Status run() override;

}; // class TestContext