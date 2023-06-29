add_executable(RedisTest Redis_unit.cc)
target_link_libraries(RedisTest PRIVATE Lute_Base Lute_Redis)
