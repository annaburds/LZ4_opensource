
MODULE = tb_fsm

SRC = \
	sv/frame_struct.sv \
	sv/frame_assembler.sv \
	sv/frame_mux.sv \
	sv/process_frame_top.sv \
	sv/hash_register.sv \
	sv/hash_table.sv \
	sv/sub_per_hash.sv \
	sv/tb_process_frame_top.sv

WAIVERS = \
	waivers/pulp_platform/sub_per_hash_waivers.vlt \
	waivers/lz4/tb_process_frame_top.vlt

VERILATOR_FLAGS = \
	--trace

all: build

.PHONY: lint
lint:
	verilator --lint-only $(WAIVERS) $(SRC)

.PHONY: build
build:
	verilator $(VERILATOR_FLAGS) $(WAIVERS) --binary $(SRC) --top-module $(MODULE)

.PHONY: sim
sim: build
	./obj_dir/V$(MODULE)

.PHONY:sim
sim: waveform.vcd

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd -a gtkwave_setup.gtkw

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	./obj_dir/V$(MODULE) +verilator+rand+reset+2 

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
