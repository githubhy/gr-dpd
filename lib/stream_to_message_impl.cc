/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "stream_to_message_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace dpd {

using input_type = gr_complex;
using output_type = gr_complex;
stream_to_message::sptr stream_to_message::make()
{
    return gnuradio::make_block_sptr<stream_to_message_impl>();
}


/*
 * The private constructor
 */
stream_to_message_impl::stream_to_message_impl()
    : gr::sync_block("stream_to_message",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         0 /* min outputs */, 0 /*max outputs */, 0))//sizeof(output_type)))
{
    message_port_register_out(pmt::mp("samples"));
}

/*
 * Our virtual destructor.
 */
stream_to_message_impl::~stream_to_message_impl() {}

int stream_to_message_impl::work(int noutput_items,
                                 gr_vector_const_void_star& input_items,
                                 gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    // auto out = static_cast<output_type*>(output_items[0]);

    // Do <+signal processing+>

    for (int i = 0; i < noutput_items; i++) {
        // Converting stream item to message PMT
        pmt::pmt_t P_complex_samples = pmt::from_complex(in[i]);
        message_port_pub(pmt::mp("samples"), P_complex_samples);
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace dpd */
} /* namespace gr */
