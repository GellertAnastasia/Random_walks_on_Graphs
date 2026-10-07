#include "experiment_runner.h"

#include "absorbing_chain.h"
#include "simulator.h"

#include <fstream>

void ExperimentRunner::run(const AbsorbingChain& chain, int initialState, int simulations,
                           const std::string& filename) {

    Simulator simulator(chain);

    std::ofstream file(filename);

    file << "simulation_id,absorption_time,absorbing_state\n";

    for (int i = 0; i < simulations; ++i) {
        Path path = simulator.run(initialState);

        file << i << "," << path.getAbsorptionTime() << "," << path.getLastState() << "\n";
    }
}