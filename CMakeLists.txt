cmake_minimum_required(VERSION 3.30)

include(FetchContent)

set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(vcpkg
    GIT_REPOSITORY https://github.com/microsoft/vcpkg.git
    GIT_TAG dfb72f61c5a066ab75cd0bdcb2e007228bfc3270)
FetchContent_MakeAvailable(vcpkg)

set(CMAKE_TOOLCHAIN_FILE
    "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "" FORCE)

project(a.out LANGUAGES CXX)

find_package(unifex CONFIG REQUIRED)

add_executable(a.out
    src/main.cpp)

target_link_libraries(a.out
    PRIVATE
        unifex::unifex)

target_compile_features(a.out PRIVATE cxx_std_23)


