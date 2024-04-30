/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gain_phase_calibrate_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace dpd {

using input_type = gr_complex;
using output_type = gr_complex;
gain_phase_calibrate::sptr gain_phase_calibrate::make()
{
    return gnuradio::make_block_sptr<gain_phase_calibrate_impl>();
}


/*
 * The private constructor
 */
gain_phase_calibrate_impl::gain_phase_calibrate_impl()
    : gr::block("gain_phase_calibrate",
                gr::io_signature::make(
                    3 /* min inputs */, 3 /* max inputs */, sizeof(input_type)),
                gr::io_signature::make(
                    1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
    previous_cfactor = gr_complex(0.0, 0.0);
    d_reference_acquired = false;
    d_sample = gr_complex(0.0, 0.0);
}

/*
 * Our virtual destructor.
 */
gain_phase_calibrate_impl::~gain_phase_calibrate_impl() {}

void gain_phase_calibrate_impl::forecast(int noutput_items,
                                         gr_vector_int& ninput_items_required)
{
    ninput_items_required[0] = noutput_items;
    ninput_items_required[1] = noutput_items;
    ninput_items_required[2] = noutput_items;
}

bool gain_phase_calibrate_impl::almost_equals_zero(double a, int num_digits)
{
    // identify the first few significant digits
    int na = floor(fabs(a) * pow(10.0, num_digits));

    if (na == 0)
        return true;

    return false;
}

int gain_phase_calibrate_impl::general_work(int noutput_items,
                                            gr_vector_int& ninput_items,
                                            gr_vector_const_void_star& input_items,
                                            gr_vector_void_star& output_items)
{
    auto in1 = static_cast<const input_type*>(input_items[0]); // PA_output
    auto in2 = static_cast<const input_type*>(input_items[1]); // Input Sample
    auto in3 = static_cast<const input_type*>(input_items[2]); // PA_DPD
    auto out = static_cast<output_type*>(output_items[0]);

    // Do <+signal processing+>
    _ninput_items = std::min(ninput_items[0], noutput_items);
    item = 0;
    gr_complex cfactor_avg_sum = gr_complex(0.0, 0.0);
    while (item < _ninput_items) {

        sample = in2[item];
        current_cfactor = sample / in1[item]; // Inverse of PA gain

        if (previous_cfactor != gr_complex(0.0, 0.0)) {
            cfactor_avg_sum = cfactor_avg_sum + current_cfactor;
            cfactor = cfactor_avg_sum / gr_complex(item + 1.0);
        } else
            cfactor = current_cfactor;

        // cfactor = gr_complex(0.5, 0.0) * (previous_cfactor + current_cfactor);

        if (!almost_equals_zero(std::real(in1[item]), 5) &&
            !almost_equals_zero(std::imag(in1[item]), 5))
            previous_cfactor = cfactor;

        out[item] = cfactor * in3[item];
        item++;
    }

    // Tell runtime system how many input items we consumed on
    // each input stream.
    consume_each(noutput_items);

    // Tell runtime system how many output items we produced.
    return _ninput_items;
}

} /* namespace dpd */
} /* namespace gr */
