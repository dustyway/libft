function(target_set_warnings TARGET ENABLED ENABLED_AS_ERRORS)
    if (NOT ${ENABLED})
        message(STATUS "Warnings Disabled for: ${TARGET}")
    endif ()
    set(CLANG_WARNINGS
        -Wall
        -Wextra
        -Wpedantic)

    set(GCC_WARNINGS
            -Wall
            -Wextra
            -Wpedantic)

    if(${ENABLED_AS_ERRORS})
        set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
        set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
    endif ()

    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
        set(WARNINGS ${GCC_WARNINGS})
    endif ()

    target_compile_options(${TARGET} PRIVATE ${WARNINGS})
endfunction(target_set_warnings)


