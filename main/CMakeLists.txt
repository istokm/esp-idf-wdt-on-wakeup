idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS "include"
		REQUIRES ulp soc
)

set(ulp_app_name "ulp_wakeup")
set(ulp_s_sources "ulp/wakeup.S")
set(ulp_exp_dep_srcs "main.cpp")

ulp_embed_binary(${ulp_app_name} "${ulp_s_sources}" "${ulp_exp_dep_srcs}")

component_compile_options(-std=gnu++14)