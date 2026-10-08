# Variables
COMPILER = iverilog
SIMULATOR = vvp
VIEWER = gtkwave
VCD_FILE = dff_test.vcd

# Default target prints a help menu
all:
	@echo "Specify a circuit to compile and simulate:"
	@echo "  make dffreset      - Resettable D Flip-Flop"
	@echo "  make dff           - Simple D Flip-Flop"
	@echo "  make dffresetload  - D Flip-Flop with Resettable Load"
	@echo "  make view          - Open GTKWave"
	@echo "  make clean         - Remove compiled files"

# --- Circuit 1: Resettable D Flip-Flop ---
dffreset:
	$(COMPILER) -o dffreset.out dffreset.v dffreset_tb.v
	$(SIMULATOR) dffreset.out

# --- Circuit 2: Simple D Flip-Flop ---
dff:
	$(COMPILER) -o dff.out diff.v diff_tb.v
	$(SIMULATOR) dff.out

# --- Circuit 3: D Flip-Flop with Resettable Load ---
dffresetload:
	$(COMPILER) -o dffresetload.out diffresetload.v diffresetload_tb.v
	$(SIMULATOR) dffresetload.out

# --- View Waveforms ---
view:
	$(VIEWER) $(VCD_FILE)

# --- Clean Up ---
clean:
	rm -f dffreset.out dff.out dffresetload.out $(VCD_FILE)