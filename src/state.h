/*
********************************************************************************
********************************************************************************
***
***     Project: Alexandra
***
***     Copyright (C) Stoneridge Electronics AB 1990 - 2018
***
***     The information in this document belongs to Stoneridge, Inc. or its
***     subsidiaries and may be confidential. This document and information
***     in it may not be copied, reproduced, revealed or appropriated, either
***     in whole or in part, without the prior written consent of
***     Stoneridge, Inc.
***
********************************************************************************
********************************************************************************
*/

#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <iostream>
#include <memory>
#include <string>

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
 */
class IContext;

class IState {
    /**
     * @var Context
     */
protected:
   std::string m_name;
   std::shared_ptr<IContext> m_context;

   IState(std::weak_ptr<IContext> context,
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

   typedef std::shared_ptr<IState> ptr_t;

   virtual ~IState(){}

   std::string name() const
   {
      return m_name;
   }

   virtual Status run() = 0;
};

typedef IState::ptr_t IState_ptr;

#endif // SRC_STATE_H_