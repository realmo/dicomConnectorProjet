#--------------------------------------------
#         CamiTK Extension Project
#--------------------------------------------
cmake_minimum_required(VERSION 2.6)

# Find CamiTK SDK
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
find_package(CamiTK REQUIRED)
include(${CAMITK_USE_FILE})

# define the CEP
camitk_extension_project(NAME "src" 
                         CONTACT "jean-loup.haberbusch@imag.fr"
                         DESCRIPTION "Source directory for the DicomConnector Action"
                         ENABLED
)



