
add_executable(MacroLab
    main.cpp
)

target_link_libraries(MacroLab
    ${OpenCV_LIBS}
    ${GPHOTO2_LIBRARIES}
)
