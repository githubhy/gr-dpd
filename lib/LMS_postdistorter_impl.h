/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DPD_LMS_POSTDISTORTER_IMPL_H
#define INCLUDED_DPD_LMS_POSTDISTORTER_IMPL_H

#include <gnuradio/dpd/LMS_postdistorter.h>
#include <armadillo>
using namespace arma;

namespace gr {
namespace dpd {

class LMS_postdistorter_impl : public LMS_postdistorter
{
private:
    std::vector<int> d_dpd_params;
    int K_a, K_b, L_a, L_b, M_b;
    int M;
    int d_iter_limit;
    std::string str;
    int iteration;

    cx_mat w_iMinus1;
    const int sreg_len = 50;
    gr_complexd sreg[50];
    const gr_complexd* ptr_sreg = sreg;
    gr_complexd pa_input, error, learning_rate;

    std::vector<gr_complexd> taps;

public:
    LMS_postdistorter_impl(const std::vector<int>& dpd_params,
                           int iter_limit,
                           std::string method,
                           gr_complexd learning_rate);
    ~LMS_postdistorter_impl();

    // Least Squares Estimation utility
    cx_mat ls_estimation(cx_mat A, gr_complexd y);
    // Genrates shift-structured GMP vector
    void gen_GMPvector(const gr_complexd* const in,
                       int item,
                       int K_a,
                       int L_a,
                       int K_b,
                       int M_b,
                       int L_b,
                       cx_colvec& GMP_vector);
    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace dpd
} // namespace gr

#endif /* INCLUDED_DPD_LMS_POSTDISTORTER_IMPL_H */
