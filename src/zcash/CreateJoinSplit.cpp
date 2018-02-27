// Copyright (c) 2016 The Zcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//#include "../util.h"
//#include "primitives/transaction.h"
#include "zcash/JoinSplit.hpp"
#include "zcash/ShieldTransaction.h"
#include <libsnark/common/profiling.hpp>

using namespace libzcash;

int main(int argc, char **argv)
{
    libsnark::start_profiling();

    char* home = getenv("HOME");
    string param_path;
    
    if (home == NULL || strlen(home)) {
        param_path = "/.zcash-params";
    } else {
        param_path = string(home) + "/.zcash-params";
    }

    auto p = ZCJoinSplit::Prepared(param_path + "/sprout-verifying.key"),
                                  (param_path + "/sprout-proving.key"));

    // construct a proof.

    for (int i = 0; i < 5; i++) {
        uint256 anchor = ZCIncrementalMerkleTree().root();
        uint256 pubKeyHash;

        JSDescription jsdesc(*p,
                             pubKeyHash,
                             anchor,
                             {JSInput(), JSInput()},
                             {JSOutput(), JSOutput()},
                             0,
                             0);
    }

    delete p; // not that it matters
}
