set(CHARIFY_SOURCE_FILES
	src/main.cpp
    src/image.cpp
    src/kernel.cpp
)

set(CHARIFY_HEADER_FILES
	stb_image.h
    image.hpp
    kernel.hpp
)

add_executable(Charify ${CHARIFY_SOURCE_FILES} ${CHARIFY_HEADER_FILES})
target_include_directories(Charify PUBLIC ..)
set_target_properties(Charify PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
