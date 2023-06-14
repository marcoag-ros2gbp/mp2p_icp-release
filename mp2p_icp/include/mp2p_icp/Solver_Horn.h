/* -------------------------------------------------------------------------
 *  A repertory of multi primitive-to-primitive (MP2P) ICP algorithms in C++
 * Copyright (C) 2018-2021 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   Solver_Horn.h
 * @brief  ICP solver for pointclouds split in different "layers"
 * @author Jose Luis Blanco Claraco
 * @date   Jan 20, 2019
 */
#pragma once

#include <mp2p_icp/Solver.h>

namespace mp2p_icp
{
/** ICP registration for pointclouds split in different "layers"
 *
 * \ingroup mp2p_icp_grp
 */
class Solver_Horn : public Solver
{
    DEFINE_MRPT_OBJECT(Solver_Horn, mp2p_icp)
   public:
    /** Weight and robust kernel parameters associated with the low-level
     * optimal pose estimation algorithms */
    WeightParameters pairingsWeightParameters;

    void initialize(const mrpt::containers::yaml& params) override;

   protected:
    // See base class docs
    bool impl_optimal_pose(
        const Pairings& pairings, OptimalTF_Result& out,
        const SolverContext& sc) const override;
};

}  // namespace mp2p_icp