armino_build_get_property(target ARMINO_SOC)

if(NOT "${target}" STREQUAL "bk7236")
    return()
endif()

armino_component_register(REQUIRES partitions)

if (CONFIG_TFM_V17)
armino_build_get_property(partition_hdr_dir PARTITIONS_HDR_DIR)
set(armino_dir ${COMPONENT_DIR}/../..)
set(tfm_dir ${COMPONENT_DIR}/tfm)
set(tfm_platform beken/${target})
set(tfm_toolchain_path ${CONFIG_TOOLCHAIN_PATH})
set(tfm_build_dir ${CMAKE_BINARY_DIR}/armino/tfm_v17)
set(tfm_install_dir ${CMAKE_BINARY_DIR}/install)

include(ExternalProject)
ExternalProject_Add(tfm_project
	SOURCE_DIR ${tfm_dir}
	CONFIGURE_COMMAND ""
	BUILD_IN_SOURCE 1
	CMAKE_ARGS
	BUILD_COMMAND
		cmake
		-G Ninja
		-B ${tfm_build_dir}
		-DCMAKE_PREFIX_PATH=${tfm_toolchain_path}
		-DCMAKE_INSTALL_PREFIX=${tfm_install_dir}
		-DARMINO_SDK_PATH=${armino_path}
		-DTFM_PLATFORM=${tfm_platform}
		-DTFM_TOOLCHAIN_FILE=toolchain_GNUARM.cmake
		-DCMAKE_BUILD_TYPE=${CONFIG_TFM_BUILD_TYPE}
		-DTEST_S=${CONFIG_TFM_TEST_S}
		-DTEST_NS=${CONFIG_TFM_TEST_NS}
		-DUSER=$ENV{USER}
		-DBL2=${CONFIG_TFM_BL2}
		-DTFM_PROFILE=profile_medium
		-DFPGA=${CONFIG_TFM_FPGA}
		-DOTP_NV_COUNTERS_RAM_EMULATION=${CONFIG_OTP_NV_COUNTERS_RAM_EMULATION}
		-DPLATFORM_DEFAULT_OTP_WRITEABLE=ON
		-DPLATFORM_DEFAULT_NV_COUNTERS=ON
		-DMCUBOOT_LOG_LEVEL=${CONFIG_TFM_BL2_LOG_LEVEL}
		-DPARTITION_HDR_DIR=${partition_hdr_dir}
		&& cd ${tfm_build_dir}
		&& ninja -- install
	BUILD_ALWAYS 1
	INSTALL_COMMAND ""
	)

add_dependencies(${COMPONENT_LIB} tfm_project)
endif()
