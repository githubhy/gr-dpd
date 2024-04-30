/* -*- c++ -*- */
/*
 * Copyright 2024 gr-dpd author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DPD_GAIN_PHASE_CALIBRATE_H
#define INCLUDED_DPD_GAIN_PHASE_CALIBRATE_H

#include <gnuradio/block.h>
#include <gnuradio/dpd/api.h>

namespace gr {
namespace dpd {

/*!
 * \brief  Removes the gain from the Power Amplifier Output to calibrate it
 *  for error calculation with the predistorter output (input to PA).
 * \ingroup dpd
 *
 * \details
 *  It has three input ports, of which, first is the PA_DPD to be calibrated
 *  and the other two inputs, i.e., Input Sample and PA_Output are used to
 *  calculate the inverse gain multiplier.
 *
 *  Both Input and Output Ports are only for Complex Data Type.
 */
class DPD_API gain_phase_calibrate : virtual public gr::block
{
public:
    typedef std::shared_ptr<gain_phase_calibrate> sptr;

    /*!
     * \brief Make the gain_phase_calibrate block
     *
     */
    static sptr make();
};

} // namespace dpd
} // namespace gr

#endif /* INCLUDED_DPD_GAIN_PHASE_CALIBRATE_H */
