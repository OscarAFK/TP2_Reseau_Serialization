# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("TP2_Reseau_Serialization")

##########La lib d'utilities
set(Utils_TP2_SRC 
                        "utils/framework.cpp"
                        "utils/NetworkObject.cpp"
                        "utils/Enemy.cpp"
                        "utils/Player.cpp"
						)

set(Utils_TP2_HEADERS 
							"utils/framework.h"
                            "utils/NetworkObject.h"
                            "utils/Enemy.h"
                            "utils/Player.h")

add_library(Utils_TP2 STATIC ${Utils_TP2_SRC} ${Utils_TP2_HEADERS})
target_include_directories(Utils_TP2 PUBLIC utils)

##########

##########La lib du TP2
set(TP2_libSerializer_SRC 
                        "libSerializer/Serializer.cpp"
						"libSerializer/Compressor.cpp"
                        "libSerializer/Deserializer.cpp"
						)

set(TP2_libSerializer_HEADERS
						"libSerializer/Serializer.h"
						"libSerializer/Compressor.h"
						"libSerializer/Deserializer.h"
						)

add_library(TP2_libSerializer STATIC ${TP2_libSerializer_SRC} ${TP2_libSerializer_HEADERS})
target_include_directories(TP2_libSerializer PUBLIC libSerializer)
##########

target_link_libraries( TP2_libSerializer PUBLIC Utils_TP2 )
target_link_libraries( Utils_TP2 PUBLIC TP2_libSerializer )


#L'executable du TP2
add_executable( "TP2_PlayerSerialization" "libSerializer/mainSerialization.cpp" )
target_link_libraries( "TP2_PlayerSerialization" PUBLIC TP2_libSerializer )
target_link_libraries( "TP2_PlayerSerialization" PUBLIC Utils_TP2 )