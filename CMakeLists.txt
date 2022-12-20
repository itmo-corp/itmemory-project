cmake_minimum_required(VERSION 3.16)
project(helloworld)

set(KF5_DEP_VERSION "5.79.0")
set(REQUIRED_QT_VERSION "5.15.0")

add_definitions( -Wall -O0 -fexceptions )

find_package(ECM ${KF5_DEP_VERSION} REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(Qt5 ${REQUIRED_QT_VERSION} REQUIRED NO_MODULE COMPONENTS Core Quick Test Gui QuickControls2 Widgets)
find_package(KF5 ${KF5_DEP_VERSION} REQUIRED COMPONENTS Kirigami2 I18n CoreAddons)

if(ANDROID)
    find_package(Qt5AndroidExtras ${REQUIRED_QT_VERSION} REQUIRED)
    # include(${CMAKE_CURRENT_SOURCE_DIR}/android_openssl/CMakeLists.txt)
    find_package(OpenSSL REQUIRED COMPONENTS Crypto SSL)
else()
    find_package(Qt${QT_MAJOR_VERSION}Widgets ${REQUIRED_QT_VERSION} REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
