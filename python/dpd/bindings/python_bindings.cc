/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/pybind11.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

namespace py = pybind11;

// Headers for binding functions
/**************************************/
// The following comment block is used for
// gr_modtool to insert function prototypes
// Please do not delete
/**************************************/
// BINDING_FUNCTION_PROTOTYPES(
    void bind_gain_phase_calibrate(py::module& m);
    void bind_GMP_model_PA(py::module& m);
    void bind_LMS_postdistorter(py::module& m);
    void bind_MP_model_PA(py::module& m);
    void bind_predistorter_training(py::module& m);
    void bind_RLS_postdistorter(py::module& m);
    void bind_stream_to_gmp_vector(py::module& m);
    void bind_stream_to_message(py::module& m);
// ) END BINDING_FUNCTION_PROTOTYPES


// We need this hack because import_array() returns NULL
// for newer Python versions.
// This function is also necessary because it ensures access to the C API
// and removes a warning.
void* init_numpy()
{
    import_array();
    return NULL;
}

PYBIND11_MODULE(dpd_python, m)
{
    // Initialize the numpy C API
    // (otherwise we will see segmentation faults)
    init_numpy();

    // Allow access to base block methods
    py::module::import("gnuradio.gr");

    /**************************************/
    // The following comment block is used for
    // gr_modtool to insert binding function calls
    // Please do not delete
    /**************************************/
    // BINDING_FUNCTION_CALLS(
    bind_gain_phase_calibrate(m);
    bind_GMP_model_PA(m);
    bind_LMS_postdistorter(m);
    bind_MP_model_PA(m);
    bind_predistorter_training(m);
    bind_RLS_postdistorter(m);
    bind_stream_to_gmp_vector(m);
    bind_stream_to_message(m);
    // ) END BINDING_FUNCTION_CALLS
}