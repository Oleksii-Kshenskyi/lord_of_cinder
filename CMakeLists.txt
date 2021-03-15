cmake_minimum_required(VERSION 3.0.0)

project(LordOfCinder)

get_filename_component(CINDER_PATH "/opt/cinder" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

find_package(Boost COMPONENTS system filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories(${APP_PATH}/include)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

ci_make_app(
    APP_NAME "los"
    SOURCES ${APP_PATH}/src/los_app.cxx
    INCLUDES ${APP_PATH}/include
    CINDER_PATH ${CINDER_PATH}
    LIBRARIES ${Boost_LIBRARIES}
)