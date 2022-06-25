add_library(labs lab3/backup_job.cpp lab3/backup_job.h lab3/job_object.cpp lab3/job_object.h lab3/repository.cpp lab3/repository.h lab3/restore_point.cpp lab3/restore_point.h lab3/storage.cpp lab3/storage.h)

add_subdirectory(libzippp-master)
include_directories(${libzippp-master_SOURCE_DIR}/src ${libzippp-master_SOURCE_DIR})

target_sources(labs
  PRIVATE
        lab3/job_object.cpp
  PUBLIC
        lab3/backup_job.h
  )

target_include_directories(labs
  PUBLIC
        .
  )

target_link_libraries(labs PRIVATE libzippp::libzippp)

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
    PUBLIC
      "--coverage"
    )
  target_link_options(labs
    INTERFACE
      "--coverage"
    )
endif()
