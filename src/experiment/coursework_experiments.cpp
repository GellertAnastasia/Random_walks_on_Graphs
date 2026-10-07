#include "coursework_experiments.h"

CourseworkExperiments::CourseworkExperiments(int numberOfSimulations)
    : numberOfSimulations(numberOfSimulations) {}

void CourseworkExperiments::runSizeExperiment() {
    CSVManager simulationCSV("data/size_simulation.csv",
                             {"graph_size", "simulation_id", "absorption_time", "absorbing_state"});

    CSVManager theoryCSV("data/size_theory.csv",
                         {"graph_size", "initial_state", "mean_absorption_time", "variance",
                          "prob_cheese", "prob_cat"});

    for (int graphSize = 5; graphSize <= 41; graphSize += 4) {

        GraphModel model = graphBuilder.createSizeGraph(graphSize);

        AbsorbingChain chain(model);

        int initialState = graphSize / 2;
        int cheese = model.getCheese();
        int cat = model.getCat();

        TheoryResult theory = TheoryAnalyzer::calculate(chain, initialState, cheese, cat);

        theoryCSV.writeRow({std::to_string(graphSize), std::to_string(initialState),
                            std::to_string(theory.meanAbsorptionTime),
                            std::to_string(theory.variance), std::to_string(theory.probCheese),
                            std::to_string(theory.probCat)});

        Simulator simulator(model);

        for (int simulationId = 0; simulationId < numberOfSimulations; ++simulationId) {
            Path path = simulator.run(initialState);

            simulationCSV.writeRow({std::to_string(graphSize), std::to_string(simulationId),
                                    std::to_string(path.getAbsorptionTime()),
                                    std::to_string(path.getLastState())});
        }
    }

    simulationCSV.close();
    theoryCSV.close();
}

void CourseworkExperiments::runDeadEndExperiment() {
    CSVManager simulationCSV("data/dead_end_simulation.csv",
                             {"number_of_dead_ends", "dead_end_length", "simulation_id",
                              "absorption_time", "absorbing_state"});

    CSVManager theoryCSV("data/dead_end_theory.csv",
                         {"number_of_dead_ends", "dead_end_length", "initial_state",
                          "mean_absorption_time", "variance", "prob_cheese", "prob_cat"});

    const int deadEndLength = 3;

    for (int numberOfDeadEnds = 1; numberOfDeadEnds <= 10; ++numberOfDeadEnds) {
        GraphModel model = graphBuilder.deadEndExperimentGraph(numberOfDeadEnds, deadEndLength);
        AbsorbingChain chain(model);
        int initialState = 7;

        int cheese = model.getCheese();
        int cat = model.getCat();
        TheoryResult theory = TheoryAnalyzer::calculate(chain, initialState, cheese, cat);

        theoryCSV.writeRow({std::to_string(numberOfDeadEnds), std::to_string(deadEndLength),
                            std::to_string(initialState), std::to_string(theory.meanAbsorptionTime),
                            std::to_string(theory.variance), std::to_string(theory.probCheese),
                            std::to_string(theory.probCat)});
        Simulator simulator(model);

        for (int simulationId = 0; simulationId < numberOfSimulations; ++simulationId) {
            Path path = simulator.run(initialState);

            simulationCSV.writeRow({std::to_string(numberOfDeadEnds), std::to_string(deadEndLength),
                                    std::to_string(simulationId),
                                    std::to_string(path.getAbsorptionTime()),
                                    std::to_string(path.getLastState())});
        }
    }

    simulationCSV.close();
    theoryCSV.close();
}

