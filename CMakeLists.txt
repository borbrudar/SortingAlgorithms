cmake_minimum_required(VERSION 3.16)
if(WIN32)
    #no spaces in path
    set(CMAKE_INSTALL_PREFIX C:/ CACHE PATH "default path" FORCE)
endif()
set(PR_NAME Sorting)
project(${PR_NAME} VERSION 0.1.0)
set(CMAKE_CXX_STANDARD)

include(GNUInstallDirs)
enable_testing()


find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    #get submodules etc
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules.")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/SFML/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again. :/")
endif()


#source files
set(SOURCES
    BinaryTree
    Bubble
    Bucket
    Button 
    Cycle 
    Dropdown
    Game 
    Insertion 
    main    
    Merge 
    Quick  
    QuickTree 
    Selection 
    SortingAlgorithm
    StringU
)

list(TRANSFORM SOURCES APPEND ".cpp")
list(TRANSFORM SOURCES PREPEND "src/")

if(UNIX)
    set(CMAKE_INSTALL_RPATH $ORIGIN/../lib)
endif()

add_executable(${PR_NAME} ${SOURCES})

target_include_directories(${PR_NAME} 
PRIVATE
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/src>
)

#copy sfml and openal .dlls
if(WIN32)
    add_custom_command(TARGET ${PR_NAME} POST_BUILD
       COMMAND ${CMAKE_COMMAND} -E copy 
       "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-audio-2.dll"
       "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-graphics-2.dll"
       "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-system-2.dll"
       "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-window-2.dll"
        ${CMAKE_CURRENT_BINARY_DIR})
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/win32/OpenAL32.dll"
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)    
endif()

#copy fonts
file(COPY font DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

#add sfml
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/SFML")
target_link_libraries(${PR_NAME} sfml-graphics sfml-audio)

#------------------INSTALL SECTION----------------------
install(TARGETS ${PR_NAME} 
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/font DESTINATION ${CMAKE_INSTALL_BINDIR})

if(WIN32)
    #sfml
    add_custom_command(TARGET ${PR_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-audio-2.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-graphics-2.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-system-2.dll"
        "${CMAKE_CURRENT_BINARY_DIR}/external/SFML/lib/sfml-window-2.dll"
         ${CMAKE_CURRENT_BINARY_DIR})
    #openal ig
    add_custom_command(TARGET ${PR_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_CURRENT_SOURCE_DIR}/win32/OpenAL32.dll"
                ${CMAKE_INSTALL_BINDIR})
elseif(UNIX)
    install(TARGETS ${PR_NAME} 
       LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

#-------PACKAGING------------------------------------
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack) 

