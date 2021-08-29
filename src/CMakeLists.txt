set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS} 
  ${CMAKE_SOURCE_DIR}/lib/fmt/include
  engine
)

add_subdirectory(engine)

add_executable(${CMAKE_PROJECT_NAME}
  main
  game
)

add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_SOURCE_DIR}/examples
    $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/examples
)

target_link_libraries(${CMAKE_PROJECT_NAME} engine)