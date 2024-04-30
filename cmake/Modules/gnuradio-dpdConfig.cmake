find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_DPD gnuradio-dpd)

FIND_PATH(
    GR_DPD_INCLUDE_DIRS
    NAMES gnuradio/dpd/api.h
    HINTS $ENV{DPD_DIR}/include
        ${PC_DPD_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_DPD_LIBRARIES
    NAMES gnuradio-dpd
    HINTS $ENV{DPD_DIR}/lib
        ${PC_DPD_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-dpdTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_DPD DEFAULT_MSG GR_DPD_LIBRARIES GR_DPD_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_DPD_LIBRARIES GR_DPD_INCLUDE_DIRS)
