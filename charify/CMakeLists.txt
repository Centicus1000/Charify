set(CHARIFY_SOURCE_FILES
	main.cpp
)

add_executable(Charify ${CHARIFY_SOURCE_FILES})
target_link_libraries(Charify PUBLIC )
set_target_properties(Charify PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
