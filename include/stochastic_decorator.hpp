#pragma once
#include "base_decorator.hpp"

class CStochasticDecorator: public BaseDecorator
{
public:
    CStochasticDecorator(CAgent* pAgent):BaseDecorator(pAgent){}

public:
    virtual bool detect(CAgent* pTarget)
    {
        std::cout << "StochasticDecorator" << std::endl;
        return m_wrappee->detect(pTarget);
    }
};