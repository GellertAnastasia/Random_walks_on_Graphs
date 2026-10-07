#include "coursework_experiments.h"

int main() {
    CourseworkExperiments experiments(10000);

    experiments.runSizeExperiment();
    experiments.runDeadEndExperiment();
    experiments.runDeadEndLengthExperiment();
    experiments.runCycleExperiment();
    experiments.runJointExperiment();

    return 0;
}