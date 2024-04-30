/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DPD_STREAM_TO_MESSAGE_H
#define INCLUDED_DPD_STREAM_TO_MESSAGE_H

#include <gnuradio/dpd/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace dpd {

/*!
 * \brief Converts a stream of single complex data item into messages (PMT's)
 *  which are published by output message port 'message'.
 * \ingroup dpd
 *
 */
class DPD_API stream_to_message : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<stream_to_message> sptr;

    /*!
     * \brief Make stream_to_message block
     *
     */
    static sptr make();
};

} // namespace dpd
} // namespace gr

#endif /* INCLUDED_DPD_STREAM_TO_MESSAGE_H */
