# **************************************************************************
# * Copyright(c) 1998-2014, ALICE Experiment at CERN, All rights reserved. *
# *                                                                        *
# * Author: The ALICE Off-line Project.                                    *
# * Contributors are mentioned in the code where appropriate.              *
# *                                                                        *
# * Permission to use, copy, modify and distribute this software and its   *
# * documentation strictly for non-commercial purposes is hereby granted   *
# * without fee, provided that the above copyright notice appears in all   *
# * copies and that both the copyright notice and this permission notice   *
# * appear in the supporting documentation. The authors make no claims     *
# * about the suitability of this software for any purpose. It is          *
# * provided "as is" without express or implied warranty.                  *
# **************************************************************************

# Additional include folders in alphabetical order except ROOT
include_directories(SYSTEM ${ROOT_INCLUDE_DIR})
include_directories(${AliRoot_SOURCE_DIR}/ITSMFT/COMMONITSMFT
                   )


# Libraries
add_subdirectory(COMMONITSMFTBase)
add_subdirectory(COMMONITSMFTSim)
add_subdirectory(COMMONITSMFTRec)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/misc)
    install(DIRECTORY misc DESTINATION ITSMFT/COMMONITSMFT)
elseif(FATAL_IF_MISSING)
    message(FATAL_ERROR "misc is missing")
endif()

message(STATUS "COMMONITSMFT from ITSMFT enabled")
