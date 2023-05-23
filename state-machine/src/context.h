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

#ifndef SRC_CONTEXT_H_
#define SRC_CONTEXT_H_

#include <iostream>
#include <string>

#include "state.h"

class IContext {
   /**
    * @var State A reference to the current state of the Context.
    */
protected:
   IState_ptr m_state = nullptr;

public:
   enum class Status {
      SUCCESS,
      ERROR,
      FATAL_ERROR,   
      RUNNING
   };

   typedef std::shared_ptr<IContext> ptr_t;

   IContext() {}

   virtual ~IContext() {}

   virtual void transition_to(IState_ptr &&state) = 0;

   virtual void start(IState_ptr &&state) = 0;

   virtual Status run() = 0;

   virtual void stop() = 0;

};

typedef IContext::ptr_t IContext_ptr;


template<typename State>
std::unique_ptr<State> make_state(std::shared_ptr<IContext> &c)
{
    return std::unique_ptr<State>(new State(c));
}

#endif // SRC_CONTEXT_H_