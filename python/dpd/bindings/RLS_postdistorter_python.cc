/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(RLS_postdistorter.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(5e698cb235e970e7ec67718c28fd2e90)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dpd/RLS_postdistorter.h>
// pydoc.h is automatically generated in the build directory
#include <RLS_postdistorter_pydoc.h>

void bind_RLS_postdistorter(py::module& m)
{

    using RLS_postdistorter = gr::dpd::RLS_postdistorter;


    py::class_<RLS_postdistorter,
               gr::block,
               gr::basic_block,
               std::shared_ptr<RLS_postdistorter>>(
        m, "RLS_postdistorter", D(RLS_postdistorter))

        .def(py::init(&RLS_postdistorter::make),
             py::arg("dpd_params"),
             py::arg("iter_limit"),
             D(RLS_postdistorter, make))


        ;
}
