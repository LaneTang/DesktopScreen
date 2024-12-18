# Register components in the 'components' folder
file(GLOB_RECURSE COMPONENT_SRCS "components/src/*.c")
file(GLOB_RECURSE COMPONENT_INCLUDES "components/inc")

idf_component_register(
    SRCS "main.c" ${COMPONENT_SRCS}  # Include both main.c and components' .c files
    INCLUDE_DIRS "." ${COMPONENT_INCLUDES}  # Include directories for header files
    REQUIRES  # Add any dependencies if necessary, such as FreeRTOS, etc.
)