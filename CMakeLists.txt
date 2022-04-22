cmake_minimum_required(VERSION 3.8)

project(CharifyProject)

# Externe Bibs
add_subdirectory(charify)

if (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CharifyProject)
	set_property(TARGET Charify PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()
