set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
project(engine)

find_package(SDL2_image REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS} 
  ${CMAKE_SOURCE_DIR}/lib/fmt/include
)

file(GLOB_RECURSE ENGINE_SRC "./*.cpp")
add_library(${PROJECT_NAME} STATIC ${ENGINE_SRC})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} fmt)