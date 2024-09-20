add_executable(ListeTesteur ListeTesteur.cpp)

target_include_directories(ListeTesteur PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(
        ListeTesteur
        gtest
        gtest_main
        pthread
)

include(GoogleTest)
gtest_discover_tests(ListeTesteur)