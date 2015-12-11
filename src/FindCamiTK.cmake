#
# DO NOT EDIT THIS FILE OR YOU WILL DAMAGE ALL YOUR CONFIGURATION
#
# Try to find a CamiTK installation or build tree (CAMITK_DIR)
# If CamiTK is not found, CAMITK_FOUND is set to false.
#
# This module can be used to find CamiTK.
#
# To use this file, you just need to have the path to it in your
# CMAKE_MODULE_PATH and add this line to your CMakeLists.txt
#
# find_package(CamiTK ${CAMITK_VERSION} REQUIRED)
#
# where CAMITK_VERSION is the minimal needed version (e.g. "3.2")
#
# Once done, just add this line to your CMakeLists.txt:
# include("${CAMITK_USE_FILE}")
# et voilà!
#
# Once this module has run, the following variables will be properly defined
#  CAMITK_FOUND            - system has CamiTK
#  CAMITK_DIR              - root installation for CamiTK (at least the SDK)
#  CAMITK_USE_FILE         - CMake file to use CamiTK (CamiTKConfig.cmake)
#  CAMITK_VERSION_MAJOR    - CamiTK major version number.
#  CAMITK_VERSION_MINOR    - CamiTK minor version number
#

#=============================================================================
# $CAMITK_LICENCE_BEGIN$
# 
# CamiTK - Computer Assisted Medical Intervention ToolKit
# (c) 2001-2014 UJF-Grenoble 1, CNRS, TIMC-IMAG UMR 5525 (GMCAO)
# 
# Visit http://camitk.imag.fr for more information
# 
# This file is part of CamiTK.
# 
# CamiTK is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License version 3
# only, as published by the Free Software Foundation.
# 
# CamiTK is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License version 3 for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# version 3 along with CamiTK.  If not, see <http://www.gnu.org/licenses/>.
# $CAMITK_LICENCE_END$
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

#-- CamiTK currently support CMake 2.8.12 policy (not 3.0 yet)
cmake_policy(VERSION 2.8.12)

message(STATUS "Looking for CamiTK ${CamiTK_FIND_VERSION}")

# Assume not found.
set(CAMITK_FOUND FALSE)

# name of the camitk configuration file (created during SDK build)
set(CAMITK_USE_FILE "CamiTKConfig.cmake")
set(CAMITK_DIR_DESCRIPTION "directory containing a build tree or install tree of CamiTK.\n   It must have the camitk-config binary in its 'bin' subdirectory.")

# ------------------------------------
# Stage #1: try to find camitk-config
# ------------------------------------

# User Config directory variable (if the user installed CamiTK her/himself the
# CamiTKDir.txt file can be found there
# see http://qt-project.org/doc/qt-4.8/qsettings.html#platform-specific-notes
if(WIN32)
    # %APPDATA%
    set(FIND_CAMITK_USER_BASE_DIR $ENV{APPDATA})
else() # (UNIX OR APPLE)
    # $HOME/.config/
    set(FIND_CAMITK_USER_BASE_DIR "$ENV{HOME}/.config")
endif()

# Check if the user installed CamiTK her/himself
if (EXISTS "${FIND_CAMITK_USER_BASE_DIR}/CamiTK/CamiTKDir.txt")
    file(STRINGS "${FIND_CAMITK_USER_BASE_DIR}/CamiTK/CamiTKDir.txt" FIND_CAMITK_USER_DIR_LAST_INSTALL)
endif()

# Try to find camitk-config binary in usual/recommanded path/variable/user directories
find_program(CAMITK_CONFIG_EXECUTABLE
        NAMES camitk-config-debug camitk-config
        PATH_SUFFIXES "bin"
        PATHS
                #-- 0. from CAMITK_DIR environment or cache variable
                "${CAMITK_DIR}"
                "$ENV{CAMITK_DIR}"

                #-- 1. Build path
                # Read from the CMakeSetup registry entries.  It is likely that
                # CamiTK will have been recently built.
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild1]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild2]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild3]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild4]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild5]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild6]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild7]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild8]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild9]
                [HKEY_CURRENT_USER\\Software\\Kitware\\CMakeSetup\\Settings\\StartPath;WhereBuild10]

                # For camitk opensource compilation
                "${CMAKE_BINARY_DIR}"

                #-- 2. installed path
                # Unix/MacOS
                "/usr"
                "/usr/local"
                "/opt/CamiTK"
                "$ENV{HOME}/Dev/CamiTK"
                "$ENV{HOME}/Dev/camitk"
                
                # Windows
                "C:/Programs "
                "C:/Programs/CamiTK"
                "C:/Program Files/CamiTK"
                "C:/Programs/camitk"
                "C:/Program Files/camitk"
                "C:/Dev"
                "C:/Dev/CamiTK"
                "C:/Dev/camitk"

                # From last installation
                "${FIND_CAMITK_USER_DIR_LAST_INSTALL}"
)

# hide this from the user
mark_as_advanced(CAMITK_CONFIG_EXECUTABLE)

# ---------------------------------
# Stage 2: Identify CamiTK version
# ---------------------------------
if (NOT CAMITK_CONFIG_EXECUTABLE)
    # camitk-config is not in an obvious place, ask the user to update its PATH env. variable, or define CAMITK_DIR
    set(CAMITK_NOT_FOUND_MESSAGE "CamiTK not found.\n   To solve this problem, you can (in order of preference):\n   a) make sure CamiTK SDK is installed and camitk-config is in a directory included\n      in the environment command path ($PATH or %PATH%).\n   b) or specify the CMake cache variable (e.g. modify the value directly in the cmake GUI\n      or run cmake from the command line with -DCAMITK_DIR:PATH=...)\n   c) or specify a CAMITK_DIR environment variable (system variable)")
    # use file was not found, camitk-imp was no help
    set(CAMITK_DIR "CAMITK_DIR-NOTFOUND" CACHE PATH "The ${CAMITK_DIR_DESCRIPTION}" FORCE)
