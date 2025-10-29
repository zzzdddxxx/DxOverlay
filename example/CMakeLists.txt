

file(GLOB TARGET_SOURCE 
				"${PROJECT_SOURCE_DIR}/src/*.cpp" 
				"${PROJECT_SOURCE_DIR}/src/*.h" 
				"${PROJECT_SOURCE_DIR}/example/*.cpp" 
				"${PROJECT_SOURCE_DIR}/example/*.h" 
)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${TARGET_SOURCE})

add_executable(example ${TARGET_SOURCE})

set_target_properties(example  PROPERTIES AUTOMOC ON)
set_target_properties(example  PROPERTIES AUTORCC ON)
set_target_properties(example  PROPERTIES AUTOUIC ON)

#如果启用此变量，T4​​074T 会自动将 CMAKE_CURRENT_SOURCE_DIR 和 CMAKE_CURRENT_BINARY_DIR 添加到每个目录的包含路径中。这些额外的包含目录不会传播到子目录。这主要用于源外构建，其中生成到构建树中的文件由位于源树中的文件包含。
#用于解决ui_xxx.h无法打开情况
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core )

target_link_libraries(example PRIVATE 
						Qt6::Widgets
						Qt6::Core 
)

target_include_directories(example PRIVATE 
				"${PROJECT_SOURCE_DIR}/src/
				"${PROJECT_SOURCE_DIR}/example
)