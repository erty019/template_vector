file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${vectortest} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${vectortest}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${vectortest} ${vectorlib} gtest) #Подключаем к проекту с именем ${vector} библиотеки с именами ${vectorlib} и gtest