void CourseworkExperiments::runDeadEndLengthExperiment() {
    CSVManager simulationCSV("data/dead_end_length_simulation.csv",
                             {"number_of_dead_ends", "dead_end_length", "simulation_id",
                              "absorption_time", "absorbing_state"});

    CSVManager theoryCSV("data/dead_end_length_theory.csv",
                         {"number_of_dead_ends", "dead_end_length", "initial_state",
                          "mean_absorption_time", "variance", "prob_cheese", "prob_cat"});

    const int numberOfDeadEnds = 2;

    for (int deadEndLength = 1; deadEndLength <= 10; ++deadEndLength) {
        GraphModel model = graphBuilder.deadEndExperimentGraph(numberOfDeadEnds, deadEndLength);
        AbsorbingChain chain(model);
        int initialState = 7;

        int cheese = model.getCheese();
        int cat = model.getCat();
        TheoryResult theory = TheoryAnalyzer::calculate(chain, initialState, cheese, cat);

        theoryCSV.writeRow({std::to_string(numberOfDeadEnds), std::to_string(deadEndLength),
                            std::to_string(initialState), std::to_string(theory.meanAbsorptionTime),
                            std::to_string(theory.variance), std::to_string(theory.probCheese),
                            std::to_string(theory.probCat)});

        Simulator simulator(model);

        for (int simulationId = 0; simulationId < numberOfSimulations; ++simulationId) {
            Path path = simulator.run(initialState);

            simulationCSV.writeRow({std::to_string(numberOfDeadEnds), std::to_string(deadEndLength),
                                    std::to_string(simulationId),
                                    std::to_string(path.getAbsorptionTime()),
                                    std::to_string(path.getLastState())});
        }
    }

    simulationCSV.close();
    theoryCSV.close();
}

void CourseworkExperiments::runCycleExperiment() {
    CSVManager simulationCSV("data/cycle_simulation.csv", {"cycle_length", "simulation_id",
                                                           "absorption_time", "absorbing_state"});

    CSVManager theoryCSV("data/cycle_theory.csv",
                         {"cycle_length", "initial_state", "mean_absorption_time", "variance",
                          "prob_cheese", "prob_cat"});

    const int initialState = 3;

    for (int cycleLength = 3; cycleLength <= 15; ++cycleLength) {
        GraphModel model = graphBuilder.cycleExperimentGraph(cycleLength);

        AbsorbingChain chain(model);

        int cheese = model.getCheese();
        int cat = model.getCat();

        TheoryResult theory = TheoryAnalyzer::calculate(chain, initialState, cheese, cat);

        theoryCSV.writeRow({std::to_string(cycleLength), std::to_string(initialState),
                            std::to_string(theory.meanAbsorptionTime),
                            std::to_string(theory.variance), std::to_string(theory.probCheese),
                            std::to_string(theory.probCat)});

        Simulator simulator(model);

        for (int simulationId = 0; simulationId < numberOfSimulations; ++simulationId) {
            Path path = simulator.run(initialState);

            simulationCSV.writeRow({std::to_string(cycleLength), std::to_string(simulationId),
                                    std::to_string(path.getAbsorptionTime()),
                                    std::to_string(path.getLastState())});
        }
    }

    simulationCSV.close();
    theoryCSV.close();
}

void CourseworkExperiments::runJointExperiment() {
    CSVManager simulationCSV("data/joint_simulation.csv",
                             {"topology", "added_vertices", "total_vertices", "simulation_id",
                              "absorption_time", "absorbing_state"});

    CSVManager theoryCSV("data/joint_theory.csv",
                         {"topology", "added_vertices", "total_vertices", "initial_state",
                          "mean_absorption_time", "variance", "prob_cheese", "prob_cat"});

    std::vector<std::string> topologies = {"dead_end", "petal_cycle", "bypass_route"};

    const int initialState = 3;

    for (int addedVertices = 2; addedVertices <= 10; ++addedVertices) {
        for (const auto& topology : topologies) {
            GraphModel model = graphBuilder.createJointGraph(topology, addedVertices);

            AbsorbingChain chain(model);

            int cheese = model.getCheese();
            int cat = model.getCat();
            int totalVertices = static_cast<int>(model.getGraph().getCountVertices());

            TheoryResult theory = TheoryAnalyzer::calculate(chain, initialState, cheese, cat);

            theoryCSV.writeRow({topology, std::to_string(addedVertices),
                                std::to_string(totalVertices), std::to_string(initialState),
                                std::to_string(theory.meanAbsorptionTime),
                                std::to_string(theory.variance), std::to_string(theory.probCheese),
                                std::to_string(theory.probCat)});

            Simulator simulator(model);

            for (int simulationId = 0; simulationId < numberOfSimulations; ++simulationId) {
                Path path = simulator.run(initialState);

                simulationCSV.writeRow({topology, std::to_string(addedVertices),
                                        std::to_string(totalVertices), std::to_string(simulationId),
                                        std::to_string(path.getAbsorptionTime()),
                                        std::to_string(path.getLastState())});
            }
        }
    }

    simulationCSV.close();
    theoryCSV.close();
}