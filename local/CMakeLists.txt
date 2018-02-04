aux_source_directory(. DIR_LOCAL_SRCS)

aux_source_directory(./fs DIR_FS_SRCS)

add_library(Local ${DIR_LOCAL_SRCS} ${DIR_FS_SRCS})

