
add_executable(MacroLab
    main.cpp
    CameraHandler.cpp
    CommandInterface.cpp
    FrameManager.cpp
    FrameAnalyzer.cpp
    DecisionFunctions.cpp
)

target_link_libraries(MacroLab
    ${OpenCV_LIBS}
    ${GPHOTO2_LIBRARIES}
)
