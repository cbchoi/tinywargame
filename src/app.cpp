#include <iostream>
#include "agent.hpp"
#include "stochastic_decorator.hpp"
#include "simple_decorator.hpp"
#include "mmanager.hpp"

int main(int argc, char** argv)
{// Clinet Code
    
    
    /* Simulation Engine */
    CManeuverManager mmanager;

    /* Simulation Model Registration */
    CAgent* p_agent1 = new CAgent(10,  0, 0, 1, 10);
    p_agent1 = new CStochasticDecorator(p_agent1);
    p_agent1 = new CSimpleDecorator(p_agent1);
    
    mmanager.register_publisher(p_agent1);

    CAgent* p_agent2 = new CAgent(10,  30, 180, 1, 10);
    mmanager.register_publisher(p_agent2);

    //CAgent* p_agent3 = new CAgent(15, 15, 0, 0, 10);
    //mmanager.register_publisher(p_agent3);
    //mmanager.register_subscriber(p_agent3);

    /* Simulation Engine Initialization */
    double sim_time;
    double time_step = 1;

    for(sim_time = 0; sim_time < 30; sim_time += time_step)
    {   
        mmanager.svc(time_step);

        std::cout << "----" << std::endl;
        std::cout << "Time: " << time_step << ", " <<*p_agent1 << std::endl;
        std::cout << "Time: " << time_step << ", " <<*p_agent2 << std::endl;
        //std::cout << "Time: " << time_step << ", " <<*p_agent3 << std::endl;
    }
    return 0;
}
