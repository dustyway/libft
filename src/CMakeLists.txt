project(libft VERSION 0.0.2 LANGUAGES C)

set(CMAKE_C_STANDARD 90)



set(LIBFT_DIR libft_core)
set(FTPRINTF_DIR ft_printf)
set(GNL_DIR get_next_line)
set(LIBFT_ADD_DIR libft_addendum)
set(HT_DIR hashtable)
set(QU_DIR queue)
set(ST_DIR stack)
set(MATH_DIR mathematics)

add_subdirectory(${LIBFT_DIR})
add_subdirectory(${LIBFT_ADD_DIR})
add_subdirectory(${FTPRINTF_DIR})
add_subdirectory(${GNL_DIR})
add_subdirectory(${HT_DIR})
add_subdirectory(${QU_DIR})
add_subdirectory(${ST_DIR})
add_subdirectory(${MATH_DIR})

list(TRANSFORM SRC_LIBFT PREPEND "${LIBFT_DIR}/")
list(TRANSFORM SRC_FTPRINTF PREPEND "${FTPRINTF_DIR}/")
list(TRANSFORM SRC_GNL PREPEND "${GNL_DIR}/")
list(TRANSFORM SRC_LIBFT_ADD PREPEND "${LIBFT_ADD_DIR}/")
list(TRANSFORM SRC_HT PREPEND "${HT_DIR}/")
list(TRANSFORM SRC_QU PREPEND "${QU_DIR}/")
list(TRANSFORM SRC_ST PREPEND "${ST_DIR}/")
list(TRANSFORM SRC_MATH PREPEND "${MATH_DIR}/")

set(SRC_FILES
        ${SRC_LIBFT}
        ${SRC_GNL}
        ${SRC_FTPRINTF}
        ${SRC_LIBFT_ADD}
        ${SRC_HT}
        ${SRC_QU}
        ${SRC_ST}
        ${SRC_MATH}
)

add_library(${LIBRARY_NAME} STATIC ${SRC_FILES})
if(ENABLE_WARNINGS)
    target_set_warnings(${LIBRARY_NAME} ON OFF)
endif ()
