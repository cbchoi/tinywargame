#include <iostream>
#include "agent.hpp"

#include "mmanager.hpp"

int main(int argc, char** argv)
{
    // Clinet Code
    CAgent agent1(0,  0, 270, 1, 10);
    //CAgent agent2(10, 0, 90, 1);
    //CAgent agent3(20, 0, 180, 1);
    
    /* Simulation Engine */
    CManeuverManager mmanager;

    double sim_time;
    double time_step = 1;

    for(sim_time = 0; sim_time < 100; sim_time += time_step)
    {
        agent1.maneuver(time_step);
        //agent2.maneuver(time_step);
        //agent3.maneuver(time_step);

        std::cout << "----" << std::endl;
        std::cout << agent1 << std::endl;
        //std::cout << agent2 << std::endl;
        //std::cout << agent3 << std::endl;
    }
    return 0;
}
