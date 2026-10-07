#ifndef THEORY_ANALYZER
#define THEORY_ANALYZER

#include "absorbing_chain.h"
#include "theoretical_calculator.h"
#include "theory_result.h"

class TheoryAnalyzer {
public:
    static TheoryResult calculate(const AbsorbingChain& chain, int initialState, int cheese,
                                  int cat);
};

#endif