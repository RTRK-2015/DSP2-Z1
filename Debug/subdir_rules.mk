################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
filter_coeff.obj: ../filter_coeff.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/materija/RA151-2013/Zadatak1/c55xx_csl/inc" --include_path="C:/materija/RA151-2013/Zadatak1/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="filter_coeff.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fir.obj: ../fir.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/materija/RA151-2013/Zadatak1/c55xx_csl/inc" --include_path="C:/materija/RA151-2013/Zadatak1/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="fir.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/materija/RA151-2013/Zadatak1/c55xx_csl/inc" --include_path="C:/materija/RA151-2013/Zadatak1/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

processing.obj: ../processing.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/materija/RA151-2013/Zadatak1/c55xx_csl/inc" --include_path="C:/materija/RA151-2013/Zadatak1/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="processing.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

signal.obj: ../signal.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/materija/RA151-2013/Zadatak1/c55xx_csl/inc" --include_path="C:/materija/RA151-2013/Zadatak1/include" --define=c5535 --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="signal.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