else()
    # get the path to the installation dir from the camitk-config
    execute_process(COMMAND "${CAMITK_CONFIG_EXECUTABLE}" "--camitkDir"
                RESULT_VARIABLE CAMITK_CONFIG_DIR_RETURN_CODE
                OUTPUT_VARIABLE CAMITK_CONFIG_DIR_OUTPUT
                ERROR_VARIABLE  CAMITK_CONFIG_DIR_OUTPUT_ERROR
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_STRIP_TRAILING_WHITESPACE
    )    

    if (CAMITK_CONFIG_DIR_RETURN_CODE)
        set(CAMITK_NOT_FOUND_MESSAGE "CamiTK configuration utility reports errors. Check the output of ${CAMITK_DIR}/bin/camitk-config --camitkDir\n   Returns:\n   ${CAMITK_CONFIG_DIR_RETURN_CODE}\n   Error message:\n${CAMITK_CONFIG_DIR_OUTPUT_ERROR}\n   Output:${CAMITK_CONFIG_DIR_OUTPUT}")
    else()
        # use camitk-config output directly
        set(CAMITK_DIR ${CAMITK_CONFIG_DIR_OUTPUT})
        
        # get the version number automatically from camitk-config
        execute_process(COMMAND "${CAMITK_CONFIG_EXECUTABLE}" "--shortVersion"
                    RESULT_VARIABLE CAMITK_CONFIG_VERSION_RETURN_CODE
                    OUTPUT_VARIABLE CAMITK_CONFIG_VERSION_OUTPUT
                    ERROR_VARIABLE  CAMITK_CONFIG_VERSION_OUTPUT_ERROR
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    ERROR_STRIP_TRAILING_WHITESPACE
        )

        if (CAMITK_CONFIG_VERSION_RETURN_CODE)
            set(CAMITK_NOT_FOUND_MESSAGE "CamiTK configuration utility reports errors. Check the output of ${CAMITK_DIR}/bin/camitk-config --shortVersion\n   Returns:\n   ${CAMITK_CONFIG_VERSION_RETURN_CODE}\n   Error message:\n${CAMITK_CONFIG_VERSION_OUTPUT_ERROR}\n   Output:${CAMITK_CONFIG_VERSION_OUTPUT}")
        else()
            # use camitk-config output directly
            set(CAMITK_SHORT_VERSION_STRING ${CAMITK_CONFIG_VERSION_OUTPUT})
            # extract major and minor version
            string(REGEX REPLACE "^camitk-([0-9]+).*" "\\1" CAMITK_VERSION_MAJOR "${CAMITK_SHORT_VERSION_STRING}")
            string(REGEX REPLACE "^camitk-[0-9]+\\.([0-9]+)" "\\1" CAMITK_VERSION_MINOR "${CAMITK_SHORT_VERSION_STRING}")
            set(CAMITK_VERSION_FOUND "${CAMITK_VERSION_MAJOR}.${CAMITK_VERSION_MINOR}")
        endif()
    endif()   
endif()


# -----------------------------------------------------------------------------------
# Stage 3: check that the version matches (if the user asked for a specific version)
# -----------------------------------------------------------------------------------
if (CAMITK_VERSION_FOUND)
    if(CamiTK_FIND_VERSION)
        if ("${CAMITK_VERSION_FOUND}" STRLESS "${CamiTK_FIND_VERSION}")
            set(CAMITK_NOT_FOUND_MESSAGE "CamiTK ${CAMITK_VERSION_FOUND} found, mismatch required version ${CamiTK_FIND_VERSION}\n   To solve this problem, you can (in order of preference):\n   a) make sure CamiTK SDK ${CamiTK_FIND_VERSION} is installed and camitk-config is in a directory included\n      in the environment command path ($PATH or %PATH%) before the install dir of version ${CAMITK_VERSION_FOUND}\n   b) or specify the CMake cache variable (e.g. modify the value directly in the cmake GUI\n      or run cmake from the command line with -DCAMITK_DIR:PATH=...)\n   c) or specify a CAMITK_DIR environment variable (system variable)\n   d) or remove the version requirement in the CMakeLists.txt (e.g. use a simple\n      \"find_package(CamiTK REQUIRED)\" without specifying the version)")
        else()
            set(CAMITK_VERSION_MESSAGE " (found suitable version \"${CAMITK_VERSION_FOUND}\", required is \"${CamiTK_FIND_VERSION}\")")
            set(CAMITK_FOUND TRUE)            
        endif()
    else()
        set(CAMITK_FOUND TRUE)
    endif()
endif()

# -------------------------
# Stage 4: Notify the user
# -------------------------
if(CAMITK_FOUND)
    # advertise the success
    message(STATUS "Found CamiTK (version ${CAMITK_VERSION_FOUND}) in ${CAMITK_DIR}${CAMITK_VERSION_MESSAGE}")
    # update module path and use file
    set(CAMITK_USE_FILE "CamiTKConfig")
    # setup the module path to find the use file
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CAMITK_DIR}/share/${CAMITK_SHORT_VERSION_STRING}/cmake)
else()
    # CamiTK not found, explain to the user how to specify its location.
    if(CamiTK_FIND_REQUIRED)
        message(FATAL_ERROR ${CAMITK_NOT_FOUND_MESSAGE})
    else()
        if(NOT CamiTK_FIND_QUIETLY)
            message(STATUS ${CAMITK_NOT_FOUND_MESSAGE})
        endif()
    endif()
endif()

