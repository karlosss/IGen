# ================================================================================
# Add here user defined variables
# ================================================================================
set(IGEN_LIB             ../../igen_lib)
set(IGEN_COMMON          ../../common)
set(MPREAL               ../../third-party/mpreal)
if (NOT DEFINED IGEN_VEC)
    set(IGEN_VEC "YES")   # Use IGen with vectorized output by default
#    set(IGEN_VEC "NO")
endif()

# ================================================================================
# User configuration. E.g. compiler, debug, verbose, etc
# ================================================================================
set(PROJECT_NAME immintrin)       # Specify project name
set(CONFIG_COMPILER "GNU")           # GNU, Clang or Intel
set(CONFIG_DEBUG "OFF")              # ON or OFF
set(CONFIG_GENERATE_ASSEMBLY "OFF")  # ON or OFF
set(CMAKE_VERBOSE_MAKEFILE "OFF")    # ON or OFF
set(CONFIG_FLAGS "-O3 -march=skylake -frounding-math")
#set(CONFIG_LIBRARIES mpfi mpfr yalaa prim m gaol gdtoa crlibm)    # Used libraries, e.g. crlibm, mpfr
set(CONFIG_LIBRARIES mpfi mpfr m crlibm)    # Used libraries, e.g. crlibm, mpfr

# ================================================================================
# Include directories, set source files and user definitions
# ================================================================================
if (${IGEN_VEC} STREQUAL "YES")
    add_definitions(-DIGEN_LIB_VECTORIZED)
endif()

include_directories(
        ${IGEN_LIB}
        ${IGEN_COMMON}
        libraries
        mpfr
        ${MPREAL}
)

#AUX_SOURCE_DIRECTORY(netlib NETLIB_SRC)

set(SOURCE_FILES
        main.cpp
        common.h
        init.cpp
        verify.cpp
        benchmark.cpp
        random_range.cpp

        benchmarks/mm256_blend_pd.cpp

        # IGen files
        ${IGEN_COMMON}/util.cpp
        ${IGEN_LIB}/igen_dd_immintrin_fallback.c
        ${IGEN_LIB}/igen_immintrin_fallback.c
        )

# ================================================================================
# Do not modify the following
# ================================================================================
cmake_minimum_required(VERSION 3.14)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

# ================================================================================
# Specify compiler and flags (do not change this)
# ================================================================================
if (${CONFIG_COMPILER} STREQUAL GNU)
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
    set(CMAKE_C_COMPILER_ID "GNU")
    set(CMAKE_CXX_COMPILER_ID "GNU")
elseif(${CONFIG_COMPILER} STREQUAL Clang)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_C_COMPILER_ID "Clang")
    set(CMAKE_CXX_COMPILER_ID "Clang")
elseif(${CONFIG_COMPILER} STREQUAL Intel)
    set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
    set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")
    set(CMAKE_C_COMPILER_ID "Intel")
    set(CMAKE_CXX_COMPILER_ID "Intel")
else()
    message([FATAL_ERROR] " Compiler not selected correctly in CMakeLists. Using default config" ...)
endif ()

# Reset compiler flags to get full control
set(CMAKE_C_FLAGS           "")
set(CMAKE_CXX_FLAGS         "")
set(CMAKE_C_FLAGS_RELEASE   "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_C_FLAGS_DEBUG     "")
set(CMAKE_CXX_FLAGS_DEBUG   "")

# Define standard
set(CMAKE_C_FLAGS   "-std=c11 -Wno-deprecated -g")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated -g")

if (${CONFIG_DEBUG} STREQUAL "ON")
    # Debug flag
    set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -O0 -g -march=native -frounding-math --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -march=native -frounding-math --coverage")
else()
    # Set compiler flags
    set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS} ${CONFIG_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CONFIG_FLAGS}")
endif ()


# ================================================================================
# Define binary executable and libraries to be linked (Do not change this)
# ================================================================================
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (${CONFIG_GENERATE_ASSEMBLY} MATCHES "ON")
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -save-temps)
endif ()

# Add math library for floating point environment
target_link_libraries(${PROJECT_NAME} ${CONFIG_LIBRARIES})
