#ifndef COURSEWORK_EXPERIMENTS
#define COURSEWORK_EXPERIMENTS

#include "absorbing_chain.h"
#include "csv_manager.h"
#include "experiment_graph_builder.h"
#include "simulator.h"
#include "theory_analyzer.h"
#include "transition_matrix_builder.h"

class CourseworkExperiments {
private:
    ExperimentGraphBuilder graphBuilder;

    int numberOfSimulations;

public:
    CourseworkExperiments(int numberOfSimulations);

    void runSizeExperiment();
    void runDeadEndExperiment();
    void runDeadEndLengthExperiment();
    void runCycleExperiment();
    void runJointExperiment();
};

#endif