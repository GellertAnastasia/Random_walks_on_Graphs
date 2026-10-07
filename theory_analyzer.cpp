#include "theory_analyzer.h"

#include <algorithm>

TheoryResult TheoryAnalyzer::calculate(const AbsorbingChain& chain, int initialState, int cheese,
                                       int cat) {
    TheoreticalCalculator calculator(chain);

    const auto& transientStates = chain.getTransientStates();

    const auto& absorbingStates = chain.getAbsorbingStates();

    int transientIndex = std::find(transientStates.begin(), transientStates.end(), initialState) -
                         transientStates.begin();

    int cheeseIndex =
        std::find(absorbingStates.begin(), absorbingStates.end(), cheese) - absorbingStates.begin();

    int catIndex =
        std::find(absorbingStates.begin(), absorbingStates.end(), cat) - absorbingStates.begin();

    TheoryResult result;

    result.meanAbsorptionTime = calculator.getMean()(transientIndex);

    result.variance = calculator.getVariance()(transientIndex);

    result.probCheese = calculator.getB()(transientIndex, cheeseIndex);

    result.probCat = calculator.getB()(transientIndex, catIndex);

    result.graphSize = static_cast<int>(transientStates.size() + absorbingStates.size());

    return result;
}