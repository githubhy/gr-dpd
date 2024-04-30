/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DPD_LMS_POSTDISTORTER_H
#define INCLUDED_DPD_LMS_POSTDISTORTER_H

#include <gnuradio/dpd/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace dpd {

/*!
 * \brief LMS based Algorithm implemented to estimate the coefficients of
 *  the behaviorial model (GMP) of the Power Amplifier and thus
 *  predistorter taps.
 * \ingroup dpd
 *
 * \details
 *  It estimates the coefficients based on the PA_output and PA_input.
 *  It uses the LMS (Least Mean Squares) Algorithm with two methods options,
 *  namely, Newton based and EMA based methods.
 *
 *  It has two input ports, one for the PA_output (gain phase calibrated)
 *  and other for the PA_input (or predistorter output).
 *
 *  The coefficients estimated are passed as messages through message
 *  output port 'taps'.
 *  Both Input ports are only for Complex Data Type.
 */
class DPD_API LMS_postdistorter : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<LMS_postdistorter> sptr;

    /*!
     * \brief Make LMS_postdistorter
     *
     * \param dpd_params The (K_a, L_a, K_b, L_b, M_b) int_vector denoting
     *  the GMP model parameters used for predistorter 'taps' estimation.
     *  Total No. of coefficients = ((K_a * L_a) + (K_b * M_b * L_b))
     * \param iter_limit Iteration limit or Max. number of iterations of training
     *  to be performed for predistorter DPD coefficients estimation.
     * \param method Method of LMS algorithm used for coefficients estimation,
     *  i.e., Newton or EMA based method
     * \param learning_rate Learning rate, float value can lie in range 0 to 1.
     *
     */
    static sptr make(const std::vector<int>& dpd_params,
                     int iter_limit,
                     std::string method,
                     gr_complexd learning_rate);
};

} // namespace dpd
} // namespace gr

#endif /* INCLUDED_DPD_LMS_POSTDISTORTER_H */
