#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <iostream>
#include <memory>
#include <string>

class IContext;

class IState {
protected:
    std::string m_name;
    std::shared_ptr<IContext> m_context;

    IState(std::shared_ptr<IContext> context,
        const std::string &name) : 
        m_name(name),
        m_context(context) {}

public:
    enum class Status {
        SUCCESS,
        ERROR,  
        RUNNING,
        TIMEOUT,
        FINISHED
   };

   typedef std::unique_ptr<IState> ptr_t;

   virtual ~IState(){}

   std::string name() const
   {
      return m_name;
   }

   virtual Status run() = 0;
};
// -----------------------------------------------------------------------------

typedef IState::ptr_t IState_ptr;

#endif // SRC_STATE_H_