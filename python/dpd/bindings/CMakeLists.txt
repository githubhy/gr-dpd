# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT dpd_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT dpd_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND dpd_python_files
    gain_phase_calibrate_python.cc
    GMP_model_PA_python.cc
    LMS_postdistorter_python.cc
    MP_model_PA_python.cc
    predistorter_training_python.cc
    RLS_postdistorter_python.cc
    stream_to_gmp_vector_python.cc
    stream_to_message_python.cc python_bindings.cc)

gr_pybind_make_oot(dpd ../../.. gr::dpd "${dpd_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET dpd_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dpd_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/dpd/)

install(
    TARGETS dpd_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/dpd
    COMPONENT pythonapi)
