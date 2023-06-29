if (NOT BUILD_TEST)
    message("Build LuxRedis tests.")
    add_subdirectory(test)
else()
    message("Don't Build LuxRedis tests.")
endif()

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)
add_library(Lute_Redis STATIC ${srcs})
target_include_directories(Lute_Redis PUBLIC include)
# 依赖
target_link_libraries(Lute_Redis PUBLIC Lute_Base hiredis)
