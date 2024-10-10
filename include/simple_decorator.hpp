#pragma once
#include "base_decorator.hpp"

class CSimpleDecorator: public BaseDecorator
{
public:
    CSimpleDecorator(CAgent* pAgent):BaseDecorator(pAgent){}

public:
    virtual bool detect(CAgent* pTarget)
    {
        std::cout << "CSimpleDecorator" << std::endl;
        return m_wrappee->detect(pTarget);
    }
};