    cmake_minimum_required(VERSION 3.10.0)
    project(flappy VERSION 0.1.0 LANGUAGES C CXX)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

  
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets/" DESTINATION "${CMAKE_BINARY_DIR}/assets/")
    file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
        "src/*.cpp"
        "src/**/*.cpp" # This finds .cpp files in subdirectories of src
    )
    add_executable(flappy ${SOURCE_FILES})
    find_package(raylib CONFIG REQUIRED)

    target_link_libraries(flappy PRIVATE raylib)

