find_package(hiredis)

if(hiredis_FOUND)
    message(STATUS "hiredis found~")
else()
    message(STATUS "hiredis NOT found")
    message(STATUS "    SET hiredis_DIR to /usr/local/lib/hiredis")
    SET(hiredis_DIR /usr/local/lib/hiredis)
endif()


file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)
add_library(Lute_Redis STATIC ${srcs})
target_include_directories(Lute_Redis PUBLIC include)
# 依赖
target_link_libraries(Lute_Redis PUBLIC Lute_Base hiredis)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Build Redis tests.")
    add_subdirectory(test)
else()
    message("Don't Build Redis tests.")
endif()
