cmake_minimum_required(VERSION 2.8)
project(QRcodeProcessing)
add_executable(main.o ../test/main.cpp ../src/extract.cpp ../src/processVideo.cpp ../src/splice.cpp ../src/identify.cpp)
find_package(OpenCV 3 REQUIRED)
target_link_libraries(main.o ${OpenCV_LIBS} ${ZBAR_LIBS})

set(zbar_include_dir "/usr/local/include")
set(zbar_link_dir "/usr/local/lib")

include_directories(${zbar_include_dir})
link_directories(${zbar_link_dir})
link_libraries(zbar)

target_link_libraries(main.o zbar)

