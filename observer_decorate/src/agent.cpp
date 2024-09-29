#include <iostream>
#include <cmath>
#include "agent.hpp"

/* INITIALIZE STATIC FIELDS*/
unsigned long CAgent::AGENT_ID = 0;

CAgent::CAgent(double x, double y, double heading, double speed, double drange)
{
    AGENT_ID++;

    m_position.x = x;
    m_position.y = y;

    m_heading = heading;
    m_speed = speed;
    m_detect_range = drange;
}

CAgent::~CAgent()
{

}

void CAgent::maneuver(double time)
{
    m_position.x += sin(DEG2RAD(m_heading)) * m_speed * time;
    m_position.y += cos(DEG2RAD(m_heading)) * m_speed * time;

}

bool CAgent::detect(Pos loc)
{
    return false;
}

const Pos& CAgent::getPosition() const
{
    return m_position;
}

unsigned long CAgent::getAgentID() const
{
    return AGENT_ID;
}

double CAgent::getSpeed() const
{
    return m_speed;
}

double CAgent::getHeading() const
{
    return m_heading;
}

double CAgent::getRange() const
{
    return m_detect_range;
}

std::ostream& operator<<( std::ostream& os, const CAgent& ag)
{
        const Pos pos = ag.getPosition();
        os << "Agent ID:" << ag.getAgentID() << '(' << (long) pos.x << ", " << (long) pos.y << ")";
        os << " [S: " << ag.getSpeed() << ", H: " << ag.getHeading() << ", R: " << ag.getRange()<< "]";
        return os;
    }