# Ceci est un commentaire.
# Retirez le # pour que l'instruction soit prise en compte.

add_executable(
    hello-world
    helloworld.cpp
)

target_compile_features(hello-world PRIVATE cxx_std_17)

target_compile_options(hello-world PRIVATE
-Wall
-Wextra
#-Werror
)
