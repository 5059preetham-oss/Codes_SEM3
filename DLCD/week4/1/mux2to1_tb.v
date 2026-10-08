module mux2to1_tb;

    // Declare inputs as reg (registers can hold values)
    reg i0;
    reg i1;
    reg j;

    // Declare outputs as wire
    wire O;

    // Instantiate the multiplexer module
    mux2to1 uut (
        .i0(i0),
        .i1(i1),
        .j(j),
        .O(O)
    );

    initial begin
        // Generate waveform file for GTKWave
        $dumpfile("mux_waves.vcd");
        $dumpvars(0, mux2to1_tb);

        // Apply test vectors (all possible combinations of inputs)
        // Format: {j, i1, i0}
        
        // Select = 0 (Output should follow i0)
        j = 0; i1 = 0; i0 = 0; #10;
        j = 0; i1 = 0; i0 = 1; #10; 
        j = 0; i1 = 1; i0 = 0; #10;
        j = 0; i1 = 1; i0 = 1; #10;

        // Select = 1 (Output should follow i1)
        j = 1; i1 = 0; i0 = 0; #10;
        j = 1; i1 = 0; i0 = 1; #10;
        j = 1; i1 = 1; i0 = 0; #10;
        j = 1; i1 = 1; i0 = 1; #10;

        // End simulation
        $finish;
    end

    // Optional: Print to terminal to see values during simulation
    initial begin
        $monitor("Time=%0t | j=%b | i1=%b | i0=%b || O=%b", $time, j, i1, i0, O);
    end

endmodule