#pragma once

#include <iostream>
#include "definition.hpp"

class CAgent
{
public:
    CAgent(double x, double y, double heading, double speed, double drange);
    virtual ~CAgent();

public:
    void maneuver(double time);
    bool detect(Pos loc);

public:
    const Pos& getPosition() const;
    unsigned long getAgentID() const;
    double getSpeed() const;
    double getHeading() const;
    double getRange() const;

private:
    Pos    m_position;  
    double m_heading;
    double m_speed;
    double m_detect_range;

private:
    static unsigned long AGENT_ID;

public:
    friend std::ostream& operator<<(std::ostream& os, const CAgent& ag);
};