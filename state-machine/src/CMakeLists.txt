file(GLOB SOURCES_APP "*.cpp")

add_executable(${APP_NAME} ${SOURCES_APP})

target_link_libraries(${APP_NAME} pthread)

include(GNUInstallDirs)
install(TARGETS ${APP_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
